//
// Created by Lars on 16/06/2019.
//

#ifndef LENSESIM_LINE_H
#define LENSESIM_LINE_H

#include "Vec2.h"
#include <optional>

class Line {

public:

    Line() = delete;
    Line(double a1, double a2, double b1, double b2) : a(a1, a2), b(b1, b2) {}
    Line(const Vec2<>& p1, const Vec2<>& p2) : a(p1), b(p2) {}

    double sq_length() const;

    Vec2<> direction() const;

    std::optional<Vec2<>> intersection(const Line& other) const;

private:

    Vec2<> a;
    Vec2<> b;

};

#endif //LENSESIM_LINE_H
