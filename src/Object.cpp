//
// Created by Lars on 07/06/2019.
//

#include "Object.h"

void Trait::init() {}

void Trait::update(double) {}

void Trait::draw(sf::RenderWindow&) {}

void Trait::destroy() {
    marked_for_deletion = true;
}

void Object::init() {

}

void Object::clean() {
    // remove all marked traits from the traits_arr and delete them afterwards
    for (Trait*& ptr : traits_arr) {
        if (ptr && ptr->marked_for_deletion) {
            ptr = nullptr;
        }
    }

    // delete all marked traits
    traits.erase(std::remove_if(
            std::begin(traits),
            std::end(traits),
            [](const auto& traitptr) -> bool {
                return traitptr->marked_for_deletion;
            }),
                    std::end(traits)
    );
}

void Object::update(double dt) {
    for (auto& t : traits) {
        t->update(dt);
    }
}

void Object::draw(sf::RenderWindow& window) {
    for (auto& t : traits) {
        t->draw(window);
    }
}

void Object::destroy() {
        marked_for_deletion = true;
}

void ObjectManager::clean() {
    // delete all marked objects
    objects.erase(std::remove_if(
            std::begin(objects),
            std::end(objects),
            [](const auto& objectptr) -> bool {
                return objectptr->marked_for_deletion;
            }),
                  std::end(objects)
    );
    // clean all remaining objects
    for (auto& o : objects) {
        o->clean();
    }
}

void ObjectManager::update(double dt) {
    for (auto& o : objects) {
        o->update(dt);
    }
}

void ObjectManager::draw(sf::RenderWindow& window) {
    for (auto& o : objects) {
        o->draw(window);
    }
}
