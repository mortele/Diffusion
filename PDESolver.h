#pragma once
#include <armadillo>
#include <fstream>

class Algorithm;


class PDESolver {
private:
    std::ofstream* m_outFile;
    Algorithm*     m_algorithm;
    arma::vec      m_boundaryConditions;
    arma::vec      m_initialConditions;
    arma::vec      m_u;
    double         m_a;
    int            m_Nt;
    int            m_Nx;

public:
    PDESolver();
    PDESolver(Algorithm* algorithm);
    ~PDESolver() {}

    void      setAlgorithm         (Algorithm*);
    void      setInitialConditions (arma::vec);
    void      setBoundaryConditions(arma::vec);
    void      setUpSolver          (int,int,double);
    void      writeToFile          (arma::vec);
    arma::vec solve                (std::ofstream*);
};


