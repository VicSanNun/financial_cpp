#ifndef MovingAverage_hpp
#define MovingAverage_hpp

#include <iostream>
#include <vector>

class MovingAverageCalculator {

private:
    uint16_t m_numPeriods;
    std::vector<float> m_prices;
    
public:
    MovingAverageCalculator(uint16_t period);
    MovingAverageCalculator(const MovingAverageCalculator&);
    MovingAverageCalculator &operator = (const MovingAverageCalculator&);
    ~MovingAverageCalculator();
    
    void addPriceQuote(float &closePrice);
    std::vector<float> calculateMA();
    std::vector<float> calculateEMA();
};

#endif
