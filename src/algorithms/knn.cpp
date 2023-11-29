#include "../../lib/algorithms/knn.h"

template <typename T>
KNN<T>::KNN(std::shared_ptr<SearchAlgorithm<T>> searchAlgorithm, std::shared_ptr<Distance> distance, double contamination, int k) :
    _searchAlgorithm(searchAlgorithm), _distance(distance), _contamination(contamination), _k(k) { }

template <typename T>
void KNN<T>::fit(std::vector<std::vector<T>> data,
                 std::vector<std::vector<int>> labels) {
    _searchAlgorithm->fit(data, _distance);
    auto distances = _searchAlgorithm->distance_to_knearest(_k);

    for (auto const& [sample, distance] : distances) {
        Algorithm<T>::_decision_scores.push_back(distance);
    }



}

template <typename T>
std::vector<int> KNN<T>::predict(std::vector<std::vector<T>> data) {

}

template class KNN<int>;
template class KNN<double>;