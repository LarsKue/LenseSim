//
// Created by Lars on 16/06/2019.
//

#include "Line.h"
#include <cmath>

#include "utils.h"

double Line::sq_length() const {
    return a.sq_distance_to(b);
}

Vec2<> Line::direction() const {
    return b - a;
}

std::optional<Vec2<>> Line::intersection(const Line& other) const {
    // compare: https://stackoverflow.com/a/565282/9746273
    Vec2<> p = a;
    Vec2<> q = other.a;
    Vec2<> r = direction();
    Vec2<> s = direction();
    double rxs = r.cross_product(s);
    if (almost_equal(rxs, 0.0)) {
        // lines are collinear or parallel, and may barely intersect, but we ignore this collision
        return {};
    }
    auto qmp = (q - p);
    double t = qmp.cross_product(s) / rxs;
    double u = qmp.cross_product(r) / rxs;
    if (t >= 0 && t <= 1 && u >= 0 && u <= 1) {
        // the lines intersect at p + tr = q + us
        return p + t * r;
    }
    return {};
}
