clear all;
clc;
ele = input('Input elevation(in degrees): ');
dis = input('Distance of measured points in kilometeters: ');
angle = ele;
cperdegree = dis / angle;
c = 360 * cperdegree;
r = c /(2* pi);
fprintf('The circumference of Earth: %.2f km, The radius: %.2f km',c,r);