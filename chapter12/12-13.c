#include <stdio.h>

#include <string.h>

#include <stdlib.h>

int main() {
	int N, D;
	int* p;
	scanf("%d", &N);
	p = (int*)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++) {
		scanf("%d", &p[i]);
	}
	scanf("%d", &D);
	p = (int*)realloc(p, (N-D) * sizeof(int));
	for (int i = 0; i < N - D; i++) {
		printf("%d\n", p[i]);
	}
	free(p);
	return 0;
}
