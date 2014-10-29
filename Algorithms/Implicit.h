#pragma once
#include <Algorithms/Algorithm.h>

class Implicit : public Algorithm {

public:
    Implicit() {}
    arma::vec advanceOneTimeStep(arma::vec);
    arma::vec tridiagonalMatrixSolver(arma::vec);
};


