#include <Algorithms/Explicit.h>


arma::vec Explicit::advanceOneTimeStep(arma::vec u) {
    arma::vec uNew = u;
    uNew(1) = spatialDerivative(m_boundaryConditions(0), u(1), u(2));

    for (int i = 2; i < m_Nx-2; i++) {
        uNew(i) = spatialDerivative(u(i-1), u(i), u(i+1));
    }

    uNew(m_Nx-2) = spatialDerivative(u(m_Nx-3), u(m_Nx-2), m_boundaryConditions(1));
    return uNew;
}


double Explicit::spatialDerivative(double uPrev, double uThis, double uNext) {
    return m_a * (uPrev + uNext) + (1 - 2 * m_a) * uThis;
}
