#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int add(int x, int y) {
	return x + y;
}

int main() {
	int A, x, y;
	void* pA;
	pA = &A;
	int  (*fp)(int, int);
	fp = add;
	scanf("%d", &A);
	scanf("%d %d", &x, &y);
	printf("%d\n", *((int*)pA));
	printf("%d", fp(x, y));
	return 0;
}
