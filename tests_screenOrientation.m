function tests_screenOrientation
% Check that ebsdSquare2ij and ij2EbsdSquare agree with the screen
% convention they are given.
%
% Syntax
%   tests_screenOrientation
%
% ij order is defined here as: dimension 1 of the matrix runs screen south,
% dimension 2 runs screen east. That is what MATLAB shows under axis ij.
% Every check below is written against that definition rather than against
% the current implementation, so it can disagree with the code.
%
% Four checks per plotting convention:
%
%   1 orientation - the columns of the returned matrix step east and its
%     rows step south. This is the only check that can catch a wrong entry
%     in the permutation table.
%   2 round trip - the two functions invert each other. NOTE this passes
%     even when both carry the same wrong entry, so it guards the refactor
%     but is not a bug detector.
%   3 rejection - a convention whose axes are not screen axes must error.
%   4 equivalence - nwse2EbsdPos and ebsdMapOffset agree with plain
%     plottingConvention arithmetic. Skipped once those two are deleted.
%
% Runs in seconds on mtexdata('twins'). Requires MTEX on the path.

addpath(genpath(fileparts(mfilename('fullpath'))));

fprintf('=== TrueEBSD screen orientation ===\n');
fprintf('MTEX %s on MATLAB %s\n\n', getMTEXpref('version'), version('-release'));

% the eight axis-aligned conventions, as (outOfScreen, east) pairs. The
% numbering matches the case comments in tools/ebsdSquare2ij.m.
pcs = { plottingConvention(-vector3d.Z, vector3d.X), ...   % 1  e=+X n=-Y o=-Z
        plottingConvention( vector3d.Z, vector3d.Y), ...   % 2  e=+Y n=-X o=+Z
        plottingConvention( vector3d.Z, vector3d.X), ...   % 3  e=+X n=+Y o=+Z
        plottingConvention(-vector3d.Z, vector3d.Y), ...   % 4  e=+Y n=+X o=-Z
        plottingConvention(-vector3d.Z,-vector3d.X), ...   % 5  e=-X n=+Y o=-Z
        plottingConvention( vector3d.Z,-vector3d.Y), ...   % 6  e=-Y n=+X o=+Z
        plottingConvention( vector3d.Z,-vector3d.X), ...   % 7  e=-X n=-Y o=+Z
        plottingConvention(-vector3d.Z,-vector3d.Y)};      % 8  e=-Y n=-X o=-Z

raw = mtexdata('twins');
fails = {};

for layout = ["columnMajor" "rowMajor"]

    ebsd = gridify(raw,char(layout));
    assert(isa(ebsd,'EBSDsquare'),'test needs a square grid dataset');
    assert(size(ebsd,1) ~= size(ebsd,2), ...
        'test needs a non-square map, or a transpose cannot be detected');

    fprintf('%s layout, %s map\n', layout, mat2str(size(ebsd)));

    for k = 1:numel(pcs)
        ebsd.how2plot = pcs{k};
        tag = sprintf('%s case %d (%s)', layout, k, char(pcs{k}));
        fails = [fails, runChecks(ebsd,pcs{k},tag)]; %#ok<AGROW>
    end
    fprintf('\n');
end

% ---- check 3, once: a convention off the coordinate axes must be refused
ebsd = gridify(raw);
ebsd.how2plot = plottingConvention(vector3d(1,1,1),vector3d(1,-1,0));
try
    ebsdSquare2ij(ebsd,ebsd.pos.x);
    fails{end+1} = 'rejection: a non-axis-aligned convention was accepted';
catch
    fprintf('rejection OK: non-axis-aligned convention refused\n\n');
end

% ---- verdict
if isempty(fails)
    fprintf('=== ALL SCREEN ORIENTATION CHECKS PASSED ===\n');
else
    fprintf('%d FAILURE(S):\n', numel(fails));
    fprintf('  %s\n', fails{:});
    error('tests_screenOrientation:failed','%d check(s) failed', numel(fails));
end

end

% =========================================================================
function fails = runChecks(ebsd,pC,tag)

fails = {};
tol   = 1e-6;

% ---- check 1: orientation against the definition of ij order
X = ebsdSquare2ij(ebsd,ebsd.pos.x);
Y = ebsdSquare2ij(ebsd,ebsd.pos.y);

stepCol = vector3d(X(1,2)-X(1,1), Y(1,2)-Y(1,1), 0);
stepRow = vector3d(X(2,1)-X(1,1), Y(2,1)-Y(1,1), 0);

if angle(stepCol,pC.east) > tol
    fails{end+1} = sprintf('%s: columns do not run east', tag);
end
if angle(stepRow,pC.south) > tol
    fails{end+1} = sprintf('%s: rows do not run south', tag);
end

% ---- check 2: round trip, both directions
A = reshape(1:numel(ebsd),size(ebsd));
if ~isequal(ij2EbsdSquare(ebsd,ebsdSquare2ij(ebsd,A)),A)
    fails{end+1} = sprintf('%s: ij2EbsdSquare o ebsdSquare2ij is not the identity', tag);
end
B = ebsdSquare2ij(ebsd,A);
if ~isequal(ebsdSquare2ij(ebsd,ij2EbsdSquare(ebsd,B)),B)
    fails{end+1} = sprintf('%s: ebsdSquare2ij o ij2EbsdSquare is not the identity', tag);
end

% ---- check 4: the position algebra
E = rand(3,4);
S = rand(3,4);
v = E .* pC.east + S .* pC.south;

% convention-free invariants, true whatever the helpers do
if max(abs(dot(v,pC.east) - E),[],'all') > 1e-12 || ...
   max(abs(dot(v,pC.south) - S),[],'all') > 1e-12 || ...
   max(abs(dot(v,pC.outOfScreen)),[],'all') > 1e-12
    fails{end+1} = sprintf('%s: east/south decomposition is not self consistent', tag);
end

% equivalence with the helpers, while they still exist
if exist('nwse2EbsdPos','file') == 2
    [x0,y0] = nwse2EbsdPos(ebsd,E,S);
    if max(abs(x0 - v.x),[],'all') > 1e-12 || max(abs(y0 - v.y),[],'all') > 1e-12
        fails{end+1} = sprintf('%s: nwse2EbsdPos differs from pC arithmetic', tag);
    end
end

if exist('ebsdMapOffset','file') == 2
    e1 = ebsdMapOffset(ebsd,3,7);
    e2 = ebsd + (3*pC.east + 7*pC.south);
    if max(norm(e1.pos - e2.pos),[],'all') > 1e-12
        fails{end+1} = sprintf('%s: ebsdMapOffset differs from pC arithmetic', tag);
    end
end

end
