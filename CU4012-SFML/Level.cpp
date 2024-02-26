#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	ballTex.loadFromFile("gfx/Beach_Ball.png");

	ball1.setTexture(&ballTex);
	ball1.setCollisionBox(sf::FloatRect(0, 0, 50, 50));
	ball1.setSize(sf::Vector2f(100, 100));
	ball1.setPosition(sf::Vector2f(100, 100));
	ball1.setVelocity(250, 250);

	ball2.setTexture(&ballTex);
	ball2.setSize(sf::Vector2f(100, 100));
	ball2.setPosition(sf::Vector2f(500, 100));
	ball2.setVelocity(-100, 0);

	CollisionSquare[0].setSize(sf::Vector2f(50, 50));
	CollisionSquare[0].setCollisionBox(sf::FloatRect(0, 0, 50, 50));
	CollisionSquare[0].setPosition(sf::Vector2f(100, 300));
	CollisionSquare[0].setVelocity(100, 0);
	CollisionSquare[0].setFillColor(sf::Color::Red);

	CollisionSquare[1].setSize(sf::Vector2f(50, 50));
	CollisionSquare[1].setCollisionBox(sf::FloatRect(0, 0, 50, 50));
	CollisionSquare[1].setPosition(sf::Vector2f(500, 300));
	CollisionSquare[1].setVelocity(-100, 0);
	CollisionSquare[1].setFillColor(sf::Color::Blue);

	p1.setSize(sf::Vector2f(50, 150));
	p1.setCollisionBox(sf::FloatRect(0, 0, 50, 150));
	p1.setPosition(sf::Vector2f(0, 200));
	p1.setFillColor(sf::Color::Blue);
	p1.setInput(input);

	p2.setSize(sf::Vector2f(50, 150));
	p2.setCollisionBox(sf::FloatRect(0, 0, 50, 150));
	p2.setPosition(sf::Vector2f(1000, 200));
	p2.setFillColor(sf::Color::Red);
	p2.setInput(input);


}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	p1.handleInput(dt);
	p2.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	ball1.update(dt);
	//ball2.update(dt);
	if (Collision::checkBoundingCircle(&ball1, &ball2))
	{
		ball1.CollisionResponse(&ball1);
		ball2.CollisionResponse(&ball2);
	}

	CollisionSquare[0].update(dt);
	CollisionSquare[1].update(dt);
	if (Collision::checkBoundingBox(&CollisionSquare[0], &CollisionSquare[1])) {
		CollisionSquare[0].CollisionResponse(&CollisionSquare[0]);
		CollisionSquare[1].CollisionResponse(&CollisionSquare[1]);

	}

	if (Collision::checkBoundingBox(&p1, &ball1)) {
		p1.CollisionResponse(&ball1);
	}
	if (Collision::checkBoundingBox(&p2, &ball1)) {
		p2.CollisionResponse(&ball1);
	}
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(ball1);
	//window->draw(ball2);

	//window->draw(CollisionSquare[0]);
	//window->draw(CollisionSquare[1]);

	window->draw(p1);
	window->draw(p2);
	
	endDraw();
}
