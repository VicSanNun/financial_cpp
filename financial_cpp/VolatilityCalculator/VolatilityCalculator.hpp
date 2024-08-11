#ifndef VolatilityCalculator_hpp
#define VolatilityCalculator_hpp

#include <iostream>
#include <vector>

class VolatilityCalculator {

private:
    std::vector<float> m_prices;
    double mean();
    
public:
    VolatilityCalculator();
    VolatilityCalculator(const VolatilityCalculator&);
    VolatilityCalculator &operator = (const VolatilityCalculator&);
    ~VolatilityCalculator();
    
    void addPrice(double price) {
        m_prices.push_back(price);
    }
    double rangeVolatility();
    double avgDailyRange();
    double stdDev();
};

#endif /* VolatilityCalculator_hpp */
