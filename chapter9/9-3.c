#include<stdio.h>

int main() {
	int ar[50], N, result=0;   // 배열, 정수 N, 정수 개수 선언
	int *p;    // 포인터 선언
	scanf("%d", &N);    // N 입력받음
	for (p = ar; p < ar + N; p++) {
		scanf("%d", p);    // 정수 N개 입력받음
	}
	for (p = ar; p < ar + N; p++) {
		if (*p == 0) {
			break;     // 0이 입력되면 반복 종료
		}
		result += 1;    // 결과값에 1을 더함
	}
	printf("%d", result);    // 0이 입력되기 전까지의 정수 개수 출력
}
