#pragma once

#include <vector>
#include <memory>
#include "distance.h"

class SearchAlgorithm {
    public:
        virtual void fit(const std::vector<std::vector<int>>& data, std::shared_ptr<Distance> distance) = 0;
        virtual void fit(const std::vector<std::vector<double>>& data, std::shared_ptr<Distance> distance) = 0;
        virtual void search_knearest(std::vector<std::pair<std::vector<int>, double>>& k_nearest, int k = 3) = 0;
        virtual void search_knearest(std::vector<std::pair<std::vector<double>, double>>& k_nearest, int k = 3) = 0;
};