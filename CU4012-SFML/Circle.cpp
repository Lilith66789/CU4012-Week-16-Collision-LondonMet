#include "Circle.h"

Circle::Circle()
{
}

Circle::~Circle()
{
}

void Circle::update(float dt)
{
	move(velocity * dt);
	if (getPosition().x < 0)
	{ 
		setPosition(0, getPosition().y);
		velocity.x = -velocity.x;
	}
	if (getPosition().x > 750)
	{	
		setPosition(750, getPosition().y);
		velocity.x = -velocity.x; 
	}
}

void Circle::CollisionResponse(GameObject* collider) 
{
	velocity.x = -velocity.x;
}
