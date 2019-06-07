//
// Created by Lars on 07/06/2019.
//

#include <SFML/Graphics.hpp>

constexpr int window_width = 1920;
constexpr int window_height = 1080;
constexpr double aspect_ratio = static_cast<double>(window_width) / window_height;
constexpr int anti_aliasing_level = 8;

int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = anti_aliasing_level;
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "LenseSim", sf::Style::Default, settings);
    sf::CircleShape shape(100.f, 100);
    shape.setFillColor(sf::Color::Green);

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