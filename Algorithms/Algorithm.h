#pragma once
#include <armadillo>


class Algorithm {

private:
    arma::vec m_boundaryConditions;

public:
    Algorithm() {}
    ~Algorithm() {}

    virtual arma::vec advanceOneTimeStep(arma::vec) = 0;
    void              setBoundaryConditions(arma::vec);
};


