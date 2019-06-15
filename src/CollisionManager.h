//
// Created by Lars on 15.06.2019.
//

#ifndef LENSESIM_COLLISIONMANAGER_H
#define LENSESIM_COLLISIONMANAGER_H

class Object;
class Photon;

class CollisionManager {

public:

    void addObject(Photon* ptr) {
        photons.emplace_back(ptr);
    }

    template<typename T>
    void addObject(T* ptr) {
        objects.emplace_back(static_cast<Object*>(ptr));
    }

    void update(double dt) {
        for (auto& p : photons) {
            /* TODO:
             *  Call collision function of object with two photon positions (pre and post update)
             *  have new photon position and velocity returned
             */
            for (auto& o : objects) {

            }
        }
    }

private:

    std::vector<Photon*> photons = {};
    std::vector<Object*> objects = {};

};

#endif //LENSESIM_COLLISIONMANAGER_H
