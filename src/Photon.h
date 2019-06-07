//
// Created by Philipp on 07/06/2019.
//

#ifndef LENSESIM_PHOTON_H
#define LENSESIM_PHOTON_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstddef> // size_t

#include "Object.h"

class Photon : public Object {

public:

    explicit Photon(float posX, float posY) {
        shape.setFillColor(sf::Color(255, 255, 255, 75));
        shape.setPosition(posX, posY);
    }

    void draw(sf::RenderWindow& window) override {
        auto pos = shape.getPosition();
        auto windowSize = window.getSize();
        if (pos.x < 0 || pos.y < 0 || pos.x > windowSize.x || pos.y > windowSize.y) {
            return;
        }
        window.draw(shape);
    }


private:

    sf::CircleShape shape = sf::CircleShape(1, 3);

};


#endif //LENSESIM_Photon_H
