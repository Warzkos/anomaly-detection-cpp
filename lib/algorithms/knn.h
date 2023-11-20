#pragma once

#include <memory>

#include "../algorithm.h"
#include "../utils/search_algorithm.h"
#include "../utils/distance.h"

class KNN : public Algorithm {
    public:
        KNN(std::shared_ptr<SearchAlgorithm> searchAlgorithm, std::shared_ptr<Distance> distance);

        void fit(std::vector<std::vector<double>> data,
                    std::vector<std::vector<int>> labels = {}) override;

        void fit(std::vector<std::vector<int>> data,
                    std::vector<std::vector<int>> labels = {}) override;

        std::vector<int> predict(std::vector<std::vector<double>> data) override;

        std::vector<int> predict(std::vector<std::vector<int>> data) override;

    private:
        std::vector<std::tuple<double, double>> _quartiles = {};

        template <typename T>
        void fitAny(std::vector<std::vector<T>> data,
                    std::vector<std::vector<int>> labels = {});

        template <typename T>
        std::vector<int> predictAny(std::vector<std::vector<T>> data);
};

// TODO: Implement neighbour search algorithms like KD-Tree, Ball-Tree, etc.