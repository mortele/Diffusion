#include <Algorithms/Implicit.h>
#include <armadillo>

using arma::vec;
using arma::ones;


vec Implicit::advanceOneTimeStep(vec u) {
    return this->tridiagonalMatrixSolver(u);
}


vec Implicit::tridiagonalMatrixSolver(vec u) {
    double a = -m_a;
    double c = -m_a;
    vec    b = ones(m_Nx) * (1 + 2 * m_a);

    u(0)      = 0;
    u(m_Nx-1) = 0;

    for (int i = 2; i < m_Nx-1; i++) {
        b(i) = b(i) - a / b(i-1) * a;
        u(i) = u(i) - a / b(i-1) * u(i-1);
    }
    u(m_Nx-2) = u(m_Nx-2) / b(m_Nx-2);
    for (int i = m_Nx-3; i >= 1; i--) {
        u(i) = (u(i) - c * u(i+1)) / b(i);
    }

    return u;
}
