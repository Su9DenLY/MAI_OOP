#ifndef FIGURE_HPP
#define FIGURE_HPP

#include "point.hpp"

class Figure {
public:
    Figure() = default;

    virtual void output(std::ostream& os) const noexcept = 0;
    virtual void input(std::istream& is) noexcept = 0;

    virtual ~Figure() noexcept = default;
    virtual double square() const noexcept = 0;
    virtual Point center() const noexcept = 0;

    explicit virtual operator double() const noexcept = 0;

    friend std::ostream& operator<<(std::ostream& os, const Figure& figure) noexcept {
        figure.output(os);
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Figure& figure) {
        figure.input(is);
        return is;
    }
};

#endif