#ifndef TimeSeries_hpp
#define TimeSeries_hpp

#include <iostream>
#include <vector>
#include <cmath>

class TimeSeries {
    private:
        std::vector<double> m_values;
    public:
        TimeSeries();
        TimeSeries(const TimeSeries &ts);
        TimeSeries &operator = (const TimeSeries &ts);
        ~TimeSeries();
        
        void addValue(double value) {
            m_values.push_back(value);
        };
        double stdDev();
        double mean();
        size_t size() {
            return m_values.size();
        };
        double elem(int i) {
            return m_values[i];
        };
};

#endif
