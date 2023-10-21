#ifndef RHOMB_HPP
#define RHOMB_HPP

#include "figure.hpp"

class Rhomb final : public Figure {
private:
    Point coordinates[4];

public:
    bool check() const;

    Rhomb() = default;
    Rhomb(const Point &p0, const Point &p1, const Point &p2, const Point &p3);
    ~Rhomb() = default;

    void output(std::ostream &os) const noexcept override;
    void input(std::istream &is) override;

    Rhomb(const Rhomb &other);
    Rhomb(Rhomb &&other) noexcept;
    Rhomb &operator=(const Rhomb &other);
    Rhomb &operator=(Rhomb &&other);

    explicit operator double() const noexcept override;

    friend std::ostream &operator<<(std::ostream &os, const Rhomb &obj);
    friend std::istream &operator>>(std::istream &is, Rhomb &obj);

    bool operator==(const Rhomb &other) const;
    bool operator!=(const Rhomb &other) const;

    double square() const noexcept override;
    Point center() const noexcept override;
};

#endif