//
// Created by Lars on 08/06/2019.
//

#ifndef LENSESIM_MIRROR_H
#define LENSESIM_MIRROR_H

#include <SFML/Graphics.hpp>
#include <utility> // forward
#include <iostream>

#include "Object.h"

template<typename ShapeType>
class Mirror : public Object {

public:

    template<typename... Args>
    explicit Mirror(Args... args) : shape(std::forward<Args>(args)...) {
        shape.setFillColor(sf::Color(0, 0, 0, 0));
        shape.setOutlineThickness(0.5f);
        shape.setOutlineColor(sf::Color(255, 255, 255, 255));
    }

    void set_line_thickness(float lt) {
        shape.setOutlineThickness(lt);
    }

    void draw(sf::RenderWindow& window) override {
        window.draw(shape);
    }


private:

    ShapeType shape;

};

#endif //LENSESIM_MIRROR_H
