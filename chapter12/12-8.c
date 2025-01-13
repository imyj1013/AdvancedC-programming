#include <stdio.h>

#include <string.h>

#include <stdlib.h>

int main() {
	int N, len=0, in=0;
	char**p;
	scanf("%d", &N);
	getchar();
	p = (char**)malloc(N * sizeof(char*)); // 포인터 배열 할당
	for (int i = 0; i < 3; i++)
		p[i] = (char*)malloc(100 * sizeof(char)); // 1차원 배열 할당
	if (p == NULL) {      // 메모리 할당 실패하면,
		printf("Not enough memory!");      // 오류 상황 알리고,
		return -1;      // 함수 종료
	}
	for (int i = 0; i < N; i++) {
		gets(p + i);
	}
	len = strlen(p);
	for (int i = 1; i < N; i++) {
		if (len > strlen(p + i)) {
			len = strlen(p + i);
			in = i;
		}
	}
	printf("%s", p + in);
	return 0;
}
