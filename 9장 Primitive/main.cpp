#include <Windows.h>
#include <glut.h>

void MyDisplay() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	//// 다각형 그리기 : GL_TRIANGLES, GL_QUADS, GL_POLYGON
	//glColor3f(0.0, 1.0, 0.0);
	//glBegin(GL_POLYGON);
	//	glVertex3f(0.0, -0.5, 0.0);
	//	glVertex3f(0.3, -0.4, 0.0);
	//	glVertex3f(0.5, 0.0, 0.0);
	//	glVertex3f(0.3, 0.4, 0.0);
	//	glVertex3f(0.0, 0.5, 0.0);
	//	glVertex3f(-0.3, 0.4, 0.0);
	//	glVertex3f(-0.5, 0.0, 0.0);
	//	glVertex3f(-0.3, -0.4, 0.0);
	//glEnd();

	//// 정점 그리기 : GL_POINTS
	//// 선 그리기 : GL_LINES, GL_LINE_STRIP, GL_LINE_LOOP
	//glColor3f(1.0, 0.0, 0.0);
	//glPointSize(5.0);
	//glLineWidth(5.0);
	//glBegin(GL_POINTS);
	//	glVertex3f(0.0, -0.5, 0.0);
	//	glVertex3f(0.3, -0.4, 0.0);
	//	glVertex3f(0.5, 0.0, 0.0);
	//	glVertex3f(0.3, 0.4, 0.0);
	//	glVertex3f(0.0, 0.5, 0.0);
	//	glVertex3f(-0.3, 0.4, 0.0);
	//	glVertex3f(-0.5, 0.0, 0.0);
	//	glVertex3f(-0.3, -0.4, 0.0);
	//glEnd();



	////  : GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN, GL_QUAD_STRIP
	//glColor3f(0.0, 1.0, 0.0);
	//glBegin(GL_TRIANGLE_STRIP);
	//	glVertex3f(-0.8, 0.5, 0.0);
	//	glVertex3f(-0.8, -0.5, 0.0);
	//	glVertex3f(-0.3, 0.4, 0.0);
	//	glVertex3f(-0.2, -0.3, 0.0);
	//	glVertex3f(0.2, 0.5, 0.0);
	//	glVertex3f(0.5, -0.5, 0.0);
	//glEnd();


	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0.0, -0.5, 0.0);
	glVertex3f(0.8, 0.5, 0.0);
	glVertex3f(0.5, 0.8, 0.0);
	glVertex3f(0.1, 0.7, 0.0);
	glVertex3f(-0.3, 0.8, 0.0);
	glVertex3f(-0.5, 0.5, 0.0);
	glEnd();

	glFlush();
}

int main() {
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_SINGLE);
	glutCreateWindow("bbb");

	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}