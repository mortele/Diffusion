%% Clean up
close all;
clear all;
clc;
format;


%% Load in data
u    = load    ('../Diffusion-Debug/PDE_data.dat');
x    = linspace(0, 1, size(u,2));
u_ss = 1-x;


%% Animate the solution
figure(1);
hold on;
p = plot(x,u_ss-u(1,:), 'r-');

for i=2:size(u,1)
    set(p, 'YData', u_ss-u(i,:));
    pause(0.001);
end