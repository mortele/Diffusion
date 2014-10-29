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
    int    Nx = 1e3;
    int    Nt = 1e3;
    double D  = 1;
    double T  = 0.3;
    double dx = D / Nx;
    double dt = T / Nt;
    double a  = dt / (dx*dx);


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
    PDESolver solver            (new Implicit);
    solver.setInitialConditions (initialConditions);
    solver.setBoundaryConditions(boundaryConditions);
    solver.setUpSolver          (Nx, Nt, a, dx, dt, D, T);

    // Integrate the system.
    solver.solve(&uFile, &parameterFile);

    // Compute the closed form solution.
    closedForm(linspace(0,D,Nx), linspace(0,T,Nt+1), Nx, Nt+1, 200);

    // Program run successfully.
    return 0;
}

