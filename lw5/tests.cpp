#include <gtest/gtest.h>

#include "allocator.hpp"
#include "stack_iterator.hpp"

TEST(StackTest, PushElements) {
    My_stack<int, Allocator<Node<int>>> stack;
    stack.push(5);
    stack.push(10);
    stack.push(15);

    ASSERT_EQ(stack.size(), 3);
}

TEST(StackTest, TopTest) {
    My_stack<int, Allocator<Node<int>>> stack;
    stack.push(5);
    stack.push(10);
    stack.push(15);

    ASSERT_EQ(stack.top(), 15);
}

TEST(StackTest, PopTest) {
    My_stack<int, Allocator<Node<int>>> stack;
    stack.push(15);
    stack.push(10);
    stack.push(5);
    stack.pop();
    stack.pop();
    ASSERT_EQ(stack.size(), 1);
}

TEST(StackTest, IteratorTest1) {
    My_stack<int, Allocator<Node<int>>> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    int expected_output = 3;
    for (auto it = stack.begin(); it != stack.end(); ++it) {
        ASSERT_EQ(*it, expected_output--);
    }
}

TEST(StackTest, IteratorTest2) {
    My_stack<int, Allocator<Node<int>>> stack;
    stack.push(5);
    stack.push(11);
    stack.push(15);

    int expected_output = 825;
    int ans = 1;
    for (auto it = stack.begin(); it != stack.end(); ++it) {
        ans *= *it;
    }
    ASSERT_EQ(ans, expected_output);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}