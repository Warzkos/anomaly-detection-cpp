#include <gtest/gtest.h>
#include <memory>
#include "../lib/utils/distance.h"
#include "../lib/utils/distances/euclidean.h"
#include "../lib/utils/distances/chebyshev.h"
#include "../lib/utils/distances/manhattan.h"
#include "../lib/utils/distances/minkowski.h"

class EuclideanDistanceTest : public ::testing::Test {
protected:
    void SetUp() override {
        distance = std::make_unique<Euclidean>();
    }
public:
    std::unique_ptr<Distance> distance;
};

TEST_F(EuclideanDistanceTest, calculateDistance_2dIntegerPoints) {
    std::vector<int> p1 = {0, 0};
    std::vector<int> p2 = {3, 4};
    double result = distance -> calculateDistance(p1, p2);
    ASSERT_DOUBLE_EQ(result, 5.0);
}

TEST_F(EuclideanDistanceTest, calculateDistance_3dIntegerPoints) {
    std::vector<int> p1 = {0, 0, 0};
    std::vector<int> p2 = {3, 4, 5};
    double result = distance -> calculateDistance(p1, p2);
    ASSERT_DOUBLE_EQ(result, std::sqrt(50));
}

TEST_F(EuclideanDistanceTest, calculateDistance_2dDoublePoints) {
    std::vector<double> p1 = {0.0, -0.5};
    std::vector<double> p2 = {3.0, 3.5};
    double result = distance -> calculateDistance(p1, p2);
    ASSERT_DOUBLE_EQ(result, 5.0);
}

TEST_F(EuclideanDistanceTest, calculateDistance_3dDoublePoints) {
    std::vector<double> p1 = {0.0, -0.5, 3.0};
    std::vector<double> p2 = {3.0, 3.5, -2.0};
    double result = distance -> calculateDistance(p1, p2);
    ASSERT_DOUBLE_EQ(result, std::sqrt(50));
}

class ChebyshevDistanceTest : public ::testing::Test {
protected:
    void SetUp() override {
        distance = std::make_unique<Chebyshev>();
    }
public:
    std::unique_ptr<Distance> distance;
};

TEST_F(ChebyshevDistanceTest, calculateDistance_2dIntegerPoints) {
    std::vector<int> p1 = {0, 0};
    std::vector<int> p2 = {3, 4};
    double result = distance -> calculateDistance(p1, p2);
    ASSERT_DOUBLE_EQ(result, 4.0);
}

TEST_F(ChebyshevDistanceTest, calculateDistance_3dIntegerPoints) {
    std::vector<int> p1 = {0, 0, 0};
    std::vector<int> p2 = {3, 4, 5};
    double result = distance -> calculateDistance(p1, p2);
    ASSERT_DOUBLE_EQ(result, 5.0);
}

TEST_F(ChebyshevDistanceTest, calculateDistance_2dDoublePoints) {
    std::vector<double> p1 = {0.0, -0.5};
    std::vector<double> p2 = {3.0, 3.5};
    double result = distance -> calculateDistance(p1, p2);
    ASSERT_DOUBLE_EQ(result, 4.0);
}

TEST_F(ChebyshevDistanceTest, calculateDistance_3dDoublePoints) {
    std::vector<double> p1 = {0.0, -0.5, 3.0};
    std::vector<double> p2 = {3.0, 3.5, -2.0};
    double result = distance -> calculateDistance(p1, p2);
    ASSERT_DOUBLE_EQ(result, 5.0);
}

class ManhattanDistanceTest : public ::testing::Test {
protected:
    void SetUp() override {
        distance = std::make_unique<Manhattan>();
    }
public:
    std::unique_ptr<Distance> distance;
};

TEST_F(ManhattanDistanceTest, calculateDistance_2dIntegerPoints) {
    std::vector<int> p1 = {0, 0};
    std::vector<int> p2 = {3, 4};
    double result = distance -> calculateDistance(p1, p2);
    ASSERT_DOUBLE_EQ(result, 7.0);
}

TEST_F(ManhattanDistanceTest, calculateDistance_3dIntegerPoints) {
    std::vector<int> p1 = {0, 0, 0};
    std::vector<int> p2 = {3, 4, 5};
    double result = distance -> calculateDistance(p1, p2);
    ASSERT_DOUBLE_EQ(result, 12.0);
}

TEST_F(ManhattanDistanceTest, calculateDistance_2dDoublePoints) {
    std::vector<double> p1 = {0.0, -0.5};
    std::vector<double> p2 = {3.0, 3.5};
    double result = distance -> calculateDistance(p1, p2);
    ASSERT_DOUBLE_EQ(result, 7.0);
}

TEST_F(ManhattanDistanceTest, calculateDistance_3dDoublePoints) {
    std::vector<double> p1 = {0.0, -0.5, 3.0};
    std::vector<double> p2 = {3.0, 3.5, -2.0};
    double result = distance -> calculateDistance(p1, p2);
    ASSERT_DOUBLE_EQ(result, 12.0);
}

class MinkowskiDistanceDefaultOrderTest : public ::testing::Test {
protected:
    void SetUp() override {
        distance = std::make_unique<Minkowski>();
    }
public:
    std::unique_ptr<Distance> distance;
};

TEST_F(MinkowskiDistanceDefaultOrderTest, calculateDistance_2dIntegerPoints) {
    std::vector<int> p1 = {0, 0};
    std::vector<int> p2 = {3, 4};
    double result = distance -> calculateDistance(p1, p2);
    ASSERT_DOUBLE_EQ(result, 5.0);
}

TEST_F(MinkowskiDistanceDefaultOrderTest, calculateDistance_3dIntegerPoints) {
    std::vector<int> p1 = {0, 0, 0};
    std::vector<int> p2 = {3, 4, 5};
    double result = distance -> calculateDistance(p1, p2);
    ASSERT_DOUBLE_EQ(result, std::sqrt(50));
}

TEST_F(MinkowskiDistanceDefaultOrderTest, calculateDistance_2dDoublePoints) {
    std::vector<double> p1 = {0.0, -0.5};
    std::vector<double> p2 = {3.0, 3.5};
    double result = distance -> calculateDistance(p1, p2);
    ASSERT_DOUBLE_EQ(result, 5.0);
}

TEST_F(MinkowskiDistanceDefaultOrderTest, calculateDistance_3dDoublePoints) {
    std::vector<double> p1 = {0.0, -0.5, 3.0};
    std::vector<double> p2 = {3.0, 3.5, -2.0};
    double result = distance -> calculateDistance(p1, p2);
    ASSERT_DOUBLE_EQ(result, std::sqrt(50));
}

class MinkowskiDistance3rdOrderTest : public ::testing::Test {
protected:
    void SetUp() override {
        distance = std::make_unique<Minkowski>(3.0);
    }
public:
    std::unique_ptr<Distance> distance;
};

TEST_F(MinkowskiDistance3rdOrderTest, calculateDistance_2dIntegerPoints) {
    std::vector<int> p1 = {0, 0};
    std::vector<int> p2 = {3, 4};
    double result = distance -> calculateDistance(p1, p2);
    ASSERT_DOUBLE_EQ(result, std::pow(91.0, 1.0/3.0));
}

TEST_F(MinkowskiDistance3rdOrderTest, calculateDistance_3dIntegerPoints) {
    std::vector<int> p1 = {0, 0, 0};
    std::vector<int> p2 = {3, 4, 5};
    double result = distance -> calculateDistance(p1, p2);
    ASSERT_DOUBLE_EQ(result, 6.0);
}

TEST_F(MinkowskiDistance3rdOrderTest, calculateDistance_2dDoublePoints) {
    std::vector<double> p1 = {0.0, -0.5};
    std::vector<double> p2 = {3.0, 3.5};
    double result = distance -> calculateDistance(p1, p2);
    ASSERT_DOUBLE_EQ(result, std::pow(91.0, 1.0/3.0));
}

TEST_F(MinkowskiDistance3rdOrderTest, calculateDistance_3dDoublePoints) {
    std::vector<double> p1 = {0.0, -0.5, 3.0};
    std::vector<double> p2 = {3.0, 3.5, -2.0};
    double result = distance -> calculateDistance(p1, p2);
    ASSERT_DOUBLE_EQ(result, 6.0);
}