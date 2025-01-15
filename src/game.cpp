#include "game.h"

Game::Game(int width, int height, const string& title)
    : window(VideoMode(width, height), title) {}
      

void Game::run() {
    Clock clock;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        float dt = clock.restart().asSeconds();

        handler.handle(window);

        physics.update_physics(dt);

        PhysicsObject::updateAll(dt);

        window.clear();

        PhysicsObject::drawAll(window);

        window.display();
    }
}