#include <iostream>
#include <iomanip>
#include <fstream>
#include <armadillo>
#include <cmath>
#include <cstdlib>

#include <PDESolver.h>

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
    double dx = 0.01;
    double dt = 0.0001;
    double a  = dt / dx;
    int    Nx = floor(D/dx);
    int    Nt = floor(T/dt);

    // Set up printing to file.
    ofstream outFile;
    outFile.open("PDE_data.dat", std::ios::out);

    // Set up initial conditions and boundary conditions.
    vec boundaryConditions = zeros(2);
    vec initialConditions  = 1-linspace(0,1,Nx);
    initialConditions(0)   = initialConditions(Nx-1) = 0;

    // Create a solver, pass parameters to it, and solve the PDE.
    PDESolver solver            (new Explicit);
    solver.setInitialConditions (initialConditions);
    solver.setBoundaryConditions(boundaryConditions);
    solver.setUpSolver          (Nx, Nt, a);

    // Integrate the system.
    solver.solve(&outFile);

    // Close output stream, ensure buffers are written.
    outFile.close();

    // Program run successfully.
    return 0;
}

