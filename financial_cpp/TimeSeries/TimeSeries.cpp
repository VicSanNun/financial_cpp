#include "TimeSeries.hpp"

TimeSeries::TimeSeries() {};
TimeSeries::~TimeSeries() {};
TimeSeries::TimeSeries(const TimeSeries &ts) {};
TimeSeries &TimeSeries::operator=(const TimeSeries &ts) {
    if (this != &ts) {
        this->m_values = ts.m_values;
    }
    return *this;
}

double TimeSeries::mean() {
    double n = size();
    double sum = 0;
    
    for (int i = 0; i < n; ++i) {
        sum += elem(i);
    }
    
    return sum/n;
}

double TimeSeries::stdDev() {
    double n = size();
    double m = mean();
    double sum = 0;
    
    for (int i = 0; i < n; ++i) {
        double value = (elem(i) - m);
        sum += value*value;
    }
    
    return sqrt(sum/(n-1));
}

