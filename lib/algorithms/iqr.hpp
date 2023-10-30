#include "../algorithm.h"
#include <concepts>


class IQR : public Algorithm {
    private:
        std::vector<std::tuple<float, float>> _quartiles;

        template <typename T>
        void fitAny(T data,
                    std::vector<std::vector<int>> labels) {
            int elements = data.size();
            int num_features = data[0].size();

            for(int i = 0; i < num_features; i++){
                std::vector<T> feature_vec;
                std::transform(data.begin(), data.end(), std::back_inserter(feature_vec), 
                    [i](auto const& inner) { return inner[i]; });
                    
                
            }
        };

        template <typename T>
        void predictAny(T data) {

        };

    public:
        void fit(std::vector<std::vector<float>> data,
                 std::vector<std::vector<int>> labels) override {
                    fitAny(data, labels);
                };
        void fit(std::vector<std::vector<int>> data,
                 std::vector<std::vector<int>> labels) override {
                    fitAny(data, labels);
                };
    
        void predict(std::vector<std::vector<float>> data) override {
            predictAny(data);
        };
        void predict(std::vector<std::vector<int>> data) override {
            predictAny(data);
        };
};