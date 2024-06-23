//
//  Matrix.cpp
//  practical_cpp_financial_programming
//
//  Created by Alden Braverman on 6/14/24.
//

#include "Matrix.h"

Matrix::Matrix(int size)
{
    for (unsigned i=0; i<size; ++i )
    {
        std::vector<double> row(size, 0);
        m_rows.push_back(row);
    }
}

Matrix::Matrix(int size, int size2)
{
    for (unsigned i=0; i<size; ++i )
    {
        std::vector<double> row(size2, 0);
        m_rows.push_back(row);
    }
}

Matrix::Matrix(const Matrix &s)
: m_rows(s.m_rows)
{
    
}

Matrix::~Matrix()
{
    
}

Matrix &Matrix::operator=(const Matrix &s)
{
    if (this != &s)
    {
        m_rows = s.m_rows;
    }
    return *this;
}

Matrix::Row &Matrix::operator[](int pos)
{
    return m_rows[pos];
}

void Matrix::transpose()
{
    std::vector<Row> rows;
    for (unsigned i=0;i <m_rows[0].size(); ++i)
    {
        std::vector<double> row;
        for (unsigned j=0; j<m_rows.size(); ++j)
        {
            row[j] = m_rows[j][i];
        }
        rows.push_back(row);
    }
    m_rows.swap(rows);
}

double Matrix::trace()
{
    if (m_rows.size() != m_rows[0].size())
    {
        return 0;
        
    }
    
    double total = 0;
    
    for (unsigned i=0; i<m_rows.size(); ++i)
    {
        total += m_rows[i][i];
    }
    
    return total;
}
void Matrix::add(const Matrix &s)
{
    if (m_rows.size() != s.m_rows.size() ||
        m_rows[0].size() != s.m_rows[0].size())
    {
        throw new std::runtime_error("invalid matrix dimensions");
    }
    
    for (unsigned i=0; i<m_rows.size(); ++i)
    {
        for (unsigned j=0; j<m_rows[0].size(); ++j)
        {
            m_rows[i][j] += s.m_rows[i][j];
        }
    }
}
