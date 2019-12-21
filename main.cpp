#include "gameplay.h"
#include "Bat.h"
#include "Ball.h"
#include <sstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
using namespace sf;

enum GameState{
	MENU,
	GAMEPLAY,
	PAUSE,
	GAMEOVER
};


void menu(){
	std::cout << "menu" << std::endl;
}
void pause(){
	std::cout << "pause" << std::endl;
}
void gameover(){
	std::cout << "game over" << std:: endl;
}

int main()
{
	int windowWidth = 700;
	int windowHeight = 500;
	Clock clock;
	float delta;

	int score = 0;
	Text scoreText;
	Font scoreFont;
	scoreFont.loadFromFile("font/DejaVuSerif.ttf");
	scoreText.setFont(scoreFont);
	scoreText.setColor(Color::White);

	std::string scoreString = std::to_string(score);
	scoreText.setString(scoreString);
	scoreText.setCharacterSize(24);

	Bat bat(windowWidth/2, windowHeight - 20);
	Ball ball(windowWidth/2, 1);

	GameState gameState = GAMEPLAY;
	RenderWindow window(VideoMode(windowWidth, windowHeight), "Zach's Pong Game!");




	while (window.isOpen()){
	Event event;
		while (window.pollEvent(event)){
			if (event.type == Event::Closed){
				window.close();
			}
		}

		window.clear(Color(148,213,0,255));

		if (gameState == MENU){
			menu();
		}
		if (gameState == GAMEPLAY){
			gameplay(windowWidth, windowHeight, &window, &clock, &delta, &bat, &ball, &score, &scoreText, &scoreString);
		}
		if (gameState == PAUSE){
			pause();
		}
		if (gameState == GAMEOVER){
			gameover();
		}

		window.display();
	}
	

	return 0;
}
