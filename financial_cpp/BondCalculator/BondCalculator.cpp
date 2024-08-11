#include "BondCalculator.hpp"

BondCalculator::BondCalculator(std::string institution, uint16_t numPeriods, float principal, float couponValue) :
                m_institution(institution),
                m_numPeriods(numPeriods),
                m_coupon(couponValue),
                m_principal(principal) {};

BondCalculator::~BondCalculator() {};

BondCalculator::BondCalculator(const BondCalculator &v) :
                m_institution(v.m_institution),
                m_numPeriods(v.m_numPeriods),
                m_coupon(v.m_coupon),
                m_principal(v.m_principal) {};

BondCalculator &BondCalculator::operator =(const BondCalculator &v)
{
    if (this != &v) {
        this->m_institution = v.m_institution;
        this->m_principal = v.m_principal;
        this->m_numPeriods = v.m_numPeriods;
        this->m_coupon = v.m_coupon;
    }
    return *this;
}

float BondCalculator::interestRate() {
    return m_coupon / m_principal;
}
