//
// Created by Lars on 07/06/2019.
//

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <ratio>
#include "Lense.h"
#include "Photon.h"
#include "Object.h"


constexpr int window_width = 1600;
constexpr int window_height = 900;
constexpr std::ratio<window_width, window_height> aspect_ratio;
constexpr int anti_aliasing_level = 8;
constexpr int window_flags = sf::Style::Close;


int main() {
    std::cout << "Launching..." << std::endl;
    std::cout << "Aspect Ratio:" << aspect_ratio.num << ":" << aspect_ratio.den << std::endl;
    sf::ContextSettings settings;
    settings.antialiasingLevel = anti_aliasing_level;
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "LenseSim", window_flags, settings);

    auto om = ObjectManager();
    auto lense_test = om.addObject<Lense<sf::CircleShape>>(100.f, 30);
    auto lense_test2 = om.addObject<Lense<sf::CircleShape>>(20.f, 3);

    auto photon_test = om.addObject<Photon>(100, 100);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            window.clear();
            om.draw(window);
            window.display();
        }
    }
    return 0;
}