%% WP1 - MTEX TrueEBSD
% Description
% main script to run trueEBSD workflow
% MATLAB R2025a and mtex 6.1 (develop)

% Version 20240721 - inherited from NPL/EBSD Interfaces 2024 project
%
% % Inputs 
% Section "Import data + file saving:"
% dataPath = folder path to input data files (images, text, or hdf5
% format)
% setSave = do you want to save outputs? 1 (yes) or 0 (no)
% Section "Load EBSD data and images"
% dataPath = folder path to input data files (images, text, or hdf5
% format)
% setSave = do you want to save outputs? 1 (yes) or 0 (no)
% 
% Outputs
% Default save dir savepname = fullfile(cd,'..\Data\mtexOut\', dataName,timestamp);
% Save: plotted images, MAT file, command window outputs, copy of source code for current run
% 

clear; close all; home;

%% Check and add MATLAB paths
%add code paths
[mpath,mname,mext] = fileparts(matlab.desktop.editor.getActiveFilename);
cd(mpath);

% startup local MTEX
mtexPath = fullfile(mpath, 'mtex');
cd(mtexPath);
startup_mtex; %variables get cleared after this step so you need to recreate mpath

[mpath,mname,mext] = fileparts(matlab.desktop.editor.getActiveFilename);
trueEbsdPath = fullfile(mpath, 'trueEbsd')
addpath(genpath(trueEbsdPath));
cd(mpath); %return to starting folder


%% Import data + file saving
tic

% version ID as git hash in mtex-trueEbsd repo
% vId can be a number or char array
try vId = githash(fullfile(mpath,[mname,mext])); catch, vId = '0'; end

dataPath = '/media/Files/RockShare/Work/Projects/2025_TrueEBSD_BU_VG1/Test-Data-fcc-Ni';
% dataPath = uigetdir([],'Select input data folder');
[~, t, ~] = fileparts(dataPath);
dataName = removeweirdchars(t);

% file saving housekeeping
setSave = 1;
timestamp = char(datetime('now'),'yyMMdd_HHmm');
savepname = fullfile(dataPath, [dataName '_' timestamp]);

if setSave
    if ~exist (savepname, 'dir')
        mkdir(savepname);
    end
    diary(fullfile(savepname,[dataName '.log']));
    diary on
end

disp(['MTEX-TrueEBSD' newline 'Version ' num2str(vId)]);
disp(['TrueEBSD output log for date_time ' timestamp '.']);
if setSave
    disp(['Outputs and log files for ' dataName ' will be saved in ' savepname]);
else
    disp(['Output and log files for ' dataName ' will not be saved']);
end

%% Load EBSD data and images

disImgRef = im2double(imread(fullfile(dataPath,"PLX_1kres_10.00kV_1.6nA_20250602_5_Electron_233×_SE_ETD_1.00µs_12.0_10.0mm_32µm_289nm - Copy.tif")));
% t = imfinfo(fullfile(dataPath,"PLX_1kres_10.00kV_1.6nA_20250602_5_Electron_233×_SE_ETD_1.00µs_12.0_10.0mm_32µm_289nm - Copy.tif"));
% t.UnknownTags.Value
% % PixelWidth=2.89062e-07
disImgRef_pixelSize_um = 0.289062;

disImgNF = im2double(rgb2gray(imread(fullfile(dataPath,"NEAR_FSE_164.5mm.tif"))));
% t = imfinfo(fullfile(dataPath,"NEAR_FSE_164.5mm.tif"));
% t.UnknownTags.Value
% %     'PixelExtent=0.000000409398
% %      Date=02/06/2025 14:54:51
disImgNF_pixelSize_um = 0.409398;

disImgFF = im2double(rgb2gray(imread(fullfile(dataPath,"FAR_108.5mm__200dwelll_FSE.tif"))));
% t = imfinfo(fullfile(dataPath,"FAR_108.5mm__200dwelll_FSE.tif"));
% t.UnknownTags.Value
% % 'PixelExtent=0.000000409398
% % Date=02/06/2025 15:10:00
disImgFF_pixelSize_um = 0.409398;

ebsdFilePath = fullfile(dataPath,"fccnickel Specimen 7 Site 1 Map Data 12.ctf");
CS = {'notIndexed'; crystalSymmetry('m-3m','Mineral','fcc-Ni')};
ebsd = EBSD.load(ebsdFilePath,CS,'interface','ctf');
ebsd = gridify(rotate(ebsd,reflection(xvector),'keepEuler')); %CTF recorded x-values match the beam scan coordinates, not the SEM spatial coordinates
ebsd.how2plot = plottingConvention(vector3d.Z,-vector3d.X);

%% Image pre-processing

% fsd1a = imboxfilt(fsd1B,5);(I) 
disImgRef = imboxfilt(adapthisteq(disImgRef),5);
% disImgRef = imboxfilt(nthroot(disImgRef,0.3),5);
disImgFF = imboxfilt(disImgFF,3);

%% set up trueEBSD job
% job = trueEbsd(disImgEBSD, disImgNF, disImgFF, disImgRef);

% Construct @distortedImg imgList{:} 
imgList=cell(1,4);
imgList{1} = distortedImg('bc','drift-shift', ebsd, 'mapPlottingConvention', ebsd.how2plot);
imgList{2} = distortedImg(disImgNF,'shift', 'dxy', disImgNF_pixelSize_um, 'highContrast',1,'edgePadWidth',3); % 
imgList{3} = distortedImg(disImgFF,'tilt', 'dxy', disImgFF_pixelSize_um, 'highContrast',1,'edgePadWidth',3); % 
imgList{4} = distortedImg(disImgRef,'true', 'dxy', disImgRef_pixelSize_um, 'highContrast',0,'edgePadWidth',3); %

job = trueEbsd(imgList{:});

%%%
% Plot as-imported image sequence to check they are all of similar regions
% on the sample, but the image contrasts look quite different.

figure('WindowState', 'maximized'); 
t=tiledlayout('flow','TileSpacing','tight','Padding','tight');
title(t,'TrueEBSD starting image sequence');
for n=1:numel(imgList)
    nexttile; 
    imagesc('XData',imgList{n}.dx.*(1:size(imgList{n}.img,2)),...
        'YData',imgList{n}.dy*(1:size(imgList{n}.img,1)),...
        'CData',imgList{n}.img);
    colormap gray; axis image on ij;
end
linkaxes;



t1  = toc;
disp(['Finished set up trueEBSD job for ' dataName ' in ' num2str(t1,'%.1f') ' seconds']);
%% resize images to match pixel size and FOV

pixSzIn = 0; %set to 0 to use default pixel size (smallest in imgList)
job = pixelSizeMatch(job,pixSzIn);


figure('WindowState', 'maximized'); 
t=tiledlayout('flow','TileSpacing','tight','Padding','tight');
title(t,'TrueEBSD image sequence for cross-correlation');
for n=1:numel(job.resizedList)
    nexttile; 
    imagesc('XData',job.resizedList{n}.dx.*(1:size(job.resizedList{n}.img,2)),...
        'YData',job.resizedList{n}.dy*(1:size(job.resizedList{n}.img,1)),...
        'CData',job.resizedList{n}.(job.resizedList{n}.setXCF{1}.xcfImg));
    colormap gray; axis image on ij;
end
linkaxes;

t1  = toc;
disp(['Finished resize images to match pixel size and FOV for ' dataName ' in ' num2str(t1,'%.1f') ' seconds']);

%% optionally change cross-correlation ROI size and number
% these settings specific to seco contiguity workflow
% %{
% customSetXCF1.ROISize=512; % 4x biggest shift
% customSetXCF1.NumROI=struct;
% customSetXCF1.NumROI.x = 40; %  as many ROI as grains in FOV
% customSetXCF1.NumROI.y = round(customSetXCF1.NumROI.x * size(job.resizedList{1}.img,1)/size(job.resizedList{1}.img,2)); % follow image aspect ratio
% customSetXCF1.XCFMesh=250; % correlation peak upsampling, default 250
% customSetXCF1.xcfImg = 'edge';

% customSetXCF2 = customSetXCF1;
% customSetXCF2.ROISize=512;
% customSetXCF2.xcfImg = 'edge';

% % assign customSetXCF
% job.resizedList{1}.setXCF{1} = customSetXCF1;
% job.resizedList{3}.setXCF{1} = customSetXCF2;
% % or just rewrite individual properties
% job.resizedList{3}.setXCF{1}.xcfImg = 'img';
% job.resizedList{4}.setXCF{1}.xcfImg = 'img';
% job.resizedList{5}.setXCF{1}.xcfImg = 'img';
%}
%% calculate image distortions --> output job.shifts
% calculate ROI shifts

job = calcShifts(job,'fitErr');

t1  = toc;
disp(['Finished calculate image shifts and fit distortion models for ' dataName ' in ' num2str(t1,'%.1f') ' seconds']);

%% undistort images

job = undistort(job);

t1  = toc;
disp(['Finished remove image distortions for ' dataName ' in ' num2str(t1,'%.1f') ' seconds']);

%% Plotting script
% run and export plotting script
% %{
try %in case this fails, still save the data!
    trueEbsdPlots
    t1  = toc;
    disp(['Finished plot figures for ' dataName ' in ' num2str(t1,'%.1f') ' seconds']);

catch ME
    ME1 = ME;
    warning(ME.message);
    t1  = toc;
    disp(['Failed plot figures for ' dataName ' in ' num2str(t1,'%.1f') ' seconds']);

end
%}



%% Save stuff
if setSave
    close all
    srcFiles = cellfun(@which, ...
        {mname; 'trueEbsdPlots'; 'contiguityTest'; 'gbVoidsTest'; 'oriCompareTest'; ['loadDemoData_' removeweirdchars(dataName)]}, ...
        'UniformOutput',0);
    srcFiles(cellfun(@numel,srcFiles)==0)=[]; %remove empty files
    saveVarsAndScript(savepname, [removeweirdchars(dataName) '_' timestamp], srcFiles);
end

t1  = toc;
disp(['Finished TrueEBSD workflow for ' dataName ' in ' num2str(t1,'%.1f') ' seconds']);

if setSave
    diary off
end
% end
