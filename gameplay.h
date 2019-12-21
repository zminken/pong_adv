#pragma once
#include "Bat.h"
#include "Ball.h"
#include <SFML/Graphics.hpp>
using namespace sf;

void gameplay(int windowWidth, int windowHeight, RenderWindow * window, Clock* clock, float* delta, Bat* bat, Ball* ball, int* score, Text* scoreText, std::string* scoreString);
