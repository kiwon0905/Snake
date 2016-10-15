#include "Game.h"
#include <iostream>
#include <gl/freeglut.h>
#include <time.h>
#include <cstring>

Game::Game()
{
	difficulty=snake.difficulty;
}

void Game::update()
{
	snake.update();	
	difficulty=snake.difficulty;
	score=snake.score;
}

void Game::render()
{
	drawer.draw(snake);
	glutPostRedisplay();
}

void Game::keyEvent(int key)
{
	snake.keyEvent(key);
}