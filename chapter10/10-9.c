#include <stdio.h>

#include <string.h>

#include <stdlib.h>

int check(char* ar)
{
	int result, x=0;
	char* p, *q;
	for (p = ar, q = ar+strlen(ar)-1; p < ar + strlen(ar); p++, q--) {
		if (*p == *q) {   // 회문여부 판단
			x += 1;   // 같으면 1 더함
		}
	}
	if (x == strlen(ar)) {    // x가 문자열 길이와 같으면
		result = 1;    // 결과값은 1
	}
	else {    // x가 문자열 길이와 다르면
		result = 0;    // 결과값은 0
	}
	return result;    // 결과값 반환
}

int main() 
{
	char str[31];
	scanf("%s", str);    // 문자열 입력
	printf("%d %d", strlen(str), check(str));   // 문자열 길이와 회문여부 출력
	return 0;
}
