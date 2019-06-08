//
// Created by Lars on 08/06/2019.
//

#ifndef LENSESIM_PHYSICSTRAIT_H
#define LENSESIM_PHYSICSTRAIT_H

#include "Object.h"
#include "Vec2.h"
#include "utils.h" // almost_equal

class PhysicsTrait : public Trait {

public:

    void update(double dt) override {
        // TODO: Runge-Kutta

        // we use implicit Euler for now
        if (!almost_equal(mass, 0.0)) {
            // update velocity based on force
            vel += (force / mass) * dt;
        }
        // update position based on velocity
        pos += vel * dt;
    }

    Vec2<> pos = {0, 0};
    Vec2<> vel = {0, 0};
    Vec2<> force = {0, 0};
    double mass = 0;
};

#endif //LENSESIM_PHYSICSTRAIT_H
