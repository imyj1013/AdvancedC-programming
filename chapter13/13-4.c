#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int x, y, z, t;
	unsigned int a;
	scanf("%d %d %d %d", &x, &y, &z, &t);
	a = t + (z << 8) + (y << 16) + (x << 24);
	printf("%d", a);
	return 0;
}
