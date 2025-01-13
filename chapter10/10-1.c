#include<stdio.h>

int main()
{
	char str[21];   // 배열 선언
	int i;    // 변수 선언
	scanf("%s", str);    // 문자열 입력받음
	for (i = 0; i < 21; i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {    // 문자가 소문자이면
			printf("%c", str[i]);    // 소문자 출력
		}
	}
	return 0;
}
