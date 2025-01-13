#include <stdio.h>

#include <string.h>

#include <stdlib.h>

int main()
{
	char str[101], short_str[101];     // 입력받아 비교할 문자열, 길이가 가장 짧은 문자열
	int N, i;     // 입력받을 문자열의 수, 반복문 매개변수

	scanf("%d", &N);     // 입력받을 문자열의 수를 입력받음
	getchar();

	gets(short_str);     // 처음 입력받는 문자열은 short_str에 저장
	for (i = 1; i < N; i++) {
		gets(str);     // 문자열 str에 입력받음
		if (strlen(short_str) > strlen(str)) {     // 문자열 길이 비교
			strcpy(short_str, str);     // 더 짧은 문자열을 short_str에 복사
		}
	}

	printf("%s", short_str);     // 길이가 가장 짧은 문자열 출력
	return 0;
}
