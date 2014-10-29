#include <Algorithms/Algorithm.h>

using arma::vec;

void Algorithm::setBoundaryConditions(vec boundaryConditions) {
    m_boundaryConditions = boundaryConditions;
}
