#include <stdio.h>

#include <string.h>

#include <stdlib.h>

int main()
{
	char str1[80], str2[10];
	int i, j, k, x, a = 0;
	scanf("%s", str1);    // 문자열 입력
	scanf("%s", str2);     // 문자열 입력
	printf("%d ", strlen(str1));    // 첫번째 문자열 길이 출력
	for (i = 0; i < strlen(str2); i++) {     // 포함여부 검사
		for (j = 0; j < strlen(str1); j++) {
			if (str2[i] == str1[j]) {    // str2[i]와 str1[j]가 같으면
				x = 0;
				for (k = 0; k < strlen(str2); k++) {
					if (str2[k] == str1[j+k]) {    // str2[k]와 str1[j+k]가 같으면
						x += 1;
					}
				}
				if (x == strlen(str2)) {
					a = 1;
					printf("%d", a);    // 포함 여부 출력
					return 0;
				}
			}
		}
	}
	printf("%d", a);    // 포함 여부 출력
	return 0;
}
