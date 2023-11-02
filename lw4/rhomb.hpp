#ifndef RHOMB_HPP
#define RHOMB_HPP

#define POINT_COUNT_RHOMB 4

#include "figure.hpp"

template <std::floating_point T>

class Rhomb final : public Figure<T> {
protected:
    void output(std::ostream &os) const noexcept override {
        for (int i = 0; i < POINT_COUNT_RHOMB; ++i) {
            os << coordinates[i] << " ";
        }
    }

    void input(std::istream &is) override {
        for (int i = 0; i < POINT_COUNT_RHOMB; ++i) {
            is >> coordinates[i];
        }

        if (!(this->check())) {
            throw std::invalid_argument("This figure is not a rhomb");
        }
    }

private:
    Point<T> coordinates[4];

public:
    bool check() const {
        T side1 = distance(coordinates[0], coordinates[1]);
        T side2 = distance(coordinates[1], coordinates[2]);
        T side3 = distance(coordinates[2], coordinates[3]);
        T side4 = distance(coordinates[3], coordinates[0]);

        return (side1 == side2) && (side2 == side3) && (side3 == side4);
    }

    Rhomb() = default;
    ~Rhomb() = default;

    Rhomb(const Point<T> &p0, const Point<T> &p1, const Point<T> &p2, const Point<T> &p3) {
        coordinates[0] = p0;
        coordinates[1] = p1;
        coordinates[2] = p2;
        coordinates[3] = p3;
        if (!(this->check())) {
            throw std::invalid_argument("This figure is not a rhomb");
        }
    }

    explicit operator double() const noexcept override {
        return this->square();
    }

    friend std::ostream &operator<<(std::ostream &os, const Rhomb<T> &obj) {
        obj.output(os);
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Rhomb<T> &obj) {
        obj.input(is);
        return is;
    }

    bool operator==(const Rhomb<T> &other) const {
        return this->square() == other.square();
    }

    bool operator!=(const Rhomb<T> &other) const {
        return !(*this == other);
    }

    T square() const noexcept override {
        return distance(coordinates[0], coordinates[2]) * distance(coordinates[1], coordinates[3]) * 0.5;
    }

    Point<T> center() const noexcept override {
        T x_center = 0.0, y_center = 0.0;
        for (int i = 0; i < POINT_COUNT_RHOMB; ++i) {
            x_center += coordinates[i].get_x();
            y_center += coordinates[i].get_y();
        }

        return Point<T>(x_center * 0.25, y_center * 0.25);
    }
};

#endif