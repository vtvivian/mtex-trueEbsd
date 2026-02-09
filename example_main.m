%% MTEX TrueEBSD example main script
%
% Description:  
% Example script to run trueEBSD workflow using data import UI.
%
% Inputs: 
% EBSD map and/or images for TrueEBSD analysis
% Images can be loaded as image files (e.g. PNG, BMP, TIFF) or read from a .h5oina container.
%
% Outputs: 
% <dataName>.log file with printed outputs
% <dataName>_figs.pdf file of figures
% <dataName>_out.mat data file.
%

clear; close all; home;

%% Add trueEBSD and MTEX MATLAB paths
% startup MTEX (replace this with local path to skip UI)
mtexPath = "";
if ~isfile(fullfile(mtexPath,"startup_mtex.m"))
    mtexPath = uigetdir(cd,"Select MTEX folder:");
elseif mtexPath == ""
    mtexPath = cd;
end
cd(mtexPath);
startup_mtex;
%variables get cleared after this step so recreate path
mtexPath = cd;

% startup trueEbsd (replace this with local path to skip UI)
trueEbsdPath = "";
if ~isfolder(fullfile(trueEbsdPath,"@trueEbsd"))
    trueEbsdPath = uigetdir(cd,"Select TrueEBSD folder:");
elseif trueEbsdPath == ""
    trueEbsdPath = cd;
end
addpath(genpath(trueEbsdPath));

%% Set up TrueEBSD job
% job is a |@trueEbsd| object containing a sequence of |@distortedImg|
% images.
%
% The starting data for the TrueEBSD workflow are stored in |job.imgList|.
% Select data and define user parameters using the dataLoaderWizard UI.
% Simple image denoising (a kernel avg filter) is available using the 
% wizard. Consider writing your own code for more complex operations.

[job, matFileOut] = dataLoaderWizard;

%% Import data + file saving
tic
if matFileOut == ""
    setSave = 0;
    dataName = "this dataset";
    disp(append('Outputs will not be saved. ', newline));
else
    setSave = 1;
    [savepname,dataName,~] = fileparts(matFileOut);
    diary(fullfile(savepname,append(dataName,'_trueEbsd.log')));
    diary on
    disp(append('Outputs will be saved to ', savepname, '/. ', newline));
end

%%
%%%
% Plot as-imported image sequence to check: they should be all of similar regions
% on the sample with similar orientation, but the image contrasts may look quite different.
% You can zoom in and out as tile axes are linked.
figure("WindowState","maximized");
tiledlayout('flow','TileSpacing','compact','Padding','tight');
for n=1:numel(job.imgList)
    nexttile;
    imagesc('XData',job.imgList(n).dx.*(1:size(job.imgList(n).img,2)),...
        'YData',job.imgList(n).dy*(1:size(job.imgList(n).img,1)),...
        'CData',job.imgList(n).img);
    colormap gray; axis image on ij;
    title(['Distorted Image ' num2str(n)])
end
linkaxes;
if setSave, saveFigs(gcf,append(dataName, '_figs.pdf'),savepname); close; end

t1  = toc;
disp(append('Finished set up trueEBSD job for ', dataName ,' in ', num2str(t1,'%.1f'), ' seconds'));

%% Resize images to match pixel size and FOV
% The EBSD map and images in |job.imgList| are of the same sample area but
% have different pixel sizes. Here, we match up the pixel positions of the 
% the image sequence in |job.imgList|.
%
% Inputs - distorted image sequence |job.imgList|, target pixel size pixSzIn
%
% Outputs - distorted image sequence on a common pixel grid
% |job.resizedList{:}|.

pixSzIn = uiSelectPixSize(job);
job = pixelSizeMatch(job,pixSzIn);

%%%
% Now |job| has a new property |job.resizedList|, which is where the outputs of
% pixelSizeMatch are stored.
display(job);
display(job.resizedList(1).ebsd);

t1  = toc;
disp(append('Finished resize images to match pixel size and FOV for ', dataName ,' in ', num2str(t1,'%.1f'), ' seconds'));

%% Calculate local image shifts and fit to a distortion model
% Now we compute local image ROI shifts and fit them to distortion models. 
% After each image correction step, the average ROI shifts (X, Y and length
% components) are printed to the command window. 
%
% The 'fitErr' flag means that residual local image shifts are recomputed 
% after image correction but not included in the final result. If this
% number is small (less than 2 pixels) then most likely the image 
% registration was successful. 
%
%%%
% These are the image pairs that will be used for cross-correlation. 

figure('WindowState', 'maximized'); 
t=tiledlayout('flow','TileSpacing','tight','Padding','tight');
title(t,'TrueEBSD image sequence for cross-correlation');
for n=1:numel(job.resizedList)
    nexttile; 
    imagesc('XData',job.resizedList(n).dx.*(1:size(job.resizedList(n).img,2)),...
        'YData',job.resizedList(n).dy*(1:size(job.resizedList(n).img,1)),...
        'CData',job.resizedList(n).(job.resizedList(n).setXCF(1).xcfImg));
    colormap gray; axis image on ij;
end
linkaxes;
if setSave, saveFigs(gcf,append(dataName, '_figs.pdf'),savepname); close; end

%% Compute image shifts

job = calcShifts(job,'fitErr');

%%%
% Now job has a new property job.shifts, which is where the outputs of
% calcShifts are stored.

display(job);

t1  = toc;
disp(append('Finished calculate image shifts and fit distortion models for ', dataName, ' in ', num2str(t1,'%.1f'), ' seconds'));

%% Undistort images
% This applies the image shifts between each image pair in |job.shifts| to
% the data in |job.resizedList|, and outputs a new property
% job.undistortedList which contains aligned image data. Now all pixels in
% this image sequence can be directly overlaid.

job = undistort(job);

%% Plot images after distortion correction
display(job);

figure('WindowState', 'maximized');
t=tiledlayout('flow','TileSpacing','tight','Padding','tight');
title(t,'Aligned image sequence (MATLAB images)');
for n=1:numel(job.undistortedList)
    nexttile; 
    imagesc('XData',job.undistortedList(n).dx.*(1:size(job.undistortedList(n).img,2)),...
        'YData',job.undistortedList(n).dy*(1:size(job.undistortedList(n).img,1)),...
        'CData',job.undistortedList(n).img);
    colormap gray; axis image on ij;
end
linkaxes;
if setSave, saveFigs(gcf,append(dataName, '_figs.pdf'),savepname); close; end

t1  = toc;
disp(append('Finished remove image distortions for ', dataName, ' in ', num2str(t1,'%.1f'), ' seconds'));

%%
% This is the end of the TrueEBSD distortion correction workflow. 
t1  = toc;
if setSave, save(matFileOut,"job","-append"); close; end
disp(append('Finished TrueEBSD for ', dataName, ' in ', num2str(t1,'%.1f'), ' seconds.'));
