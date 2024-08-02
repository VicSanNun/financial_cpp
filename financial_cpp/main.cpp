#include <iostream>
#include "InterestRateCalculator/InterestRateCalculator.hpp"
#include "CashFlowCalculator/CashFlowCalculator.hpp"
#include "BondCalculator/BondCalculator.hpp"
#include "MovingAverageCalculator/MovingAverageCalculator.hpp"


int main(int argc, const char* argv[]) {
    
    float rate = 0.08;
    float value {10000};
    uint16_t numPeriodsMaCalc = 5;
    std::vector<float> cashFlows ({200, 300, 500, -1000});
    std::vector<float>closePrices ({10, 11, 22, 12, 13, 23, 12, 32, 12, 3, 2, 22, 32});
    
    IntRateCalculator irCalculator {rate};
    CashFlowCalculator cashFlowCalc {rate};
    BondCalculator bondCalc {"Company A", 20, 100000, 5000};
    MovingAverageCalculator maCalc {numPeriodsMaCalc};
    
    float res1 = irCalculator.singlePeriod(value);
    float res2 = irCalculator.multiplePeriods(value, 2);
    float res3 = irCalculator.continuousCompounding(value, 2);
    
    for (int i = 0; i < cashFlows.size(); ++i) {
        cashFlowCalc.addCashPayment(cashFlows[i], i+1);
    }
    
    float res4 = cashFlowCalc.presentValue();
    float res5 = bondCalc.interestRate();
    
    for (float i : closePrices) {
        maCalc.addPriceQuote(i);
    }
    std::vector<float> ma_res = maCalc.calculateMA();
    std::vector<float> ema_res = maCalc.calculateEMA();
    
    std::cout << "Result Single Period Interest Rate is: " << res1 << '\n';
    std::cout << "Result Mult Period Interest Rate is: " << res2 << '\n';
    std::cout << "Result Continuous Compounding Interest Rate is: " << res3 << '\n';
    std::cout << "Result Present Value by Cash Flow is: " << res4 << '\n';
    std::cout << "Result Interest Rate by Bond Modeling is: " << res5 << '\n';
    for (float i : ma_res) {
        std::cout << "Média Móvel Item: " << i << '\n';
    }
    
    for (float i : ema_res) {
        std::cout << "Média Móvel Exponencial Item: " << i << '\n';
    }
    
    return 0;
}
