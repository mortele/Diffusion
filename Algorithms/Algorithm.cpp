#include <Algorithms/Algorithm.h>

using arma::vec;

void Algorithm::setInitialConditions(arma::vec initialConditions) {
    m_initialConditions = initialConditions;
}


void Algorithm::setBoundaryConditions(vec boundaryConditions) {
    m_boundaryConditions = boundaryConditions;
}


void Algorithm::setUpAlgorithm(int Nx, double a) {
    m_Nx = Nx;
    m_a  = a;
}


