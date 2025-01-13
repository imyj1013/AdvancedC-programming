#include<stdio.h>

void gcdlcm(int a, int b, int* p, int* q)
{
	int min, max;    // 변수 선언
	if (a <= b) {
		min = a;    // a,b 중 작은 값은 min에 저장
		max = b;    // a,b 중 큰 값은 max에 저장
	}
	else {
		min = b;    // a,b 중 작은 값은 min에 저장
		max = a;    // a,b 중 큰 값은 max에 저장
	}
	for (int i = min; i >= 1; i--) {
		if (a % i == 0 && b % i == 0) {    // i가 a, b의 공약수라면
			*p = i;     // 최대공약수는 i
			break;    // 반복문 종료
		}
	}
	int j=max;
	while (1) {
		if (j % a == 0 && j % b == 0) {    // j가 a, b의 공배수라면
			*q = j;    // 최소공배수는 j
			break;     // 반복문 종료
		}
		j += 1;
	}
}

int main()
{
	int x, y, m, n;
	scanf("%d %d", &x, &y);    // 정수 2개 입력받음
	gcdlcm(x, y, &m, &n);     // 함수 종료
	printf("%d %d", m, n);     // 최대공약수와 최소공배수 출력
	return 0;
}
