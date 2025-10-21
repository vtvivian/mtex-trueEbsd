% this script was used to debug calcShifts.m and is not part of the rest of
% the TrueEBSD code

n=4;m=4;
close all
figure; scatter(job.shifts{n}{m}.ROI.position_X_pass_1(:),job.shifts{n}{m}.ROI.position_Y_pass_1(:),200,...
    job.shifts{n}{m}.yshiftsROI(:)/job.resizedList{1}.dx,'filled',"square"); 
axis image ij; colorbar;  cx=clim;
figure; scatter(job.shifts{n}{m}.ROI.position_X_pass_1(:),job.shifts{n}{m}.ROI.position_Y_pass_1(:),200,...
    job.shifts{n}{m}.ROI.Shift_Y_1(:),'filled',"square"); 
axis image ij; colorbar; clim(cx);
figure; scatter(job.shifts{n}{1}.fitError.ROI.position_X_pass_1(:),job.shifts{n}{1}.fitError.ROI.position_Y_pass_1(:),200,...
    job.shifts{n}{1}.fitError.ROI.Shift_Y_1(:),'filled',"square"); 
axis image ij; colorbar;

figure; scatter(job.shifts{n}{m}.ROI.position_X_pass_1(:),job.shifts{n}{m}.ROI.position_Y_pass_1(:),200,...
    job.shifts{n}{m}.xshiftsROI(:)/job.resizedList{1}.dx,'filled',"square"); 
axis image ij; colorbar;  cx=clim;
figure; scatter(job.shifts{n}{m}.ROI.position_X_pass_1(:),job.shifts{n}{m}.ROI.position_Y_pass_1(:),200,...
    job.shifts{n}{m}.ROI.Shift_X_1(:),'filled',"square"); 
axis image ij; colorbar; clim(cx);
figure; scatter(job.shifts{n}{1}.fitError.ROI.position_X_pass_1(:),job.shifts{n}{1}.fitError.ROI.position_Y_pass_1(:),200,...
    job.shifts{n}{1}.fitError.ROI.Shift_X_1(:),'filled',"square"); 
axis image ij; colorbar;

figure; imagesc(job.shifts{n}{m}.y/job.resizedList{1}.dx); 
axis image ij; colorbar;
figure; imagesc(job.shifts{n}{m}.x/job.resizedList{1}.dx); 
axis image ij; colorbar;

figure; imagesc(job.resizedList{n}.img); axis image ij; colorbar;
figure; imagesc(job.resizedList{n+1}.img); axis image ij; colorbar;
figure; imagesc(job.resizedList{n}.edge); axis image ij; colorbar;
figure; imagesc(job.resizedList{n+1}.edge); axis image ij; colorbar;

figure; imagesc(job.undistortedList{n}.img); axis image ij; colorbar;
figure; imagesc(job.undistortedList{n+1}.img); axis image ij; colorbar;
figure; imagesc(job.undistortedList{n}.edge); axis image ij; colorbar;
figure; imagesc(job.undistortedList{n+1}.edge); axis image ij; colorbar;