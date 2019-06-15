//
// Created by Lars on 07/06/2019.
//

#ifndef LENSESIM_OBJECT_H
#define LENSESIM_OBJECT_H

#include <SFML/Graphics.hpp>

#include <vector>
#include <array>
#include <memory>
#include <algorithm>

#include "CollisionManager.h"

constexpr int max_trait_num = 32;

using TraitID = std::size_t;

inline TraitID getNewTraitID() noexcept {
    static TraitID lastID = 0u;
    return lastID++;
}

template<typename T>
inline TraitID getTraitID() noexcept {
    static TraitID id = getNewTraitID();
    return id;
}

class Trait {

    friend class Object;

public:

    virtual void init();
    virtual void update(double);
    virtual void draw(sf::RenderWindow&);
    virtual void destroy();

    virtual ~Trait() = default;

protected:
    Trait() = default;
    bool marked_for_deletion = false;

private:
    inline const static TraitID ID = getTraitID<Trait>();
};

class Object {

    friend class ObjectManager;

public:

    template<typename T, typename... Args>
    T* addTrait(Args... args) {
        T* ptr = new T(std::forward<Args>(args)...);
        traits.emplace_back(std::unique_ptr<Trait>(ptr));
        traits_arr[getTraitID<T>()] = ptr;
        ptr->init();
        return ptr;
    }

    template<typename T>
    bool hasTrait() {
        return traits_arr[getTraitID<T>()] != nullptr;
    }

    template<typename T>
    T* getTrait() {
        return static_cast<T*>(traits_arr[getTraitID<T>()]);
    }

    virtual void init();
    void clean();
    virtual void update(double dt);
    virtual void draw(sf::RenderWindow&);
    virtual void destroy();

    virtual ~Object() = default;

protected:
    // Base class constructor is protected
    Object() = default;
    std::array<Trait*, max_trait_num> traits_arr = {};
    std::vector<std::unique_ptr<Trait>> traits = {};
    bool marked_for_deletion = false;
};

class ObjectManager {

public:

    ObjectManager() = default;

    template<typename T, typename... Args>
    T* addObject(Args... args) {
        T* ptr = new T(std::forward<Args>(args)...);
        objects.emplace_back(std::unique_ptr<Object>(ptr));
        ptr->init();
        cm.addObject(ptr);
        return ptr;
    }

    void clean();

    void update(double dt);

    void draw(sf::RenderWindow& window);

private:

    std::vector<std::unique_ptr<Object>> objects = {};
    CollisionManager cm = CollisionManager();

};


#endif //LENSESIM_OBJECT_H
