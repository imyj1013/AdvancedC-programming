#include <stdio.h>

#include <string.h>

#include <stdlib.h>

int main()
{
	int N, n1 = 0;
	char* p;
	scanf("%d", &N);
	p = (char*)malloc((N + 1) * sizeof(char));
	if (p == NULL) {      // 메모리 할당 실패하면,
		printf("Not enough memory!");      // 오류 상황 알리고,
		return -1;      // 함수 종료
	}
	scanf("%s", p);
	getchar();
	for (int i = 0; i < N-2; i++) {
		if (p[i] == 'c' && p[i+1] == 'a' && p[i+2] == 't') {
			n1++;
		}
	}
	printf("%d", n1);
	if (p != NULL)      // p가 NULL이 아닌 경우에만
		free(p);      //free() 함수 호출
	return 0;
}
