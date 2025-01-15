#include "externalForces.h"

using namespace std;
using namespace sf;

Vector2f ExternalForces::gravity(float dt, float g, float m) {
    Vector2f gravityForce = Vector2f(0, g * m) * dt;

    return gravityForce;
}

Vector2f ExternalForces::wind(float dt) {
    Vector2f windForce = Vector2f(1.0f, 0.0f) * dt;

    return windForce;
}

Vector2f ExternalForces::applyForces(float dt, float g, float m) {
    Vector2f all_forces = gravity(dt, g, m) + wind(dt);

    return all_forces;
}
