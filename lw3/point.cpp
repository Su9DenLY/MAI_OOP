#include "point.hpp"

Point::Point() {
    x = y = 0;
}

Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
}

Point &Point::operator=(const Point &other) {
    this->x = other.x;
    this->y = other.y;

    return *this;
}

Point::Point(const Point &other) {
    this->x = other.x;
    this->y = other.y;
}

Point::Point(Point &&other) noexcept {
    this->x = other.x;
    this->y = other.y;

    other.x = 0;
    other.y = 0;
}

Point &Point::operator=(Point &&other) {
    this->x = other.x;
    this->y = other.y;

    other.x = 0;
    other.y = 0;

    return *this;
}

double Point::get_x() const noexcept {
    return x;
}

double Point::get_y() const noexcept {
    return y;
}

std::ostream &operator<<(std::ostream &os, const Point &obj) {
    os << "(" << obj.x << ", " << obj.y << ")";
    return os;
}

std::istream &operator>>(std::istream &is, Point &obj) {
    is >> obj.x >> obj.y;
    return is;
}

bool Point::operator==(const Point &other) const noexcept {
    return (this->x == other.x) && (this->y == other.y);
}

bool Point::operator!=(const Point &other) const noexcept {
    return !(*this == other);
}

double distance(Point first, Point second) noexcept {
    return sqrt(pow(second.get_x() - first.get_x(), 2) + pow(second.get_y() - first.get_y(), 2));
}