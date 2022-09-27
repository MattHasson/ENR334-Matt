#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	int a[3], b[3], c[3];

	a[0] = 4, a[1] = 2, a[2] = 7;
	b[0] = 5, b[1] = 3, b[2] = 9;

	c[0] = a[1] * b[2];
	c[1] = a[2] * b[0];
	c[2] = a[0] * b[1];

	for(int i = 0; i <= 2; i++) {
		printf("The value for C[%d] is %d\n", i, c[i]);
	}

	return 0;
}
