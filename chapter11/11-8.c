#include<stdio.h>

struct complex {     // 구조체 정의
	float real, im;
};

struct complex add (struct complex a, struct complex b)    // 함수 정의
{
	struct complex c;   // 구조체 선언
	c.real = a.real + b.real;    // 실수부 계산
	c.im = a.im + b.im;    // 허수부 계산
	return c;    // 구조체 c반환
}

int main()
{
	struct complex one;   // 구조체 선언
	struct complex two;   // 구조체 선언
	struct complex three;   // 구조체 선언
	scanf("%f %f", &one.real, &one.im);    // 첫번째 복소수 입력
	scanf("%f %f", &two.real, &two.im);    // 두번째 복소수 입력
	three = add(one, two);    // 함수호출
	printf("%.1f + %.1fi", three.real, three.im);    // 두 복소수의 합 출력
	return 0;
}
