#include<stdio.h>

void swap(int* p, int* q)
{
	int i;     // 변수 선언
	i = *p;     // i에 *p 저장
	*p = *q;     // *p에 *q 저장
	*q = i;      // *q에 i 저장
}

int main()
{
	int N, x[50],a ,b;     // 변수 선언
	int *p;     // 포인터 선언
	scanf("%d", &N);    // N 입력받음
	for (p = x; p < x + N; p++) {     // N개의 정수 입력받음
		scanf("%d", p);
	}
	scanf("%d %d", &a, &b);    // 교환할 인덱스 입력받음
	swap(x + a, x + b);     // 함수호출
	for (p = x; p < x + N; p++) {
		printf(" %d", *p);     // 교환한 배열 출력
	}
	return 0;
}
