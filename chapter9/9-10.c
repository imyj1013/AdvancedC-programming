#include<stdio.h>

void strcpy(char a[], char b[])
{
	char* p, * q;     // 포인터 선언
	for (p = a, q = b; p < a + 6; p++, q++) {
		*q = *p;     // 배열 a에 담긴 문자를 배열 b에 복사
	}
}

int main()
{
	char a[6], b[6];    // 배열 선언
	char* p;     // 포인터 선언
	for (p = a; p < a + 6; p++) {
		scanf("%c", p);     // 문자 6개 입력받음
	}
	strcpy(a, b);      // 함수 호출
	for (p = b; p < b + 6; p++) {
		printf("%c", *p);      // 문자 6개 출력
	}
	return 0;
}
