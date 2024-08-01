#include <iostream>
#include "InterestRateCalculator/InterestRateCalculator.hpp"
#include "CashFlowCalculator/CashFlowCalculator.hpp"


int main(int argc, const char* argv[]) {
    
    float rate = 0.08;
    float value {10000};
    std::vector<float> cashFlows ({200, 300, 500, -1000});
    
    IntRateCalculator irCalculator {rate};
    CashFlowCalculator cashFlowCalc {rate};
    
    float res1 = irCalculator.singlePeriod(value);
    float res2 = irCalculator.multiplePeriods(value, 2);
    float res3 = irCalculator.continuousCompounding(value, 2);
    
    for (int i = 0; i < cashFlows.size(); ++i) {
        cashFlowCalc.addCashPayment(cashFlows[i], i+1);
    }
    
    float res4 = cashFlowCalc.presentValue();
    
    
    std::cout << "Result 1 is: " << res1 << '\n';
    std::cout << "Result 2 is: " << res2 << '\n';
    std::cout << "Result 3 is: " << res3 << '\n';
    std::cout << "Result 4 is: " << res4 << '\n';
    
    return 0;
}
