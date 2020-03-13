#include <Windows.h>
#include <glut.h>

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	//glColor3f(1.0, 0.0, 0.0);
	glColor4f(1.0, 0.0, 0.0, 0.5);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glEnable(GL_POINT_SMOOTH);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
	glPointSize(10);
	glBegin(GL_POINTS);
	glVertex3f(-0.9, -0.65, 0.0);
	glEnd();

	glEnable(GL_LINE_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glLineWidth(5);
	glBegin(GL_LINES);
	glVertex3f(-1.0, -0.6, 0.0);
	glVertex3f(1.0, -0.2, 0.0);
	glVertex3f(-1.0, -0.6, 0.0);
	glVertex3f(0.75, 1.0, 0.0);
	glVertex3f(-1.0, -0.6, 0.0);
	glVertex3f(-0.75, 1.0, 0.0);
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