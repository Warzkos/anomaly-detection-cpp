#include "../../lib/utils/quartile_calculator.h"

template <typename T>
double QuartileCalculator::calcQuartileAny(std::vector<T> nums, Quartile quartile){
    if ((quartile == 2 && nums.size() % 2 == 1) ||
        (quartile != 2 && (nums.size() % 4) / 2 == 1)) {
        int quartilePos = (nums.size() * quartile) / 4;
        std::nth_element(nums.begin(), nums.begin() + quartilePos, nums.end());

        return static_cast<double>(nums[quartilePos]);
    } else {
        int quartilePos = ((nums.size() + 1) * quartile) / 4;
        std::nth_element(nums.begin(), nums.begin() + quartilePos, nums.end());
        T first = nums[quartilePos];
        std::nth_element(nums.begin(), nums.begin() + quartilePos - 1,
                         nums.end());
        T second = nums[quartilePos - 1];

        return static_cast<double>((first + second)) / 2.0d;
    }
}

template <typename T>
double QuartileCalculator::calcQuartileAny(std::vector<std::vector<T>> data, int feature, Quartile quartile) {
    std::vector<T> feature_vec;
    std::transform(data.begin(), data.end(),
                    std::back_inserter(feature_vec),
                    [feature](auto const &sample) { return sample[feature]; });
    return calcQuartileAny(feature_vec, quartile);
}

double QuartileCalculator::calcQuartile(std::vector<int> nums, Quartile quartile) {
    return calcQuartileAny(nums, quartile);
}
double QuartileCalculator::calcQuartile(std::vector<double> nums, Quartile quartile) {
    return calcQuartileAny(nums, quartile);
}

double QuartileCalculator::calcQuartile(std::vector<std::vector<int>> data, int feature, Quartile quartile) {
    return calcQuartileAny(data, feature, quartile);
}

double QuartileCalculator::calcQuartile(std::vector<std::vector<double>> data, int feature, Quartile quartile) {
    return calcQuartileAny(data, feature, quartile);
}


        // std::vector<T> feature_vec;
        // std::transform(data.begin(), data.end(),
        //                std::back_inserter(feature_vec),
        //                [i](auto const &sample) { return sample[i]; });