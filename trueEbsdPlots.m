%% plot TrueEBSD data
% this script will change with each dataset depending on what needs to be
% plotted, not really needed in source version control, but a copy saved
% with the MAT files and exported images

% not-EBSD data inside an MTEX mapPlot - use ij2EbsdSquare(ebsd,otherMapData)

% edge transforms
figure('WindowState', 'maximized'); tiledlayout('flow','TileSpacing','compact','Padding','compact');
for n=1:numel(job.resizedList)
    nexttile;
    imagesc(job.resizedList{n}.edge); axis ij image off; colormap gray;
    title(['Resized edge ' num2str(n)]);
end
if setSave
    saveFigs(gcf,['resizedList_edge'],savepname);
end

% images
figure('WindowState', 'maximized'); tiledlayout('flow','TileSpacing','compact','Padding','compact');
for n=1:numel(job.resizedList)
    nexttile;
    if ndims(job.resizedList{n}.img)<3
        imagesc(job.resizedList{n}.img); axis image off; colormap gray;
    else
        p1 = min(size(job.resizedList{n}.img,3),3);
        imagesc(job.resizedList{n}.img(:,:,1:p1)); axis image off; colormap gray;
    end
    title(['Resized image ' num2str(n)]);
end
if setSave
    saveFigs(gcf,['resizedList_img'],savepname);
end


% edge transforms
f0 = figure('WindowState', 'maximized'); t1=tiledlayout('flow','TileSpacing','compact','Padding','compact');
for n=1:numel(job.undistortedList)
    nexttile(t1);
    h1 = imagesc(job.undistortedList{n}.edge); axis ij image off; colormap gray;
    title(['Undistorted edge ' num2str(n)]);

    f1 = figure; copyobj(h1,gca); axis ij image off; colormap gray;
    if setSave
        saveFigs(f1,['undistortedList_edge_'  num2str(n)],savepname);
    end
end
if setSave
    saveFigs(f0,['undistortedList_edge'],savepname);
end

% images
f0 = figure('WindowState', 'maximized'); t1=tiledlayout('flow','TileSpacing','compact','Padding','compact');
for n=1:numel(job.undistortedList)
    nexttile(t1);
    if ndims(job.undistortedList{n}.img)<3 %#ok<*ISMAT>
        h1 = imagesc(job.undistortedList{n}.img); axis ij image off; colormap gray;
    else
        p1 = min(size(job.undistortedList{n}.img,3),3);
        h1 = imagesc(im2double(job.undistortedList{n}.img(:,:,1:p1))); axis image off; colormap gray;
    end
    title(['Undistorted image ' num2str(n)]);

    f1 = figure; copyobj(h1,gca); axis ij image off; colormap gray;
    if setSave
        saveFigs(f1,['undistortedList_img_'  num2str(n)],savepname);
    end
end
if setSave
    saveFigs(f0,['undistortedList_img'],savepname);
end
%% TrueEBSD images
% find out which images have associated EBSD data

ebsdIdx = ~cellfun(@isempty,{cat(1,job.undistortedList{:}).ebsd});
% replot undistorted images as MTEX figures - check map axes plot ok

if any(ebsdIdx)
    n1 = find(ebsdIdx,1,"first");
    figure;
    for n=1:numel(job.undistortedList)
        % check and remove >3 colour channels
        if ndims(job.undistortedList{n}.img)<3 %#ok<*ISMAT>
            img1 = job.undistortedList{n}.img;
        else
            p1 = min(size(job.undistortedList{n}.img,3),3);
            img1 = job.undistortedList{n}.img(:,:,1:p1);
        end

        nextAxis;
        
        plot(job.undistortedList{n1}.ebsd, ...
            ij2EbsdSquare(job.undistortedList{n1}.ebsd,img1), ...
            job.undistortedList{n1}.ebsd.how2plot);
        mtexColorMap gray;
        title(['Undistorted MTEX image ' num2str(n)]);
    end
    clear img1;
    if setSave
        saveFigs(gcf,['undistortedList_imgMtex'],savepname);
    end
    %% plot orientations and pattern quality
    %the extent of the single phase is different to the extent of the entire
    %EBSD map, which ends up messing with the image scaling, so let's plot a
    % transparent bottom layer to force the correct map FOV
    % % TODO - write a wrapper function for plots
    figure;
    for n=find(ebsdIdx)
        % deal with different names for the same thing
        if isfield(job.imgList{n}.ebsd.prop,'bc')
            plotVal = 'bc';
        elseif isfield(job.imgList{n}.ebsd.prop,'iq')
            plotVal = 'iq';
        elseif isfield(job.imgList{n}.ebsd.prop,'pq')
            plotVal = 'pq';
        end

        phaseName = job.imgList{n}.ebsd.CSList{job.imgList{n}.ebsd.indexedPhasesId(1)}.mineral;
        %IPF-NORTH
         ipfvec = vector3d(0,0,0);
        [x1,y1] = nwse2EbsdPos(job.undistortedList{n}.ebsd,0,-1);
        ipfvec.x = x1; ipfvec.y = y1; clearvars x1 y1; % direct assignment doesn't work properly for some reason



        % corrected EBSD
        ipfKey = ipfColorKey(job.undistortedList{n}.ebsd(phaseName).CS.Laue);
        ipfKey.inversePoleFigureDirection = ipfvec;
        ipfCols = ipfKey.orientation2color(job.undistortedList{n}.ebsd(phaseName).orientations);
        
        plot(job.resizedList{n}.ebsd,job.resizedList{n}.ebsd.x,job.resizedList{n}.ebsd.how2plot,'faceAlpha',0); hold on;      
        plot(job.undistortedList{n}.ebsd(phaseName),ipfCols,job.undistortedList{n}.ebsd.how2plot);
        title(['Undistorted EBSD Map ' num2str(n)]);
        if setSave
            saveFigs(gcf,['ebsd_ipfNorth' num2str(n)],savepname);
            clf(gcf);
        end

    end %end EBSD plotting for loop
    clear ipfCols
end %end EBSD plotting if statement
