#pragma once

#include <vector>
#include <memory>
#include "distance.h"

template <typename T>
class SearchAlgorithm {
    public:
        virtual void fit(const std::vector<std::vector<T>>& data, std::shared_ptr<Distance> distance) = 0;
        virtual void search_knearest(std::vector<std::pair<std::vector<T>, double>>& k_nearest, int k = 3) = 0;
};