#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "figure.hpp"
#include "hexagon.hpp"
#include "pentagon.hpp"
#include "point.hpp"
#include "rhomb.hpp"

class Array final {
private:
    size_t len;
    size_t capacity;
    Figure **array;

    void reallocate(size_t capacity);

public:
    Array();
    Array(size_t len);
    Array(size_t len, size_t capacity);
    ~Array();

    Array(const Array &other);
    Array(Array &&other) noexcept;
    Array &operator=(const Array &other);
    Array &operator=(Array &&other);

    void push_back(Figure *elem);
    void pop_back();
    void remove(int index);
    void insert(Figure *elem, int index);

    Figure *operator[](int index);
    size_t length() const noexcept;
};

#endif