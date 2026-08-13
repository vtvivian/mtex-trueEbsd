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
% Uses mtexdata('twins') rather than mtexdata('trueEbsdWCCo') to stay fast -
% this runs in seconds where the WC-Co workflow takes about ten minutes.
% examples/example_WCCo.m is the end to end check on the real dataset.
%
% The body runs once per plotting convention, because a permutation applied
% consistently to everything is invisible to a size or count check. See
% tests_screenOrientation for the orientation of the helpers themselves.

addpath(genpath(fileparts(mfilename('fullpath'))));

fprintf('=== TrueEBSD / MTEX 7 acceptance test ===\n');
fprintf('MTEX %s on MATLAB %s\n', getMTEXpref('version'), version('-release'));

conventions = { plottingConvention.ij, ...                      % case 1
                plottingConvention(-vector3d.Z,vector3d.Y) };   % case 4

checkHow2plotDefault(conventions{2});

for c = 1:numel(conventions)
    fprintf('\n--- plotting convention %s ---\n', char(conventions{c}));
    runWorkflow(conventions{c});
end

fprintf('\n=== ALL ACCEPTANCE CHECKS PASSED ===\n');
end

% =========================================================================
function checkHow2plotDefault(how2plot)
% A @distortedImg carrying an @EBSD map must adopt that map's convention
% unless told otherwise. It used to default to plottingConvention.ij
% regardless, so a caller who omitted 'how2plot' got an image extracted
% under one convention and a map later re-stamped with another.

ebsd = gridify(mtexdata('twins'));
ebsd.how2plot = how2plot;

disImg = distortedImg('bc','shift',ebsd);
assert(isapprox(disImg.how2plot,ebsd.how2plot), ...
    'distortedImg ignored the EBSD map''s plotting convention');

% an explicit option still wins
disImg = distortedImg('bc','shift',ebsd,'how2plot',plottingConvention.ij);
assert(isapprox(disImg.how2plot,plottingConvention.ij), ...
    'explicit how2plot was overridden');

fprintf('how2plot default OK: adopted %s from the map\n', char(how2plot));

end

% =========================================================================
function runWorkflow(how2plot)

%% build a two-map job: an EBSD map and a deliberately shifted copy
ebsd = gridify(mtexdata('twins'));
assert(isa(ebsd,'EBSDsquare'), 'test needs a square grid dataset');
ebsd.how2plot = how2plot;

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
% NB the shapes are compared in ij order inside assertAligned, not here. A
% @distortedImg holds img in image order and ebsd in EBSD grid order, and
% for the four transposing conventions those two differ by a transpose -
% legitimately, since every boundary between them goes through
% ebsdSquare2ij / ij2EbsdSquare.
fprintf('pixelSizeMatch OK: %s, how2plot %s\n', ...
    mat2str(size(job.resizedList(1).ebsd)), char(job.resizedList(1).ebsd.how2plot));
assertAligned(job.resizedList(1), 'after pixelSizeMatch');

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
assert(abs(gotX-shiftRC(2)) < 0.15, 'x shift not recovered');
assert(abs(gotY-shiftRC(1)) < 0.15, 'y shift not recovered');

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

assertAligned(job.undistortedList(1), 'after undistort');

end

% =========================================================================
function assertAligned(disImg,when)
% The @EBSD payload and the image ride through the workflow on separate
% paths - the image is interpolated directly, the map is rebuilt from
% resampled ids - so the image is an independent witness to whether the
% map came back the right way round. A wrong permutation leaves the two
% rotated or flipped relative to each other and the correlation collapses;
% a size or count check cannot see that.

a = double(ebsdSquare2ij(disImg.ebsd,'bc'));
b = double(disImg.img);
assert(isequal(size(a),size(b)), ...
    'ebsd and image differ in size %s', when);

ix = ~isnan(a) & ~isnan(b) & a > 0;
assert(nnz(ix) > 100, 'too few overlapping pixels to correlate %s', when);

r = corrcoef(a(ix),b(ix));
fprintf('alignment %s: corr(ebsd.bc, img) = %.4f\n', when, r(1,2));
assert(r(1,2) > 0.99, ...
    'EBSD map is not aligned with its own image %s (corr %.3f)', when, r(1,2));

end
