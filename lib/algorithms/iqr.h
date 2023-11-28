#pragma once

#include "../algorithm.h"
#include "../utils/quartile_calculator.h"
#include <tuple>
#include <stdexcept>
#include <algorithm>

template <typename T>
class IQR : public Algorithm<T> {
    public:
        void fit(std::vector<std::vector<T>> data,
                 std::vector<std::vector<int>> labels = {}) override;
    
        std::vector<int> predict(std::vector<std::vector<T>> data) override;
    
    private:
        std::vector<std::tuple<double, double>> _quartiles = {};
};