#include <stdio.h>

#include <string.h>

#include <stdlib.h>

int main()
{
	int N, n1=0, n2=0;    // 문자열 길이, 포함횟수
	char* p;    // 포인터
	char c1, c2;    // 비교 문자 2개
	scanf("%d", &N);    // 문자열 길이 입력
	p = (char*)malloc((N+1) * sizeof(char));    // 동적메모리 할당
	if (p == NULL) {      // 메모리 할당 실패하면,
		printf("Not enough memory!");      // 오류 상황 알리고,
		return -1;      // 함수 종료
	}
	scanf("%s", p);    // 문자열 입력
	getchar();
	scanf("%c %c", &c1, &c2);    // 비교 문자 입력
	for (int i = 0; i < N; i++) {
		if (*(p + i) == c1) {    // 동일한 문자이면
			n1++;   // 횟수에 1 더함
		}
		if (*(p + i) == c2) {    // 동일한 문자이면
			n2++;   // 횟수에 1 더함
		}
	}
	printf("%d %d", n1, n2);    // 포함 횟수 출력
	if (p != NULL)      // p가 NULL이 아닌 경우에만
		free(p);      //free() 함수 호출
	return 0;
}
