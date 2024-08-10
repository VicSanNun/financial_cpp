#include "InterestRateCalculator.hpp"
#include <iostream>

IntRateCalculator::IntRateCalculator(float &rate) : m_rate(rate) {};
IntRateCalculator::~IntRateCalculator() {};
IntRateCalculator::IntRateCalculator(const IntRateCalculator &v) : m_rate(v.rate()) {};
IntRateCalculator &IntRateCalculator::operator = (IntRateCalculator &v) {
    if (&v != this) {
        this -> m_rate = v.rate();
    }
    return *this;
};



