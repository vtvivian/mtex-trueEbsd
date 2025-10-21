%% WP1 - MTEX TrueEBSD
% Description
% main script to run trueEBSD workflow
% MATLAB R2023a and local mtex version (forked from develop, approx mtex6.0.beta3)
%
% Inputs 
% dataName = @char array, relative path to dataset from
%       fullfile(cd,'\..\Data\') 
% loadDemoData_<dataName1>.m  user-created import script where 
%       dataName1 = dataName with illegal characters removed (non alphabetic, 
%   numeric, or underscore). See dataLoader/loadDemoData.m for more
%   information on how to write the loadDemoData_<dataName1>.m script.
% setSave = do you want to save outputs? 1 (yes) or 0 (no)
% 
% Outputs
% Default save dir savepname = fullfile(cd,'..\Data\mtexOut\', dataName,timestamp);
% Save: plotted images, MAT file, command window outputs, copy of source code for current run
% 
% Version control
% 20230104 - created
% 20240717 - updated after SQD review
% 20240721 - create contiguity dataloader script generator

clear; close all; home;
% manually update version ID (this can be a number, timestamp, or git hash)
% vId can be a number or char array
vId = '20240721';
%% Check and add MATLAB paths
% for creating standalone applications, you can't use addpath, so run this
% manually before starting matlab
if ~isdeployed
    %add all code from WP1,2,3
    [mpath,mname,mext] = fileparts(matlab.desktop.editor.getActiveFilename);
    cd(mpath);
    addpath(genpath(fullfile(cd,'\..\WP3_Contiguity')));
    addpath(genpath(fullfile(cd,'\..\WP2_GrainSegmentation')));
    addpath(genpath(fullfile(cd,'\..\WP1_TrueEBSD')));
    warning('off','MATLAB:rmpath:DirNotFound');
    rmpath(genpath(fullfile(cd,'\..\Data\mtexOut')));

    % check if the correct version of mtex is already on the path
    p = strsplit(mpath, filesep); %temporary variable to construct parent folder
    mtexPath = dir(fullfile(mpath, '..' ,'mtex*'));
    % now look for mtexPath in existing matlab path
    if any(strcmpi(strsplit(path,pathsep),fullfile(mtexPath.folder,mtexPath.name)))
        % mtex already in search path, which mean it's already loaded
        % update mtex settings just in case
        mtex_settings;
    else
        % startup MTEX then return to original folder
        cd(fullfile(mtexPath.folder,mtexPath.name));
        startup_mtex;
        cd(mpath);
    end
else
    [mpath,mname,mext] = fileparts(which('main.m'));
    mtex_settings;
end

%% Set up multiple datasets
% nameList{1} = 'Seco\AKPZ_020_1_1_site2';
% nameList{1} = 'Seco\AKPZ_020_2_1_site3';
% nameList{end+1} = 'Seco\AKPZ_021_1_1_site1';
% nameList{end+1} = 'Seco\AKPZ_021_2_1_site1';
% % 
% nameList{end+1} = 'Seco\AKPZ_020_1_1_site1';
% nameList{end+1} = 'Seco\AKPZ_020_2_1_site2';
% nameList{end+1} = 'Seco\AKPZ_021_1_1_site2';
% nameList{end+1} = 'Seco\AKPZ_021_2_1_site2';

% nameList{end+1} = 'Seco\AKPZ_020_1_1_site3';
% nameList{1} = 'Seco\AKPZ_020_2_1_site1'; %drifted bad - migth not work?
% nameList{end+1} = 'Seco\AKPZ_021_2_1_site3';
% nameList{end+1} = 'Seco\AKPZ_021_2_1_site3';

% for d = 1:numel(nameList)

%% Import data + file saving
tic

if ~isdeployed
    dataName = 'Ti-64';
    % dataName = 'CP-Zr'; dataName = 'ZrH';
    % dataName = nameList{d};    
else    
     %run import wizard on standalone app, automatically constructs
     %dataName
    [imgList,dataName] = loadDemoData('','wizard'); 
end


% file saving housekeeping
setSave = 1;
timestamp = char(datetime('now'),'yyMMdd_HHmm');
if ~isdeployed
    savepname = fullfile(cd,'..\Data\mtexOut\', dataName,timestamp);
else
    % prompt for a file path
    savepname = uigetdir(cd,'Select outputs folder');
end

if setSave
    if ~exist (savepname, 'dir')
        mkdir(savepname);
    end
    diary(fullfile(savepname,[removeweirdchars(dataName) '_log.txt']));
    diary on
end


disp(['EBSD Interfaces project 2024, Vivian Tong' newline 'Version ' num2str(vId)]);
disp(['TrueEBSD output log for date_time ' timestamp '.']);
if setSave
    disp(['Outputs and log files for ' dataName ' will be saved in ' savepname]);
else
    disp(['Output and log files for ' dataName ' will not be saved']);
end


%% set up trueEBSD job
% job = trueEbsd(disImgEBSD, disImgNF, disImgFF, disImgBSE);

job = trueEbsd(imgList{:});

t1  = toc;
disp(['Finished set up trueEBSD job for ' dataName ' in ' num2str(t1,'%.1f') ' seconds']);
%% resize images to match pixel size and FOV

if ~isdeployed
    pixSzIn = 0; %set to 0 to use default pixel size
else
    % prompt for a pixel size
    pixSzIn = inputdlg('Input pixel size: ', 'dataName', 1, {'0'}); pixSzIn = str2double(pixSzIn{:});

end
% TODO -- use default input if pixSzin = 0
% TODO -- allow prompts for the other name,value pair options?
job = pixelSizeMatch(job,pixSzIn);

t1  = toc;
disp(['Finished resize images to match pixel size and FOV for ' dataName ' in ' num2str(t1,'%.1f') ' seconds']);

%% optionally change cross-correlation ROI size and number
% these settings specific to seco contiguity workflow
% %{
customSetXCF1.ROISize=512; % 4x biggest shift
customSetXCF1.NumROI=struct;
customSetXCF1.NumROI.x = 40; %  as many ROI as grains in FOV
customSetXCF1.NumROI.y = round(customSetXCF1.NumROI.x * size(job.resizedList{1}.img,1)/size(job.resizedList{1}.img,2)); % follow image aspect ratio
customSetXCF1.XCFMesh=250; % correlation peak upsampling, default 250
customSetXCF1.xcfImg = 'edge';

customSetXCF2 = customSetXCF1;
customSetXCF2.ROISize=512;
customSetXCF2.xcfImg = 'edge';

% assign customSetXCF
job.resizedList{1}.setXCF{1} = customSetXCF1;
job.resizedList{3}.setXCF{1} = customSetXCF2;
% or just rewrite individual properties
job.resizedList{3}.setXCF{1}.xcfImg = 'img';
job.resizedList{4}.setXCF{1}.xcfImg = 'img';
job.resizedList{5}.setXCF{1}.xcfImg = 'img';
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


%% Contiguity calculation script
% only do this for relevant samples
% %{
try %in case this fails, still save the data!
    contiguityTest
    t1 = toc;   
    disp(['Finished contiguity calculation for ' dataName ' in ' num2str(t1,'%.1f') ' seconds']);
catch ME 
    ME2 = ME;
    warning(ME.message);
    t1  = toc;
    disp(['Failed contiguity calculation for ' dataName ' in ' num2str(t1,'%.1f') ' seconds']);
end
%}

%% grain boundary voids calculation script
% only do this for relevant samples
%{
try %in case this fails, still save the data!
    gbVoidsTest
catch ME 
    ME3 = ME;
    warning(ME.message);
end
%}

%% EBSD map absolute orientations comparison script
% only do this for relevant samples
%{
try %in case this fails, still save the data!
    oriCompareTest
catch ME 
    ME3 = ME;
    warning(ME.message);
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