//
// Created by Lars on 07/06/2019.
//

#ifndef LENSESIM_LENSE_H
#define LENSESIM_LENSE_H

#include <SFML/Graphics.hpp>
#include <utility> // forward

template<typename ShapeType>
class Lense {

public:

    template<typename... Args>
    explicit Lense(Args... args) : shape(std::forward<Args>(args)...) {
        shape.setFillColor(sf::Color(0, 0, 0, 0));
        shape.setOutlineThickness(lineThickness);
        shape.setOutlineColor(sf::Color(255, 255, 255));
    }

    void set_line_thickness(float lt) {
        lineThickness = lt;
    }

    void draw(const sf::RenderWindow& window) {
        window.draw(shape);
    }


private:

    ShapeType shape;
    float lineThickness = 0.5f;

};


#endif //LENSESIM_LENSE_H
