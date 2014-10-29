#pragma once
#include <armadillo>
#include <Algorithms/Algorithm.h>

class Explicit : public Algorithm {

public:
    Explicit() {}
    arma::vec advanceOneTimeStep(arma::vec);
    double    spatialDerivative(double, double, double);
};
