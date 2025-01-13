#include<stdio.h>

int main()
{
	int n=0;    // 변수 선언
	char ar[1000];     //  배열 선언
	char* p, *q, *x;    //  포인터 선언
	for (p = ar; p < ar + 1000; p++) {
		scanf("%c", p);    // 문자 입력받음
		n += 1;    // n에 1 더함
		if (*p == '.' || *p == '?' || *p == '!') {    // 문장부호 . ? !가 입력되면
			break;     // 반복 종료
		}
	}
	x = ar + n - 1;
	for (p = ar + n - 2; p >= ar; p--) {    // 맨 뒤의 단어부터 출력
		if (*p == ' ') {    // 공백이 나오면
			for (q = p + 1; q < x; q++) {    // 공백 바로 다음에 입력된 단어 출력
				printf("%c", *q);    // 문자 출력
			}
			printf(" ");    // 공백출력
			x = p;    // x에 단어의 마지막 문자 주소 저장
		}
	}
	for (p = ar; p < x; p++) {     // 가장 처음에 입력된 단어 출력
		printf("%c", *p);   // 문자 출력
	}
	printf("%c", *(ar + n - 1));     // 문장부호 출력
	return 0;
}
