#include <gtest/gtest.h>
#include "../lib/utils/quartile_calculator.h"

TEST(QuartileCalculatorTest, calculateQuartiles_7IntegerVector) {
    std::vector<int> nums = {5, 7, 4, 4, 6, 2, 8};
    double q1 = QuartileCalculator::calcQuartile(nums, QuartileCalculator::FIRST);
    double q2 = QuartileCalculator::calcQuartile(nums, QuartileCalculator::SECOND);
    double q3 = QuartileCalculator::calcQuartile(nums, QuartileCalculator::THIRD);
    ASSERT_DOUBLE_EQ(q1, 4.0);
    ASSERT_DOUBLE_EQ(q2, 5.0);
    ASSERT_DOUBLE_EQ(q3, 7.0);
}

TEST(QuartileCalculatorTest, calculateQuartiles_8IntegerVector) {
    std::vector<int> nums = {5, 7, 4, 2, 4, 6, 2, 8};
    double q1 = QuartileCalculator::calcQuartile(nums, QuartileCalculator::FIRST);
    double q2 = QuartileCalculator::calcQuartile(nums, QuartileCalculator::SECOND);
    double q3 = QuartileCalculator::calcQuartile(nums, QuartileCalculator::THIRD);
    ASSERT_DOUBLE_EQ(q1, 3.0);
    ASSERT_DOUBLE_EQ(q2, 4.5);
    ASSERT_DOUBLE_EQ(q3, 6.5);
}

TEST(QuartileCalculatorTest, calculateQuartiles_9IntegerVector) {
    std::vector<int> nums = {5, 7, 4, 2, 5, 4, 6, 2, 8};
    double q1 = QuartileCalculator::calcQuartile(nums, QuartileCalculator::FIRST);
    double q2 = QuartileCalculator::calcQuartile(nums, QuartileCalculator::SECOND);
    double q3 = QuartileCalculator::calcQuartile(nums, QuartileCalculator::THIRD);
    ASSERT_DOUBLE_EQ(q1, 3.0);
    ASSERT_DOUBLE_EQ(q2, 5.0);
    ASSERT_DOUBLE_EQ(q3, 6.5);
}

TEST(QuartileCalculatorTest, calculateQuartiles_10IntegerVector) {
    std::vector<int> nums = {1, 3, 8, 4, 6, 3, 6, 7, 5, 8};
    double q1 = QuartileCalculator::calcQuartile(nums, QuartileCalculator::FIRST);
    double q2 = QuartileCalculator::calcQuartile(nums, QuartileCalculator::SECOND);
    double q3 = QuartileCalculator::calcQuartile(nums, QuartileCalculator::THIRD);
    ASSERT_DOUBLE_EQ(q1, 3.0);
    ASSERT_DOUBLE_EQ(q2, 5.5);
    ASSERT_DOUBLE_EQ(q3, 7.0);
}

class QuartileCalculatorFromDataTest : public ::testing::Test {
public:
    std::vector<std::vector<int>> data = {
        {5,5,5,1},
        {7,7,7,3},
        {4,4,4,8},
        {4,2,2,4},
        {6,4,5,6},
        {2,6,4,3},
        {8,2,6,6},
        {4,8,2,7},
        {5,5,8,5},
        {7,7,7,8}
    };
};

TEST_F(QuartileCalculatorFromDataTest, calculateQuartilesFromData_Feature0) {
    double q1 = QuartileCalculator::calcQuartile(data, 0, QuartileCalculator::FIRST);
    double q2 = QuartileCalculator::calcQuartile(data, 0, QuartileCalculator::SECOND);
    double q3 = QuartileCalculator::calcQuartile(data, 0, QuartileCalculator::THIRD);
    ASSERT_DOUBLE_EQ(q1, 4.0);
    ASSERT_DOUBLE_EQ(q2, 5.0);
    ASSERT_DOUBLE_EQ(q3, 7.0);
}

TEST_F(QuartileCalculatorFromDataTest, calculateQuartilesFromData_Feature1) {
    double q1 = QuartileCalculator::calcQuartile(data, 1, QuartileCalculator::FIRST);
    double q2 = QuartileCalculator::calcQuartile(data, 1, QuartileCalculator::SECOND);
    double q3 = QuartileCalculator::calcQuartile(data, 1, QuartileCalculator::THIRD);
    ASSERT_DOUBLE_EQ(q1, 4.0);
    ASSERT_DOUBLE_EQ(q2, 5.0);
    ASSERT_DOUBLE_EQ(q3, 7.0);
}

TEST_F(QuartileCalculatorFromDataTest, calculateQuartilesFromData_Feature2) {
    double q1 = QuartileCalculator::calcQuartile(data, 2, QuartileCalculator::FIRST);
    double q2 = QuartileCalculator::calcQuartile(data, 2, QuartileCalculator::SECOND);
    double q3 = QuartileCalculator::calcQuartile(data, 2, QuartileCalculator::THIRD);
    ASSERT_DOUBLE_EQ(q1, 4.0);
    ASSERT_DOUBLE_EQ(q2, 5.0);
    ASSERT_DOUBLE_EQ(q3, 7.0);
}

TEST_F(QuartileCalculatorFromDataTest, calculateQuartilesFromData_Feature3) {
    double q1 = QuartileCalculator::calcQuartile(data, 3, QuartileCalculator::FIRST);
    double q2 = QuartileCalculator::calcQuartile(data, 3, QuartileCalculator::SECOND);
    double q3 = QuartileCalculator::calcQuartile(data, 3, QuartileCalculator::THIRD);
    ASSERT_DOUBLE_EQ(q1, 3.0);
    ASSERT_DOUBLE_EQ(q2, 5.5);
    ASSERT_DOUBLE_EQ(q3, 7.0);
}