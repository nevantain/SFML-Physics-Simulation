#include "physicsObject.h"

vector<unique_ptr<PhysicsObject>> PhysicsObject::objects;

PhysicsObject::PhysicsObject(Vector2f pos, Vector2f vel, Color col, float m)
    : position(pos), velocity(vel), color(col), m(m) {}

PhysicsObject::~PhysicsObject() {}

Vector2f PhysicsObject::getPos() const {
    return position;
}

void PhysicsObject::setPos(Vector2f pos) {
    position = pos;
}

Vector2f PhysicsObject::getVel() const {
    return velocity;
}

void PhysicsObject::setVel(Vector2f vel) {
    velocity = vel;
}

float PhysicsObject::getMass() const {
    return m;
}

void PhysicsObject::addObject(unique_ptr<PhysicsObject> object) {
    objects.push_back(move(object));
}

void PhysicsObject::updateAll(float dt) {
    for (auto& obj : objects) {
        obj->update(dt);
    }
}

vector<unique_ptr<PhysicsObject>>& PhysicsObject::getObjects() {
    return objects;
}

void PhysicsObject::drawAll(RenderWindow& window) {
    for (auto& obj : objects) {
        obj->draw(window);
    }
}