//
// Created by Lars on 07/06/2019.
//

#include <SFML/Graphics.hpp>
#include <vector>
#include "Lense.h"


constexpr int window_width = 1920;
constexpr int window_height = 1080;
constexpr double aspect_ratio = static_cast<double>(window_width) / window_height;
constexpr int anti_aliasing_level = 8;
constexpr int window_flags = sf::Style::Close;

//std::vector<

int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = anti_aliasing_level;
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "LenseSim", window_flags, settings);
    sf::CircleShape shape(100.f, 100);
    shape.setFillColor(sf::Color(0, 0, 0, 0));
    shape.setOutlineThickness(0.3f);
    shape.setOutlineColor(sf::Color(255, 255, 255));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            window.clear();
            window.draw(shape);
            window.display();
        }
    }
    return 0;
}