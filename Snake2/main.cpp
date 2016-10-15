#include <iostream>
#include "Game.h"
#include <string>
#include <GL/freeglut.h>

Game game;


void advanceSnake(int time)
{
	game.update();
	glutTimerFunc(game.difficulty,advanceSnake, 0);
}

void keyEvent(int key, int x, int y)
{
	game.keyEvent(key);
}

void display()
{
    glClear (GL_COLOR_BUFFER_BIT);
	game.render();

    glFlush ();
}

void init (void) 
{
    glClearColor (0.9, 0.9, 0.9, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 50, 0, 25);	//There are 25 rows and 50 columns
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (600, 300); 
    glutInitWindowPosition (500, 0);
    glutCreateWindow ("hello");
    init ();
    glutDisplayFunc(display); 
	glutSpecialFunc(keyEvent);
	glutTimerFunc(game.difficulty, advanceSnake, 0);
    glutMainLoop();
    return 0;   /* ISO C requires main to return int. */
}

