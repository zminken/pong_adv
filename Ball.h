#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Ball
{
	private:
		Vector2f position;
		RectangleShape ballShape;
		float xVelocity = 250.1f;
		float yVelocity = 250.1f;

	public:
		Ball(float startX, float startY);
		FloatRect getPosition();
		RectangleShape getShape();
		float getXVelocity();
		void reboundSides();
		void reboundBatOrTop(float delta);
		void hitBottom();
		void update(float delta);
};
