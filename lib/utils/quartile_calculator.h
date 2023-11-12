#pragma once

#include <vector>
#include <algorithm>

class QuartileCalculator {
public:
    enum Quartile {
        FIRST = 1,
        SECOND,
        THIRD,
    };

    QuartileCalculator() = delete;

    static double calcQuartile(std::vector<int> nums, Quartile quartile);
    static double calcQuartile(std::vector<double> nums, Quartile quartile);
    
private:
    template <typename T>
    static double calcQuartileAny(std::vector<T> nums, Quartile quartile);
};