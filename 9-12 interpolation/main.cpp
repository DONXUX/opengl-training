#include <Windows.h>
#include <glut.h>
#include <math.h>

GLfloat Alpha = 0.3;
GLenum Src = GL_SRC_ALPHA;
GLenum Dest = GL_ONE_MINUS_SRC_ALPHA;

void MyDisplay() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glLineWidth(5.0);
	glBegin(GL_LINES);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-1.0, 0.0, 0.0);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(1.0, 0.0, 0.0);
	glEnd();

	// GL_FLAT, GL_SMOOTH
	glShadeModel(GL_SMOOTH);
	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-0.5, -0.5, 0.0);
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(0.5, -0.5, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.0, 0.5, 0.0);
	glEnd();
	glFlush();
}

int main() {
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_SINGLE);
	glutCreateWindow("Interpolation");

	glutDisplayFunc(MyDisplay);
	glutMainLoop(); return 0;
}