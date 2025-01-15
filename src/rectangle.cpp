#include "rectangle.h"

Rectangle::Rectangle(Vector2f pos, Vector2f vel, Color col, int x, int y, float m)
    : PhysicsObject(pos, vel, col, m) {
    shape.setSize(Vector2f(x, y));
    shape.setFillColor(col);
    shape.setPosition(position);
}

bool Rectangle::checkCollisionWithPoint(const Vector2f& point) const {
    return point.x >= position.x - size.x / 2 &&
           point.x <= position.x + size.x / 2 &&
           point.y >= position.y - size.y / 2 &&
           point.y <= position.y + size.y / 2;
}

void Rectangle::update(float dt) {
    position += velocity * dt;
    shape.setPosition(position);
}

void Rectangle::draw(RenderWindow& window) {
    window.draw(shape);
}