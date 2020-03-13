#include <Windows.h>
#include <glut.h>
#include <stdio.h>
GLboolean bCullFace = GL_FALSE;
GLboolean bCcwFront = GL_TRUE;

void DoMenu(int value) {
	switch (value) {
	case 1: bCullFace = GL_TRUE;	break;
	case 2: bCullFace = GL_FALSE;	break;
	case 3: bCcwFront = GL_TRUE;	break;
	case 4: bCcwFront = GL_FALSE;	break;
	}
	char info[128];
	sprintf_s(info, "Cull = %s, Front = %s", bCullFace ? "ON" : "OFF", bCcwFront ? "CCW" : "CW");
	glutSetWindowTitle(info);
	glutPostRedisplay();
}

void DoDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	if (bCullFace)
		glEnable(GL_CULL_FACE);
	else
		glDisable(GL_CULL_FACE);
	glFrontFace(bCcwFront ? GL_CCW : GL_CW);
	
	glBegin(GL_POLYGON);		// CCW
		glColor3f(1.0, 0.0, 0.0);
		glVertex2f(-0.5, 0.5);
		glVertex2f(-0.9, -0.5);
		glVertex2f(-0.1, -0.5);
	glEnd();

	glBegin(GL_POLYGON);		// CW
		glColor3f(0.0, 1.0, 0.0);
		glVertex2f(0.5, 0.5);
		glVertex2f(0.9, -0.5);
		glVertex2f(0.1, -0.5);
	glEnd();
	glFlush();
}

int main() {
	glutInitWindowSize(500, 500);
	glutCreateWindow("�ĸ����� ����");
	glutDisplayFunc(DoDisplay);
	glutCreateMenu(DoMenu);
	glutAddMenuEntry("CullFace ON", 1);
	glutAddMenuEntry("CullFace OFF", 2);
	glutAddMenuEntry("CCW", 3);
	glutAddMenuEntry("CW", 4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();

	return 0;
}