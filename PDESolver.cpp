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


void PDESolver::setInitialConditions(arma::vec initialConditions) {
    m_algorithm->setInitialConditions(initialConditions);
    m_initialConditions = initialConditions;
    m_u                 = initialConditions;
}


void PDESolver::setBoundaryConditions(vec boundaryConditions) {
    m_algorithm->setBoundaryConditions(boundaryConditions);
    m_boundaryConditions = boundaryConditions;
}


vec PDESolver::solve(ofstream* outFile) {
    m_outFile = outFile;
    this->writeToFile(m_initialConditions);

    for (int i = 0; i < m_Nt; i++) {
        m_u = m_algorithm->advanceOneTimeStep(m_u);
        this->writeToFile(m_u);

        // Print the progress to terminal.
        if (i % 100 == 0) {
            printf("Progress: %10.2f %%\r", 100 * i / ((double) m_Nt));
            fflush(stdout);
        }
    }

    return m_u;
}


void PDESolver::setUpSolver(int Nx, int Nt, double a) {
    m_algorithm->setUpAlgorithm(Nx, a);
    m_Nx = Nx;
    m_Nt = Nt;
    m_a = a;
}


void PDESolver::writeToFile(vec u) {
    for (int i = 0; i < m_Nx-1; i++) {
        (*m_outFile) << u(i) << " ";
    }
    (*m_outFile) << "\n";
}



