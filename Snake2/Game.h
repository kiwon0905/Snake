#pragma once

#include "Drawer.h"
#include "Game.h"
#include "Snake.h"

class Game
{
private:
	Snake snake;	//This contains the snake's coordinate
	Drawer drawer;
	int score;

public:
	Game();
	void render();
	void update();  //update the screen
	void keyEvent(int key);
	
	int difficulty;
};

