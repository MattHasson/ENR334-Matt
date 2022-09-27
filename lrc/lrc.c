#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv){
	
	float A=1, B=1, C=1;
	float x=0, x0;
	float v=1, v0;
	float a=0, a0;
	float dt=0.1;

	for (float t=0; t<20; t+=dt) {
		x0 = x;
		v0 = v;
		a0 = a;
		x = x0 + v0*dt;
		v = v0 + a0*dt;
		a = (-B/A)*v0-(C/A)*x0;
		printf("%f %f %f %f\n", t, x, v, a);
	}
	
	return 0;
}
