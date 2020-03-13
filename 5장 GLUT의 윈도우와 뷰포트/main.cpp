#include <Windows.h>
#include <glut.h>

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);	// ������ ���� ���� cf. GL_DEPTH_BUFFER_BIT
	glColor3f(1.0, 1.0, 1.0);		// default �����(foreground color)

	glViewport(0, 0, 300, 300);		// gl��ǥ��� ���ϴ��� ����
	glutWireSphere(0.5, 5, 10��);	// ���̾� �� ����
	glFlush();
}

int main(void) {
	// glutInit() �Լ��� �ַ� X������ ȯ�濡�� ��� (MS������ ȯ�濡���� ���ʿ�)
	glutInitDisplayMode(GLUT_RGB);		// default	Ʈ���÷� ���
	glutInitWindowSize(300, 300);		// default  ���� ���� ����
	glutInitWindowPosition(0, 0);		// default  ������ x, y ��ǥ, glut��ǥ��� �»���� ����
	glutCreateWindow("GLUT�� ������� �� ��Ʈ");
	glClearColor(0.0, 0.0, 0.0, 1.0);	// RGB + ������
	glMatrixMode(GL_PROJECTION);		// �������  cf. GL_MODELVIEW, GL_TEXTURE
	glLoadIdentity();			
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);	// default
	glutDisplayFunc(MyDisplay);			// GLUT �ݹ��Լ�
	glutMainLoop();						// �̺�Ʈ ���� ����

	return 0;
}

