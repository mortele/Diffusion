%% Clean up
close all;
clear all;
clc;
format;


%% Load in data
u          = load('../Diffusion--Release/PDE_data.dat');
parameters = load('../Diffusion--Release/parameter_data.dat');
closedForm = load('../Diffusion--Release/closedForm_data.dat');
closedForm = closedForm(:,1:end-1);


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
p = plot(x, u_ss  -  u(1,:), 'r-');
c = plot(x, closedForm(1,:), 'b-');

% Plot aesthetics.
t = text(0.825, 0.8, ' t = 0.0 ', 'FontSize', 14, 'Units', 'Normalized',...
         'EdgeColor', [0 0 0]);
h = legend('numerical approximation', 'closed form');
set(h, 'FontSize', 14);
xlabel('Position, x',    'FontSize', 14);
ylabel('Density,  u(x)', 'FontSize', 14);

% Animate the solution, u.
for i=2:20:size(u,1)
    set(t, 'String', sprintf(' t = %6.3f ', dt*i));
    set(p, 'YData', u_ss - u(i,:));
    set(c, 'YData', u_ss - closedForm(i,:));
    pause(1e-3);
end