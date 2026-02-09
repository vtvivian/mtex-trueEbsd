function pixSzIn = uiSelectPixSize(job)
% UI dialog box for selecting common TrueEbsd pixel length for
% pixelSizeMatch.m
% assumes everything is in um length units
% Input = @trueEbsd job
% Output = pixel length in um (@double)

% 1. Find candidate pixel sizes
szAll = [job.imgList(:).dx];
sz0 = min(szAll);
sz1 = max(szAll);
ebsdTemp = [job.imgList(:).ebsd];
szE = ebsdTemp(1).dPos; %TODO -- handle case of more than 1 EBSD pixel size?

% 2. Create selection text list...
pixSzOptsList = [append("Smallest (default): ", num2str(sz0), " um");
    append("Largest: ", num2str(sz1), " um");
    append("EBSD step size: ", num2str(szE), " um");
    "Image #" + num2str((1:numel(szAll)).') + ": " + num2str(szAll(:)) + " um";
    "User-defined (enter number in next dialog box)."];
% ... and corresponding numbers list
pixSzNumsList = [sz0 sz1 szE szAll nan];

[indx,tf] = listdlg('ListString',pixSzOptsList,...
    'PromptString','Select TrueEBSD pixel length:',...
    'ListSize',[400 200],...
    'SelectionMode','single');

% 3. Read selection and convert output to number
if ~tf || isnan(pixSzNumsList(indx)) % if user clicks 'Cancel' or 'user defined'
    pixSzIn = str2double(inputdlg('Enter TrueEBSD pixel length in um: ','TrueEBSD pixel length', 1, "0"));
else
    pixSzIn = pixSzNumsList(indx); % target pixel length in microns, or 0 to default to smallest common pixel size
end
end