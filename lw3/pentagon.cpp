#include "pentagon.hpp"

#define POINT_COUNT 5

bool Pentagon::check() const {
    bool sign = false;
    for (int i = 0; i < POINT_COUNT; ++i) {
        Point v1(coordinates[(i + 1) % POINT_COUNT].get_x() - coordinates[i].get_x(), coordinates[(i + 1) % POINT_COUNT].get_y() - coordinates[i].get_y());
        Point v2(coordinates[(i + 2) % POINT_COUNT].get_x() - coordinates[(i + 1) % POINT_COUNT].get_x(),
                 coordinates[(i + 2) % POINT_COUNT].get_y() - coordinates[(i + 1) % POINT_COUNT].get_y());
        int cross_product = v1.get_x() * v2.get_y() - v1.get_y() * v2.get_x();
        if (i == 0) {
            sign = cross_product > 0;
        } else if ((cross_product > 0) != sign) {
            return false;
        }
    }
    return true;
}

Pentagon::Pentagon(const Point &p0, const Point &p1, const Point &p2, const Point &p3, const Point &p4) {
    coordinates[0] = p0;
    coordinates[1] = p1;
    coordinates[2] = p2;
    coordinates[3] = p3;
    coordinates[4] = p4;

    if (!(this->check())) {
        throw std::invalid_argument("This figure is not convex");
    }
}

void Pentagon::output(std::ostream &os) const noexcept {
    for (int i = 0; i < POINT_COUNT; ++i) {
        os << coordinates[i] << " ";
    }
}

void Pentagon::input(std::istream &is) noexcept {
    for (int i = 0; i < POINT_COUNT; ++i) {
        is >> coordinates[i];
    }

    if (!(this->check())) {
        throw std::invalid_argument("This figure is not convex");
    }
}

Pentagon::Pentagon(const Pentagon &other) {
    for (int i = 0; i < POINT_COUNT; ++i) {
        this->coordinates[i] = other.coordinates[i];
    }
}

Pentagon::Pentagon(Pentagon &&other) noexcept {
    for (int i = 0; i < POINT_COUNT; ++i) {
        this->coordinates[i] = other.coordinates[i];
    }
}

Pentagon &Pentagon::operator=(const Pentagon &other) {
    for (int i = 0; i < POINT_COUNT; ++i) {
        this->coordinates[i] = other.coordinates[i];
    }

    return *this;
}

Pentagon &Pentagon::operator=(Pentagon &&other) {
    for (int i = 0; i < POINT_COUNT; ++i) {
        this->coordinates[i] = other.coordinates[i];
    }

    return *this;
}

Pentagon::operator double() const noexcept {
    return this->square();
}

std::ostream &operator<<(std::ostream &os, const Pentagon &obj) {
    obj.output(os);
    return os;
}

std::istream &operator>>(std::istream &is, Pentagon &obj) {
    obj.input(is);
    return is;
}

bool Pentagon::operator==(const Pentagon &other) const {
    return (*this).square() == other.square();
}

bool Pentagon::operator!=(const Pentagon &other) const {
    return !(*this == other);
}

double Pentagon::square() const noexcept {
    double Square = 0.0;

    for (int i = 0; i < POINT_COUNT; ++i) {
        int j = (i + 1) % POINT_COUNT;
        Square += (coordinates[i].get_x() + coordinates[j].get_x()) * (coordinates[i].get_y() - coordinates[j].get_y());
    }

    Square = fabs(Square) * 0.5;
    return Square;
}

Point Pentagon::center() const noexcept {
    double x_center = 0.0, y_center = 0.0;
    for (int i = 0; i < POINT_COUNT; ++i) {
        x_center += coordinates[i].get_x();
        y_center += coordinates[i].get_y();
    }

    return Point(x_center * 0.2, y_center * 0.2);
}