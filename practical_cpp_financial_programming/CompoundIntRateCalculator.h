//
//  CompoundIntRateCalculator.h
//  practical_cpp_financial_programming
//
//  Created by Alden Braverman on 6/4/24.
//

#ifndef CompoundIntRateCalculator_h
#define CompoundIntRateCalculator_h

class CompoundIntRateCalculator {
public:
    CompoundIntRateCalculator(double rate);
    CompoundIntRateCalculator(const CompoundIntRateCalculator &v);
    CompoundIntRateCalculator &operator = (const CompoundIntRateCalculator &v);
    ~CompoundIntRateCalculator();
    
    double multiplePeriod(double value, int numPeriods);
    double continuousCompounding(double value, int numPeriods);
    
private:
    double m_rate;
};

#endif /* CompoundIntRateCalculator_h */
