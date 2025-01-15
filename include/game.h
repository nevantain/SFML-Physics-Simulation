#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "physicsObject.h"
#include "inputHandler.h"
#include "physicsEngine.h"
#include "circle.h"

using namespace std;
using namespace sf;

class Game {
private:
    RenderWindow window;
    InputHandler handler;
    PhysicsEngine physics;

public:
    Game(int width, int height, const string& title);

    void run();
};

#endif // GAME_H