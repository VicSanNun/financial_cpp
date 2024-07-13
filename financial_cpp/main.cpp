#include <iostream>
#include "InterestRateCalculator.hpp"

int main(int argc, const char* argv[]) {
    
    if (argc != 3) {
        std::cout << "usage: progName <interest_rate> <value>" << '\n';
        return 1;
    }
    
    float rate = atof(argv[1]);
    float value = atof(argv[2]);
    
    IntRateCalculator irCalculator(rate);
    
    float res = irCalculator.singlePeriod(value);
    
    std::cout << "Result is: " << res << '\n';
    
    return 0;
}
