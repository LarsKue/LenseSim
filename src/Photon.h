//
// Created by Philipp on 07/06/2019.
//

#ifndef LENSESIM_PHOTON_H
#define LENSESIM_PHOTON_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstddef> // size_t

#include "Object.h"
#include "PhysicsTrait.h"

class Photon : public Object {

public:

    void init() override {
        Object::init();
        shape.setFillColor(sf::Color(255, 255, 255, 125));
        pt = addTrait<PhysicsTrait>();
        shape.setPosition(pt->pos.x, pt->pos.y);
    }

    void update(double dt) override {
        Object::update(dt);
        shape.setPosition(pt->pos.x, pt->pos.y);
    }

    void draw(sf::RenderWindow& window) override {
        Object::draw(window);
        auto windowSize = window.getSize();
        if (pt->pos.x < 0 || pt->pos.y < 0 || pt->pos.x > windowSize.x || pt->pos.y > windowSize.y) {
            return;
        }
        window.draw(shape);
    }


private:

    sf::CircleShape shape = sf::CircleShape(1, 3);
    PhysicsTrait* pt = nullptr;

};


#endif //LENSESIM_Photon_H
