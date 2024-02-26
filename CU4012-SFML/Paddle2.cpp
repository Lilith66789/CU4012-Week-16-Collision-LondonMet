#include "Paddle2.h"

Paddle2::Paddle2()
{
}

Paddle2::~Paddle2()
{
}

void Paddle2::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Up)) {
		//input->setKeyUp(sf::Keyboard::Up);
		move(0, -0.1);
	}

	if (input->isKeyDown(sf::Keyboard::Down)) {
		//input->setKeyUp(sf::Keyboard::Down);
		move(0, 0.1);
	}
}

void Paddle2::CollisionResponse(GameObject* collider)
{
	collider->setVelocity(-collider->getVelocity());
}
