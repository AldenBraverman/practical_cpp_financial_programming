//
//  LPSolver.cpp
//  practical_cpp_financial_programming
//
//  Created by Alden Braverman on 6/14/24.
//


#include "LPSSolver.h"
#include <glpk.h>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::endl;

LPSolver::LPSolver(Matrix &m, const vector<double> &b, const vector<double> &c)
: m_M(m.numRows()),
  m_N(m[0].size()),
  m_c(c),
  m_b(b),
  m_A(m),
  m_lp(glp_create_prob())
{
    initProblem(m_M, m_N);
}

