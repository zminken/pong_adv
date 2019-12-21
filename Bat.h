#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Bat
{
	private:
		Vector2f position;
		RectangleShape batShape;
		float batSpeed = 750.3f;

	public:
		Bat(float startX, float startY);
		FloatRect getPosition();
		RectangleShape getShape();
		
		void moveLeft(float delta);
		void moveRight(float delta);
		void update();

};
