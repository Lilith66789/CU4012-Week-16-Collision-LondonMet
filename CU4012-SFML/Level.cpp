#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	ballTex.loadFromFile("gfx/Beach_Ball.png");

	ball1.setTexture(&ballTex);
	ball1.setSize(sf::Vector2f(100, 100));
	ball1.setPosition(sf::Vector2f(100, 100));
	ball1.setVelocity(100, 0);

	ball2.setTexture(&ballTex);
	ball2.setSize(sf::Vector2f(100, 100));
	ball2.setPosition(sf::Vector2f(500, 100));
	ball2.setVelocity(-100, 0);


}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)
{
	ball1.update(dt); 
	ball2.update(dt); 
	if (Collision::checkBoundingCircle(&ball1, &ball2)) 
	{	
		ball1.CollisionResponse(&ball1);
		ball2.CollisionResponse(&ball2); 
	}
	
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(ball1);
	window->draw(ball2);

	
	endDraw();
}
