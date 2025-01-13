#include<stdio.h>

int main()
{
	char str1[41], str2[21];    // 배열 선언
	int a = 0, b = 0, x, y, i, j;    // 변수 선언
	scanf("%s", str1);    // 문자열 입력받음
	scanf("%s", str2);    // 문자열 입력받음
	scanf("%d", &x);    // 삽입위치 입력받음
	scanf("%d", &y);
	while (str1[a]) {
		a += 1;     // 첫번째 문자열 길이 세기
	}
	while (str2[b]) {
		b += 1;     // 두번째 문자열 길이 세기
	}
	str1[a] = 'a';
	for (i = a + b - 1; i >= x + b; i--) {
		str1[i] = str1[i - b];     // 삽입위치 뒤로 있는 문자 뒤로 미루기
	}
	str1[a + b] = NULL;
	if (y == 0) {    // y가 0이면
		for (i = x, j = 0; i < x + b; i++, j++) {
			str1[i] = str2[j];     // 정순으로 삽입
		}
	}
	else {    // y가 1이면
		for (i = x, j = b-1; i < x + b; i++, j--) {
			str1[i] = str2[j];    // 역순으로 삽입
		}
	}
	printf("%s", str1);    // 합친 문자열 출력
	return 0;
}
