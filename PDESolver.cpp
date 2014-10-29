#include <PDESolver.h>
#include <armadillo>
#include <iomanip>
#include <Algorithms/Algorithm.h>

using std::ofstream;
using std::setprecision;
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


vec PDESolver::solve(ofstream* uFile, ofstream* parameterFile) {
    m_uFile         = uFile;
    m_parameterFile = parameterFile;
    this->writeParametersToFile();
    this->writeToFile          (m_initialConditions);

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


void PDESolver::setUpSolver(int Nx,
                            int Nt,
                            double a,
                            double dx,
                            double dt,
                            double D,
                            double T) {

    m_algorithm->setUpAlgorithm(Nx, a);
    m_Nx = Nx;
    m_Nt = Nt;
    m_a  = a;
    m_dx = dx;
    m_dt = dt;
    m_D  = D;
    m_T  = T;
}


void PDESolver::writeToFile(vec u) {
    for (int i = 0; i < m_Nx; i++) {
        (*m_uFile) << setprecision(16) << u(i) << " ";
    }
    (*m_uFile) << "\n";
}


void PDESolver::writeParametersToFile() {
    (*m_parameterFile) << setprecision(16) << m_Nx << " " << m_Nt << " ";
    (*m_parameterFile) << m_a << " "       << m_dx << " " << m_dt << " ";
    (*m_parameterFile) << m_D << " "       << m_T;
}






