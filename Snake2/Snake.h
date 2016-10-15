#pragma once

#include <deque>

class Drawer;

class Snake
{
	friend class Drawer;
	class Point	//A structure that holds the coordinate of snake
	{
	public:
		int x;
		int y;
	};

	enum Direction{STILL ,UP, DOWN, LEFT, RIGHT};
	enum Field{EMPTY, SNAKE};
public:
	Snake();
	void keyEvent(int key);
	void update();

	int score;


	Point fruitLoc;

	int difficulty;
private:
	std::deque<Point> snake;
	Direction direction;
	int field[50][25];

	bool outtaBounds();
	bool ranIntoMyself();


	bool ateFruit();
	void newFruit();

	bool collided();
};

