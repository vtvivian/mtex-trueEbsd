function [disImgs,nameOut,pathOut,varargout] = loadTrueEbsdData(nameIn,varargin)
% load TrueEBSD datasets 
% This function runs the script loadContigData_<dataName>.m, which is a
% script the operator needs to write themselves to set up the input data.
% This can include importing images and EBSD maps using MATLAB and MTEX
% functions. 
% loadContigData_<dataName>.m is a script created by the user and saved in
% the current folder.
% Create one script for each dataset and make sure the file name matches
% the variable dataName in main.m.
%
% loadContigData_<dataName>.m should import image data + metadata (can be from text, 
% HDF5 or image files) and construct a disImgs{n} = @distortedImg object from each one. 
% The images need to contain the same physical features but may have different contrast modes.
%
% Inputs
% nameIn – input dataset name as @char array 
%
% Outputs
% disImgs – @distortedImg cell array of imported image data 


nameIn = argin_check(nameIn,{'char', 'string'});
nameIn = convertContainedStringsToChars(nameIn);

if isempty(nameIn) || numel(varargin)>0 && strcmpi(varargin{1},'wizard')
    % run import wizard instead of loading existing data
    [disImgs,nameOut,pathOut,setSave,phaseSegMethod,h5oinaLoc,flatBseImgLoc,thermocalcCsvLoc] = dataLoaderWizard_contiguity;
else
    nameOut = removeweirdchars(nameIn);
    ld = str2func(append("loadContigData_", nameOut));
    ld()
    pathOut = dataPath;
    % these variables may not exist in older versions of loadContigData_*
    % do this for backcompatibility
    if exist("setSave","var"), setSave = 1; end
    if exist("phaseSegMethod","var"), phaseSegMethod = ""; end
    if exist("h5oinaLoc","var"), h5oinaLoc = ["" ""]; end
    if exist("flatBseImgLoc","var"), flatBseImgLoc = ""; end
    if exist("thermocalcCsvLoc","var"), thermocalcCsvLoc = ""; end
end
varargout = {setSave,phaseSegMethod,h5oinaLoc,flatBseImgLoc,thermocalcCsvLoc};
