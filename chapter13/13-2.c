#pragma warning(disable: 4996)
#pragma warning(disable: 4013)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int fac(int a) {
	double c = 1;
	for (int i = 1; i <= a; i++) {
		c *= i;
	}
	return c;
}

int main() {
	int a;
	double re = 1;
	scanf("%d", &a);
	for (int i = 1; i <= a; i++) {
		re += (1.0 / fac(i));
	}
	printf("%.6f", re);
	return 0;
}
