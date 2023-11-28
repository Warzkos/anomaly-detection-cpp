#include "../../lib/algorithms/iqr.h"

template <typename T>
void lable_data(const std::vector<T> &data, std::vector<int> &labels,
                const std::vector<std::tuple<double, double>> &quartiles) {
    int num_features = quartiles.size();

    for (auto const &sample : data) {
        labels.push_back(0);
        for (int i = 0; i < num_features; i++) {
            const auto [lower, upper] = quartiles[i];
            if (sample[i] > upper + 1.5d * (upper - lower) ||
                sample[i] < lower - 1.5d * (upper - lower)) {
                labels.back() = 1;
                break;
            }
        }
    }
}

template <typename T>
void IQR<T>::fit(std::vector<std::vector<T>> data,
                 std::vector<std::vector<int>> labels) {
    int num_features = data[0].size();

    for (int feature = 0; feature < num_features; feature++) {
        _quartiles.push_back(
            std::make_tuple(QuartileCalculator::calcQuartile(data, feature, QuartileCalculator::Quartile::FIRST),
                            QuartileCalculator::calcQuartile(data, feature, QuartileCalculator::Quartile::THIRD)));
    }

    lable_data(data, Algorithm<T>::_labels, _quartiles);
}

template <typename T>
std::vector<int> IQR<T>::predict(std::vector<std::vector<T>> data) {
    if (std::any_of(data.begin(), data.end(), [this](auto const &sample) {
            return sample.size() != _quartiles.size();
        })) {
        throw std::invalid_argument("Passed data has different number of "
                                    "features than the model was trained on.");
    }
    std::vector<int> labels = {};
    lable_data(data, labels, _quartiles);
    return labels;
}

template class IQR<int>;
template class IQR<double>;