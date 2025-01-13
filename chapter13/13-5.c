#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void pswap(int** ppx, int** ppy) {
	int* t;
	t = *ppx;
	*ppx = *ppy;
	*ppy = t;
}


int main() {
	int x, y;
	int *px, *py;
	px = &x;
	py = &y;
	scanf("%d %d", px, py);
	pswap(&px, &py);
	printf("%d %d", *px, *py);
	return 0;
}
