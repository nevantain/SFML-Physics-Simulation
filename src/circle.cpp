#include "circle.h"

Circle::Circle(Vector2f pos, Vector2f vel, Color col, float rad, float m)
    : PhysicsObject(pos, vel, col, m), radius(rad) {
    shape.setRadius(radius);
    shape.setFillColor(col);
    shape.setPosition(position);
    shape.setOrigin(radius, radius);
}

bool Circle::checkCollisionWithPoint(const Vector2f& point) const {
    float distanceSquared = (point.x - position.x) * (point.x - position.x) +
                            (point.y - position.y) * (point.y - position.y);
    return distanceSquared <= radius * radius;
}

void Circle::update(float dt) {
    position += velocity * dt;
    shape.setPosition(position);
}

void Circle::draw(RenderWindow& window) {
    window.draw(shape);
}