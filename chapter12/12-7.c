#include <stdio.h>

#include <string.h>

#include <stdlib.h>

int main()
{
	int c, r, a=0, b=1;
	char** p;
	scanf("%d %d", &c, &r);
	p = (char**)malloc(r * sizeof(char*)); // 포인터 배열 할당
	for (int i = 0; i < r; i++)
		p[i] = (char*)malloc((c+1) * sizeof(char)); // 1차원 배열 할당
	if (p == NULL) {      // 메모리 할당 실패하면,
		printf("Not enough memory!");      // 오류 상황 알리고,
		return -1;      // 함수 종료
	}
	for (int i = 0; i < r; i++) {
		if (p[i] == NULL) {      // 메모리 할당 실패하면,
			printf("Not enough memory!");      // 오류 상황 알리고,
			return -1;      // 함수 종료
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j <= c; j++) {
			if (j == c) {
				p[i][j] = '\0';
				a--;
			}
			if (a >= 26) {
				a = 0;
				b *= -1;
			}
			if (b == 1) {
				p[i][j] = (char)'a' + a;
			}
			else {
				p[i][j] = (char)'A' + a;
			}
			a++;
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf("%c ", p[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < 3; i++)
		free(p[i]); // 1차원 배열 메모리 해제
	free(p);
	return 0;
}
