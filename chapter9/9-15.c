#include<stdio.h>

void ABC(int* a, int k)
{
	int* p, *i=a;    // 포인터 선언
	int max = *a, n=*a;     // 변수 선언
	for (p = a; p < a + k; p++) {
		if (max < *p) {    // 배열의 원소가 max보다 크면
			max = *p;    // max에 *p 저장
			i = p;     // i에 p 저장
		}
	}
	*a = max;     // 첫번째 위치에 가장 큰값 저장
	*i = n;     // 첫번째 위치에 있던 수를 i 위치에 저장
}

int main()
{
	int x[10], i;     // 변수 선언
	int* p;
	for (p = x; p < x + 10; p++) {     // 10개의 정수 입력받음
		scanf("%d", p);
	}
	for (i = 10, p = x; i >= 1; i--, p++) {
		ABC(p, i);     // ABC 호출
	}
	for (p = x; p < x + 10; p++) {      //  내림차순 정렬된 배열 출력
		printf(" %d", *p);
	}
	return 0;
}
