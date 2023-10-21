#include <gtest/gtest.h>

#include <iostream>

#include "array.hpp"
#include "figure.hpp"
#include "hexagon.hpp"
#include "pentagon.hpp"
#include "rhomb.hpp"

using namespace std;

TEST(rhomb, equal) {
    Point p1(-7, 4), p2(-6, 7), p3(-5, 4), p4(-6, 1);
    Rhomb obj1(p1, p2, p3, p4);
    Rhomb obj2(p1, p2, p3, p4);

    ASSERT_TRUE(obj1 == obj2);
}

TEST(rhomb, notequal) {
    Point p1(-7, 4), p2(-6, 7), p3(-5, 4), p4(-6, 1);
    Rhomb obj1(p1, p2, p3, p4);
    Rhomb obj2(p1, p2, p3, p4);

    ASSERT_FALSE(obj1 != obj2);
}

TEST(rhomb, square) {
    Point p1(-7, 4), p2(-6, 7), p3(-5, 4), p4(-6, 1);
    Rhomb obj1(p1, p2, p3, p4);

    ASSERT_DOUBLE_EQ(obj1.square(), 6);
}

TEST(rhomb, center) {
    Point p1(-7, 4), p2(-6, 7), p3(-5, 4), p4(-6, 1);
    Rhomb obj1(p1, p2, p3, p4);

    Point temp(-6, 4);

    ASSERT_TRUE(obj1.center() == temp);
}

TEST(pentagon, equal) {
    Point p1(5, 2), p2(4, 4), p3(6, 6), p4(8, 4), p5(7, 2);
    Pentagon obj1(p1, p2, p3, p4, p5);
    Pentagon obj2(p1, p2, p3, p4, p5);

    ASSERT_TRUE(obj1 == obj2);
}

TEST(pentagon, notequal) {
    Point p1(5, 2), p2(4, 4), p3(6, 6), p4(8, 4), p5(7, 2);
    Pentagon obj1(p1, p2, p3, p4, p5);
    Pentagon obj2(p1, p2, p3, p4, p5);

    ASSERT_FALSE(obj1 != obj2);
}

TEST(pentagon, square) {
    Point p1(5, 2), p2(4, 4), p3(6, 6), p4(8, 4), p5(7, 2);
    Pentagon obj1(p1, p2, p3, p4, p5);

    ASSERT_DOUBLE_EQ(obj1.square(), 10);
}

TEST(pentagon, center) {
    Point p1(5, 2), p2(4, 4), p3(6, 6), p4(8, 4), p5(7, 2);
    Pentagon obj1(p1, p2, p3, p4, p5);

    Point temp(6, 3.6);

    ASSERT_TRUE(obj1.center() == temp);
}

TEST(hexagon, equal) {
    Point p1(-1, 0), p2(1, 0), p3(2, 2), p4(1, 4), p5(-1, 4), p6(-2, 2);
    Hexagon obj1(p1, p2, p3, p4, p5, p6);
    Hexagon obj2(p1, p2, p3, p4, p5, p6);
    ASSERT_TRUE(obj1 == obj2);
}

TEST(hexagon, notequal) {
    Point p1(-1, 0), p2(1, 0), p3(2, 2), p4(1, 4), p5(-1, 4), p6(-2, 2);
    Hexagon obj1(p1, p2, p3, p4, p5, p6);
    Hexagon obj2(p1, p2, p3, p4, p5, p6);

    ASSERT_FALSE(obj1 != obj2);
}

TEST(hexagon, square) {
    Point p1(-1, 0), p2(1, 0), p3(2, 2), p4(1, 4), p5(-1, 4), p6(-2, 2);
    Hexagon obj1(p1, p2, p3, p4, p5, p6);

    ASSERT_DOUBLE_EQ(obj1.square(), 12);
}

TEST(hexagon, center) {
    Point p1(-1, 0), p2(1, 0), p3(2, 2), p4(1, 4), p5(-1, 4), p6(-2, 2);
    Hexagon obj1(p1, p2, p3, p4, p5, p6);

    Point temp(0, 2);

    ASSERT_TRUE(obj1.center() == temp);
}

TEST(array, push_back) {
    Array array;
    Point p1(-1, 0), p2(1, 0), p3(2, 2), p4(1, 4), p5(-1, 4), p6(-2, 2);
    Hexagon obj1(p1, p2, p3, p4, p5, p6);
    array.push_back(&obj1);

    ASSERT_TRUE(array[0]->square() == obj1.square());
    ASSERT_TRUE(array[0]->center() == obj1.center());
}

TEST(array, remove) {
    Array array;
    Point p1(-1, 0), p2(1, 0), p3(2, 2), p4(1, 4), p5(-1, 4), p6(-2, 2);
    Hexagon obj1(p1, p2, p3, p4, p5, p6);
    array.push_back(&obj1);
    array.remove(0);

    ASSERT_TRUE(array.length() == 0);
}

TEST(array, pop_back) {
    Array array;
    Point p1(-1, 0), p2(1, 0), p3(2, 2), p4(1, 4), p5(-1, 4), p6(-2, 2);
    Hexagon obj1(p1, p2, p3, p4, p5, p6);
    array.push_back(&obj1);
    array.pop_back();

    ASSERT_TRUE(array.length() == 0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}