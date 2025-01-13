#include <stdio.h>

#include <string.h>

#include <stdlib.h>

int main()
{
	char str1[51], str2[51];    // 배열 선언
	int a;
	scanf("%s", str1);    // 문자열 입력
	scanf("%s", str2);    // 문자열 입력
	a = strcmp(str1, str2);    // 사전순 비교
	if (a > 0) {
		printf("%s%s", str1, str2);    // 사전역순으로 더 빠른 문자열먼저 출력
	}
	else {
		printf("%s%s", str2, str1);    // 사전역순으로 더 빠른 문자열먼저 출력
	}
	return 0;
}
