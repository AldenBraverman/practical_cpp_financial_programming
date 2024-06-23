//
//  main.cpp
//  practical_cpp_financial_programming
//
//  Created by Alden Braverman on 6/4/24.
//

#include <iostream>

// IntRateCalculator main()
/*
#include "IntRateCalculator.h"
int main(int argc, const char * argv[])
{
    if (argc != 3)
    {
        std::cout << "usage: progName <interest rate> <value> " << std::endl;
        return 1;
    }
    
    double rate = atof(argv[1]);
    double value = atof(argv[2]);
    IntRateCalculator irCalculator(rate);
    double res = irCalculator.singlePeriod(value);
    std::cout << " result is " << res << std::endl;
    return 0;
}
*/

// CompoundIntRateCalculator main()

#include "CompoundIntRateCalculator.h"
int main(int argc, const char * argv[])
{
    if (argc != 4)
    {
        std::cout << "usage: progName <interest rate> <present value> <num periods>" << std::endl;
    return 1;
    }
    
    double rate = atof(argv[1]);
    double value = atof(argv[2]);
    int num_periods = atoi(argv[3]);
    CompoundIntRateCalculator cIRCalc(rate);
    double res = cIRCalc.multiplePeriod(value, num_periods);
    double contRes = cIRCalc.continuousCompounding(value, num_periods);
    std::cout << " future value for multiple period compounding is " << res << std::endl;
    std::cout << " future value for continuous compounding is " << contRes << std::endl;
    return 0;
}

