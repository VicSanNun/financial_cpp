#ifndef CashFlowCalculator_hpp
#define CashFlowCalculator_hpp

#include <iostream>
#include <vector>

class CashFlowCalculator {
    private:
        std::vector<float> m_cashPayments;
        std::vector<uint16_t> m_timePeriods;
        float presentValue(float futureValue, uint16_t timePeriod);
        float m_rate;
    
    public:
        CashFlowCalculator(float &rate);
        CashFlowCalculator(const CashFlowCalculator &v);
        CashFlowCalculator &operator = (CashFlowCalculator &v);
        ~CashFlowCalculator();
    
        void addCashPayment(float value, uint16_t timePeriod);
        float presentValue();
        
        float rate() const {
            return this->m_rate;
        }
};

#endif
