#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	int A[3][3], B[3][3], C[3][3];
	A[0][0] = 1, A[0][1] = 2, A[0][2] = 3;
	A[1][0] = 4, A[1][1] = 5, A[1][2] = 6;
	A[2][0] = 7, A[2][1] = 8, A[2][2] = 9;
	B[0][0] = 10, B[0][1] = 11, B[0][2] = 12;
	B[1][0] = 13, B[1][1] = 14, B[1][2] = 15;
	B[2][0] = 16, B[2][1] = 17, B[2][2] = 18;
	
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			C[i][j] = 0;
			for (int k = 0; k <= 2; k++) {
				C[i][j] += A[i][k] * B[k][j];
			}
			printf("C[%d][%d] = %d\n", i, j, C[i][j]);
		}
	}

	return 0;
}
