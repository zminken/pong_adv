#include "Bat.h"

Bat::Bat(float startX, float startY)
{
	position.x = startX;
	position.y = startY;
	batShape.setSize(sf::Vector2f(100,10));
	batShape.setPosition(position);
}

FloatRect Bat::getPosition()
{
	return batShape.getGlobalBounds();
}

RectangleShape Bat::getShape()
{
	return batShape;
}

void Bat::moveLeft(float delta)
{
	position.x -= (batSpeed * delta);
}

void Bat::moveRight(float delta)
{
	position.x += (batSpeed * delta);
}

void Bat::update()
{
	batShape.setPosition(position);
}
