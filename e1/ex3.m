clear all;
clc;
img=imread('p');
imgrr=img;
imgrb=img;
imgrr(:,:,1)=255-imgrr(:,:,1);
imgrb(:,:,3)=255-imgrb(:,:,3);
image(img);
figure
ax(1) = subplot(1,3,1);
image(img);
title('Original')
ax(2)=subplot(1,3,2);
image(imgrr);
title('Red Reversed')
ax(3)=subplot(1,3,3);
image(imgrb);
title('Blue Reversed')
linkaxes(ax,'xy')
axis(ax,'image')