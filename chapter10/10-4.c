#include<stdio.h>

int main()
{
	char str1[101], str2[101];   // 배열 선언
	int i = 0, j, a=0, A;   // 변수 선언
	scanf("%s", str1);    // 문자열 입력받음
	scanf("%s", str2);    // 문자열 입력받음
	while (str1[i]) {
		i += 1;     // 문자열의 길이 세기
	}
	for (j = 0; j < i; j++) {
		if (str1[j] == str2[j]) {   // 두 문자열이 같은지 확인
			a += 1;   // a에 1 더함
		}
		else {
			break;     // 문자가 다르다면 반복종료
		}
	}
	if (a == i) {   // a가 문자열의 길이 i와 같다면
		A = 1;   // A에 1 저장
	}
	else {
		A = 0;   // A에 0 저장
	}
	printf("%d %d", i, A);    // 첫번째 문자열의 길이와 일치 여부 출력
	return 0;
}
