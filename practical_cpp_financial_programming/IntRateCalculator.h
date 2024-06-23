//
//  IntRateCalculator.h
//  practical_cpp_financial_programming
//
//  Created by Alden Braverman on 6/4/24.
//

#ifndef IntRateCalculator_h
#define IntRateCalculator_h

#include <iostream>

class IntRateCalculator {
public:
    IntRateCalculator(double rate);
    IntRateCalculator(const IntRateCalculator &v);
    IntRateCalculator &operator =(const IntRateCalculator &v);
    ~IntRateCalculator();
    
    double singlePeriod(double value);
private:
    double m_rate;
};

inline double IntRateCalculator::singlePeriod(double value)
{
    double f = value * ( 1 + this->m_rate );
    return f;
}

#endif /* IntRateCalculator_h */
