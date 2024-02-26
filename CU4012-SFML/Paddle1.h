#pragma once
#include "Framework/GameObject.h"
class Paddle1 : public GameObject
{
public:
    Paddle1();
    ~Paddle1();

    void handleInput(float dt);
    void CollisionResponse(GameObject* collider);
};

