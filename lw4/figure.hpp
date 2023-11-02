#ifndef FIGURE_HPP
#define FIGURE_HPP

#include <exception>

#include "point.hpp"

template <std::floating_point T>

class Figure {
protected:
    virtual void output(std::ostream& os) const noexcept = 0;
    virtual void input(std::istream& is) = 0;

public:
    Figure() = default;

    virtual ~Figure() noexcept = default;
    virtual T square() const noexcept = 0;
    virtual Point<T> center() const noexcept = 0;

    explicit virtual operator double() const noexcept = 0;

    friend std::ostream& operator<<(std::ostream& os, const Figure<T>& figure) noexcept {
        figure.output(os);
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Figure<T>& figure) {
        figure.input(is);
        return is;
    }
};

#endif