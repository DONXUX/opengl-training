#include <Windows.h>
#include <glut.h>
int Width, Height;

void Init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, 0.5, 5.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void DrawScene() {
	glColor3f(0.7, 0.7, 0.7);
	glPushMatrix();
	glTranslatef(0.0, -1.0, 0.0);
	glBegin(GL_QUADS);
		glVertex3f(2.0, 0.0, 2.0);
		glVertex3f(2.0, 0.0, -2.0);
		glVertex3f(-2.0, 0.0, -2.0);
		glVertex3f(-2.0, 0.0, 2.0);
	glEnd();
	glPopMatrix();
	glColor3f(0.3, 0.3, 0.7);
	glPushMatrix();
		glTranslatef(0.0, 0.0, -0.5);
		glutWireTeapot(1.0);
	glPopMatrix();
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glViewport(0, 0, Width / 2, Height / 2);
	glPushMatrix();
		gluLookAt(0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		DrawScene();
	glPopMatrix();
	glViewport(Width / 2, 0, Width / 2, Height / 2);
	glPushMatrix();
		gluLookAt(1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		DrawScene();
	glPopMatrix();
	glViewport(0, Height / 2, Width / 2, Height / 2);
	glPushMatrix();
		gluLookAt(0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);
		DrawScene();
	glPopMatrix();
	glViewport(Width / 2, Height / 2, Width / 2, Height / 2);
	glMatrixMode(GL_PROJECTION);

	glPushMatrix();
		glLoadIdentity();
		gluPerspective(30, (GLdouble)Width / (GLdouble)Height, 3.0, 50.0);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
			gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
			DrawScene();
		glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glFlush();
}

void MyReshape(int w, int h) {
	Width = w; Height = h;
	GLdouble aspectRatio = (GLdouble)w / (GLdouble)h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (Width < Height)
		glOrtho(-2.0, 2.0, -2.0 / aspectRatio, 2.0 / aspectRatio, 0.5, 5.0);
	else
		glOrtho(-2.0 * aspectRatio, 2.0 * aspectRatio, -2.0, 2.0, 0.5, 5.0);
}

int main(int argc, char** argv) {
	Width = 500; Height = 500;
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(Width, Height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("ddd')");
	Init();
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutMainLoop();
	return 0;
}