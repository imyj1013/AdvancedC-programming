#include <stdio.h>

#include <string.h>

#include <stdlib.h>

int main() {
	int N;
	char ch[101];
	char** p;
	scanf("%d", &N);
	getchar();
	p = (char**)malloc(N * sizeof(char*)); // 포인터 배열 할당
	if (p == NULL) {      // 메모리 할당 실패하면,
		printf("Not enough memory!");      // 오류 상황 알리고,
		return -1;      // 함수 종료
	}
	for (int i = 0; i < N; i++) {
		gets(ch);
		p[i] = (char*)malloc((strlen(ch) + 1) * sizeof(char)); // 1차원 배열 할당
		if (p[i] == NULL) {      // 메모리 할당 실패하면,
			printf("Not enough memory!");      // 오류 상황 알리고,
			return -1;      // 함수 종료
		}
		strcpy(p[i], ch);
	}
	for (int i = 0; i < N-1; i++) {
		for (int j = i; j < N; j++) {
			if (strlen(p[i]) < strlen(p[j])) {
				char *tmp;
				tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		printf("%s\n", p[i]);
	}
	return 0;
}
