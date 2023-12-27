#include <iostream>
#include <map>
#include <vector>

#include "allocator.hpp"
#include "stack_iterator.hpp"

int factorial(int n) {
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

int main() {
    std::map<int, int, std::less<>, Allocator<std::pair<const int, int>, 10>> myMapAllocator;
    for (int i = 0; i < 10; ++i) {
        myMapAllocator.emplace(i, factorial(i));
    }

    for (const auto& pair : myMapAllocator) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }

    Allocator<int, 10> allocator;
    int* ptr = allocator.allocate(3);

    for (int i = 0; i < 3; ++i) {
        ptr[i] = i;
    }

    int* new_ptr = allocator.allocate(6);

    for (int i = 0; i < 3; ++i) {
        std::cout << ptr[i] << " " << new_ptr[i] << std::endl;
    }

    My_stack<int, Allocator<Node<int>>> stack;

    stack.push(5);
    stack.push(10);
    stack.push(15);
    for (auto it = stack.begin(); it != stack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    while (!stack.empty()) {
        std::cout << stack.top() << " ";
        stack.pop();
    }

    return 0;
}