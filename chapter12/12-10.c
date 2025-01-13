#include <stdio.h>

#include <string.h>

#include <stdlib.h>

int main()
{
	int N;
	int* p;
	scanf("%d", &N);
	p = (int*)malloc((N-1) * sizeof(int));
	if (p == NULL) {      // 메모리 할당 실패하면,
		printf("Not enough memory!");      // 오류 상황 알리고,
		return -1;      // 함수 종료
	}
	for (int i = 0; i < N-1; i++) {
		if (i < (N - 1) / 2) {
			p[i] = i;

		}
		else {
			p[i] = i + 1;
		}
	}
	for (int i = 0; i < N-1; i++) {
		printf(" %d", p[i]);
	}
	if (p != NULL)      // p가 NULL이 아닌 경우에만
		free(p);      //free() 함수 호출
	return 0;
}
