#include<stdio.h>

int main()
{
	char str[10];   // 배열 선언
	int a, i = 0;   // 변수 선언
	scanf("%d", &a);    // 정수 입력받음
	while (a >= 10) {
		str[i] = (a % 10) + '0';   // 정수를 문자로 변환하여 배열에 저장
		a /= 10;   // a를 10으로 나눔
		i += 1;   // i에 1을 더함

	}
	str[i] = (a % 10) + '0';   // 정수를 문자로 변환하여 배열에 저장
	i += 1;   // i에 1을 더함
	str[i] = NULL;
	printf("%s", str);    // 문자열 출력
	return 0;
}
