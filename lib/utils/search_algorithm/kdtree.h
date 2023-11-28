#pragma once

#include "../search_algorithm.h"

#include <numeric>

template <typename T>
class KDTree : public SearchAlgorithm<T> {
    public:
        void fit(const std::vector<std::vector<T>>& data, std::shared_ptr<Distance> distance) override;
        std::vector<std::pair<std::vector<T>, double>> distance_to_knearest(int k = 3) override;

    private:
        struct Node {
            std::vector<T> point;
            int depth;
            std::shared_ptr<Node> left_bottom = nullptr;
            std::shared_ptr<Node> right_top = nullptr;
        };

        std::shared_ptr<Node> _root = nullptr;
        std::shared_ptr<Distance> _distance = nullptr;
        int _num_features;
        std::vector<std::vector<T>> _data = {};

        void buildKDTree(std::vector<std::vector<T>> &data);

        void insertNodeRecursive(const std::vector<T> &point, std::shared_ptr<Node> current);

        void searchRecursive(std::shared_ptr<Node> current, const std::vector<T> &target, std::vector<std::pair<std::vector<T>, double>> &k_nearest, const int &k);
};