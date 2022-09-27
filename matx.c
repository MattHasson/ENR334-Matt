#include <stdlib.h>
#include <stdio.h>

int main (int argc, char **argv) {
	
	int A[2][2], B[2][2], C[2][2];
	A[0][0] = 1, A[0][1] = 2;
	A[1][0] = 3, A[1][1] = 4;
	B[0][0] = 5, B[0][1] = 6;
	B[1][0] = 7, B[1][1] = 8;
	
	for (int i=0; i<2; i++) {
		for (int j=0; j<2; j++) {
			C[i][j]=0;
			for (int k=0; k<2; k++) {
				C[i][j] = C[i][j] + A[i][k]*B[k][j];
			}
			printf("C[%d][%d]=%d\n", i, j, C[i][j]);
		}
	}

	return 0;
}
