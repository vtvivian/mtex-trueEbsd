function [ebsdImg] = ij2EbsdSquare(ebsd,ebsdImg,varargin)
% index an image ij ordered matrix in the same order as a gridified ebsd map
%
% Syntax
%
%   plot(ebsd, ij2EbsdSquare(ebsd,img))
%   map = ij2EbsdSquare(ebsd,img,pC)   % override ebsd.how2plot
%
% Input
%  ebsd    - @EBSDsquare, gridified
%  ebsdImg - a matrix in image ij order
%  pC      - @plottingConvention, defaults to ebsd.how2plot
%
% Output
%  ebsdImg - the same values in EBSD grid order
%
% Description
% The exact inverse of ebsdSquare2ij. It is that function run backwards
% rather than a second table, so the two cannot drift apart.
%
% See also
% ebsdSquare2ij

ebsdImg = ebsdSquare2ij(ebsd,ebsdImg,varargin{:},'inverse');

end
