#ifndef HEXAGON_HPP
#define HEXAGON_HPP

#include "figure.hpp"

class Hexagon final : public Figure {
private:
    Point coordinates[5];

public:
    bool check() const;

    Hexagon() = default;
    Hexagon(const Point &p0, const Point &p1, const Point &p2, const Point &p3, const Point &p4, const Point &p5);
    ~Hexagon() = default;

    void output(std::ostream &os) const noexcept override;
    void input(std::istream &is) override;

    Hexagon(const Hexagon &other);
    Hexagon(Hexagon &&other) noexcept;
    Hexagon &operator=(const Hexagon &other);
    Hexagon &operator=(Hexagon &&other);

    explicit operator double() const noexcept override;

    friend std::ostream &operator<<(std::ostream &os, const Hexagon &obj);
    friend std::istream &operator>>(std::istream &is, Hexagon &obj);

    bool operator==(const Hexagon &other) const;
    bool operator!=(const Hexagon &other) const;

    double square() const noexcept override;
    Point center() const noexcept override;
};

#endif