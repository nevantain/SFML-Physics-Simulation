#ifndef PHYSICS_ENGINE_H
#define PHYSICS_ENGINE_H

#include "physicsObject.h"
#include "externalForces.h"
#include <vector>

class PhysicsEngine {
private:
    const float g = 9.81f;

    ExternalForces forces;

    void handleBorderCollision(PhysicsObject& objects);
    void handleCollisions(PhysicsObject& obj1, PhysicsObject& obj2);
    void handleAllCollisions(vector<unique_ptr<PhysicsObject>>& objects);

public:
    void update_physics(float dt);
};

#endif // PHYSICS_ENGINE_H