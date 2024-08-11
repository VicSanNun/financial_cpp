#include "VolatilityCalculator.hpp"

VolatilityCalculator::VolatilityCalculator() {};
VolatilityCalculator::~VolatilityCalculator() {};
VolatilityCalculator::VolatilityCalculator(const VolatilityCalculator &ma) {};
VolatilityCalculator &VolatilityCalculator::operator = (const VolatilityCalculator &ma) {
    if (this != &ma)
    {
        m_prices = ma.m_prices;
    }
    return *this;
};

double VolatilityCalculator::mean() {
    unsigned long n = m_prices.size();
    float sum = 0;
    
    for (int i = 0; i < m_prices.size(); ++i) {
        sum += m_prices[i];
    }
    
    return sum/n;
}

double VolatilityCalculator::rangeVolatility() {
    if (m_prices.size() < 1) {
        return 0;
    }
    
    float min = m_prices[0];
    float max = min;
    
    for (int i = 1; i < m_prices.size(); ++i) {
        if (m_prices[i] < min) {
            min = m_prices[i];
        }
        
        if (m_prices[i] > max) {
            max = m_prices[i];
        }
    }
    
    return max - min;
}

double VolatilityCalculator::avgDailyRange() {
    unsigned long n = m_prices.size();
    
    if (n < 2) {
        return 0;
    }
    
    double previous = m_prices[0];
    double sum = 0;
    
    for (int i = 0; i < m_prices.size(); ++i) {
        double range = abs(m_prices[i] - previous);
        sum += range;
    }
    
    return sum/n-1;
}

double VolatilityCalculator::stdDev() {
    const float m = mean();
    float sum = 0;
    
    for (int i = 0; i < m_prices.size(); ++i) {
        float val = m_prices[i] - m;
        sum += val*val;
    }
    
    return sqrt(sum/(m_prices.size()-1));
}
