#include<stdio.h>

int main()
{
	char str[101], s[101];   // 배열 선언
	int i=0, j, k;     // 변수 선언
	scanf("%s", str);    // 문자열 입력받음
	while (str[i]) {
		k = 0;
		printf("%s", str + i);   // 문자열의 인덱스 i부터 출력
		for (j = 0; j < i; j++,k++) {
			s[j] = str[k];    // 문자열의 인덱스 i까지를 s에 저장
		}
		s[j] = NULL;
		printf("%s", s);    // s 출력
		i += 1;   // i에 1을 더함
		printf("\n");   // 줄바꿈
	}
	return 0;
}
