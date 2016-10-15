#include "Drawer.h"
#include <gl/freeglut.h>


Drawer::Drawer()
{
}

void Drawer::draw(const Snake & s)
{

	glColor3f(1.0, 1.0, .0);
	glBegin(GL_QUADS);
	glVertex2f(s.snake.front().x+0.2, s.snake.front().y+0.2);
	glVertex2f(s.snake.front().x+0.8, s.snake.front().y+0.2);
	glVertex2f(s.snake.front().x+0.8, s.snake.front().y+0.8);
	glVertex2f(s.snake.front().x+0.2, s.snake.front().y+0.8);
	glEnd();
	
	glColor3f(0.5, 0.5, 0.5);
	//Draw Snakes
	glBegin(GL_QUADS);
	for(auto a=s.snake.cbegin()+1; a!=s.snake.cend(); a++)
	{
		glVertex2f(static_cast<GLfloat>((*a).x+0.2),static_cast<GLfloat>((*a).y+0.2));
		glVertex2f(static_cast<GLfloat>((*a).x+0.8),static_cast<GLfloat>((*a).y+0.2));
		glVertex2f(static_cast<GLfloat>((*a).x+0.8),static_cast<GLfloat>((*a).y+0.8));
		glVertex2f(static_cast<GLfloat>((*a).x+0.2),static_cast<GLfloat>((*a).y+0.8));
	}
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	for(auto a=s.snake.cbegin(); a!=s.snake.cend(); a++)
	{
		glVertex2f(static_cast<GLfloat>((*a).x+0.2),static_cast<GLfloat>((*a).y+0.2));
		glVertex2f(static_cast<GLfloat>((*a).x+0.8),static_cast<GLfloat>((*a).y+0.2));
		glVertex2f(static_cast<GLfloat>((*a).x+0.8),static_cast<GLfloat>((*a).y+0.8));
		glVertex2f(static_cast<GLfloat>((*a).x+0.2),static_cast<GLfloat>((*a).y+0.8));
	}
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glColor3f(1.0, 0.0, 0.4);
	glBegin(GL_QUADS);
		glVertex2f(static_cast<GLfloat>(s.fruitLoc.x+0.2), static_cast<GLfloat>(s.fruitLoc.y+0.2));
		glVertex2f(static_cast<GLfloat>(s.fruitLoc.x+0.8), static_cast<GLfloat>(s.fruitLoc.y+0.2));
		glVertex2f(static_cast<GLfloat>(s.fruitLoc.x+0.8), static_cast<GLfloat>(s.fruitLoc.y+0.8));
		glVertex2f(static_cast<GLfloat>(s.fruitLoc.x+0.2), static_cast<GLfloat>(s.fruitLoc.y+0.8));
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POINTS);
		glVertex2f(static_cast<GLfloat>(s.fruitLoc.x+0.4), static_cast<GLfloat>(s.fruitLoc.y+0.4));
		glVertex2f(static_cast<GLfloat>(s.fruitLoc.x+0.6), static_cast<GLfloat>(s.fruitLoc.y+0.4));
		glVertex2f(static_cast<GLfloat>(s.fruitLoc.x+0.6), static_cast<GLfloat>(s.fruitLoc.y+0.6));
		glVertex2f(static_cast<GLfloat>(s.fruitLoc.x+0.4), static_cast<GLfloat>(s.fruitLoc.y+0.6));
	glEnd();

	glColor3f(0.5, 0.5, 0.5);


}