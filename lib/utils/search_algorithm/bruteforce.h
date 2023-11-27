#pragma once

#include <numeric>

#include "../search_algorithm.h"

template <typename T>
class BruteForce : public SearchAlgorithm<T> {
    public:
        void fit(const std::vector<std::vector<T>>& data, std::shared_ptr<Distance> distance) override;
        void search_knearest(std::vector<std::pair<std::vector<T>, double>>& distanceToKNN, int k = 3) override;
    private:
        std::vector<std::vector<T>> _data = {};
        std::shared_ptr<Distance> _distance = nullptr;
};