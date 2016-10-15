#include "Snake.h"
#include <iostream>
#include <gl/freeglut.h>
#include <random>
#include <ctime>

Snake::Snake()
{
	srand(time(0));
	
	Point temp;
	temp.y=0;
	for(int x=0; x<=4; x++)//Initialize default snake position
	{
		temp.x=x;				 //       0 1 2 3 4
		snake.push_front(temp);  //back<- X X X X X ->front
		//field[0][x]=SNAKE;
	}
	direction=STILL;
	difficulty=500;
	
	score=0;
	newFruit();
}

bool Snake::collided()
{
	return (ranIntoMyself()||outtaBounds());
}

bool Snake::ranIntoMyself()
{
	for(unsigned int i=1; i<snake.size(); i++)
	{
		if(snake[i].x==snake.front().x && snake[i].y==snake.front().y)
			return true;
	}
	return false;



// Devise better collision system later!
}

bool Snake::outtaBounds()
{
	if(snake.front().x<0||snake.front().x>=50||snake.front().y<0||snake.front().y>=25)
		return true;
	return false;
}

bool Snake::ateFruit()
{
	if(difficulty>100)
		difficulty-=5;
	if(snake.front().x==fruitLoc.x && snake.front().y==fruitLoc.y)
		return true;
	return false;
}

void Snake::newFruit()
{
	static int x;
	static int y;
	do{
		x=rand()%50;
		y=rand()%25;
	}while(field[y][x]!=EMPTY);
	fruitLoc.x=x;
	fruitLoc.y=y;
	//field[y][x]=FRUIT;
}

void Snake::keyEvent(int key)
{
	switch(key)
	{
	case GLUT_KEY_UP:
		if (direction==DOWN)
			return;
		direction=UP;
		break;
	case GLUT_KEY_DOWN:
		if (direction==UP)
			return;
		direction=DOWN;
		break;
	case GLUT_KEY_LEFT:
		if (direction==RIGHT)
			return;
		direction=LEFT;
		break;
	case GLUT_KEY_RIGHT:
		if (direction==LEFT)
			return;
		direction=RIGHT;
		break;
	}
	update();
	glutPostRedisplay();
}

void Snake::update()//This advances the snake
{
	static Point temp;
	temp.x=snake.front().x;
	temp.y=snake.front().y;
	switch(direction)
	{
	case UP:
		temp.y=snake.front().y+1;
		break;
	case DOWN:
		temp.y=snake.front().y-1;
		break;
	case LEFT:
		temp.x=snake.front().x-1;
		break;
	case RIGHT:
		temp.x=snake.front().x+1;
		break;
	default:
		return;
	}	
	snake.push_front(temp);
	field[temp.y][temp.x]=SNAKE; 
	field[snake.back().y][snake.back().x]=EMPTY; 
	snake.pop_back();

	if(collided())
	{
		std::cout<<"Game Over";
		Sleep(1000);
		exit(0);
	}
	if(ateFruit())
	{
		newFruit();
		switch(direction)
		{
		case UP:
			temp.y-=1;
			break;
		case DOWN:
			temp.y+=1;
			break;
		case LEFT:
			temp.x+=1;
			break;
		case RIGHT:
			temp.x-=1;
			break;
		default:
			return;
		}
		snake.push_back(temp);
	}

}


