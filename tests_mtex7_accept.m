function tests_mtex7_accept
% Acceptance test for running TrueEBSD against MTEX 7.
%
% Syntax
%   tests_mtex7_accept
%
% Runs the whole workflow (pixelSizeMatch -> calcShifts -> undistort) on a
% stock MTEX dataset with an @EBSD payload attached, and checks the result
% is correct rather than merely non-crashing: a known shift is imposed on
% the reference image and must be recovered, and the @EBSD object must
% survive both rebuilds with its positions, phases, orientations, crystal
% symmetries and properties intact.
%
% Requires MTEX on the path (run startup_mtex first). Uses mtexdata('twins'),
% which is downloaded on first use.
%
% Deliberately does not use mtexdata('trueEbsdWCCo'): that .mat predates
% MTEX's move from EBSDsquare.dx/.dy to pos-derived d1/d2, so MATLAB drops
% its positions on load and ebsd.pos comes back empty. That is an MTEX
% loadobj limitation, not a TrueEBSD one, and it blocks examples/example_WCCo.m
% until MTEX rebuilds pos from the unit cell and grid size on load.

addpath(genpath(fileparts(mfilename('fullpath'))));

fprintf('=== TrueEBSD / MTEX 7 acceptance test ===\n');
fprintf('MTEX %s on MATLAB %s\n', getMTEXpref('version'), version('-release'));

%% build a two-map job: an EBSD map and a deliberately shifted copy
ebsd = gridify(mtexdata('twins'));
assert(isa(ebsd,'EBSDsquare'), 'test needs a square grid dataset');

bc      = ebsdSquare2ij(ebsd,'bc',ebsd.how2plot);
shiftRC = [4 3];                    % [rows(=y) cols(=x)] pixels
ref     = circshift(rescale(bc), shiftRC);
px      = double(ebsd.d2.norm);

imgList = createArray(2,1,'distortedImg');
imgList(1) = distortedImg('bc','shift', ebsd, 'how2plot', ebsd.how2plot, ...
    'highContrast',1,'edgePadWidth',3);
imgList(2) = distortedImg(ref,'true','dxy',px,'highContrast',1,'edgePadWidth',3);
job = trueEbsd(imgList);

%% pixelSizeMatch -- rebuilds the @EBSD object on the common grid
job = pixelSizeMatch(job);
assert(isa(job.resizedList(1).ebsd,'EBSDsquare'), 'resized ebsd is not EBSDsquare');
assert(~isempty(job.resizedList(1).ebsd.pos), 'resized ebsd lost its positions');
assert(isequal(size(job.resizedList(1).ebsd), size(job.resizedList(1).img)), ...
    'resized ebsd and image have different sizes');
fprintf('pixelSizeMatch OK: %s, how2plot %s\n', ...
    mat2str(size(job.resizedList(1).ebsd)), char(job.resizedList(1).ebsd.how2plot));

%% calcShifts -- the imposed shift must come back out
for n = 1:numel(job.resizedList)
    job.resizedList(n).setXCF(1).ROISize  = 48;
    job.resizedList(n).setXCF(1).NumROI.x = 4;
    job.resizedList(n).setXCF(1).NumROI.y = 4;
end
job = calcShifts(job,'fitErr');

gotX = mean(job.shifts{1}(end).xShiftsMap(:)) / px;
gotY = mean(job.shifts{1}(end).yShiftsMap(:)) / px;
fprintf('calcShifts OK: imposed [x=%d y=%d] px, recovered [x=%.2f y=%.2f] px\n', ...
    shiftRC(2), shiftRC(1), gotX, gotY);
assert(abs(abs(gotX)-shiftRC(2)) < 0.15, 'x shift not recovered');
assert(abs(abs(gotY)-shiftRC(1)) < 0.15, 'y shift not recovered');

%% undistort -- rebuilds the @EBSD object again
job = undistort(job);
e2  = job.undistortedList(1).ebsd;
assert(isa(e2,'EBSDsquare'), 'undistorted ebsd is not EBSDsquare');
assert(~isempty(e2.pos), 'undistorted ebsd lost its positions');
assert(isequal(size(e2), size(job.resizedList(1).ebsd)), 'undistorted ebsd changed size');

nBefore = nnz(job.resizedList(1).ebsd.phase > 0);
nAfter  = nnz(e2.phase > 0);
fprintf('undistort OK: indexed %d -> %d (%.1f%% kept), phases %s\n', ...
    nBefore, nAfter, 100*nAfter/nBefore, mat2str(unique(e2.phase(:))'));
assert(nAfter > 0.5*nBefore, 'undistort lost most indexed points');
assert(~all(isnan(e2.rotations(e2.phase>0))), 'all orientations are NaN');

% NB: in MTEX 7 CSList is a symmetry array, not a cell array
csl = e2.CSList;
assert(numel(csl) == numel(job.resizedList(1).ebsd.CSList), 'CSList changed length');
mins = {};
for k = 1:numel(csl)
    if isa(csl(k),'crystalSymmetry'), mins{end+1} = csl(k).mineral; end %#ok<AGROW>
end
assert(~isempty(mins), 'all crystal symmetries lost');
fprintf('minerals preserved: %s\n', strjoin(mins,', '));

assert(isfield(e2.prop,'bc'), 'bc property lost');
fprintf('props preserved: %s\n', strjoin(fieldnames(e2.prop)',', '));

fprintf('=== ALL ACCEPTANCE CHECKS PASSED ===\n');
end
