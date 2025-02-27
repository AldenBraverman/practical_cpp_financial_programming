//
//  LPSSolver.h
//  practical_cpp_financial_programming
//
//  Created by Alden Braverman on 6/14/24.
//

#ifndef LPSSolver_h
#define LPSSolver_h

#include <vector>
#include <string>

#include "Matrix.h"

struct glp_prob;

class LPSolver {
public:
    LPSolver(Matrix &A, const std::vector<double> &b, const std::vector<double> &c);
    LPSolver(const LPSolver &p);
    ~LPSolver();
    LPSolver &operator=(const LPSolver &p);
    
    enum ResultType {
        INFEASIBLE,
        FEASIBLE,
        ERROR
    };
    
    virtual ResultType solve(std::vector<double> &result, double &objValue);
    void setName(const std::string &s);
    bool isValid();
    void setMaximization();
    void setMinimization();
    
private:
    size_t m_M;
    size_t m_N;
    std::vector<double> m_c;
    std::vector<double> m_b;
    Matrix m_A;
    glp_prob *m_lp;
    void initProblem(size_t M, size_t N);
    void setRowBounds();
    void setColumnCoefs();
    
protected:
    glp_prob *getLP();
    int getNumCols();
    int getNumRows();
    
};

#endif /* LPSSolver_h */
