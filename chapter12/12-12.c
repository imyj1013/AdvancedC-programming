#include <stdio.h>

#include <string.h>

#include <stdlib.h>

int main()
{
	int N;
	char** p;
	scanf("%d", &N);
	p = (char**)malloc(N * sizeof(char*)); // 포인터 배열 할당
	if (p == NULL) {      // 메모리 할당 실패하면,
		printf("Not enough memory!");      // 오류 상황 알리고,
		return -1;      // 함수 종료
	}
	for (int i = 0; i < N; i++) {
		char tmp[101];
		scanf("%s", tmp);
		p[i] = (char*)malloc((strlen(tmp)+1) * sizeof(char)); // 1차원 배열 할당
		strcpy(p[i], tmp);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - i-1; j++) {
			if (strcmp(p[j], p[j + 1]) > 0) {
				char* q;
				q = p[j];
				p[j] = p[j + 1];
				p[j + 1] = q;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		printf("%s\n", p[i]);
	}
	for (int i = 0; i < 3; i++)
		free(p[i]); // 1차원 배열 메모리 해제
	free(p);
	return 0;
}
