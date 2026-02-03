function [job,matFileOut] = dataLoaderWizard
% dataloader wizard - import script generator
% UI will ask for:
 % - input data (images and EBSD maps)
 % - save option & folder
 % - input parameters
% outputs: @trueEbsd job with job.imgList

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
        "Options",["EBSD map","Image(s)","Done"], "DefaultOption","Done","CloseFcn",@(~, ~) close(f1));
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
% UI reorder and construct disImgs array
fig = uifigure('WindowState', 'maximized');
reorderImagesUI(fig,dxy,imgsIn{:});
uiwait(fig);

% % outputs are stored in fig.UserData.disImgs
job = trueEbsd(fig.UserData.disImgs);
close(fig);

%% Do you want to save trueEbsd job?
f1 = uifigure;
selection = uiconfirm(f1,"Save trueEbsd job to file?","Save options", ...
    "Options",["Yes","No"], "DefaultOption",1,"CloseFcn",@(~, ~) close(f1));
if selection=="Yes"
    [file, savepname] = uiputfile('*.mat',"Save trueEbsd job as MAT file:","untitled.mat");
    if ischar(file) || isstring(file)
        matFileOut = fullfile(savepname,file);
        save(matFileOut,"job","-v7.3");
    end
else
    matFileOut="";
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
        display(ebsd);
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
            try %#ok<TRYNC> % to display any TIFF metadata
                info = imfinfo(fullfile(dataPath,f1));
                tag=[info.UnknownTags.Value];
                infoPix = extract(tag,caseInsensitivePattern(wildcardPattern(20)+"pixel"+wildcardPattern(50)));
                f1 = uifigure; 
                uialert(f1,[infoPix{:}],"TIFF tag info possibly related to image pixel size:",...
                    "CloseFcn",@(~, ~) close(f1));
                uiwait(f1);
            end
            dxy(imgN) = str2double(inputdlg('Enter image pixel length in um: ','Image pixel length', 1, "1"));
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