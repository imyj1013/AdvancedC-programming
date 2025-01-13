#include<stdio.h>

int add_to_k(int* a, int* b)
{
	int result=0;     // 반환값 선언
	int* p;
	for (p = a; p <= b; p++) {    // 두 포인터 사이의 원소들을 모두 더함
		result += *p;
	}
	return result;    // 배열의 원소를 더한 값 반환
}

int main()
{
	int N, d[100], Result=0;     // 변수 선언
	int* p;
	scanf("%d", &N);     // N 입력받음
	for (p = d; p < d + N; p++) {
		scanf("%d", p);     // N개의 정수를 입력받음
	}
	for (p = d; p < d + N; p++) {     // 함수 N번 호출
		Result+=add_to_k(d, p);    // 결과값에 함수 반환값 더함
	}
	printf("%d", Result);    // Result 출력
	return 0;
}
