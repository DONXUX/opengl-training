#include <windows.h>
#include <glut.h>
#include <glaux.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void DoDisplay();
GLfloat lx, ly = 1.0, lz;
GLfloat xAngle = 0, yAngle, zAngle;
GLboolean bAmbient;
GLboolean bAttach;
GLboolean bSwitch = true;
GLfloat vx, vy, vz = 0.0;
GLfloat speed = 0.1;

unsigned int MyTextureObject[1];
AUX_RGBImageRec* pTextureImage[1];  //텍스쳐 저장 공간을 가리키는 포인터

AUX_RGBImageRec* LoadBMP(char* filename)
{
	FILE* hFile = NULL;
	if (!filename) return NULL;

	hFile = fopen(filename, "r");
	if (hFile) {
		fclose(hFile);
		//printf("%s", filename);
		return auxDIBImageLoad(filename);
	}

	return NULL;
}

int LoadGLTextures(char* szFilePath)
{
	int Status = FALSE;
	glClearColor(0.0, 0.0, 0.0, 0.5);
	memset(pTextureImage, 0, sizeof(void*) * 1);    // 포인터를 널로

	if (pTextureImage[0] = LoadBMP(szFilePath)) {   // 비트맵을 로드하고 오류확인
		Status = TRUE;                              // 상태 플랙을 True로
		glGenTextures(1, &MyTextureObject[0]);      // 텍스쳐 생성
		glBindTexture(GL_TEXTURE_2D, MyTextureObject[0]);
		glTexImage2D(GL_TEXTURE_2D, 0, 3,
			pTextureImage[0]->sizeX, pTextureImage[0]->sizeY,
			0, GL_RGB, GL_UNSIGNED_BYTE, pTextureImage[0]->data);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glEnable(GL_TEXTURE_2D);
	}
	if (pTextureImage[0]) {                 // 텍스쳐가 존재하면
		if (pTextureImage[0]->data) {       // 텍스쳐 영상이 존재하면
			free(pTextureImage[0]->data);   // 텍스쳐 영상공간 반납
		}
		free(pTextureImage[0]);             // 텍스쳐 반납
	}
	return Status;
}

void MyTimer(int Value) {
	glutPostRedisplay();
	yAngle = (yAngle + speed);
	if (yAngle > 360.0) yAngle = 0.0;
	glutTimerFunc(5, MyTimer, 1);
}


void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'z':			
		vz += 0.1;
		glutPostRedisplay();
		break;
	case 'x':			
		vz -= 0.1;
		glutPostRedisplay();
		break;
	case 'a':
		vy += 0.1;
		glutPostRedisplay();
		break;
	case 's':
		vy -= 0.1;
		glutPostRedisplay();
		break;
	case 'q':
		vx += 0.1;
		glutPostRedisplay();
		break;
	case 'w':
		vx -= 0.1;
		glutPostRedisplay();
		break;
	case 'i':
		vx = 0.0, vy = 0.0, vz = 0.0;
		glutPostRedisplay();
		break;
	case 'f':
		bSwitch = bSwitch ? false : true;
		glutPostRedisplay();
		break;

	case 'n':
		speed *= 1.3;
		glutPostRedisplay();
		break;

	case 'm':
		speed /= 1.3;
		glutPostRedisplay();
		break;

		glutPostRedisplay();
	default:
		break;
	}
}

void printHelp() {
	printf("<도움말>\n");
	printf("q,w : x좌표 기준 시점 변환\n");
	printf("a,s : y좌표 기준 시점 변환\n");
	printf("z,x : z좌표 기준 시점 변환\n");
	printf("i : 시점 초기화\n");
	printf("f : 조명 on off\n");
	printf("n,m : 회전 속도 조절\n\n");
	printf("<설명>\n");
	printf("작품명 : 외로운 teapot\n");
	printf("나무 텍스처를 붙여 고풍스러운 분위기를 이끌어내고 조명은 앵글값 24도의 스포트라이트를 이용하였습니다.\n");
	printf("설정한 시간마다 조명과 바닥을 제외한 객체들은 회전변환을 합니다.\n");
	printf("조명은 시점이 변환이 되어도 고정시켜 물체가 이동하는 것처럼 연출하였습니다.\n");
}

int main(int argc, char* argv[]) { 
	char name[] = "wood24.bmp";
	glutInitWindowSize(600, 600);
	glutCreateWindow("OPEN GL");
	printHelp();
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
	glutTimerFunc(10, MyTimer, 1);
	glutDisplayFunc(DoDisplay);
	if (LoadGLTextures(name)) {
		glEnable(GL_TEXTURE_2D);
		glShadeModel(GL_SMOOTH);
		glClearDepth(1.0);
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);
		glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
		glutKeyboardFunc(MyKeyboard);
		glutMainLoop();
	}
	return 0;
}

void DoDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glShadeModel(GL_SMOOTH);    //구로 셰이딩
	glEnable(GL_DEPTH_TEST);

	glPushMatrix();
		glPushMatrix();
			if(bSwitch)
				glDisable(GL_LIGHTING);
			glTranslatef(0.0, 0.9, 0.0);
			glColor3f(1.0, 0.8, 0.3);
			glutSolidSphere(0.06, 30, 30);
			if (bSwitch)
				glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(0.0, 0.93, 0.0);
			glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
			glColor3f(0.15, 0.15, 0.15);
			glutSolidCone(0.1, 0.1, 50, 50);
			glEnable(GL_LIGHTING);
		glPopMatrix();


		GLfloat ambient[] = { 1.0, 0.8, 0.3, 1.0 };
		GLfloat diffuse[] = { 1.0, 0.8, 0.3, 1.0 };
		GLfloat specular[] = { 1.0, 0.8, 0.3, 1.0 };

		GLfloat position[] = { 0.0, 1.0, 0.0, 1.0 };	// 광원 위치
		GLfloat direction[] = { 0.0, -1.0, 0.0 };			// 광원 방향
		GLfloat spot_angle[] = { 24.0f };					// 광원 앵글

		glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);	// Id: 확산광
		glLightfv(GL_LIGHT0, GL_SPECULAR, specular);	// Is: 경면광

		glLightfv(GL_LIGHT0, GL_POSITION, position);	// 위치 설정
		glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, direction);		// 방향 설정
		glLightfv(GL_LIGHT0, GL_SPOT_CUTOFF, spot_angle);		// 앵글 설정
		glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 20.0f);

		GLfloat material_ambient[] = { 0.7, 0.7, 0.7, 1.0 };
		GLfloat material_diffuse[] = { 0.6, 0.6, 0.6, 1.0 };
		GLfloat material_specular[] = { 0.7, 0.7, 0.7, 1.0 };
		GLfloat material_shiniess[] = { 0.3 };

		glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);	// Ka: 주변광 계수
		glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);	// Kd: 확산광 계수
		glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);	// Ks: 경면광 계수
		glMaterialfv(GL_FRONT, GL_SHININESS, material_shiniess);// n: 광택 계수

		gluLookAt(vx, vy, vz, 0.0, 0.5, -1.0, 0.0, 1.0, 0.0);

		glPushMatrix();
			glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
			glutSolidTeapot(0.15);
			glPushMatrix();
				glColor3f(0.7, 0.7, 0.7);
				glTranslatef(0.5, -0.2, 0.0);
				glutSolidSphere(0.1, 50, 50);
			glPopMatrix();
			glPushMatrix();
				glColor3f(0.7, 0.7, 0.7);
				glTranslatef(-0.5, -0.2, 0.0);
				glutSolidSphere(0.1, 50, 50);
			glPopMatrix();
			glPushMatrix();
				glColor3f(0.7, 0.7, 0.7);
				glTranslatef(0.0, -0.2, 0.5);
				glutSolidSphere(0.1, 50, 50);
			glPopMatrix();
			glPushMatrix();
				glColor3f(0.7, 0.7, 0.7);
				glTranslatef(0.0, -0.2, -0.5);
				glutSolidSphere(0.1, 50, 50);
			glPopMatrix();
			glTranslatef(0.0, -0.35, 0.0);

			glDisable(GL_TEXTURE_GEN_T);
			glDisable(GL_TEXTURE_GEN_S);
			glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
			glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
			glEnable(GL_TEXTURE_GEN_T);
			glEnable(GL_TEXTURE_GEN_S);
			glBindTexture(GL_TEXTURE_2D, MyTextureObject[0]);
			glutSolidCube(0.5);
		glPopMatrix();
		
		glPushMatrix();
			glTranslatef(0.0, -0.6, 0.0);
			glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
			glColor3f(1.0, 1.0, 1.0);
			glBegin(GL_QUADS);
				glVertex2f(-0.5, 0.5);
				glVertex2f(0.5, 0.5);
				glVertex2f(0.5, -0.5);
				glVertex2f(-0.5, -0.5);
			glEnd();
		glPopMatrix();

		glDisable(GL_LIGHT0);
		if (bSwitch) {
			GLfloat lightpos[] = { lx, ly, lz, 1 };
			glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
			glEnable(GL_LIGHTING);
			glEnable(GL_LIGHT0);
		}

	glPopMatrix();

	glFlush();
}