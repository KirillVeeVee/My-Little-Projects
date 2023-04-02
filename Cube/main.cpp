#include <GL/freeglut.h>
#include <cmath>
#include <vector>

void setProjection(size_t i);
void KeyboardFunc(unsigned char key, int x, int y);


void init(void)
{
	glClearColor(0.5, 0.5, 0.5, 0);
	glShadeModel(GL_SMOOTH);
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 30.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(7,5, 7, 0, 0, 0, 0, 1, 0);
}


void PrintGrid() {
	glColor3f(1, 1, 1);
	glBegin(GL_LINES);
		for (GLfloat zi = 0; zi <= 4; zi += 1) {
			glVertex3f(0, 0, zi);
			glVertex3f(4, 0, zi);
		}
		for (GLfloat xi = 0; xi <= 4; xi += 1) {
			glVertex3f(xi, 0, 0);
			glVertex3f(xi, 0, 4);
		}
	glEnd();
}


int alpha = 0;
int angle = 0;
size_t curProj = 2;

std::vector<float> vertx = {0,0,0,0,1,-90,1,1,180,1,0,-270};

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	PrintGrid();
	glPushMatrix();
		setProjection(curProj);
		glRotatef(angle, 0, 0, 1);
		glTranslatef(0.5, 0.5, 0.5);
		glColor3f(1, 0, 0);
		glutWireCube(1);
	glPopMatrix();
	glutSwapBuffers();
}

void setProjection(size_t i) {
	size_t newIndex = i * 3;
	glTranslatef(vertx[newIndex],0,vertx[newIndex+1]);
	glRotatef(-vertx[newIndex+2], 0, 1, 0);
}

size_t cordOffset;
float offset;

void Spin() {
	angle = angle + 1;
	if (angle == 90) {
		glutIdleFunc(NULL);
		angle = 0;
		for (size_t i = 0; i < 4; ++i)
			vertx[i * 3 + cordOffset] += offset;
		glutKeyboardFunc(KeyboardFunc);
	}
	glutPostRedisplay();
}

void KeyboardFunc(unsigned char key,int x,int y) {
	switch (key) {
		case 'w': {
			if (vertx[0*3 + 1] != 0) {
				glutKeyboardFunc(NULL);
				curProj = 3;
				cordOffset = 1, offset = -1;
				glutIdleFunc(Spin);

			}
			break;
		}
		case 's': {
			if (vertx[2*3 + 1] != 4) {
				glutKeyboardFunc(NULL);
				curProj = 1;
				cordOffset = 1, offset = 1;
				glutIdleFunc(Spin);
			}
			break;
		}
		case 'a': {
			if (vertx[0 * 3] != 0) {
				glutKeyboardFunc(NULL);
				curProj = 0;
				cordOffset = 0, offset = -1;
				glutIdleFunc(Spin);

			}
			break;
		}
		case 'd': {
			if (vertx[2 * 3] != 4) {
				glutKeyboardFunc(NULL);
				curProj = 2;
				cordOffset = 0, offset = 1;
				glutIdleFunc(Spin);
			}
			break;
		}
	}
}



int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutSetOption(GLUT_MULTISAMPLE, 8);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_MULTISAMPLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Cube");
	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(KeyboardFunc);
	glutMainLoop();
	return 0;
}