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

int main() {
    // Numerics.
    double d  = 1;
    double t  = 5;
    double dx = 0.1;
    double dt = 0.01;
    double a  = dt / dx;
    int    Nx = floor(d/dx);
    int    Nt = floor(t/dt);

    // Set up printing to file.
    ofstream outFile;
    outFile.open("PDE_data.dat", std::ios::out);

    // Create a solver, pass parameters to it, and solve the PDE.
    PDESolver solver(new Explicit);
    solver.setBoundaryConditions(zeros(2));

    // Close output stream, ensure buffers are written.
    outFile.close();

    // Program run successfully.
    return 0;
}

