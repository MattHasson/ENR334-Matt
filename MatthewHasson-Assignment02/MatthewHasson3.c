#include <stdlib.h>
#include <stdio.h>

int usage (char *name);

int main (int argc, char **argv) {
	
	if (argc != 10) return usage(argv[0]);

	int i,j,k = 1;
	float det = 0;
	float A[3][3], B[3][3], e[3][3][3];
	for (i=0; i<=2; i++) {
		for (j=0; j<=2; j++) {
			A[i][j] = atof(argv[k++]);	
		}
	}
	
	B[0][0] = A[1][1] * A[2][2] - A[1][2] * A[2][1];
	B[0][1] = A[0][2] * A[2][1] - A[0][1] * A[2][2];
	B[0][2] = A[0][1] * A[1][2] - A[0][2] * A[1][1];
	B[1][0] = A[1][2] * A[2][0] - A[1][0] * A[2][2];
	B[1][1] = A[0][0] * A[2][2] - A[0][2] * A[2][0];
	B[1][2] = A[0][2] * A[1][0] - A[0][0] * A[1][2];
	B[2][0] = A[1][0] * A[2][1] - A[1][1] * A[2][0];
	B[2][1] = A[0][1] * A[2][0] - A[0][0] * A[2][1];
	B[2][2] = A[0][0] * A[1][1] - A[0][1] * A[1][0];

	for (i=0; i<=2; i++) {
		for(j=0; j<=2; j++) {
			for (k=0; k<=2; k++) {
				e[i][j][k] = 0;
			}
		}
	}
	e[0][1][2] = 1;
	e[1][2][0] = 1;
	e[2][0][1] = 1;
	e[0][2][1] = -1;
	e[1][0][2] = -1;
	e[2][1][0] = -1;

	fprintf(stdout, "A = \n\n");
	for (i=0; i<=2; i++) {
		fprintf(stdout, " %3.0f %3.0f %3.0f\n", A[i][0], A[i][1], A[i][2]);
		for (j=0; j<=2; j++) {
			for (k=0; k<=2; k++) {
				det = det + e[i][j][k] * A[0][i]*A[1][j]*A[2][k];
			}
		}
	}

	if (det == 0) {
		fprintf(stderr, "\nSingular Matrix! Inverse does not exist!\n\n");
		return 1;
	}

	fprintf(stdout, "\nAI = \n\n");
	for (i=0; i<=2; i++) {
		fprintf(stdout, " %9.5f %9.5f %9.5f\n", B[i][0]/det, B[i][1]/det, B[i][2]/det);
	}
	fprintf(stdout, "\n");

	return 0;
}

int usage(char *name) {
	fprintf(stderr, "USAGE: %s a b c d e f g h i j\n", name);
	return 1;
}
