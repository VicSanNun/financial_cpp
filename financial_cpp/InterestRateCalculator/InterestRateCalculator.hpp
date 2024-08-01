#ifndef InterestRateCalculator_hpp
#define InterestRateCalculator_hpp

#include <iostream>

class IntRateCalculator {
private:
    float m_rate;

public:
    IntRateCalculator(float &rate);
    IntRateCalculator(const IntRateCalculator &v);
    IntRateCalculator& operator = (IntRateCalculator &v);
    ~IntRateCalculator();
    
    float singlePeriod(const float &value) {
        return value * (1 + m_rate);
    }
    
    float multiplePeriods(const float &value, const uint16_t &numPeriods) {
        return value * std::pow(1 + m_rate, numPeriods);
    }
    
    float continuousCompounding(const float &value, const uint16_t &numPeriods) {
        return value * std::exp(m_rate * numPeriods);
    }
    
    float rate() const {
        return this->m_rate;
    }
};

#endif
