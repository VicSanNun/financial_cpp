#include "CashFlowCalculator.hpp"
#include <iostream>
#include <cmath>

CashFlowCalculator::CashFlowCalculator(float &rate) : m_rate {rate} {};
CashFlowCalculator::~CashFlowCalculator() {};
CashFlowCalculator::CashFlowCalculator(const CashFlowCalculator &v) : m_rate(v.rate()) {};
CashFlowCalculator &CashFlowCalculator::operator = (CashFlowCalculator &v) {
    if (&v != this) {
        this -> m_cashPayments = v.m_cashPayments;
        this -> m_timePeriods = v.m_timePeriods;
        this -> m_rate = v.rate();
    }
    return *this;
};

void CashFlowCalculator::addCashPayment(float &value, uint16_t  timePeriod){
    this -> m_cashPayments.push_back(value);
    this -> m_timePeriods.push_back(timePeriod);
}

float CashFlowCalculator::presentValue(float &futureValue, uint16_t timePeriod) {
    float pValue = futureValue / pow(1 + m_rate, timePeriod);
    std::cout << "Future Value: " << futureValue << '\n';
    std::cout << "Time Period: " << timePeriod << '\n';
    std::cout << "Value: " << pValue << '\n';
    return pValue;
}

float CashFlowCalculator::presentValue() {
    float total = 0;
    
    for (int i = 0; i < m_cashPayments.size(); ++i) {
        total += presentValue(m_cashPayments[i], m_timePeriods[i]);
    }
    
    return total;
}
