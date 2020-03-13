#include <Windows.h>>
#include <glut.h>
static int VenusDay = 0, Day = 0, Time = 0;

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glColor3f(1.0, 0.3, 0.3);
	glutWireSphere(0.2, 20, 16);	// Sun
	glPushMatrix();
	glRotated((GLfloat)VenusDay, 0.0, 1.0, 0.0);
	glTranslatef(0.4, 0.0, 0.0);
	glRotatef((GLfloat)Time, 0.0, 1.0, 0.0);
	glColor3f(0.8, 0.5, 0.5);
	glutWireSphere(0.13, 10, 8);		// Venus
	glPopMatrix();
	glPushMatrix();
	glRotated((GLfloat)Day, 0.0, 1.0, 0.0);
	glTranslatef(0.7, 0.0, 0.0);
	glRotatef((GLfloat)Time, 0.0, 1.0, 0.0);
	glColor3f(0.5, 0.6, 0.7);
	glutWireSphere(0.1, 10, 8);		// Earth
	glPushMatrix();
	glRotatef((GLfloat)Time, 0.0, 1.0, 0.0);
	glTranslatef(0.2, 0.0, 0.0);
	glColor3f(0.9, 0.8, 0.2);
	glutWireSphere(0.04, 10, 8);	// Moon
	glPopMatrix();
	glPopMatrix();
	glutSwapBuffers();
}

void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'd':			// 공전
		VenusDay = (VenusDay + 15) % 360;
		Day = (Day + 10) % 360;
		glutPostRedisplay();
		break;
	case 't':			// 자전
		Time = (Time + 5) % 360;
		glutPostRedisplay();
		break;
	case 'r':			// 공전 + 자전
		VenusDay = (VenusDay + 15) % 360;
		Day = (Day + 10) % 360;
		Time = (Time + 5) % 360;
		glutPostRedisplay();
	default:
		break;
	}
}

int main() {
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Solar System Orbit");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glutDisplayFunc(MyDisplay);
	glutKeyboardFunc(MyKeyboard);
	glutMainLoop();

	return 0;
}