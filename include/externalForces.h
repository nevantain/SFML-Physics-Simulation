#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class ExternalForces {
public:
    Vector2f gravity(float dt, float g, float m);
    Vector2f wind(float dt);
    Vector2f applyForces(float dt, float g, float m);
};