#include <windows.h>
#include <glut.h>

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

	// A
	glLoadIdentity();
	glColor3f(0.0, 0.0, 0.0);
	glutSolidTeapot(0.1);

	// 변환 행렬 스택 (B -> C -> D)
	glPushMatrix();
		// B
		glLoadIdentity();
		glTranslatef(0.2, 0.2, 0.0);
		glutSolidTeapot(0.1);
		
		// C
		glLoadIdentity();
		glTranslatef(0.7, 0.1, 0.0);
		glScalef(0.5, 0.5, 1.0);
		glRotated(45, 0, 0, 1);
		glutSolidTeapot(0.1);

		// D
		glLoadIdentity();
		glColor3f(1.0, 0.0, 0.0);
		glTranslatef(-0.7, 0.7, 0.0);
		glScalef(2.0, 2.0, 1.0);
		glRotated(90, 0, 1, 0);
		glutSolidTeapot(0.1);
	glPopMatrix();

	// E
	glLoadIdentity();
	glColor3f(0.0, 0.0, 1.0);
	glTranslatef(0.0, -0.5, 0.0);
	glutSolidTeapot(0.1);
	glFlush();
}

int main(void) {
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Geometric Transform");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}