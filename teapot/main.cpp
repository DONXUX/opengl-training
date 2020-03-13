#include <windows.h>
#include <glut.h>

// 조명
void InitLight() {
	GLfloat mat_diffuse[] = { 0.5, 0.4, 0.3, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_ambient[] = { 0.5, 0.4, 0.3, 1.0 };
	GLfloat mat_shininess[] = { 15.0 };
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat light_ambient[] = { 0.3, 0.3, 0.3, 1.0 };
	GLfloat light_position[] = { -3, 6, 3.0, 0.0 };

	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void MyReshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0.3, 0.0, 0.0, 1.0, 0.5, -0.1, 0.0, 0.0, 1.0);

	// 주석을 하나씩 해제하면서 확인하시면 됩니다.
	////////////////////////////////////////////////////////////////////////////
	// 1
	//gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0,-1.0, 0.0, 1.0, 0.0); 
	// 2
	//gluLookAt(-0.5, 0.0, 0.0, 0.0, 0.0, -5.0, 0.0, 1.0, 0.0);
	// 3
	//gluLookAt(0.5, 0.0, 0.0, 0.0, 0.0, -5.0, 0.0, 1.0, 0.0);
	// 4
	//gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0);

	// 5
	//gluLookAt(0.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	// 6
	//gluLookAt(0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	// 7
	//gluLookAt(0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, -1.0);
	// 8
	//gluLookAt(0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);

	// 9
	//gluLookAt(0.0, 0.0, 0.0, 1.0, -1.0, 1.0, 0.0, 1.0, 0.0);
	// 10
	//gluLookAt(0.0, 0.0, 0.0, -1.0, -1.0, 1.0, 0.0, 1.0, 0.0);
	// 11
	//gluLookAt(0.0, 0.0, 0.0, 1.0, -1.0, -1.0, 0.0, 1.0, 0.0);
	// 12
	//gluLookAt(0.0, 0.0, 0.0, -1.0, -1.0, -1.0, 0.0, 1.0, 0.0);
	////////////////////////////////////////////////////////////////////////////

	glutSolidTeapot(0.5);
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OPENGL SAMPLE DRAWING");
	glClearColor(0.4, 0.4, 0.4, 0.0);
	InitLight();
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutMainLoop();
	return 0;
}