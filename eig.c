#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {

	float X, Y;
	float A[2][2];

	A[0][0] = 1.0, A[0][1] = 2.0;
	A[1][0] = 3.0, A[1][1] = 4.0;
	
	X = (A[0][0] + A[1][1])/2.0;
	Y = sqrt((A[0][0] + A[1][1])*(A[0][0] + A[1][1]) - 4.0*(A[0][0]*A[1][1] - A[0][1]*A[1][0]))/2.0;
	
	printf("A = \n\n");
	for (int i=0; i<2; i++) {
		printf("	%0.0f\t%0.0f\n", A[i][0], A[i][1]);
	}	

	printf("\nlambda1 = %f\n", X+Y);
	printf("lambda2 = %f\n", X-Y);

	return 0;
}
