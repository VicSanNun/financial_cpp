#ifndef BondCalculator_hpp
#define BondCalculator_hpp

#include <iostream>

class BondCalculator {
    private:
        std::string m_institution;
        float m_principal;
        float m_coupon;
        uint16_t m_numPeriods;
        
    public:
        BondCalculator(const std::string institution, uint16_t numPeriods, float principal, float couponValue);
        BondCalculator(const BondCalculator &v);
        BondCalculator &operator =(const BondCalculator &v);
        ~BondCalculator();
        
        float interestRate();
};

#endif
