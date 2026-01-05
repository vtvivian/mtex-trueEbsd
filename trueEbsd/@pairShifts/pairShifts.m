classdef pairShifts
    % @pairShifts class constructor
    % class to store local XY shifts between test and ref images
    % also stores cross-correlation function (XCF) parameters and
    % region of interest (ROI) positions used to calculate shifts


    properties % related to shifts
        % xy units should be in um lengths, not pixels
        xShiftsMap = [] % renamed from shifts.x; 2D array, 1 value per pixel, x shifts
        yShiftsMap = [] % renamed from shifts.y; 2D array, 1 value per pixel, y shifts
    end

    properties % TODO - implement (Dependent=true) % related to shifts
        % xy units should be in um lengths, not pixels
        xShiftsFit = [] % renamed from shifts.xshiftsROI; column vector, 1 value per ROI, x shifts after surface fit
        yShiftsFit = [] % renamed from shifts.yshiftsROI;  column vector, 1 value per ROI, y shifts after surface fit

        xShiftsXcf = [] % renamed from ROI.Shift_X_1
        yShiftsXcf = [] % renamed from ROI.Shift_Y_1
    end

    properties % related to ROI
        % these are in pixel units
        % ROI = struct("size_pass_1",[],"position_X_pass_1",[],"position_Y_pass_1",[],...
        %     "num_x_pass_1",[],"num_y_pass_1",[],"coordinator_pass_1",{},...
        %     "num_pass_1",[],"Shift_X_1",[],"Shift_Y_1",[]); %TODO - make this into a separate class (private class?)
        roiPosX % renamed from ROI.position_X_pass_1
        roiPosY % renamed from ROI.position_Y_pass_1
        roiSize % renamed from ROI.size_pass_1
    end

    properties (Dependent = true)% related to ROI
        % roiNumX % renamed from ROI.num_x_pass_1
        % roiNumY % renamed from ROI.num_y_pass_1
        % roiNum % renamed from ROI.num_pass_1
    end
    
    % properties (Hidden = true)% helper variables
    %     roiCoord % renamed from ROI.coordinator_pass_1
    % end



    %%%%%%% draft ROI properties
    % properties %related to XCF ROI
    %     %TODO - remove from ROI and rename these to xcfX
    %     ROI.Shift_X_1 = [] % column vector, 1 value per ROI, x shifts as measured
    %     ROI.Shift_Y_1 = [] % column vector, 1 value per ROI, y shifts as measured
    % end
    %
    % properties %related to XCF ROI
    %     % MOVE FROM pixelSizeMatch: roiSizePix=2^(ceil(log2(numel(vc{1})/4)));
    %     ROI.size_pass_1 = [] % ROI size in pixels %TODO - rename to roiSizePix
    %
    %     % MOVE FROM fDIC_ROI_position [ROI.position_X_pass_1, ROI.position_Y_pass_1,...
    %     % ROI.num_x_pass_1,ROI.num_y_pass_1, ROI.coordinator_pass_1, ROI.num_pass_1] =
    %     % fDIC_ROI_position(ROI.size_pass_1,setXCF.NumROI,boundary);
    %     ROI.num_x_pass_1: 24
    %     ROI.num_y_pass_1: 13
    %     %TODO - rearrange to avoid cell array and rename to testPosX,
    %     %testPosY
    %     ROI.coordinator_pass_1: {13×24 cell} % 2D array of ROI positions in test image
    %     %TODO - rename to refPosX, refPosY
    %     ROI.position_X_pass_1: [299×1 double] % ROI X positions ref image (excl.
    %     ROI.position_Y_pass_1: [299×1 double]
    % end
    %
    % properties (Dependent=true)
    %     % TODO - write get function
    %     ROI.num_pass_1 %ROI.num_x_pass_1*ROI.num_y_pass_1
    % end


    methods
        function shifts = pairShifts(x,y,xshiftsROI,yshiftsROI,...
                xShiftsXcf, yShiftsXcf, roiPosX, roiPosY, roiSize, varargin)
            % Construct an instance of this class
            % inputs / outputs described in script header
            %TODO - check input types
            if nargin == 0, return; end

            % copy constructor
            if isa(x,'pairShifts')
                props=properties(x);
                for i = 1:numel(props)
                    shifts.(props{i}) = x.(props{i});
                end
                return
            end

            shifts.xShiftsMap = x;
            shifts.yShiftsMap = y;
            shifts.xShiftsFit = xshiftsROI;
            shifts.yShiftsFit = yshiftsROI;
            shifts.xShiftsXcf = xShiftsXcf;
            shifts.yShiftsXcf = yShiftsXcf;

            shifts.roiSize = roiSize;           
            shifts.roiPosX = roiPosX;
            shifts.roiPosY = roiPosY;

        end

        % 
        % function out = get.roiNumX(shifts)   
        %     % modified from fDIC_ROI_position()
        %     out = numel(unique(shifts.roiPosX));
        % end
        % 
        % function out = get.roiNumY(shifts)   
        %     % modified from fDIC_ROI_position()
        %     out = numel(unique(shifts.roiPosY));
        % end

        % function out = get.roiCoord(shifts)        
        %     % copied from fDIC_ROI_position()
        %     [ROI_position_X, ROI_position_Y] = meshgrid(shifts.ROI_posi_x, shifts.ROI_posi_y);
        %     out = cell(size(ROI_position_X,1),size(ROI_position_Y,2));
        %     for i=1:size(ROI_position_X,1)
        %         for j=1:size(ROI_position_Y,2)
        %             out{i,j} =[ROI_position_X(i,j) ROI_position_Y(i,j)];
        %         end
        %     end
        % end
        % 
        % function out = get.roiNum(shifts)   
        %     % modified from fDIC_ROI_position()
        %     out = numel(shifts.roiPosX);
        % end

    end
end