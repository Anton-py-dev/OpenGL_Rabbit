#include <stdlib.h>;
/* підключаємо бібліотеку GLUT */
#include <gl/glut.h>;
#include <gl/freeglut.h>
#include <conio.h>
#include <iostream>
/* початкова ширина і висота вікна */
GLint Width = 1080, Height = 720;
int X = 0, Y = 0;

void triangle(int x0, int y0, int x1, int y1, int x2, int y2) {
	glColor3ub(44, 153, 0);
	glBegin(GL_TRIANGLES);
		glVertex2f(x0 + X, y0 + Y);
		glVertex2f(x1 + X, y1 + Y);
		glVertex2f(x2 + X, y2 + Y);
	glEnd();

	glLineWidth(2);
	glColor3ub(0, 0, 0);

	glBegin(GL_LINES);
		glVertex2f(x0+X, y0+Y);
		glVertex2f(x1+X, y1+Y);
		glVertex2f(x1+X, y1+Y);
		glVertex2f(x2+X, y2+Y);
		glVertex2f(x2+X, y2+Y);
		glVertex2f(x0+X, y0+Y);
	glEnd();
}

void square(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3) {
	glColor3ub(44, 153, 0);
	glBegin(GL_QUADS);
	glVertex2f(x0 + X, y0 + Y);
	glVertex2f(x1 + X, y1 + Y);
	glVertex2f(x2 + X, y2 + Y);
	glVertex2f(x3 + X, y3 + Y);
	glEnd();

	glLineWidth(2);
	glColor3ub(0, 0, 0);

	glBegin(GL_LINES);
	glVertex2f(x0 + X, y0 + Y);
	glVertex2f(x1 + X, y1 + Y);
	glVertex2f(x1 + X, y1 + Y);
	glVertex2f(x2 + X, y2 + Y);
	glVertex2f(x2 + X, y2 + Y);
	glVertex2f(x3 + X, y3 + Y);
	glVertex2f(x3 + X, y3 + Y);
	glVertex2f(x0 + X, y0 + Y);
	glEnd();
}


/* ця функція керує всім виведенням на екран */
void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(246.0f / 255.0f, 127.0f / 255.0f, 40.0f / 255.0f, 1.0f);

	triangle(100, 0, 100, 200, 300, 200);
	triangle(300, 200, 500, 200, 500, 0);
	triangle(200, 100, 300, 200, 400, 100);
	triangle(0, 250, 100, 350, 100, 250);
	triangle(0, 250, 70, 321, 0, 391);

	square(0, 150, 0, 250, 100, 250, 100, 150);
	square(500, 200, 525, 300, 675, 375, 650, 275);

	glFinish();
}

/* Функція викликається при зміні розмірів вікна */
void Reshape(GLint w, GLint h)
{
	Width = w;
	Height = h;

	/* установлюємо розміри області відображення */
	glViewport(0, 0, w, h);
	/* ортографічна проекція */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, w, 0, h, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/* Функція обробляє повідомлення від клавіатури */
void KeyboardEvent(unsigned char key, int x, int y)
{
	switch (key)
	{

	case 'a':
		X -= 10;
		glutPostRedisplay();
		break;

	case 'd':
		X += 10;
		glutPostRedisplay();
		break;
	case 'w':
		Y += 10;
		glutPostRedisplay();
		break;

	case 's':
		Y -= 10;
		glutPostRedisplay();
		break;
	}
}


/* Головний цикл додатка */
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(Width, Height);
	glutCreateWindow("Red square example");
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(KeyboardEvent);
	glutMainLoop();
}

