#pragma once
#include <armadillo>
#include <fstream>

class Algorithm;


class PDESolver {
private:
    std::ofstream* m_uFile;
    std::ofstream* m_parameterFile;
    Algorithm*     m_algorithm;
    arma::vec      m_boundaryConditions;
    arma::vec      m_initialConditions;
    arma::vec      m_u;
    double         m_a;
    double         m_dx;
    double         m_dt;
    double         m_D;
    double         m_T;
    int            m_Nt;
    int            m_Nx;

public:
    PDESolver();
    PDESolver(Algorithm* algorithm);
    ~PDESolver() {m_uFile->close(); m_parameterFile->close();}

    void      setAlgorithm         (Algorithm*);
    void      setInitialConditions (arma::vec);
    void      setBoundaryConditions(arma::vec);
    void      setUpSolver          (int,int,double,double,double,double,double);
    void      writeToFile          (arma::vec);
    void      writeParametersToFile();
    arma::vec solve                (std::ofstream*,std::ofstream*);
};


