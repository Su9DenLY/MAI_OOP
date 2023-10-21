#include "rhomb.hpp"

#define POINT_COUNT 4

bool Rhomb::check() const {
    double side1 = distance(coordinates[0], coordinates[1]);
    double side2 = distance(coordinates[1], coordinates[2]);
    double side3 = distance(coordinates[2], coordinates[3]);
    double side4 = distance(coordinates[3], coordinates[0]);

    return (side1 == side2) && (side2 == side3) && (side3 == side4);
}

Rhomb::Rhomb(const Point &p0, const Point &p1, const Point &p2, const Point &p3) {
    coordinates[0] = p0;
    coordinates[1] = p1;
    coordinates[2] = p2;
    coordinates[3] = p3;
    if (!(this->check())) {
        throw std::invalid_argument("This figure is not a rhomb");
    }
}

void Rhomb::output(std::ostream &os) const noexcept {
    for (int i = 0; i < POINT_COUNT; ++i) {
        os << coordinates[i] << " ";
    }
}

void Rhomb::input(std::istream &is) {
    for (int i = 0; i < POINT_COUNT; ++i) {
        is >> coordinates[i];
    }

    if (!(this->check())) {
        throw std::invalid_argument("This figure is not a rhomb");
    }
}

Rhomb::Rhomb(const Rhomb &other) {
    for (int i = 0; i < POINT_COUNT; ++i) {
        this->coordinates[i] = other.coordinates[i];
    }
}

Rhomb::Rhomb(Rhomb &&other) noexcept {
    for (int i = 0; i < POINT_COUNT; ++i) {
        this->coordinates[i] = other.coordinates[i];
    }
}

Rhomb &Rhomb::operator=(const Rhomb &other) {
    for (int i = 0; i < POINT_COUNT; ++i) {
        this->coordinates[i] = other.coordinates[i];
    }

    return *this;
}

Rhomb &Rhomb::operator=(Rhomb &&other) {
    for (int i = 0; i < POINT_COUNT; ++i) {
        this->coordinates[i] = other.coordinates[i];
    }

    return *this;
}

Rhomb::operator double() const noexcept {
    return this->square();
}

std::ostream &operator<<(std::ostream &os, const Rhomb &obj) {
    obj.output(os);
    return os;
}

std::istream &operator>>(std::istream &is, Rhomb &obj) {
    obj.input(is);
    return is;
}

bool Rhomb::operator==(const Rhomb &other) const {
    return (*this).square() == other.square();
}

bool Rhomb::operator!=(const Rhomb &other) const {
    return !(*this == other);
}

double Rhomb::square() const noexcept {
    return distance(coordinates[0], coordinates[2]) * distance(coordinates[1], coordinates[3]) * 0.5;
}

Point Rhomb::center() const noexcept {
    double x_center = 0.0, y_center = 0.0;
    for (int i = 0; i < POINT_COUNT; ++i) {
        x_center += coordinates[i].get_x();
        y_center += coordinates[i].get_y();
    }

    return Point(x_center * 0.25, y_center * 0.25);
}