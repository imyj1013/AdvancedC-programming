#include<stdio.h>

int main() {
	int x[3];    // 배열 선언
	int *p, *q;     // 포인터 선언
	for (p = x; p < x + 3; p++) {
		scanf("%d", p);      // 정수 3개 입력받음
	}
	for (p = x; p < x + 2; p++) {      // 오름차순으로 정렬
		for (q = p + 1; q < x + 3; q++) {
			if (*p < *q) {
				int a;
				a = *p;
				*p = *q;
				*q = a;
			}
		}
	}
	printf("%d", *(x+1));      // 중앙값 출력
	return 0;
}
