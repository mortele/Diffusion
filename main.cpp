#include <iostream>
#include <iomanip>
#include <fstream>
#include <armadillo>
#include <cmath>
#include <cstdlib>

#include <PDESolver.h>
#include <ClosedForm.h>
#include <Algorithms/Algorithm.h>
#include <Algorithms/Explicit.h>
#include <Algorithms/Implicit.h>
#include <Algorithms/CrankNicolson.h>

using std::cout;
using std::endl;
using std::ofstream;
using arma::vec;
using arma::zeros;
using arma::linspace;


int main() {
    // Numerics.
    double D  = 1;
    double T  = 1;
    double dx = 0.02;
    double dt = dx * dx / 2;
    double a  = dt / (dx*dx);
    int    Nx = floor(D / dx);
    int    Nt = floor(T / dt);

    // Set up printing to file.
    ofstream uFile;
    ofstream parameterFile;
    uFile.open        ("PDE_data.dat",       std::ios::out);
    parameterFile.open("parameter_data.dat", std::ios::out);

    // Set up initial conditions and boundary conditions.
    vec boundaryConditions  = zeros(2);
    vec initialConditions   = 1 - linspace(0, D, Nx);
    initialConditions(0)    = boundaryConditions(0);
    initialConditions(Nx-1) = boundaryConditions(1);

    // Create a solver, pass parameters to it, and solve the PDE.
    PDESolver solver            (new Explicit);
    solver.setInitialConditions (initialConditions);
    solver.setBoundaryConditions(boundaryConditions);
    solver.setUpSolver          (Nx, Nt, a, dx, dt, D, T);

    // Integrate the system.
    solver.solve(&uFile, &parameterFile);

    // Compute the closed form solution.
    closedForm(linspace(0,D,Nx), linspace(0,T,Nt), Nx, Nt, 1000);

    // Program run successfully.
    return 0;
}

