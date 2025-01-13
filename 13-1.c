#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cal(int a, int b) {
	int re;
	if (a > b) {
		int t = a;
		a = b;
		b = t;
	}
	re = b;
	if (a != 0 && b != 0) {
		re = cal(b % a, a);
	}
	return re;
}


int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", cal(a, b));
	return 0;
}
