#include "MovingAverageCalculator.hpp"

MovingAverageCalculator::MovingAverageCalculator(uint16_t periods) : m_numPeriods(periods) {};
MovingAverageCalculator::~MovingAverageCalculator() {};
MovingAverageCalculator::MovingAverageCalculator(const MovingAverageCalculator &ma) : m_numPeriods(ma.m_numPeriods) {};
MovingAverageCalculator &MovingAverageCalculator::operator = (const MovingAverageCalculator &ma)
{
    if (this != &ma)
    {
        m_numPeriods = ma.m_numPeriods;
        m_prices = ma.m_prices;
    }
    return *this;
}

void MovingAverageCalculator::addPriceQuote(float &closePrice) {
    m_prices.push_back(closePrice);
}

std::vector<float> MovingAverageCalculator::calculateMA() {
    std::vector<float> maVector;
    float sum = 0;
    
    for (int i=0; i<m_prices.size(); ++i) {
        sum += m_prices[i];
        if (i >= m_numPeriods) {
            maVector.push_back(sum / m_numPeriods);
            sum -= m_prices[i-m_numPeriods];
        }
    }
    
    return maVector;
}

std::vector<float> MovingAverageCalculator::calculateEMA() {
    std::vector<float> emaVector;
    float multiplier = 2.0f / (m_numPeriods + 1);
    float sum = 0.0f;

    for (int i = 0; i < m_prices.size(); ++i) {
        sum += m_prices[i];
        if (i == m_numPeriods) {
            emaVector.push_back(sum / m_numPeriods);
            sum -= m_prices[i-m_numPeriods];
        }
        else if (i > m_numPeriods) {
            float val = (1-multiplier) * emaVector.back() + multiplier * m_prices[i];
            emaVector.push_back(val);
        }
    }
    
    return emaVector;
}

