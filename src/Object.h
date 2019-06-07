//
// Created by Lars on 07/06/2019.
//

#ifndef LENSESIM_OBJECT_H
#define LENSESIM_OBJECT_H

#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>
#include <algorithm>

class Object {

    friend class ObjectManager;

public:

    virtual void init() {}
    virtual void update() {}
    virtual void draw(sf::RenderWindow&) {}
    virtual void destroy() {
        marked_for_deletion = true;
    }

    virtual ~Object() = default;

protected:
    Object() = default;

private:
    bool marked_for_deletion = false;

};

class ObjectManager {
public:

    ObjectManager() = default;

    template<typename T, typename... Args>
    T* addObject(Args... args) {
        T* ptr = new T(std::forward<Args>(args)...);
        objects.emplace_back(std::unique_ptr<T>(ptr));
        return ptr;
    }

    void clean() {
        // delete all inactive objects
        objects.erase(std::remove_if(
                std::begin(objects),
                std::end(objects),
                [](const auto& objectptr) -> bool {
                    return objectptr->marked_for_deletion;
                }),
                std::end(objects)
                );
    }

    void update() {
        for (auto& o : objects) {
            o->update();
        }
    }

    void draw(sf::RenderWindow& window) {
        for (auto& o : objects) {
            o->draw(window);
        }
    }


private:

    std::vector<std::unique_ptr<Object>> objects = {};

};


#endif //LENSESIM_OBJECT_H
