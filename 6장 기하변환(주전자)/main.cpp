#include <Windows.h>
#include <glut.h>

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// a
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(0.0, 0.0, 0.0);
	glutSolidTeapot(0.1);

	glPushMatrix();		// a -> b
		glTranslatef(0.2, 0.2, 0.0);
		glutSolidTeapot(0.1); 
		glPushMatrix();	// b -> c
			glTranslatef(0.5, -0.1, 0.0);
			glRotatef(45, 0, 0, 1);
			glScalef(0.5, 0.5, 0.5);
			glutSolidTeapot(0.1);
		glPopMatrix();

		glPushMatrix();	// b -> d
			glColor3f(1.0, 0.0, 0.0);
			glTranslatef(-0.8, 0.5, 0.0);
			glRotatef(90, 0, 1, 0);
			glScalef(2.0, 2.0, 2.0);
			glutSolidTeapot(0.1);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();		// a -> e
		glColor3f(0.0, 0.0, 1.0);
		glTranslatef(0.0, -0.5, 0.0);
		glutSolidTeapot(0.1);
	glPopMatrix();
	glFlush();
}

int main(void) {
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("기하변환(주전자)");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();

	return 0;
}