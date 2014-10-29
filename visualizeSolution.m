%% Clean up
% close all;
% clear all;
% clc;
% format;


%% Load in data
u          = load('../Diffusion-Debug/PDE_data.dat');
parameters = load('../Diffusion-Debug/parameter_data.dat');


%% Organize data
% Extract parameter data from 'parameter_data.dat'.
Nx = parameters(1);
Nt = parameters(2);
a  = parameters(3);
dx = parameters(4);
dt = parameters(5);
D  = parameters(6);
T  = parameters(7);

% Create a lattice of positions and the steady state solution.
x    = linspace(0, D, Nx-1);
u_ss = 1-x;


%% Animate the solution
% Set up figure.
figure(1);
hold on;
p = plot(x,u_ss-u(1,:), 'r-');

% Plot aesthetics.
h = legend('t = 0.000');
set(h, 'FontSize', 14);
xlabel('Position, x',    'FontSize', 14);
ylabel('Density,  u(x)', 'FontSize', 14);

% Animate the solution, u.
for i=2:20:size(u,1)
    set(h, 'String', sprintf('t = %6.3f', dt*i));
    set(p, 'YData', u_ss-u(i,:));
    pause(1e-15);
end