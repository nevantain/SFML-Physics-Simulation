#include "inputHandler.h"

void InputHandler::leftMouseHandle(RenderWindow& window) {
    Vector2i mousePosition = Mouse::getPosition(window);

    if (Mouse::isButtonPressed(Mouse::Left) && !IS_LEFT_MOUSE_CLICK) {
        PhysicsObject::addObject(make_unique<Circle>(Vector2f(mousePosition.x, mousePosition.y), Vector2f(0, 0), Color::Green, 20, 40.0f));
        IS_LEFT_MOUSE_CLICK = true;
    }
    
    if (!Mouse::isButtonPressed(Mouse::Left)) {
        IS_LEFT_MOUSE_CLICK = false;
    }
}

void InputHandler::rightMouseHandle(RenderWindow& window) {
    Vector2i mousePosition = Mouse::getPosition(window);

    if (Mouse::isButtonPressed(Mouse::Right)) {
        if (!IS_RIGHT_MOUSE_CLICK) {
            IS_RIGHT_MOUSE_CLICK = true;

            for (auto& obj : PhysicsObject::getObjects()) {
                if (obj->checkCollisionWithPoint(Vector2f(mousePosition.x, mousePosition.y))) {
                    selectedObject = obj.get();
                    IS_SELECTED = true;
                    break;
                }
            }
        }

        if (IS_SELECTED && selectedObject) {
            selectedObject->setPos(Vector2f(mousePosition.x, mousePosition.y));
        }
    } else {
        IS_RIGHT_MOUSE_CLICK = false;
        IS_SELECTED = false;
        selectedObject = nullptr;
    }
}


void InputHandler::handle(RenderWindow& window) {
    leftMouseHandle(window);
    rightMouseHandle(window);
}