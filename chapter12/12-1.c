#include <stdio.h>

#include <string.h>

#include <stdlib.h>

int main() {
	int N, *ss, result = 0;   // 입력받을 정수 개수, 포인터, 합
	scanf("%d", &N);    // 입력받을 개수 입력
	ss = (int*) malloc(N * sizeof(int));    // 동적메모리 할당
	if (ss == NULL) {      // 메모리 할당 실패하면,
		printf("Not enough memory!");      // 오류 상황 알리고,
		return -1;      // 함수 종료
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &ss[i]);     // 정수 입력
		result += ss[i];    // 합에 더함
	}
	printf("%d", result);    // 합 출력
	if (ss != NULL)      // p가 NULL이 아닌 경우에만
		free(ss);      //free() 함수 호출
	return 0;
}
