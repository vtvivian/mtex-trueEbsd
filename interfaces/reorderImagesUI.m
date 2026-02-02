function [disImgs] = reorderImagesUI(fig,dxyList,varargin)
% construct GUI for input data order and settings
% input = imported images and/or EBSD maps
% output = @distortedImg array

if nargin<1
    return
end
imgListIn = varargin;
nImgs = numel(imgListIn);
% initialise output
disImgs=createArray(nImgs,1,'distortedImg');     
%%
% create UI
gl = uigridlayout(fig,[7 nImgs+1]); % 6 rows, n+2 columns depending on number of inputs
[gl.RowHeight{:}] = deal('1x');
[gl.ColumnWidth{:}] = deal('1x');
gl.RowHeight{1} = '2x';
gl.RowHeight{end} = 'fit';
gl.ColumnWidth{1} = 'fit';

% % % create Row headers
gl.ColumnWidth{1} = 'fit';
lbl = uilabel(gl,"Text","Image","HorizontalAlignment","center");
lbl.Layout.Row = 1; lbl.Layout.Column = 1;
lbl = uilabel(gl,"Text","List order:","HorizontalAlignment","center");
lbl.Layout.Row = 2; lbl.Layout.Column = 1;
lbl = uilabel(gl,"Text","Good image contrast?","HorizontalAlignment","center", ...
    'WordWrap','on');
lbl.Layout.Row = 3; lbl.Layout.Column = 1;
lbl = uilabel(gl,"Text","Edge width (pixels):","HorizontalAlignment","center" ...
    ,'WordWrap','on');
lbl.Layout.Row = 4; lbl.Layout.Column = 1;
lbl = uilabel(gl,"Text","Image smoothing filter kernel width (pixels):","HorizontalAlignment","center" ...
    ,'WordWrap','on');
lbl.Layout.Row = 5; lbl.Layout.Column = 1;
lbl = uilabel(gl,"Text","Distortion name relative to next image: ","HorizontalAlignment","center" ...
    ,'WordWrap','on');
lbl.Layout.Row = 6; lbl.Layout.Column = 1;

% % % create 'Reorder', 'Reset' and 'Done' buttons
btn1 = uibutton(gl, 'push','Text','Reorder',"HorizontalAlignment","center", ...
    "ButtonPushedFcn", @reorderInputs);
btn1.Layout.Column = 1; btn1.Layout.Row = 7;
btn2 = uibutton(gl, 'push','Text','Reset',"HorizontalAlignment","center", ...
    "ButtonPushedFcn", @resetInputs);
btn2.Layout.Column = 2; btn2.Layout.Row = 7;
btn3 = uibutton(gl, 'push','Text','Done',"HorizontalAlignment","center", ...
    "ButtonPushedFcn", @getCurrentValues);
btn3.Layout.Column = 3; btn3.Layout.Row = 7;

%% % create image thumbnail in each Column, Row 1
for j = 1:nImgs
    if isa(imgListIn{j},'EBSD')
        if isfield(imgListIn{j}.prop,'bc')
              imgDisp = imgListIn{j}.bc;
          elseif isfield(imgListIn{j}.prop,'iq')
              imgDisp = imgListIn{j}.iq;
          else
              warning("Couldn't find EBSD pattern quality field, using Euler Angle 1 map as image. " + ...
                  "This is probably suboptimal; please modify the script yourself.")
              imgDisp = imgListIn{j}.rotations.phi1;
        end
    else
        imgDisp = imgListIn{j};
    end
    if ndims(imgDisp)<3 %#ok<ISMAT>
        imgDisp = repmat(rescale(imgDisp),[1 1 3]);
    end
    iThumb = uiimage(gl, "ImageSource",imgDisp);
    iThumb.Layout.Column = j+1; iThumb.Layout.Row = 1;
end

%% % create list order selector in each Column, Row 2
listTxt = "Image " + num2str((1:nImgs).');
listTxt(1) = listTxt(1) + " (max distorted)";
listTxt(end) = listTxt(end) + " (ref image)";

listOrder = createArray(1,nImgs,"matlab.ui.control.ListBox");
for jj = 1:nImgs
    listOrder(jj) = uilistbox(gl,"Items",listTxt,"ItemsData",(1:nImgs));
    listOrder(jj).Value = jj; %which one is selected by default
    listOrder(jj).Layout.Column = jj+1;
    listOrder(jj).Layout.Row = 2;
end

%% % create high contrast checkboxes in each Column, Row 3
tfContrast = createArray(1,nImgs,"matlab.ui.control.CheckBox");
for jj = 1:nImgs
    tfContrast(jj) = uicheckbox(gl,'Value',true,'Text',"");
    tfContrast(jj).Layout.Column = jj+1;
    tfContrast(jj).Layout.Row = 3;
end

%% % create edge pad width selector in each Column, Row 4
padWid = createArray(1,nImgs,"matlab.ui.control.Spinner");
for jj = 1:nImgs
    padWid(jj) = uispinner(gl,'Value',3,'Limits',[1 Inf],...
        'ValueDisplayFormat','%d pixels',"HorizontalAlignment","center");
    padWid(jj).Layout.Column = jj+1;
    padWid(jj).Layout.Row = 4;
end

%% % create image filter width selector in each Column, Row 5
filtWid = createArray(1,nImgs,"matlab.ui.control.Spinner");
for jj = 1:nImgs
    filtWid(jj) = uispinner(gl,'Value',3,'Limits',[0 Inf],...
        'ValueDisplayFormat','%d pixels',"HorizontalAlignment","center");
    filtWid(jj).ValueChangedFcn = @ensureOddFilt;
    filtWid(jj).Layout.Column = jj+1;
    filtWid(jj).Layout.Row = 5;
end
% imboxfilt only allows odd pixel numbers
    function ensureOddFilt(src,event)        
        w = round(event.Value);
        wOld = event.PreviousValue;
        difference = w-wOld;
        if iseven(w)
            if  difference>0 %user clicked 'up'
            wNew = w+1; 
            elseif difference < 0 %user clicked 'down'
            wNew = w-1; 
            else %nothing happened?? pick random
            wNew = w-1; 
            end
        else
            wNew = w;
        end
        if wNew<=0 %no filter
            src.Value = 0;
        else
            src.Value = wNew;
        end
    end


%% % create dropdown for distortion name selection  in each Column, Row 6 
% distortion is w.r.t. next image
% do not allow selection before next order
% may need a 'valuechangedfcn' from the listOrder box

if any(1:nImgs ~= sort([listOrder(:).Value]))
    ddTxt = "Reorder images first!";
else
    ddTxt = ["Select distortion type:",...
        "shift","drift","shift-drift","tilt","true"];
end

distortionName = createArray(1,nImgs,"matlab.ui.control.DropDown");
for jj = 1:nImgs
    distortionName(jj) = uidropdown(gl,'Items',ddTxt,"Editable","on");
    if jj==nImgs && all(ddTxt ~= "Reorder images first!")
        distortionName(jj).Value = "true";
    else
        distortionName(jj).Value = ddTxt(1); %which one is selected by default
    end
    distortionName(jj).ItemsData = int8(str2double(extract(distortionName(jj).Value, digitsPattern)));
    distortionName(jj).Layout.Column = jj+1;
    distortionName(jj).Layout.Row = 6;
end

%% Button callback subfunctions
% reorderInputs "reorder" button
% resetInputs - "reset" button
% getCurrentValues - "done" button

    function reorderInputs(src,event)
        % button callback for 'Reorder'
        
        % make sure listOrder.ItemsData values are unique before proceeding
        if numel(unique([listOrder(:).Value]))~=nImgs
            f1 = uifigure;
            uiconfirm(f1,"Invalid image order! Try again.","Selection Error!", ...
                "Options","OK"); close(f1);
            return;
        end

        % then re-plot GUI in new order
        imgListOut = imgListIn([listOrder(:).Value]); 
        dxyListOut = dxyList([listOrder(:).Value]);
        reorderImagesUI(fig,dxyListOut,imgListOut{:});        
    end
%%
    function resetInputs(src,event)
        % button callback for 'Reset'
        % don't get current values
        % just replot GUI
        reorderImagesUI(fig,imgListIn{:});

    end
%%
    function getCurrentValues(src,event)
        % button callback for 'Done'
        % get values and return distortedImg array

        % check field values are ok first
        % 1. check distortionNames are populated correctly
        % 2. listOrder values are in order

        if any(matches({distortionName(:).Value},"Select distortion type:")) ||...
                any(matches({distortionName(:).Value},"Reorder images first!"))
            f1 = uifigure; uiconfirm(f1,"Select distortion model names first! Try again.","Selection Error", ...
                "Options","OK"); close(f1);
            return;
        end
        if distortionName(nImgs).Value ~= "true"
            f1 = uifigure; uiconfirm(f1,"Final image must be reference image. " + ...
                "Please select 'true' for distortion name.","Selection Error", ...
                "Options","OK"); close(f1);
            return;
        end
        
        if any(1:nImgs ~= sort([listOrder(:).Value]))
            f1 = uifigure; uiconfirm(f1,"Invalid image order! Try again.","Selection Error", ...
                "Options","OK"); close(f1);
            return;
        end

        %%%% end checks

        % create @distortedImg output array   
        for ii=1:nImgs
            ix = listOrder(ii).Value;
            disImg1 = imgListIn{ix};

            if isa(disImg1,"EBSD") %EBSD map
                if isfield(disImg1.prop,'bc')
                    pq = 'bc';
                elseif isfield(disImg1.prop,'iq')
                    pq = 'iq';
                else
                    warning("Couldn't find EBSD pattern quality field, using Euler Angle 1 map as image. " + ...
                        "This is probably suboptimal; please modify the script yourself.")
                    pq = 'rotations.phi1';
                end
                disImgs(ii) = distortedImg(pq, distortionName(ix).Value, disImg1, ...
                    'highContrast',tfContrast(ix),'edgePadWidth',round(padWid(ix).Value));

            else %assume image
                %filter image first
                if filtWid(ix).Value>0
                    disImg2 = rescale(imboxfilt(disImg1,round(filtWid(ix).Value)));
                else
                    disImg2=disImg1;
                end
                disImgs(ii) = distortedImg(disImg2,distortionName(ix).Value,...
                    'dxy', dxyList(ix), 'highContrast',tfContrast(ix),...
                    'edgePadWidth',round(padWid(ix).Value));
            end
            
        end
        uiresume(fig);
    end


end