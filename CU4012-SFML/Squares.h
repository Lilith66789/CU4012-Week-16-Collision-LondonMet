#pragma once
#include "Framework/GameObject.h"
class Squares :
    public GameObject
{
public:
    Squares();
    ~Squares();
    void update(float dt);

    void CollisionResponse(GameObject* collider);
};

