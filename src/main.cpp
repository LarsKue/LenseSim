//
// Created by Lars on 07/06/2019.
//

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <ratio>
#include <random> // random photon generation
#include "Lense.h"
#include "Photon.h"
#include "Object.h"
#include "Mirror.h"
#include "Timer.h"


constexpr int window_width = 1600;
constexpr int window_height = 900;
constexpr std::ratio<window_width, window_height> aspect_ratio;
constexpr int anti_aliasing_level = 8;
constexpr int window_flags = sf::Style::Close;

std::mt19937_64 eng;

double getRandom(double lower, double upper) {
    std::uniform_real_distribution<double> dist(lower, upper);
    return dist(eng);
}

void seed() {
    eng.seed(std::chrono::system_clock::now().time_since_epoch().count());
}

int main() {
    std::cout << "Launching..." << std::endl;
    std::cout << "Generating Random Seed..." << std::endl;
    seed();

    std::cout << "Aspect Ratio:" << aspect_ratio.num << ":" << aspect_ratio.den << std::endl;
    sf::ContextSettings settings;
    settings.antialiasingLevel = anti_aliasing_level;
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "LenseSim", window_flags, settings);

    auto om = ObjectManager();
//    auto lense_test = om.addObject<Lense<sf::CircleShape>>(100.f, 30);
//    auto lense_test2 = om.addObject<Lense<sf::CircleShape>>(20.f, 3);

//    auto photon_test = om.addObject<Photon>();
//    photon_test->getTrait<PhysicsTrait>()->pos = {300, 300};
//    photon_test->getTrait<PhysicsTrait>()->vel = {5, 5};

    for (unsigned i = 0; i < 10000; ++i) {
        auto p = om.addObject<Photon>();
        p->getTrait<PhysicsTrait>()->pos = {getRandom(750, window_width - 750), getRandom(400, window_height - 400)};
        p->getTrait<PhysicsTrait>()->vel = {getRandom(-20, 20), getRandom(-20, 20)};
    }

    double worstframetime = 0;
    unsigned framesum = 0;

    Timer timer;
    while (window.isOpen()) {
        timer.start();

        sf::Event event;
        if (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        double dt = timer.delta_time();
        if (dt > worstframetime) {
            worstframetime = timer.delta_time();
        }
        if (framesum % 10 == 0) {
            std::cout << 1/dt << std::endl;
        }
        ++framesum;

        om.update(dt);

        window.clear();

        om.draw(window);

        window.display();


        timer.stop();
    }

    std::cout << "Worst Frame Time: " << worstframetime << std::endl;
    std::cout << "Average Frame Time: " << timer.time_elapsed() / framesum << std::endl;
    return 0;
}