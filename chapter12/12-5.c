#include <stdio.h>

#include <string.h>

#include <stdlib.h>

int main() {
	int N;
	int* p;
	scanf("%d", &N);
	p = (int*)malloc(N * sizeof(int));
	if (p == NULL) {      // 메모리 할당 실패하면,
		printf("Not enough memory!");      // 오류 상황 알리고,
		return -1;      // 함수 종료
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &p[i]);
	}
	for (int i = 0; i < N-1; i++) {
		if (p[i] > p[i + 1]) {
			int tmp = p[i];
			p[i] = p[i + 1];
			p[i + 1] = tmp;
		}
	}
	for (int i = 0; i < N; i++) {
		printf("%d\n", p[i]);
	}
	if (p != NULL)      // p가 NULL이 아닌 경우에만
		free(p);      //free() 함수 호출
	return 0;
}
