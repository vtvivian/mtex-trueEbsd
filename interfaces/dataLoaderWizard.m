function [imgsIn] = dataLoaderWizard
% dataloader wizard - import script generator
% WC Contiguity workflow
% Assumes two h5oina files with specified data as TrueEbsd input


%% Do you want to save outputs?
f1 = uifigure;
selection = uiconfirm(f1,"Do you want to save outputs?","Save options", ...
    "Options",["Yes","No"], "DefaultOption",1); close(f1);
if selection=="No", setSave=0; else, setSave=1; end
% str_setSave = num2str(setSave);

%% Find input files
% keep loading more data until you're finished
keepLoading = 1;
imgsIn = {};
dxy = [];
dataPath = cd; %this gets updated in while loop

while keepLoading
    f1 = uifigure;
    selection = uiconfirm(f1,"What file do you want to load?","Load TrueEBSD data", ...
        "Options",["EBSD map","Image(s)","Done"], "DefaultOption","Done"); close(f1);
    switch selection
        case "EBSD map"
            [f1,dataPath] = uigetfile([getMTEXpref('EBSDExtensions').';{'*.*'}],'Select EBSD map file',...
                fullfile(dataPath),...
                'MultiSelect','off');
            try
                imgsIn{end+1} = importEbsdMap(f1,dataPath);
            catch ME
                warning("Couldn't load this EBSD map! Try again...")
            end

            %try loading images as well if they are bundled into EBSD h5oina file
            if endsWith(f1,".h5oina")
                [imgs1, dxy1] = importImages(f1, dataPath,imgsIn{end});
                % there may be more than one image loaded, append them
                % sequentially to the imgsIn list
                assert(class(imgs1)=="cell");
                for n=1:numel(imgs1)
                    imgsIn{end+1} = imgs1{n};
                    dxy(end+1) = dxy1(n);
                end
            end
        case "Image(s)"
            [f1,dataPath] = uigetfile('*.*','Select image file',...
                fullfile(dataPath),'MultiSelect','off');
            % TODO -- UI ask for image pixel size
            [imgsIn{end+1},dxy(end+1)] = importImages(f1, dataPath);
        case "Done"
            keepLoading = 0;
    end
end

% 1. Do you have an EBSD map?

% 2. Handle case where you don't have an EBSD map

% 3. Do you have images?
% If they are bundled in a container e.g. an h5oina file, create UI options

% Reorder list

return;




%% construct distortedImg list
%TODO - UI reorder and construct disImgs array
disImgs = reorderImages(imgsIn{:});

%TODO - make this into a private function
    function disImgs = reorderImages(varargin)
        if nargin<1
            return
        end
        nImgs = nargin;
        %%
        % create UI
        fig = uifigure('WindowState', 'maximized');
        gl = uigridlayout(fig,[nImgs+2 5]); %4 columns, n+2 rows depending on number of inputs

        [gl.ColumnWidth{:}] = deal('1x');

        gl.ColumnWidth{1} = 'fit';

        % % % create column headers
        gl.RowHeight{1} = 'fit';
        lbl = uilabel(gl,"Text","Image","HorizontalAlignment","center");
        lbl.Layout.Column = 1; lbl.Layout.Row = 1;
        lbl = uilabel(gl,"Text","List order:","HorizontalAlignment","center");
        lbl.Layout.Column = 2; lbl.Layout.Row = 1;
        lbl = uilabel(gl,"Text","Good image contrast?","HorizontalAlignment","center", ...
            'WordWrap','on');
        lbl.Layout.Column = 3; lbl.Layout.Row = 1;
        lbl = uilabel(gl,"Text","Edge width (pixels):","HorizontalAlignment","center" ...
            ,'WordWrap','on');
        lbl.Layout.Column = 4; lbl.Layout.Row = 1;
        lbl = uilabel(gl,"Text","Smoothing filter kernel size (pixels):","HorizontalAlignment","center" ...
            ,'WordWrap','on');
        lbl.Layout.Column = 5; lbl.Layout.Row = 1;

        % % % create 'Done' and 'Cancel' button
        gl.RowHeight{nImgs+2} = 'fit';
        btn1 = uibutton(gl, 'push','Text','Done',"HorizontalAlignment","center", ...
            "ButtonPushedFcn", @getCurrentValues);
        btn1.Layout.Row = nImgs+2; btn1.Layout.Column = [1 2];
        btn2 = uibutton(gl, 'push','Text','Cancel',"HorizontalAlignment","center", ...
            "ButtonPushedFcn", @resetInputs);
        btn2.Layout.Row = nImgs+2; btn2.Layout.Column = [3 4];

        function getCurrentValueBus(src,event)
           % get values and return TODO
        end
        function resetInputs(src,event)
            % reset and replot TODO
        end

        % % % create image thumbnail in each row, column 1
        for ii = 1:nImgs
            % avoid while debugging
            imgDisp = ebsd.bc;
            % if isa(varargin{ii},'EBSD')
            %     if isfield(varargin{ii}.prop,'bc')
            %           imgDisp = varargin{ii}.bc;
            %       elseif isfield(varargin{ii}.prop,'iq')
            %           imgDisp = varargin{ii}.iq;
            %       else
            %           warning("Couldn't find EBSD pattern quality field, using Euler Angle 1 map as image. " + ...
            %               "This is probably suboptimal; please modify the script yourself.")
            %           imgDisp = varargin{ii}.rotations.phi1;
            %     end
            % else
            %     imgDisp = varargin{ii};
            % end
            if ndims(imgDisp)<3
                imgDisp = repmat(rescale(imgDisp),[1 1 3]);
            end
            iThumb = uiimage(gl, "ImageSource",imgDisp);
            iThumb.Layout.Row = ii+1; iThumb.Layout.Column = 1;
        end

        % % % create list order selector in each row, column 2
        listTxt = "Image " + num2str((1:nImgs).');
        listTxt(1) = listTxt(1) + " (max distorted)";
        listTxt(end) = listTxt(end) + " (ref image)";

        listOrder = createArray(1,nImgs,"matlab.ui.control.ListBox");
        for ii = 1:nImgs
            listOrder(ii) = uilistbox(gl,'Items',listTxt);
            listOrder(ii).Value = listTxt(ii);
            listOrder(ii).Layout.Row = ii+1;
            listOrder(ii).Layout.Column = 2;
        end
        % TODO - make sure listOrderDD.values are unique before proceeding


        % % % create high contrast checkboxes in each row, column 3
        tfContrast = createArray(1,nImgs,"matlab.ui.control.CheckBox");
        for ii = 1:nImgs
            tfContrast(ii) = uicheckbox(gl,'Value',true,'Text',"");
            tfContrast(ii).Layout.Row = ii+1;
            tfContrast(ii).Layout.Column = 3;
        end

        % % % create edge pad width selector in each row, column 4
        padWid = createArray(1,nImgs,"matlab.ui.control.Spinner");
        for ii = 1:nImgs
            padWid(ii) = uispinner(gl,'Value',3,'Limits',[1 Inf],...
                'ValueDisplayFormat','%d pixels',"HorizontalAlignment","center");
            padWid(ii).Layout.Row = ii+1;
            padWid(ii).Layout.Column = 4;
        end       
        
        % % % create edge pad width selector in each row, column 5
        filtWid = createArray(1,nImgs,"matlab.ui.control.Spinner");
        for ii = 1:nImgs
            filtWid(ii) = uispinner(gl,'Value',2,'Limits',[0 Inf],...
                'ValueDisplayFormat','%d pixels',"HorizontalAlignment","center");
            filtWid(ii).Layout.Row = ii+1;
            filtWid(ii).Layout.Column = 5;
        end



        %%

        % create distortedImg array
        % TODO - not yet -- re-plot in correct order and define distortion models
        % first
        disImgs=createArray(nImgs,1,'distortedImg');
        for ii=1:nImgs
            disImg1 = varargin{permorder(ii)};
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
                disImgs(ii) = distortedImg(pq, distortionName(permorder(ii)), disImg1, ...
                    'highContrast',tfContrast(permorder(ii)),'edgePadWidth',padWid(permorder(ii)));
            else %assume image
                disImgs(ii) = distortedImg(imgName,distortionName(permorder(ii)),disImg1, ...
                    'dxy', dxy(permorder(ii)), ...
                    'highContrast',tfContrast(permorder(ii)),'edgePadWidth',padWid(permorder(ii)));
            end
        end

    end

%%image preprocessing
% TODO - put in reorder UI
% str_filterSize = inputdlg('Image denoising (imboxfilt) kernel radius ', 'Enter number of pixels', 1, {'3'});
% filterSize=str2double(str_filterSize{:});
%
% % image denoising
% fsdB3 = rescale(imboxfilt(fsdB3,filterSize));
% fsdT3 = rescale(imboxfilt(fsdT3,filterSize));
% fsdT1 = rescale(imboxfilt(fsdT1,filterSize));
% fsdT10= rescale(imboxfilt(fsdT10,filterSize));

% disImgs=createArray(5,1,'distortedImg');
% disImgs(1) = distortedImg('bc','shift-drift', ebsd, 'how2plot', pC, 'highContrast',1,'edgePadWidth',3);
% disImgs(2) = distortedImg(fsdB3,'true', 'dxy', pixSzImg, 'highContrast',1,'edgePadWidth',5);
% disImgs(3) = distortedImg(fsdT3,'shift', 'dxy', pixSzImg, 'highContrast',1,'edgePadWidth',5);
% disImgs(4) = distortedImg(fsdT1,'tilt', 'dxy', pixSzImg, 'highContrast',1,'edgePadWidth',5);
% disImgs(5) = distortedImg(fsdT10,'true', 'dxy', pixSzImg, 'highContrast',1,'edgePadWidth',3);

%% Check your images
% you can zoom in and out - tile axes are linked
figure("WindowState","maximized");
tiledlayout('flow','TileSpacing','compact','Padding','tight');
for n=1:numel(disImgs)
    nexttile;
    imagesc('XData',disImgs(n).dx.*(1:size(disImgs(n).img,2)),...
        'YData',disImgs(n).dy*(1:size(disImgs(n).img,1)),...
        'CData',disImgs(n).img);
    colormap gray; axis image on ij;
    title(['Distorted Image ' num2str(n)])
end
linkaxes;


%% Save script
%Load template
[fp,fn,fe]=fileparts(which('dataLoaderWizard_Template.txt'));
templateTxt = readlines(fullfile(fp,strcat(fn,fe)));
newTxt = templateTxt;
% find text between angle brackets < > you want to replace
try
    for n=1:numel(templateTxt)
        idxStart = strfind(templateTxt(n),"<");
        idxEnd = strfind(templateTxt(n),">");
        if ~isempty(idxStart)
            for c=1:numel(idxStart) % incase of more than one replacement per line
                replaceMe(c) = extractBetween(templateTxt(n),idxStart(c),idxEnd(c),'Boundaries','exclusive');
            end
            newTxt(n) = replaceBetween(templateTxt(n),idxStart(c),idxEnd(c),eval(replaceMe(c)),'Boundaries','inclusive');
        else
            continue;
        end
    end
    % guess dataset name by parent folder name
    st = split(dataPath,filesep);
    dataName = removeweirdchars(char(st(find(cellfun(@numel,st),1,"last"))));
    writelines(newTxt,fullfile(fp,['loadData_' dataName '.m']));

catch ME
    ME1 = ME;
    if n<numel(templateTxt)
        error(['error writing line ' num2str(n) ...
            ' of dataloader script, check your template.']);
    else
        error('error writing dataloader script, check your folder permissions.');
    end

end


%% %%% Subfunctions
%% Import EBSD maps
    function [ebsd] = importEbsdMap(f1,dataPath)
        % deal with manufacturer-specific params
        [~,~,ext1] = fileparts(f1);
        switch ext1
            case {".h5oina", ".ctf", ".crc", ".cpr"}
                warning("Based on your file format, I'm assuming a typical coordinate system for Oxford Instruments EBSD systems.");
                rot = rotation.map(-xvector,xvector,yvector,yvector);
                % == rotation.byAxisAngle(yvector,180*degree)
                % but a bit more readable
            case {".oh5", ".ang"}
                warning("Based on your file format, I'm assuming the 'setting 2' coordinate system for EDAX EBSD systems.");
                rot = rotation.map(-yvector,xvector,-xvector,yvector);
                % == rotation.byAxisAngle(xvector-yvector,180*degree)
                % (EDAX setting 2) but a bit more readable
            otherwise
                warning('Unrecognised EBSD file format. Check plotting conventions and rotate the crystal orientations yourself.')
                rot = rotation.byEuler(0,0,0);
        end

        % load the EBSD map and rotate everything into matlab image
        % coordinate frame
        pC = plottingConvention(-vector3d.Z,vector3d.X); pC.makeDefault;
        ebsd = gridify(rotate(EBSD.load(fullfile(dataPath,f1)),rot,'keepXY'));
        assert(isa(ebsd,'EBSDsquare'),"EBSD map must be in square grid format!");
        ebsd.how2plot = pC;
        disp("Crystal orientation reference axes rotated to match image (Y↓→X).");
    end
%% Import SEM images
    function [imgs1,dxy] = importImages(f1, dataPath, varargin)
        imgs1 = {};
        dxy = [];
        if endsWith(f1,".h5oina")
            if exist("varargin","var") && isa(varargin{1},"EBSD")
                h5Imgs = varargin{1};
            else
                h5Imgs = EBSD.load(fullfile(dataPath,f1));
            end
            % if varargin
            % TODO - ebsd object as optional input so no need to load twice
            % end
            % load images inside h5oina container
            disp(append("Loooking for images in file", f1, ": "));

            h5ImgsNames = fieldnames(h5Imgs.opt.Images);
            % only get image number from one of the 5 FSD diodes
            fsdNums = extractAfter(h5ImgsNames,'Lower_Centre_');fsdNums(cellfun(@isempty,fsdNums))=[];
            % get other SEM image names
            semNames = h5ImgsNames(contains(h5ImgsNames,'Image_','IgnoreCase',true));
            disp(append("Assuming OxInst Aztec naming conventions for FSD images, if you ", ...
                "renamed any of the images within Aztec ", ...
                "this might lead to unexpected behaviour. "));

            figure("WindowState","maximized"); tiledlayout('flow','TileSpacing','compact','Padding','tight');
            % FSD images
            for nn=1:numel(fsdNums)
                nexttile;
                imagesc(rescale(im2double(cat(3,...
                    h5Imgs.opt.Images.(['Lower_Centre_' fsdNums{nn}]), ...
                    h5Imgs.opt.Images.(['Lower_Left_' fsdNums{nn}]), ...
                    h5Imgs.opt.Images.(['Lower_Right_' fsdNums{nn}])))));
                axis image off ij;
                title(['FSD Lower ' fsdNums{nn}],'Interpreter','none');

                nexttile;
                imagesc(rescale(im2double(mean(cat(3,...
                    h5Imgs.opt.Images.(['Upper_Left_' fsdNums{nn}]), ...
                    h5Imgs.opt.Images.(['Upper_Right_' fsdNums{nn}])),3))));
                colormap gray; axis image off ij;
                title(['FSD Upper ' fsdNums{nn}],'Interpreter','none');
            end
            % SEM images
            for nn=1:numel(semNames)
                nexttile;
                imagesc(rescale(im2double(h5Imgs.opt.Images.(semNames{nn}))));
                colormap gray; axis image off ij;
                title(semNames{nn},'Interpreter','none');
            end
            linkaxes;

            % UI select images
            % construct input dialogue options
            h5ImgsList_fsdLow= cellfun(@append,repmat("FSD Lower ",size(fsdNums)), fsdNums, 'UniformOutput', false);
            h5ImgsList_fsdUp = cellfun(@append,repmat("FSD Upper ",size(fsdNums)), fsdNums, 'UniformOutput', false);
            h5ImgsList_sem = semNames;
            h5ImgsList_all = vertcat(h5ImgsList_fsdLow,h5ImgsList_fsdUp,h5ImgsList_sem);

            keepLoading1 = true;
            while keepLoading1
                [imgs1{end+1},keepLoading1] = selectImage;
                dxy(end+1) = double(h5Imgs.opt.Images.Header.X_Step);

            end

        elseif any(endsWith(f1,[imformats().ext]))
            % load normal image files
            imgs1{1} = rescale(im2double(imread(fullfile(dataPath,f1))));
            dxy(end+1) = str2double(inputdlg('Image pixel length ', 'Enter image pixel size in um: ', 1, "0"));
        else
            warning('Unrecognised image file format. No image loaded.')
        end

        %% h5oina image selection UI
        function [img1,tf] = selectImage
            img1 = [];
            % % enable user selection
            [indx,tf] = listdlg('ListString',h5ImgsList_all,...
                'PromptString','Select next image:',...
                'ListSize',[400 200],...
                'SelectionMode','single', ...
                'CancelString','Done');
            if ~tf % if user clicks 'Done'
                return;
            end

            % Load differently depending on image type
            if contains(h5ImgsList_all{indx}, "Upper") && contains(h5ImgsList_all{indx}, "FSD")
                % FSD upper diodes get averaged and loaded as greyscale
                imgNumSuffix = extractAfter(h5ImgsList_all{indx},'FSD Upper ');
                img1 = rescale(im2double(mean(cat(3,...
                    h5Imgs.opt.Images.(['Upper_Left_' imgNumSuffix]), ...
                    h5Imgs.opt.Images.(['Upper_Right_' imgNumSuffix]) ),3)));
            elseif  contains(h5ImgsList_all{indx}, "Lower") && contains(h5ImgsList_all{indx}, "FSD")
                % FSD lower diodes get loaded as RGB colour
                imgNumSuffix = extractAfter(h5ImgsList_all{indx},'FSD Lower ');
                img1 = rescale(im2double(cat(3,...
                    h5Imgs.opt.Images.(['Lower_Centre_' imgNumSuffix]), ...
                    h5Imgs.opt.Images.(['Lower_Left_' imgNumSuffix]), ...
                    h5Imgs.opt.Images.(['Lower_Right_' imgNumSuffix]) )));
            else
                % all other SEM images get loaded as greyscale
                img1 = rescale(im2double(h5Imgs.opt.Images.(h5ImgsList_all{indx})));
            end
        end

    end


end