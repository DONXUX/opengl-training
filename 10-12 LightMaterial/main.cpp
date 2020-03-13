#include <windows.h>
#include <glut.h>
#include <stdio.h>

GLfloat Ia = 0.5, Id = 0.5, Is = 0.5;				// ������ ���� 
GLfloat Ka = 0.5, Kd = 0.5, Ks = 0.5, Sn = 25.0;	// ������ ���� �ݻ� ��� (��üƯ���� ��Ÿ��)
GLfloat Px = -5.0, Py = -5.0, Pz = 5.0;			// ������ ��ġ(px, py, pz, 1.0)

void MyLightInit()
{
	// 0�� ���� ����
	GLfloat light0_ambient[] = { Ia, 0.0, 0.0, 1.0 };
	GLfloat light0_diffuse[] = { Id, 0.0, 0.0, 1.0 };
	GLfloat light0_specular[] = { Is, Is, Is, 1.0 };

	// 1�� ���� (Spot light) ����
	GLfloat light1_ambient[] = { 0.0, 0.0, Ia, 1.0 };
	GLfloat light1_diffuse[] = { 0.0, 0.0, Id, 1.0 };
	GLfloat light1_specular[] = { Is, Is, Is, 1.0 };


	// 0�� ���� Ȱ��ȭ
	glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);	// Ia: �ֺ���
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);	// Id: Ȯ�걤
	glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);	// Is: ��鱤

	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.0);	// �Ÿ� ����(���)
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION , 0.0);	// �Ÿ� ����(1����)
	glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.0);	// �Ÿ� ����(2����)

	// 1�� ���� Ȱ��ȭ (����Ʈ ����Ʈ)
	glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);	// Ia: �ֺ���
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);	// Id: Ȯ�걤
	glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);	// Is: ��鱤

	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.0);	// �Ÿ� ����(���)
	glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.0);	// �Ÿ� ����(1����)
	glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.0);	// �Ÿ� ����(2����)

}

void MyMaterialInit()
{
	GLfloat material_ambient[] = { Ka, Ka, Ka, 1.0 };
	GLfloat material_diffuse[] = { Kd, Kd, Kd, 1.0 };
	GLfloat material_specular[] = { Ks, Ks, Ks, 1.0 };
	GLfloat material_shiniess[] = { Sn };

	glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);	// Ka: �ֺ��� ���
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);	// Kd: Ȯ�걤 ���
	glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);	// Ks: ��鱤 ���
	glMaterialfv(GL_FRONT, GL_SHININESS, material_shiniess);// n: ���� ���
}

void MyReshape(int w, int h) {
	if (w < h)
		glViewport(0, 0, (GLsizei)w, (GLsizei)w);
	else
		glViewport(0, 0, (GLsizei)h, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);				//�������
	glLoadIdentity();							//�׵���� �ε�
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);	//��������
}

void DoKeyboard(unsigned char key, int x, int y)
{
	switch (key) {
	// �ֺ����� ���� �� ��� ����
	case 'q': {Ia += 0.1; Ka += 0.1; }
			break;
	case 'a': if (Ia > 0.1) { Ia -= 0.1; Ka -= 0.1; }
			break;
			
	// Ȯ�걤�� ���� �� ��� ����
	case 'e': {Id += 0.1; Kd += 0.1; }
			break;
	case 'd': if (Id > 0.1) { Id -= 0.1; Kd -= 0.1; }
			break;

	// ��鱤�� ���� �� ��� ����
	case 'w': {Is += 0.1; Ks += 0.1; }
			break;
	case 's': if (Is > 0.1) { Is -= 0.1; Ks -= 0.1; }
			break;

	// ��鱤�� ���� ��� ����
	case 'n': Sn += 5; break;
	case 'm': Sn -= 5; break;

	// ������ ��ġ
	case 'x': Px += 1.0; break;
	case 'y': Py += 1.0; break;
	case 'z': Pz += 1.0; break;

	// �ʱ�ȭ
	case 'i':
		Ia = Id = Is = 0.5;
		Ka = Kd = Ks = 0.5; Sn = 25.0;
		Px = -5.0, Py = -5.0, Pz = 5.0;
		break;
	}

	char info[128];
	sprintf_s(info, "a=(%.1f, %.1f), d=(%.1f, %.1f), s=(%.1f, %.1f, %.1f), p=(%.1f, %.1f, %.1f)",
		Ka, Ia, Kd, Id, Ks, Is, Sn, Px, Py, Pz);
	glutSetWindowTitle(info);
	MyLightInit();
	MyMaterialInit();
	glutPostRedisplay();
}


void DoDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glPushMatrix();

	// ������ Ȱ��ȭ
	glEnable(GL_LIGHTING);

	// 0�� ���� ��ġ
	glEnable(GL_LIGHT0);
	GLfloat light0_position[] = { Px, Py, Pz, 1.0 };	// ������ ��ġ
	glLightfv(GL_LIGHT0, GL_POSITION, light0_position);

	// 1�� ���� ��ġ
	GLfloat light1_position[] = { -3.0, -5.0, 3.2, 1.0 };	// ���� ��ġ
	GLfloat light1_direction[] = { 4.0, 3.8, 2.8 };			// ���� ����
	GLfloat light1_spot_angle[] = { 55.0 };					// ���� �ޱ�

	//GLfloat light1_position[] = { -5.0, -5.0, 3.2, 1.0 };
	//GLfloat light1_direction[] = { 4.0, 3.8, 2.8 };
	//GLfloat light1_spot_angle[] = { 48.0 };

	glEnable(GL_LIGHT1);
	glLightfv(GL_LIGHT1, GL_POSITION, light1_position);	// ��ġ ����
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, light1_direction);		// ���� ����
	glLightfv(GL_LIGHT1, GL_SPOT_CUTOFF, light1_spot_angle);		// �ޱ� ����
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 1.0);

	glutSolidSphere(0.5, 800, 800);

	glPopMatrix();
	glFlush();
} 

int main()
{
	glutCreateWindow("OpenGL");
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
	MyLightInit();		// ���� ����
	MyMaterialInit();	// ������ ��� ����
	glutDisplayFunc(DoDisplay);
	glutReshapeFunc(MyReshape);
	glutKeyboardFunc(DoKeyboard);
	glutMainLoop();
	return 0;
}