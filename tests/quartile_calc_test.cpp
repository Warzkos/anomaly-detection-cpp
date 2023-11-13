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