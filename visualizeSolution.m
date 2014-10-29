%% Clean up
close all;
clear all;
clc;
format;


%% Load in data
u          = load('../Diffusion--Release/PDE_data.dat');
parameters = load('../Diffusion--Release/parameter_data.dat');
closedForm = load('../Diffusion--Release/closedForm_data.dat');


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
x    = linspace(0, D, Nx);
u_ss = 1-x;

%closedForm(1,:) = - 1 + linspace(0,D,Nx);
error      = abs(closedForm - u);


%% Animate the solution
figure(2);
plot(linspace(0,T,Nt+1),max(error,[],2));

% Set up figure.
figure(1);
hold on;
p = plot(x, u_ss  -  u(1,:), 'r-');
c = plot(x, closedForm(1,:), 'b-');

% Plot aesthetics.
t = text(0.695, 0.8, ' t = 0.0 ',     'FontSize', 14, 'Units', 'Normalized',...
         'EdgeColor', [0 0 0]);
e = text(0.695, 0.7, ' max_e = 0.0 ', 'FontSize', 14, 'Units', 'Normalized',...
         'EdgeColor', [0 0 0]);
h = legend('numerical approximation', 'closed form');
set(h, 'FontSize', 14);
xlabel('Position, x',    'FontSize', 14);
ylabel('Density,  u(x)', 'FontSize', 14);
axis([-0.05 1.05 -0.05 1.05]);

% Animate the solution, u.
for i=2:1:size(u,1)-1
    set(t, 'String', sprintf('         t = %6.3f ', dt*i));
    set(e, 'String', sprintf(' |max_e| = %6.3e ', max(error(i,:))));
    set(p, 'YData', u_ss - u(i,:));
    set(c, 'YData', u_ss - closedForm(i,:));
    pause(2);
end






