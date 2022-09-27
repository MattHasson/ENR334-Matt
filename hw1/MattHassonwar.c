#include <stdio.h>
#include <stdlib.h>

#define g 9.81

int usage (char *name);

int main (int argc, char **argv) {

	if (argc != 5) return usage(argv[0]);

	float y = atof(argv[1]);
	float v = atof(argv[2]);
	float T = atof(argv[3]);
	float dt = atof(argv[4]);
	
	for (float t = 0.0; t <= T; t += dt) {
		y = y + v*dt;
		v = v - g*dt;
		fprintf(stdout, "%f\t%f\t%f\n", t, y, v);
	}

	return 0;
}

int usage(char *name) {
	fprintf(stderr, "\nUsage: %s y0 v0 T dt\n\n", name);
	fprintf(stderr, "\ty0 = init position\n\tv0 = init velocity\n\tT = final time\n\tdt = time step size\n\n");
	fprintf(stderr, "Example: %s 200 100 35 0.1\n", name);
}
