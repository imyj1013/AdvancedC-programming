#include<stdio.h>

int arrsum(int* a, int* b)
{
	int result = 0;    // 반환값 선언
	int* p;
	for (p = a; p <= b; p++) {
		result += *p;     // 구간의 원소를 반환값에 더함
	}
	return result;
}

int main()
{
	int N, S, E, x[100];    // 변수 선언
	int* p;     // 포인터 선언
	scanf("%d %d %d", &N, &S, &E);    // N, S, E를 입력받음
	for (p = x; p < x + N; p++) {
		scanf("%d", p);     // N개의 값을 입력받음
	}
	printf("%d", arrsum(x + S, x + E));     // 함수호출, 반환값 출력
	return 0;
}
