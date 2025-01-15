#include "physicsEngine.h"
#include <cmath>
#include <random>
#include <iostream>

const float HEIGHT = 1080.0f;
const float WIDTH = 960.0f;
const float RADIUS = 20.0f;
const float BOUNCE = 0.6f;
const float FRICTION = 0.98f;
const float MIN_VELOCITY = 0.1f;
const float ELASTIC = 0.8f; 

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dist(0, 1);

void PhysicsEngine::update_physics(float dt) {
    for (auto& obj : PhysicsObject::getObjects()) {
        handleBorderCollision(*obj);
        handleAllCollisions(PhysicsObject::getObjects());
        Vector2f externalForce = forces.applyForces(dt, g, obj->getMass());
        obj->setVel(obj->getVel() + externalForce);
        obj->update(dt);
    }
}

void PhysicsEngine::handleCollisions(PhysicsObject& obj1, PhysicsObject& obj2) {
    Vector2f position1 = obj1.getPos();
    Vector2f position2 = obj2.getPos();

    Vector2f velocity1 = obj1.getVel();
    Vector2f velocity2 = obj2.getVel();

    float m1 = obj1.getMass();
    float m2 = obj2.getMass();

    float distance = sqrt(pow(position2.x - position1.x, 2) + pow(position2.y - position1.y, 2));
    float minDistance = RADIUS*2;

    if (distance < RADIUS * 2) {
        Vector2f normal = position2 - position1;
        normal /= distance;

        Vector2f v1n = normal * (velocity1.x * normal.x + velocity1.y * normal.y);
        Vector2f v2n = normal * (velocity2.x * normal.x + velocity2.y * normal.y);

        Vector2f v1n_prime = (v1n * (m1 - m2) + v2n * 2.0f * m2) / (m1 + m2);
        Vector2f v2n_prime = (v2n * (m2 - m1) + v1n * 2.0f * m1) / (m1 + m2);

        velocity1 = velocity1 - v1n + v1n_prime;
        velocity2 = velocity2 - v2n + v2n_prime;

        float overlap = (RADIUS*2) - distance; 
        Vector2f correction = normal * (overlap * ELASTIC);
                        
        position1 -= correction;
        position2 += correction;

        obj1.setPos(position1);
        obj2.setPos(position2);

        obj1.setVel(velocity1);
        obj2.setVel(velocity2);
    }
}

void PhysicsEngine::handleAllCollisions(vector<unique_ptr<PhysicsObject>>& objects) {
    for (size_t i = 0; i < objects.size(); ++i) {
        for (size_t j = i + 1; j < objects.size(); ++j) {
            handleCollisions(*objects[i], *objects[j]);
        }
    }
}

void PhysicsEngine::handleBorderCollision(PhysicsObject& object) {
    Vector2f position = object.getPos();
    Vector2f velocity = object.getVel();

    cout << position.x << " " << position.y << " | " << velocity.x << " " << velocity.y << " " << "UPDATE" << endl;

    if (position.y + RADIUS*2 >= HEIGHT) {
        position.y = HEIGHT - RADIUS*2;
        velocity.y *= -BOUNCE;
    }

    if (position.y - RADIUS*2 <= 0) {
        position.y = RADIUS*2;
        velocity.y *= -BOUNCE;
    }

    if (position.x + RADIUS*2 >= WIDTH) {
        position.x = WIDTH - RADIUS*2;
        velocity.x *= -BOUNCE;
    }

    if (position.x - RADIUS*2 <= 0) {
        position.x = RADIUS*2;
        velocity.x *= -BOUNCE;
    }

    object.setPos(position);
    object.setVel(velocity);
}