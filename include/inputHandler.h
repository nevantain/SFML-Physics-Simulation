#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "physicsObject.h"
#include "circle.h"
#include "rectangle.h"

using namespace std;
using namespace sf;

class InputHandler {
    private:
        bool IS_LEFT_MOUSE_CLICK = false;
        bool IS_RIGHT_MOUSE_CLICK = false;
        bool IS_SELECTED = false;
        PhysicsObject* selectedObject = nullptr;

    public:
        void handle(RenderWindow& window);

        void leftMouseHandle(RenderWindow& window);
        void rightMouseHandle(RenderWindow& window);
};