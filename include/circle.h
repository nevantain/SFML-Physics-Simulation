#ifndef CIRCLE_H
#define CIRCLE_H

#include "physicsObject.h"
#include <iostream>
#include <cmath>

using namespace std;

class Circle : public PhysicsObject {
private:
    float radius;
    float m;
    CircleShape shape;

public:
    Circle(Vector2f pos, Vector2f vel, Color col, float rad, float m);
    bool checkCollisionWithPoint(const Vector2f& point) const;

    void update(float dt) override;
    void draw(RenderWindow& window) override;
};

#endif