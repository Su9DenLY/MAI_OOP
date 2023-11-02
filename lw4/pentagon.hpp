#ifndef PENTAGON_HPP
#define PENTAGON_HPP

#define POINT_COUNT_PENTAGON 5

#include "figure.hpp"

template <std::floating_point T>

class Pentagon final : public Figure<T> {
protected:
    void output(std::ostream &os) const noexcept override {
        for (int i = 0; i < POINT_COUNT_PENTAGON; ++i) {
            os << coordinates[i] << " ";
        }
    }

    void input(std::istream &is) override {
        for (int i = 0; i < POINT_COUNT_PENTAGON; ++i) {
            is >> coordinates[i];
        }

        if (!(this->check())) {
            throw std::invalid_argument("This figure is not convex");
        }
    }

private:
    Point<T> coordinates[5];

public:
    bool check() const {
        bool sign = false;
        for (int i = 0; i < POINT_COUNT_PENTAGON; ++i) {
            Point<T> v1(coordinates[(i + 1) % POINT_COUNT_PENTAGON].get_x() - coordinates[i].get_x(),
                        coordinates[(i + 1) % POINT_COUNT_PENTAGON].get_y() - coordinates[i].get_y());
            Point<T> v2(coordinates[(i + 2) % POINT_COUNT_PENTAGON].get_x() - coordinates[(i + 1) % POINT_COUNT_PENTAGON].get_x(),
                        coordinates[(i + 2) % POINT_COUNT_PENTAGON].get_y() - coordinates[(i + 1) % POINT_COUNT_PENTAGON].get_y());
            T cross_product = v1.get_x() * v2.get_y() - v1.get_y() * v2.get_x();
            if (i == 0) {
                sign = cross_product > 0;
            } else if ((cross_product > 0) != sign) {
                return false;
            }
        }
        return true;
    }

    Pentagon() = default;
    ~Pentagon() = default;

    Pentagon(const Point<T> &p0, const Point<T> &p1, const Point<T> &p2, const Point<T> &p3, const Point<T> &p4) {
        coordinates[0] = p0;
        coordinates[1] = p1;
        coordinates[2] = p2;
        coordinates[3] = p3;
        coordinates[4] = p4;

        if (!(this->check())) {
            throw std::invalid_argument("This figure is not convex");
        }
    }

    explicit operator double() const noexcept override {
        return this->square();
    }

    friend std::ostream &operator<<(std::ostream &os, const Pentagon<T> &obj) {
        obj.output(os);
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Pentagon<T> &obj) {
        obj.input(is);
        return is;
    }

    bool operator==(const Pentagon<T> &other) const {
        return (*this).square() == other.square();
    }

    bool operator!=(const Pentagon<T> &other) const {
        return !(*this == other);
    }

    T square() const noexcept override {
        T Square = 0.0;

        for (int i = 0; i < POINT_COUNT_PENTAGON; ++i) {
            int j = (i + 1) % POINT_COUNT_PENTAGON;
            Square += (coordinates[i].get_x() + coordinates[j].get_x()) * (coordinates[i].get_y() - coordinates[j].get_y());
        }

        Square = fabs(Square) * 0.5;
        return Square;
    }

    Point<T> center() const noexcept override {
        T x_center = 0.0, y_center = 0.0;
        for (int i = 0; i < POINT_COUNT_PENTAGON; ++i) {
            x_center += coordinates[i].get_x();
            y_center += coordinates[i].get_y();
        }

        return Point<T>(x_center * 0.2, y_center * 0.2);
    }
};

#endif