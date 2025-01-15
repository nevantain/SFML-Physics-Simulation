#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "physicsObject.h"
#include <cmath>

using namespace std;
using namespace sf;

class Rectangle : public PhysicsObject {
private:
    Vector2f size;
    RectangleShape shape;

public:
    Rectangle(Vector2f pos, Vector2f vel, Color col, int x, int y, float m);
    bool checkCollisionWithPoint(const Vector2f& point) const;

    void update(float dt) override;
    void draw(RenderWindow& window) override;
};

#endif