#include "gameplay.h"
#include "Bat.h"
#include "Ball.h"
#include <sstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
using namespace sf;

void gameplay(int windowWidth, int windowHeight, RenderWindow* window, Clock* clock, float* delta, Bat* bat, Ball* ball, int* score, Text* scoreText, std::string* scoreString)
{
	*delta = clock->restart().asSeconds();
	//std::cout << *delta << std::endl;


	if (Keyboard::isKeyPressed(Keyboard::Left)){
		bat->moveLeft(*delta);
	//	std::cout << "left" << std::endl;
	} else if (Keyboard::isKeyPressed(Keyboard::Right)){
		bat->moveRight(*delta);
	//	std::cout << "right" << std::endl;
	}

	if (ball->getPosition().top < 0){
		ball->reboundBatOrTop(*delta);
	}
	if (ball->getPosition().top > windowHeight){
		ball->hitBottom();
		*score = 0;
	}

	if (ball->getPosition().left < 0 || ball->getPosition().left + 10 > windowWidth){
		ball->reboundSides();
	}

	if (ball->getPosition().intersects(bat->getPosition())) {
			ball->reboundBatOrTop(*delta);
			*score += 1;
	}

	ball->update(*delta);
	bat->update();
	*scoreString = std::to_string(*score);
	scoreText->setString(*scoreString);
	window->draw(bat->getShape());
	window->draw(ball->getShape());
	window->draw(*scoreText);
}
