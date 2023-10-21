#include <gtest/gtest.h>

#include <iostream>

#include "array.hpp"
#include "figure.hpp"
#include "hexagon.hpp"
#include "pentagon.hpp"
#include "rhomb.hpp"

using namespace std;

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}