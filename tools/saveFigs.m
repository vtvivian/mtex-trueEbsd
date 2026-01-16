function [] = saveFigs(figHandle,imName,pName,varargin)
% function wrapper to save figures from matlab
% V1 - Vivian Tong NPL March 2020
% 2020-08-11
% enable optional inputs (varargin) into export_fig
% 2020-08-25
% set white figure background
% export_fig can't handle strings properly, convert saveLoc to char array

if ~isfolder(pName)
   mkdir(pName);
end

saveLoc = char(fullfile(pName,imName));

try figHandle.Color = 'w'; end %sometimes doesn't work with mtex figures, not dealbreaker

% export_fig(append(char(saveLoc), '.png'),'-dpng','-r300','-a1',varargin{:},figHandle);
% savefig(figHandle,saveLoc);

%save into single pdf
if isfile(saveLoc)
    export_fig(saveLoc, '-pdf','-r300','-a1','-append','-transparent', figHandle);
else
    export_fig(saveLoc, '-pdf','-r300','-a1','-transparent', figHandle);
end


