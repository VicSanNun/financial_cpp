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
    
    float singlePeriod(float &value) {
        return value * (1 + m_rate);
    }
    
    float multiplePeriods(float &value, uint16_t &numPeriods) {
        return value * std::pow(1 + m_rate, numPeriods);
    }
    
    float continuousCompounding(float &value, uint16_t &numPeriods) {
        return value * std::exp(m_rate * numPeriods);
    }
    
    float rate() const {
        return this->m_rate;
    }
};

#endif
