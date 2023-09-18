#include <gtest/gtest.h>
#include "count_ones.hpp"

TEST(test_01, basic_test_set) {
    ASSERT_TRUE(count_ones(2, 7) == 11);
}

TEST(test_02, basic_test_set) {
    ASSERT_TRUE(count_ones(0, 0) == 0);
}

TEST(test_03, basic_test_set) {
    ASSERT_TRUE(count_ones(0, -1) == -1);
}

TEST(test_04, basic_test_set) {
    ASSERT_TRUE(count_ones(-10, 10) == -1);
}

TEST(test_05, basic_test_set) {
    ASSERT_TRUE(count_ones(0, 1) == 1);
}

TEST(test_06, basic_test_set) {
    ASSERT_TRUE(count_ones(127, 127) == 7);
}

TEST(test_07, basic_test_set) {
    ASSERT_TRUE(count_ones(1022, 1024) == 20);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}