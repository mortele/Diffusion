#pragma once
#include <armadillo>


class Algorithm {

protected:
    arma::vec m_boundaryConditions;
    arma::vec m_initialConditions;
    double    m_a;
    int       m_Nx;

public:
    Algorithm()  {}
    ~Algorithm() {}

    virtual arma::vec advanceOneTimeStep   (arma::vec) = 0;
            void      setInitialConditions (arma::vec);
            void      setBoundaryConditions(arma::vec);
            void      setUpAlgorithm       (int, double);
};


