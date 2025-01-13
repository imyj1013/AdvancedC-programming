#include<stdio.h>

struct vector {     // 구조체 정의
	int x, y, z;
};

int main()
{
	struct vector one;     // 구조체 선언
	struct vector two;     // 구조체 선언
	struct vector three;     // 구조체 선언
	scanf("%d %d %d", &one.x, &one.y, &one.z);     // 3차원 벡터 입력
	scanf("%d %d %d", &two.x, &two.y, &two.z);     // 3차원 벡터 입력
	three.x = one.x * two.x;    // 두 원소를 곱함
	three.y = one.y * two.y;    // 두 원소를 곱함
	three.z = one.z * two.z;    // 두 원소를 곱함
	printf("%d %d %d\n%d", three.x, three.y, three.z, (three.x + three.y + three.z));     // 내적값 출력
	return 0;
}
