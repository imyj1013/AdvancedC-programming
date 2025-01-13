#include <stdio.h>

#include <string.h>

#include <stdlib.h>

int main()
{
	char str1[101], str2[101];      // 문자열 선언
	int result = 0, j = 0, cnt = 0;
	gets(str1);    // 문자열 입력
	gets(str2);    // 문자열 입력
	for (int i = 0; i < strlen(str1); i++) {
		if (str1[i] == str2[j]) {    // 단어 몇번 나타나는지 검사
			cnt++;    // 연속해서 겹치는 문자 수 세기
			j++;
		}
		else {     // 안 겹치면 리셋
			j = 0;
			cnt = 0;
			if (str1[i] == str2[j]) {    // 단어 몇번 나타나는지 검사
				cnt++;
				j++;
			}
		}
		if (cnt == strlen(str2)) {     // cnt 가 str2의 길이와 같으면
			result++;    // 횟수 1 증가
			j = 0;
			cnt = 0;
		}
	}
	printf("%d", result);    // 단어 나타나는 횟수 출력
	return 0;
}
