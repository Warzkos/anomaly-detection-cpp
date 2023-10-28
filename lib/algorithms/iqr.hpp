#include "../algorithm.h"

class IQR : public Algorithm {
    private:
        template <typename T, template <typename, typename = std::allocator<T>> class Container>
        void fit(Container<T> data,
                 Container<int> labels);

    public:
        void fit(std::vector<std::vector<float>> data,
                 std::vector<std::vector<int>> labels) override {
                    fit(data, labels);
                };
        void fit(std::vector<std::vector<int>> data,
                 std::vector<std::vector<int>> labels) override {
                    fit(data, labels);
                 };
    
        void predict(std::vector<std::vector<float>> data) override { };
        void predict(std::vector<std::vector<int>> data) override { };
};