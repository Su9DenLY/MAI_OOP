#ifndef PENTAGON_HPP
#define PENTAGON_HPP

#include "figure.hpp"

class Pentagon final : public Figure {
private:
    Point coordinates[5];

public:
    bool check() const;

    Pentagon() = default;
    Pentagon(const Point &p0, const Point &p1, const Point &p2, const Point &p3, const Point &p4);
    ~Pentagon() = default;

    void output(std::ostream &os) const noexcept override;
    void input(std::istream &is) noexcept override;

    Pentagon(const Pentagon &other);
    Pentagon(Pentagon &&other) noexcept;
    Pentagon &operator=(const Pentagon &other);
    Pentagon &operator=(Pentagon &&other);

    explicit operator double() const noexcept override;

    friend std::ostream &operator<<(std::ostream &os, const Pentagon &obj);
    friend std::istream &operator>>(std::istream &is, Pentagon &obj);

    bool operator==(const Pentagon &other) const;
    bool operator!=(const Pentagon &other) const;

    double square() const noexcept override;
    Point center() const noexcept override;
};

#endif