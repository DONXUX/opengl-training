#include <Windows.h>
#include <glut.h>

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);	// 프레임 버퍼 지정 cf. GL_DEPTH_BUFFER_BIT
	glColor3f(1.0, 1.0, 1.0);		// default 전경색(foreground color)

	glViewport(0, 0, 300, 300);		// gl좌표계는 좌하단이 원점
	glutWireSphere(0.5, 5, 10ㅏ);	// 와이어 공 띄우기
	glFlush();
}

int main(void) {
	// glutInit() 함수는 주로 X윈도우 환경에서 사용 (MS윈도우 환경에서는 불필요)
	glutInitDisplayMode(GLUT_RGB);		// default	트루컬러 모드
	glutInitWindowSize(300, 300);		// default  폭과 높이 설정
	glutInitWindowPosition(0, 0);		// default  윈도우 x, y 좌표, glut좌표계는 좌상단이 원점
	glutCreateWindow("GLUT의 윈도우와 뷰 포트");
	glClearColor(0.0, 0.0, 0.0, 1.0);	// RGB + 불투명도
	glMatrixMode(GL_PROJECTION);		// 투상행렬  cf. GL_MODELVIEW, GL_TEXTURE
	glLoadIdentity();			
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);	// default
	glutDisplayFunc(MyDisplay);			// GLUT 콜백함수
	glutMainLoop();						// 이벤트 루프 진입

	return 0;
}

