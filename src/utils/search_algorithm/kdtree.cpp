#include "../../../lib/utils/search_algorithm/kdtree.h"

template <typename T>
void KDTree<T>::fit(const std::vector<std::vector<T>>& data, std::shared_ptr<Distance> distance){
    _data = data;
    auto data_copy = data;
    _root = std::make_shared<Node>();
    std::nth_element(data_copy.begin(), data_copy.begin() + data_copy.size() / 2, data_copy.end(), [](auto const &p1, auto const &p2) { return p1[0] < p2[0]; });
    _root -> point = data_copy[data_copy.size() / 2];
    _root -> depth = 0;
    data_copy.erase(data_copy.begin() + data_copy.size() / 2);

    _distance = distance;
    _num_features = data_copy[0].size();

    buildKDTree(data_copy);
}

template <typename T>
std::vector<std::pair<std::vector<T>, double>> KDTree<T>::distance_to_knearest(int k) {
    std::vector<std::pair<std::vector<T>, double>> distanceToKNN = {};
    for(const auto& target : _data){
        std::vector<std::pair<std::vector<T>, double>> k_nearest = {};
        searchRecursive(_root, target, k_nearest, k);
        distanceToKNN.push_back(std::make_pair(target, std::accumulate(k_nearest.begin(), k_nearest.end(), 0.0, [](double sum, auto const &p) { return sum + p.second; })));
    }
    return distanceToKNN;
}

template <typename T>
void KDTree<T>::buildKDTree(std::vector<std::vector<T>> &data) {
    int depth = 1 % _num_features;
    while(data.size() > 0) {
        std::nth_element(data.begin(), data.begin() + data.size() / 2, data.end(), [depth](auto const &p1, auto const &p2) { return p1[depth] < p2[depth]; });
        insertNodeRecursive(data[data.size()/2], _root);
        data.erase(data.begin() + data.size() / 2);
        depth = (depth + 1) % _num_features;
    }
}

template <typename T>
void KDTree<T>::insertNodeRecursive(const std::vector<T> &point, std::shared_ptr<Node> current) {
    if(current -> point[current -> depth] > point[current -> depth]) {
        if(current -> left_bottom == nullptr) {
            current -> left_bottom = std::make_shared<Node>();
            current -> left_bottom -> point = point;
            current -> left_bottom -> depth = (current -> depth + 1) % _num_features;
        } else {
            insertNodeRecursive(point, current -> left_bottom);
        }
    } else {
        if(current -> right_top == nullptr) {
            current -> right_top = std::make_shared<Node>();
            current -> right_top -> point = point;
            current -> right_top -> depth = (current -> depth + 1) % _num_features;
        } else {
            insertNodeRecursive(point, current -> right_top);
        }
    }
} 

template <typename T>
void KDTree<T>::searchRecursive(std::shared_ptr<Node> current, const std::vector<T> &target, std::vector<std::pair<std::vector<T>, double>> &k_nearest, const int &k) {
    
    double distance = _distance -> calculateDistance(current -> point, target);
    if(k_nearest.size() < k + 1 || std::any_of(k_nearest.begin(), k_nearest.end(), [distance](auto const &p) { return p.second > distance; })){
        k_nearest.push_back(std::make_pair(current -> point, distance));
        if(k_nearest.size() > k + 1) {
            std::nth_element(k_nearest.begin(), k_nearest.end() - 1, k_nearest.end(), [](auto const &p1, auto const &p2) { return p1.second < p2.second; });
            k_nearest.pop_back();
        }
    }

    if(current -> point[current -> depth] > target[current -> depth]) {
        if(current -> left_bottom != nullptr) {
            searchRecursive(current -> left_bottom, target, k_nearest, k);
        }
    } else {
        if(current -> right_top != nullptr) {
            searchRecursive(current -> right_top, target, k_nearest, k);
        }
    }

    double min_distance = std::abs(current -> point[current -> depth] - target[current -> depth]);
    if(std::any_of(k_nearest.begin(), k_nearest.end(), [min_distance](auto const &p) { return p.second > min_distance; })) {
        if(current -> point[current -> depth] > target[current -> depth]) {
            if(current -> right_top != nullptr) {
                searchRecursive(current -> right_top, target, k_nearest, k);
            }
        } else {
            if(current -> left_bottom != nullptr) {
                searchRecursive(current -> left_bottom, target, k_nearest, k);
            }
        }
    }
}

template class KDTree<int>;
template class KDTree<double>;