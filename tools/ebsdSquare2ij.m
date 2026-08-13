function [ebsdImg] = ebsdSquare2ij(ebsd,ebsdMap,varargin)
% index a gridified ebsd map in the same order as image ij coordinates
%
% Syntax
%
%   img = ebsdSquare2ij(ebsd,'bc')        % by property name
%   img = ebsdSquare2ij(ebsd,someMap)     % a matrix laid out like the map
%   img = ebsdSquare2ij(ebsd,someMap,pC)  % override ebsd.how2plot
%
% Input
%  ebsd    - @EBSDsquare, gridified
%  ebsdMap - property name, or a matrix shaped like the EBSD grid
%  pC      - @plottingConvention, defaults to ebsd.how2plot
%
% Output
%  ebsdImg - the same values in image ij order
%
% Description
% ij order means dimension 1 runs south on screen and dimension 2 runs
% east, which is how MATLAB displays an image under axis ij. An @EBSDsquare
% is stored along its own grid directions instead - d1 steps along
% dimension 1 and d2 along dimension 2 - so the two orders differ by a
% transpose and/or a flip. Which one is decided here from the direction
% cosines of d1 and d2 against the screen axes, so it follows the plotting
% convention and the grid layout rather than being tabulated.
%
% Only a signed permutation can be expressed by a transpose and two flips,
% so each grid direction has to lie along a screen axis. A convention or a
% grid that is not axis aligned errors rather than returning something
% plausible.
%
% See also
% ij2EbsdSquare

ebsd = argin_check(ebsd,"EBSDsquare");

if isa(ebsdMap,'char')||isa(ebsdMap,'string')
    ebsdImg = ebsd.(ebsdMap);
else
    ebsdImg = ebsdMap;
end

[doTranspose,doFlip1,doFlip2] = gridOps(ebsd,varargin{:});

if check_option(varargin,'inverse')
    % transpose, flipud and fliplr are each their own inverse, so undoing
    % the three is the same three in the opposite order. This is what keeps
    % ij2EbsdSquare exactly inverse to this function whatever the
    % convention turns out to be - there is only one table to get right.
    if doFlip2, ebsdImg = fliplr(ebsdImg); end
    if doFlip1, ebsdImg = flipud(ebsdImg); end
    if doTranspose, ebsdImg = ebsdImg.'; end
else
    if doTranspose, ebsdImg = ebsdImg.'; end
    if doFlip1, ebsdImg = flipud(ebsdImg); end
    if doFlip2, ebsdImg = fliplr(ebsdImg); end
end

end

% -------------------------------------------------------------------------
function [doTranspose,doFlip1,doFlip2] = gridOps(ebsd,varargin)
% which permutation takes the stored grid order into image ij order

pC = getClass(varargin,'plottingConvention',ebsd.how2plot);

% direction cosines of the two grid directions against the two screen
% directions the matrix dimensions have to follow
c = [dot(normalize(ebsd.d1),pC.south) dot(normalize(ebsd.d1),pC.east); ...
     dot(normalize(ebsd.d2),pC.south) dot(normalize(ebsd.d2),pC.east)];

% each grid direction must lie along one screen axis, and the two must not
% pick the same one
tol = 1e-6;
onAxis = abs(c) > 1-tol;
if nnz(onAxis) ~= 2 || ~all(any(onAxis,1)) || ~all(any(onAxis,2))
    error("Can't determine screen axes for EBSD map image");
end

doTranspose = onAxis(2,1);      % d2 runs north-south, so it has to become dim 1
if doTranspose, c = c([2 1],:); end
doFlip1 = c(1,1) < 0;           % dim 1 has to increase southwards
doFlip2 = c(2,2) < 0;           % dim 2 has to increase eastwards

end
