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
void IQR::fitAny(std::vector<std::vector<T>> data,
                 std::vector<std::vector<int>> labels) {
    int num_features = data[0].size();

    for (int i = 0; i < num_features; i++) {
        std::vector<T> feature_vec;
        std::transform(data.begin(), data.end(),
                       std::back_inserter(feature_vec),
                       [i](auto const &sample) { return sample[i]; });

        _quartiles.push_back(
            std::make_tuple(QuartileCalculator::calcQuartile(feature_vec, QuartileCalculator::Quartile::FIRST),
                            QuartileCalculator::calcQuartile(feature_vec, QuartileCalculator::Quartile::THIRD)));
    }

    lable_data(data, _labels, _quartiles);
}

template <typename T>
std::vector<int> IQR::predictAny(std::vector<std::vector<T>> data) {
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

void IQR::fit(std::vector<std::vector<double>> data,
              std::vector<std::vector<int>> labels) {
    IQR::fitAny(data, labels);
}

void IQR::fit(std::vector<std::vector<int>> data,
              std::vector<std::vector<int>> labels) {
    IQR::fitAny(data, labels);
}

std::vector<int> IQR::predict(std::vector<std::vector<double>> data) {
    return IQR::predictAny(data);
}

std::vector<int> IQR::predict(std::vector<std::vector<int>> data) {
    return IQR::predictAny(data);
}