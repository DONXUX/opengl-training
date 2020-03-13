#include <Windows.h>
#include <glut.h>

void MyDisplay() {
	GLdouble eqn1[4] = { 0.0, 1.0, 0.0, 0.0 };
	GLdouble eqn2[4] = { 1.0, 0.0, 0.0, 0.0 };
	GLdouble eqn3[4] = { 1.0, 1.0, 0.0, 0.0 };		// 평면의 법선 벡터 (A,B,C)
	GLdouble eqn4[4] = { 1.0, 0.0, 0.0, 0.5 };		// Ax + By + Cz + D = 0

	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0.0, 1.0, 0.0);
	
	glTranslatef(0.0, 0.0, -5.0);
	//glRotatef(90.0, 1.0, 0.0, 0.0);

	// Clip Left half -- y < 0
	glClipPlane(GL_CLIP_PLANE0, eqn1);
	glEnable(GL_CLIP_PLANE0);

	// Clip Left half -- x < 0
	glClipPlane(GL_CLIP_PLANE1, eqn4);
	glEnable(GL_CLIP_PLANE1);

	glutWireSphere(1.0, 20, 16);
	glFlush();
}

void MyReshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
}

int main() {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("절단면 추가");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutMainLoop();

	return 0;
}