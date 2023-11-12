#ifndef POINT_HPP
#define POINT_HPP

#include <cmath>
#include <iostream>

template <std::floating_point T>

class Point {
private:
    T x;
    T y;

public:
    Point() = default;
    Point(T x, const T &y) {
        this->x = std::move(x);
        this->y = std::move(y);
    }

    T get_x() const noexcept {
        return x;
    }

    T get_y() const noexcept {
        return y;
    }

    friend std::ostream &operator<<(std::ostream &os, const Point &obj) {
        os << "(" << obj.x << ", " << obj.y << ")";
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Point &obj) {
        is >> obj.x >> obj.y;
        return is;
    }

    bool operator==(const Point &other) const noexcept {
        return (this->x == other.x) && (this->y == other.y);
    }

    bool operator!=(const Point &other) const noexcept {
        return !(*this == other);
    }
};

template <std::floating_point T>
T distance(const Point<T> first, const Point<T> second) noexcept {
    return sqrt(pow(second.get_x() - first.get_x(), 2) + pow(second.get_y() - first.get_y(), 2));
}

#endif