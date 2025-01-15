#ifndef PHYSICSOBJECT_H
#define PHYSICSOBJECT_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <iostream>

using namespace std;
using namespace sf;

class PhysicsObject {
protected:
    Vector2f position;
    Vector2f velocity;
    Color color;
    float m;

    // Статический вектор для хранения всех объектов
    static vector<unique_ptr<PhysicsObject>> objects;

public:
    PhysicsObject(Vector2f pos, Vector2f vel, Color col, float m);
    virtual ~PhysicsObject();

    virtual void update(float dt) = 0;
    virtual void draw(RenderWindow& window) = 0;
    virtual bool checkCollisionWithPoint(const Vector2f& point) const = 0;

    Vector2f getPos() const;
    void setPos(Vector2f pos);

    Vector2f getVel() const;
    void setVel(Vector2f vel);

    float getMass() const;
    
    static vector<unique_ptr<PhysicsObject>>& getObjects();

    // Статические методы для управления всеми объектами
    static void addObject(unique_ptr<PhysicsObject> object);
    static void updateAll(float dt);
    static void drawAll(RenderWindow& window);
};

#endif