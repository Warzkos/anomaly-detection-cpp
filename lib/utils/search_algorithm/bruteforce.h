#pragma once

#include <numeric>

#include "../search_algorithm.h"

template <typename T>
class BruteForce : public SearchAlgorithm {
    public:
        void fit(const std::vector<std::vector<int>>& data, std::shared_ptr<Distance> distance) override;
        void fit(const std::vector<std::vector<double>>& data, std::shared_ptr<Distance> distance) override;
        void search_knearest(std::vector<std::pair<std::vector<int>, double>>& distanceToKNN, int k = 3) override;
        void search_knearest(std::vector<std::pair<std::vector<double>, double>>& distanceToKNN, int k = 3) override;
    private:
        std::vector<std::vector<T>> _data = {};
        std::shared_ptr<Distance> _distance = nullptr;

        void fitAny(std::vector<std::vector<T>> data, std::shared_ptr<Distance> distance);
        void search_knearestAny(int k, std::vector<std::pair<std::vector<T>, double>>& distanceToKNN);
        void bruteforceKNNSearch(int k, std::vector<std::pair<std::vector<T>, double>>& distanceToKNN);
};