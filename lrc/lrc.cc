// Compile with: g++ lrc.cc -o lrc -Wall -lGL -lGLU -lglut
#include <time.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

using namespace std;

#define Lx 10
#define Ly 10
#define TIME 10
#define A 1
#define B 0.2
#define C 1
#define dt 0.05

class mass {
	float _x;
	float _v;
	float _a;
public:
	mass(void){ 
		_x = 0; 
		_v = 0; 
		_a = 0; 
	}
	void set_x(float x0){ _x = x0;}
	void set_v(float v0){ _v = v0;}
	void set_a(float a0){ _a = a0;}
	float x(void){ return(_x);}
	float v(void){ return(_v);}
	float a(void){ return(_a);}
};

mass m;

void Initialize(void);
void display(void);
void draw_axes(void);
void draw_mass(float x);
void key(unsigned char,int,int);
void Timer (int);

void propagate(mass *m) {
	float x = m->x(); 
	float v = m->v(); 
	float a = m->a(); 

	x = x + v*dt;
	v = v + a*dt;
	a = -B/A*v - C/A*x;

	m->set_x(x);
	m->set_v(v);
	m->set_a(a);
}


int main(int argc, char *argv[]) {
	srand(time(NULL));
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(50, 10);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Mass-spring Differential Equation");
	glutDisplayFunc(display);
	glutKeyboardFunc(key);
	Initialize();
	Timer(0);
	glutMainLoop();
	return 0;
}
void Initialize(void){
	glClearColor(0.8, 0.8, 0.9, 1.0);
	gluOrtho2D(-Lx, Lx, -Ly, Ly);
	m.set_x(0);
	m.set_v(8);
	m.set_a(0);
}
void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	draw_axes();
	draw_mass(m.x());
	propagate(&m);
	glutSwapBuffers();
}
void draw_axes(void){
	glColor3f(0.0, 0.0, 0.0);
  glEnable(GL_LINE_SMOOTH);
  glLineWidth(1.0);
  glBegin(GL_LINES);
    glVertex2f(-Lx+2, 0);
    glVertex2f(Lx-2, 0);
  glEnd();
  glBegin(GL_LINES);
    glVertex2f(0,-Ly+2);
    glVertex2f(0,Ly-2);
  glEnd();
}
void draw_mass(float x) {
	glColor3f(0.4, 0.8, 0.4);
	glPointSize(20.0);
	glBegin(GL_POINTS);
		glVertex2f(x,0);
	glEnd();
}
void key(unsigned char key, int x, int y) {
	switch(key) {
	case 'q':
		exit(0);
	default:
		break;
	}
}
void Timer (int iUnused) {
	glutPostRedisplay();
	glutTimerFunc(TIME, Timer, 0);
}

