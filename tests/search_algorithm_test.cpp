#include <gtest/gtest.h>
#include <memory>
#include <vector>

#include "../lib/utils/search_algorithm.h"
#include "../lib/utils/search_algorithm/bruteforce.h"
// #include "../lib/utils/search_algorithm/kdtree.h"

#include "../lib/utils/distance.h"
#include "../lib/utils/distances/euclidean.h"

// class SearchAlgorithmDoubleTest : public ::testing::Test {
// protected:
//     void SetUp() override {
//         distance = std::make_unique<Euclidean>();
//     }
// public:
//     std::unique_ptr<Distance> distance;
// };

class SearchAlgorithmIntTest : public ::testing::Test {
protected:
    void SetUp() override {
        data = {
            {0, 0},
            {4, 5},
            {3, 1},
            {1, 2},
            {2, 3},
            {5, 4},
        };

        k_nearest_ans = {
            {{0, 0}, 3.61+3.16+2.24},
            {{4, 5}, 1.41+2.83+4.12},
            {{3, 1}, 2.24+2.24+3.16},
            {{1, 2}, 1.41+2.24+2.24},
            {{2, 3}, 1.41+2.24+2.83},
            {{5, 4}, 1.41+3.16+3.61},
        };

        distance = std::make_shared<Euclidean>();

        k=3;
    }
public:
    std::shared_ptr<Distance> distance;
    std::vector<std::vector<int>> data;
    std::vector<std::pair<std::vector<int>, double>> k_nearest_ans;
    int k;
};

TEST_F(SearchAlgorithmIntTest, BruteForceSearchKNearest) {
    auto searchAlgorithm = std::make_shared<BruteForce<int>>();
    searchAlgorithm->fit(data, distance);
    std::vector<std::pair<std::vector<int>, double>> k_nearest;
    searchAlgorithm->search_knearest(k_nearest, k);

    for (int i = 0; i < k_nearest.size(); i++) {
        EXPECT_EQ(k_nearest[i].first, k_nearest_ans[i].first);
        EXPECT_NEAR(k_nearest[i].second, k_nearest_ans[i].second, 0.01);
    }
}