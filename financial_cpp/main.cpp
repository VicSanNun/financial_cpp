#include <iostream>
#include "InterestRateCalculator.hpp"

uint16_t verify_argc(int &argc) {
    if (argc < 5) {
        std::cerr << "multiple_period requires <period> argument." << '\n';
        return -1;
    }
    return 0;
}

int main(int argc, const char* argv[]) {
    
    if (argc < 3) {
        std::cout << "--------------------------------------------------" << '\n';
        std::cout << "usage: progName <type_interest_rate> <interest_rate> <value> [<period>]" << '\n';
        std::cout << "\ntype_interest_rate: " << '\n';
        std::cout << "1. single_period" << '\n';
        std::cout << "2. multiple_period" << '\n';
        std::cout << "3. compounding" << '\n';
        std::cout << "\nExample: int_rate single_period 0.08 10000" << '\n';
        std::cout << "Example: int_rate multiple_period 0.08 10000 2" << '\n';
        std::cout << "Example: int_rate compounding 0.08 10000 3" << '\n';
        std::cout << "--------------------------------------------------" << '\n';
        return 1;
    }
    
    std::string type {argv[1]};
    float rate = std::atof(argv[2]);
    float value = std::atof(argv[3]);
    
    IntRateCalculator irCalculator(rate);
    float res {0.0};
    
    if (type == "single_period") {
        res = irCalculator.singlePeriod(value);
    } else if (type == "multiple_period") {
        verify_argc(argc);
        uint16_t numPeriods = std::stoi(argv[4]);
        res = irCalculator.multiplePeriods(value, numPeriods);
    } else if (type == "compounding") {
        verify_argc(argc);
        uint16_t numPeriods = std::stoi(argv[4]);
        res = irCalculator.continuousCompounding(value, numPeriods);
    } else {
        std::cerr << "Invalid type_interest_rate. Must be 'single_period', 'multiple_period', or 'continuous_compounding'." << std::endl;
        return 1;
    }
    
    
    std::cout << "Result is: " << res << '\n';
    
    return 0;
}
