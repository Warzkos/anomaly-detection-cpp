#pragma once

#include <memory>

#include "../algorithm.h"
#include "../utils/search_algorithm.h"
#include "../utils/distance.h"

template <typename T>
class KNN : public Algorithm<T> {
    public:
        KNN(std::shared_ptr<SearchAlgorithm> searchAlgorithm, std::shared_ptr<Distance> distance);

        void fit(std::vector<std::vector<T>> data,
                    std::vector<std::vector<int>> labels = {}) override;

        std::vector<int> predict(std::vector<std::vector<T>> data) override;
    private:
        std::shared_ptr<SearchAlgorithm> _searchAlgorithm;
        std::shared_ptr<Distance> _distance;
};