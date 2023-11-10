#include "../algorithm.h"
#include <tuple>
#include <stdexcept>

class IQR : public Algorithm {
    private:
        std::vector<std::tuple<float, float>> _quartiles;

        enum Quartile {
            FIRST = 1,
            SECOND,
            THIRD
        };

        template <typename T>
        float calcQuartile(std::vector<T> nums, Quartile quartile){
            if((quartile==2 && nums.size()%2==1) || (quartile!=2 && (nums.size()%4)/2==1)) {
                int quartilePos = (nums.size() * quartile) / 4;
                std::nth_element(nums.begin(), nums.begin() + quartilePos, nums.end());

                return static_cast<float>(nums[quartilePos]);
            } else {
                int quartilePos = ((nums.size() + 1) * quartile) / 4;
                std::nth_element(nums.begin(), nums.begin() + quartilePos, nums.end());
                T first = nums[quartilePos];
                std::nth_element(nums.begin(), nums.begin() + quartilePos - 1, nums.end());
                T second = nums[quartilePos - 1];

                return static_cast<float>((first + second)) / 2.0f;
            }
        }

        template <typename T>
        void lable_data(const std::vector<T>& data, std::vector<int>& labels){
            int num_features = _quartiles.size();
            
            for(auto const& sample : data){
                labels.push_back(0);
                for(int i = 0; i < num_features; i++){
                    const auto[lower, upper] = _quartiles[i];
                    if(sample[i] > upper + 1.5f * (upper - lower) || sample[i] < lower - 1.5f * (upper - lower)){
                        labels.back() = 1;
                        break;
                    }
                }
            }
        }

        template <typename T>
        void fitAny(std::vector<std::vector<T>> data,
                    std::vector<std::vector<int>> labels) {

            int num_features = data[0].size();

            for(int i = 0; i < num_features; i++){
                std::vector<T> feature_vec;
                std::transform(data.begin(), data.end(), std::back_inserter(feature_vec), 
                    [i](auto const& sample) { return sample[i]; });
                
                _quartiles.push_back(std::make_tuple(calcQuartile(feature_vec, Quartile::FIRST), calcQuartile(feature_vec, Quartile::THIRD)));
            }

            lable_data(data, _labels);
        };

        template <typename T>
        std::vector<int> predictAny(T data) {
            if(std::any_of(data.begin(), data.end(), [this](auto const& sample) { return sample.size() != _quartiles.size(); })) {
                throw std::invalid_argument("Passed data has different number of features than the model was trained on.");
            }
            std::vector<int> labels = {};
            lable_data(data, labels);
            return labels;
        };

    public:
        void fit(std::vector<std::vector<float>> data,
                 std::vector<std::vector<int>> labels = {}) override {
                    fitAny(data, labels);
                };
        void fit(std::vector<std::vector<int>> data,
                 std::vector<std::vector<int>> labels = {}) override {
                    fitAny(data, labels);
                };
    
        std::vector<int> predict(std::vector<std::vector<float>> data) override {
            return predictAny(data);
        };
        std::vector<int> predict(std::vector<std::vector<int>> data) override {
            return predictAny(data);
        };
};