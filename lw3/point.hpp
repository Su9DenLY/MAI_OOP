#ifndef POINT_HPP
#define POINT_HPP

#include <cmath>
#include <exception>
#include <iostream>

class Point {
private:
    double x;
    double y;

public:
    Point();
    Point(double x, double y);
    ~Point() = default;

    Point(const Point &other);
    Point(Point &&other) noexcept;
    Point &operator=(const Point &other);
    Point &operator=(Point &&other);

    double get_x() const noexcept;
    double get_y() const noexcept;

    friend std::ostream &operator<<(std::ostream &os, const Point &obj);
    friend std::istream &operator>>(std::istream &, Point &obj);

    bool operator==(const Point &other) const noexcept;
    bool operator!=(const Point &other) const noexcept;
};

double distance(const Point first, const Point second) noexcept;

#endif