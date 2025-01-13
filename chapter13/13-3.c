#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int f(int a, int b, int i) {
	int sum = a + b;
	i--;
	if (i > 0) {
		sum = f(b, sum, i);
	}
	return sum;
}

int main() {
	int a = 0, b = 1, n;
	scanf("%d", &n);
	if (n == 0) {
		printf("0");
	}
	else {
		printf("%d", f(a, b, n - 1));
	}
	return 0;
}
