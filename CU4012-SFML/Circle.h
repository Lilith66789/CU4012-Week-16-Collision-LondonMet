#pragma once
#include "Framework/GameObject.h"
class Circle :
    public GameObject
{
public:
    Circle();
    ~Circle();

    void update(float dt);

    void CollisionResponse(GameObject* collider);

};

