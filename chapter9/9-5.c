#include<stdio.h>

int main() {
	int arr[5], rank[5];    // 배열 선언
	int*p,*q, *r;    // 포인터 선언
	for (p = arr; p < arr + 5; p++) {
		scanf("%d", p);     // 5개 정수 입력받음
	}
	for (p = arr, q = rank; p < arr + 5; p++, q++) {
		*q = 1;    // 1로 초기화
		for (r = arr; r < arr + 5; r++) {
			if (*p < *r) {
				*q += 1;     // *p가 *r보다 작으면 *q에 1을 더함
			}
		}
	}
	for (p = arr, q = rank; p < arr + 5; p++, q++) {
		printf("%d=r%d ", *p, *q);     // 각 정수의 내림차순 상의 순서를 출력
	}
	return 0;
}
