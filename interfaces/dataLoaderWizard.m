function [disImgs] = dataLoaderWizard
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
imgsIn = cell(100,1);
dxy = zeros(100,1);
imgNN = 0;
dataPath = cd; %this gets updated in while loop

while keepLoading
    f1 = uifigure;
    selection = uiconfirm(f1,"What file do you want to load?","Load TrueEBSD data", ...
        "Options",["EBSD map","Image(s)","Done"], "DefaultOption","Done"); close(f1);
    switch selection
        case "EBSD map"
            imgNN = imgNN+1;
            [f1,dataPath] = uigetfile([getMTEXpref('EBSDExtensions').';{'*.*'}],'Select EBSD map file',...
                fullfile(dataPath),...
                'MultiSelect','off');
            if f1==0, continue; end %user selected "cancel"
            try
                imgsIn{imgNN} = importEbsdMap(f1,dataPath);
            catch ME
                warning("Couldn't load this EBSD map! Try again...")
            end

            %try loading images as well if they are bundled into EBSD h5oina file
            if endsWith(f1,".h5oina")
                [imgs1, dxy1] = importImages(f1, dataPath,imgsIn{end});
                if ~isempty_cell(imgs1)
                    % there may be more than one image loaded, append them to the imgsIn list
                    assert(class(imgs1)=="cell");
                    imgsIn(imgNN+1:imgNN+numel(imgs1)) = imgs1;
                    dxy(imgNN+1:imgNN+numel(imgs1)) = dxy1;
                    imgNN = imgNN+numel(imgs1);
                end
            end
        case "Image(s)"
            imgNN = imgNN+1;
            [f1,dataPath] = uigetfile('*.*','Select image file',...
                fullfile(dataPath),'MultiSelect','off');
            if f1==0, continue; end %user selected "cancel"
            [imgs1, dxy1] = importImages(f1, dataPath);
            if ~isempty_cell(imgs1)
                assert(class(imgs1)=="cell");
                imgsIn(imgNN:imgNN+numel(imgs1)-1) = imgs1;
                dxy(imgNN:imgNN+numel(imgs1)-1) = dxy1;
                imgNN = imgNN+numel(imgs1)-1;
            end

        case "Done"
            keepLoading = 0;
            % Truncate extra space
            % some of these may be in the middle where an empty image is
            % selected
            rowsToKeep = ~cellfun('isempty',imgsIn);
            imgsIn = imgsIn(rowsToKeep);
            dxy = dxy(rowsToKeep);
            imgNN = nnz(rowsToKeep);
    end
end



%% construct distortedImg list
%TODO - UI reorder and construct disImgs array
fig = uifigure('WindowState', 'maximized');
disImgs =  reorderImagesUI(fig,dxy,imgsIn{:});
% uiwait(fig);
%

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
        imgs1 = cell(100,1);
        dxy = zeros(100,1);
        imgN = 0;
        if endsWith(f1,".h5oina")
            if ~isempty(varargin) && isa(varargin{1},"EBSD")
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
                imgN = imgN+1;
                [imgs1{imgN},keepLoading1] = selectImage;
                dxy(imgN) = double(h5Imgs.opt.Images.Header.X_Step);

            end

        elseif any(endsWith(f1,[imformats().ext]))
            % load normal image files
            imgN = imgN+1;
            imgs1{imgN} = rescale(im2double(imread(fullfile(dataPath,f1))));
            dxy(imgN) = str2double(inputdlg('Image pixel length ', 'Enter image pixel size in um: ', 1, "0"));
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

        % remove unallocated space
        imgs1 = imgs1(1:imgN);
        dxy = dxy(1:imgN);
    end


end