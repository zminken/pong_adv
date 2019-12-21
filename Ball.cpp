#include "Ball.h"

Ball::Ball(float startX, float startY)
{
	position.x = startX;
	position.y = startY;
	ballShape.setSize(sf::Vector2f(15,15));
	ballShape.setPosition(position);
}

FloatRect Ball::getPosition()
{
	return ballShape.getGlobalBounds();
}

RectangleShape Ball::getShape()
{
	return ballShape;
}

float Ball::getXVelocity()
{
	return xVelocity;
}

void Ball::reboundSides()
{
	xVelocity = -xVelocity;
}

void Ball::reboundBatOrTop(float delta)
{
	position.y -= (yVelocity * 30 * delta);
	yVelocity = -yVelocity;
}

void Ball::hitBottom()
{
	position.y = 1;
	position.x = 500;
}

void Ball::update(float delta)
{
	position.y += (delta * yVelocity);
	position.x += (delta * xVelocity);

	ballShape.setPosition(position);
}
