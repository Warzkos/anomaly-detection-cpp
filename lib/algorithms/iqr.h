#pragma once

#include "../algorithm.h"
#include "../utils/quartile_calculator.h"
#include <tuple>
#include <stdexcept>
#include <algorithm>

class IQR : public Algorithm {
    private:
        std::vector<std::tuple<double, double>> _quartiles = {};

        template <typename T>
        void fitAny(std::vector<std::vector<T>> data,
                    std::vector<std::vector<int>> labels = {});

        template <typename T>
        std::vector<int> predictAny(std::vector<std::vector<T>> data);

    public:

        void fit(std::vector<std::vector<double>> data,
                 std::vector<std::vector<int>> labels = {}) override;

        void fit(std::vector<std::vector<int>> data,
                 std::vector<std::vector<int>> labels = {}) override;
    
        std::vector<int> predict(std::vector<std::vector<double>> data) override;

        std::vector<int> predict(std::vector<std::vector<int>> data) override;
};