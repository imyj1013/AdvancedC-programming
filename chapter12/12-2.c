#include <stdio.h>

#include <string.h>

#include <stdlib.h>

int main() {
	int N;    // 입력받을 개수
	float* ss, result;   // 포인터, 가장 큰값
	scanf("%d", &N);   // 입력받을 개수 입력
	ss = (float*)malloc(N * sizeof(float));    // 동적메모리 할당
	if (ss == NULL) {      // 메모리 할당 실패하면,
		printf("Not enough memory!");      // 오류 상황 알리고,
		return -1;      // 함수 종료
	}
	for (int i = 0; i < N; i++) {
		scanf("%f", &ss[i]);   // 실수 입력
		if (i == 0) {    // i가 0이면
			result = ss[i];    // 결과값에 저장
		}
		else {
			if (result < ss[i]) {    // 가장큰값보다 ss[i]가 더크면
				result = ss[i];   // ss[i] 저장
			}
		}
	}
	printf("%.2f", result);    // 가장 큰값 출력
	if (ss != NULL)      // p가 NULL이 아닌 경우에만
		free(ss);      //free() 함수 호출
	return 0;
}
