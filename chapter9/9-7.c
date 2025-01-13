#include<stdio.h>

void input(int*a, int*b, int*c) {
	scanf("%d %d %d", a, b, c);    // 정수 3개 입력 받음
}

void output(int*a, int*b, int*c) {
	printf("%d %d %d", *a, *b, *c);    // 정수 3개 출력
}

int main() {
	int x, y, z;   // 변수 선언
	input(&x, &y, &z);   // input 함수 호출
	output(&x, &y, &z);  // output 함수 호출
	return 0;
}
