#include <stdlib.h>
#include <stdio.h>

int usage(char *name);

int main(int argc, char **argv) {

	if (argc != 9) return usage(argv[0]);
	
	float r1 = atof(argv[1]);
	float r2 = atof(argv[2]);
	float v1 = atof(argv[3]);
	float v2 = atof(argv[4]);
	float y1 = atof(argv[5]);
	float y2 = atof(argv[6]);
	float T = atof(argv[7]);
	float dt = atof(argv[8]);
	float dy1, dy2;
	
	for (float t = 0; t <= T; t += dt) {
		dy1 = (-r1/v1*y1 + r2/v2*y2)*dt;
		dy2 = (r1/v1*y1 - r2/v2*y2)*dt;
		y1 += dy1;
		y2 += dy2;
		printf("%f\t%f\t%f\n", t, y1, y2);
	}
	

	return 0;	
}

int usage (char *name) {
	fprintf(stderr, "USAGE: %s r1 r2 v1 v2 y1 y2 T dt", name);
	fprintf(stderr, "\nWhere: \n  r1\t= flow rate from tank 1\n  r2\t= flow rate from tank 2");
	fprintf(stderr, "\n  v1\t= volume of tank 1\n  v2\t= volume of tank 2");
	fprintf(stderr, "\n  y1\t= initial lbs of fertilizer in tank 1\n  y2\t= initial lbs of fertilizer in tank 2");
	fprintf(stderr, "\n  T\t= simulation time\n  dt\t= time step");
	fprintf(stderr, "\n\n\tEXAMPLE:\n\t%s 2 2 100 100 0 150 120 1\n", name);
	return 1;
}
