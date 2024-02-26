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
	if (getPosition().x > 1200)
	{ 
		setPosition(1200, getPosition().y);
		velocity.x = -velocity.x;
	}

	if (getPosition().y > 675)
	{
		setPosition(675, getPosition().x);
		velocity.y = -velocity.y;
	}
	if (getPosition().y < 0)
	{
		setPosition(0, getPosition().x);
		velocity.y = -velocity.y;
	}
}

void Circle::CollisionResponse(GameObject* collider) 
{
	velocity.x = -velocity.x;
}
