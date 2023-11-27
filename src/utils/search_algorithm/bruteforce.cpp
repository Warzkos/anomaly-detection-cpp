#include "../../../lib/utils/search_algorithm/bruteforce.h"

template <typename T>
void BruteForce<T>::fit(const std::vector<std::vector<T>>& data, std::shared_ptr<Distance> distance){
    _data = data;
    _distance = distance;
}

template <typename T>
void BruteForce<T>::search_knearest(std::vector<std::pair<std::vector<T>, double>>& distanceToKNN, int k){
            for(const auto& target : _data){
                std::vector<std::pair<std::vector<T>, double>> k_nearest = {};
                for(const auto& point : _data){
                    k_nearest.push_back(std::make_pair(point, _distance -> calculateDistance(target, point)));
                }
                std::sort(k_nearest.begin(), k_nearest.end(), [](auto const &p1, auto const &p2) { return p1.second < p2.second; });
                k_nearest.erase(k_nearest.begin() + k_nearest.size() - k + 1, k_nearest.end());
                distanceToKNN.push_back(std::make_pair(target, std::accumulate(k_nearest.begin(), k_nearest.end(), 0.0, [](double sum, auto const &p) { return sum + p.second; })));
            }
        }

template class BruteForce<int>;
template class BruteForce<double>;