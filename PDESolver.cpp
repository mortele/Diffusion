#include <armadillo>
#include <PDESolver.h>
#include <Algorithms/Algorithm.h>

using std::ofstream;
using arma::vec;
using arma::zeros;


PDESolver::PDESolver(Algorithm* algorithm) {
    this->setAlgorithm(algorithm);
}


void PDESolver::setAlgorithm(Algorithm* algorithm ) {
    m_algorithm = algorithm;
}


void PDESolver::setBoundaryConditions(vec boundaryConditions) {
    m_algorithm->setBoundaryConditions(boundaryConditions);
}


vec PDESolver::solve(ofstream* outFile) {
    m_outFile = outFile;

    vec u = zeros(m_Nx);

    for (int i = 0; i < m_Nt; i++) {
        u = m_algorithm->advanceOneTimeStep(u);

        this->writeToFile(u);
    }

    return u;
}


void PDESolver::setUpSolver(int Nx, int Nt, double a) {
    m_Nx = Nx;
    m_Nt = Nt;
    m_a = a;
}


void PDESolver::writeToFile(vec u) {
    for (int i = 0; i < m_Nx; i++) {
        m_outFile << u(i) << " ";
    }
    m_outFile << "\n";
}
