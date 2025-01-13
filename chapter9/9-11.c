#include<stdio.h>

void addArray(int*x, int*y, int*z, int N)
{
	int* p, *q, *r;     // 포인터 선언
	for (p = x, q = y + N - 1, r = z; p < x + N; p++, q--, r++) {
		*r = *p + *q;   // x,y 포인터에 저장된 두 수를 더함
	}
}

int main()
{
	int N, a[20], b[20], c[20];    // 변수 선언
	int* p;
	scanf("%d", &N);     // N 입력 받음
	for (p = a; p < a + N; p++) {     // N개의 정수를 입력받음
		scanf("%d", p);
	}
	for (p = b; p < b + N; p++) {     // N개의 정수를 입력받음
		scanf("%d", p);
	}
	addArray(a, b, c, N);    // 함수 호출
	for (p = c; p < c + N; p++) {     // 배열 c에 저장된 값 출력
		printf(" %d", *p);
	}
	return 0;
}
