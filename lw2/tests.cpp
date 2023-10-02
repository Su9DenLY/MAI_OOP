#include <gtest/gtest.h>

#include "seven.hpp"

using namespace std;

TEST(constructor, constructor_without_arguments) {
    Seven object1;

    ASSERT_EQ(object1.get_size(), 0);

    ASSERT_THROW(object1.get_number(), domain_error);
}

TEST(constructor, constructor_with_string) {
    Seven object1("1234560");

    ASSERT_THROW(Seven object2("789"), invalid_argument);

    ASSERT_EQ(object1.get_size(), 7);
    ASSERT_EQ(object1.get_number(), "1234560");
}

TEST(constructor, constructor_with_initializer_list) {
    Seven object1{'1', '2', '3', '4', '5', '6', '0'};

    ASSERT_THROW(Seven object2{'7'}, invalid_argument);

    ASSERT_EQ(object1.get_size(), 7);
    ASSERT_EQ(object1.get_number(), "1234560");
}

TEST(constructor, constructor_with_capacity) {
    Seven object1(5);

    ASSERT_EQ(object1.get_size(), 0);
    ASSERT_EQ(object1.get_number(), "");

    ASSERT_NO_THROW(object1.get_number());
    ASSERT_THROW(Seven object2(-1), invalid_argument);
}

TEST(constructor, copy) {
    Seven object1;
    Seven object2("123456");
    Seven object3(object2);

    ASSERT_EQ(object2.get_number(), object3.get_number());
    ASSERT_EQ(object2.get_size(), object3.get_size());

    ASSERT_THROW(Seven object4(object1), domain_error);
}

TEST(constructor, move) {
    Seven object1("123456");
    Seven object2(move(object1));

    ASSERT_EQ(object2.get_number(), "123456");
    ASSERT_EQ(object2.get_size(), 6);

    ASSERT_EQ(object1.get_size(), 0);

    ASSERT_THROW(object1.get_number(), domain_error);
}

TEST(assignment, copy) {
    Seven object1;
    Seven object2("123456");
    Seven object3;

    object3 = object2;

    ASSERT_EQ(object2.get_number(), object3.get_number());

    ASSERT_THROW(object3 = object1, domain_error);
}

TEST(assignment, move) {
    Seven object1("123456");
    Seven object2;
    object2 = move(object1);

    ASSERT_EQ(object2.get_number(), "123456");
    ASSERT_EQ(object2.get_size(), 6);

    ASSERT_EQ(object1.get_size(), 0);

    ASSERT_THROW(object1.get_number(), domain_error);
}

TEST(methods, get_size) {
    Seven object1;
    Seven object2("123");

    ASSERT_EQ(object1.get_size(), 0);
    ASSERT_EQ(object2.get_size(), 3);
}

TEST(methods, get_number) {
    Seven object1;
    Seven object2("123");

    ASSERT_THROW(object1.get_number(), domain_error);

    ASSERT_EQ(object2.get_size(), 3);
}

TEST(output, output) {
    Seven object1;

    ASSERT_THROW(cout << object1, domain_error);
}

TEST(comparison_operators, equal) {
    Seven object1;
    Seven object2("1234");
    Seven object3("1234");
    Seven object4("12345");

    ASSERT_TRUE(object2 == object3);
    ASSERT_TRUE(object3 == object2);

    ASSERT_FALSE(object2 == object4);
    ASSERT_FALSE(object4 == object2);

    ASSERT_THROW(object1 == object4, domain_error);
    ASSERT_THROW(object4 == object1, domain_error);
}

TEST(comparison_operators, no_equal) {
    Seven object1;
    Seven object2("1234");
    Seven object3("1234");
    Seven object4("12345");

    ASSERT_TRUE(object2 != object4);
    ASSERT_TRUE(object4 != object2);

    ASSERT_FALSE(object2 != object3);
    ASSERT_FALSE(object3 != object2);

    ASSERT_THROW(object1 != object3, domain_error);
    ASSERT_THROW(object3 != object1, domain_error);
}

TEST(comparison_operators, more) {
    Seven object1;
    Seven object2("1234");
    Seven object3("1234");
    Seven object4("12345");

    ASSERT_TRUE(object4 > object2);

    ASSERT_FALSE(object2 > object3);
    ASSERT_FALSE(object3 > object2);
    ASSERT_FALSE(object3 > object4);

    ASSERT_THROW(object1 > object3, domain_error);
    ASSERT_THROW(object3 > object1, domain_error);
}

TEST(comparison_operators, less_) {
    Seven object1;
    Seven object2("1234");
    Seven object3("1234");
    Seven object4("12345");

    ASSERT_TRUE(object2 < object4);

    ASSERT_FALSE(object2 < object3);
    ASSERT_FALSE(object3 < object2);
    ASSERT_FALSE(object4 < object2);

    ASSERT_THROW(object1 < object3, domain_error);
    ASSERT_THROW(object3 < object1, domain_error);
}

TEST(comparison_operators, less_or_equal) {
    Seven object1;
    Seven object2("1234");
    Seven object3("1234");
    Seven object4("12345");

    ASSERT_TRUE(object4 <= object4);
    ASSERT_TRUE(object2 <= object3);
    ASSERT_TRUE(object3 <= object2);

    ASSERT_FALSE(object4 <= object2);

    ASSERT_THROW(object1 <= object3, domain_error);
    ASSERT_THROW(object3 <= object1, domain_error);
}

TEST(comparison_operators, more_or_equal) {
    Seven object1;
    Seven object2("1234");
    Seven object3("1234");
    Seven object4("12345");

    ASSERT_TRUE(object4 >= object4);
    ASSERT_TRUE(object2 >= object3);
    ASSERT_TRUE(object3 >= object2);

    ASSERT_FALSE(object2 >= object4);

    ASSERT_THROW(object1 >= object3, domain_error);
    ASSERT_THROW(object3 >= object1, domain_error);
}

TEST(arithmetic_operators, addition) {
    Seven object1;
    Seven object2("12345654321");
    Seven object3("12345632");
    Seven object4("0");

    ASSERT_EQ((object2 + object3).get_number(), "12361333253");
    ASSERT_EQ((object3 + object2).get_number(), "12361333253");

    ASSERT_EQ((object2 + object4).get_number(), "12345654321");
    ASSERT_EQ((object4 + object2).get_number(), "12345654321");

    ASSERT_THROW(object1 + object3, domain_error);
    ASSERT_THROW(object3 + object1, domain_error);
}

TEST(arithmetic_operators, substraction) {
    Seven object1;
    Seven object2("12345654321");
    Seven object3("12345632");
    Seven object4("0");

    ASSERT_EQ((object2 - object3).get_number(), "12333305356");
    ASSERT_EQ((object2 - object4).get_number(), "12345654321");

    ASSERT_THROW((object3 - object2).get_number(), logic_error);

    ASSERT_THROW(object1 - object3, domain_error);
    ASSERT_THROW(object3 - object1, domain_error);
}

TEST(arithmetic_operations_with_assignment, addition) {
    Seven object1;
    Seven object2("12345654321");
    Seven object3("12345632");
    Seven object4("0");

    ASSERT_EQ((object3 += object2).get_number(), "12361333253");

    ASSERT_EQ((object2 += object4).get_number(), "12345654321");
    ASSERT_EQ((object4 += object2).get_number(), "12345654321");

    ASSERT_THROW(object1 += object3, domain_error);
    ASSERT_THROW(object3 += object1, domain_error);
}

TEST(arithmetic_operations_with_assignment, substraction) {
    Seven object1;
    Seven object2("12345654321");
    Seven object3("12345632");
    Seven object4("0");

    ASSERT_EQ((object2 -= object3).get_number(), "12333305356");
    ASSERT_EQ((object3 -= object3).get_number(), "0");

    ASSERT_THROW((object4 -= object2).get_number(), logic_error);

    ASSERT_THROW(object1 -= object3, domain_error);
    ASSERT_THROW(object3 -= object1, domain_error);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}