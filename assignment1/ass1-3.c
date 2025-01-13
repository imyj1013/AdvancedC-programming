#include<stdio.h>

void PRT(int n, char* p);    // 함수원형선언

int main()
{
	char ar[100], c;    // 변수 선언
	char* p, * q = ar, * par = ar;    // 포인터 선언
	int n = 0, tmp = 0;    // 변수 선언
	for (p = ar; p < ar + 100; p++) {
		scanf("%c", p);     // 문자 입력받음
		if (*p == '#') {     // #이 입력되면
			break;    // 반복종료
		}
	}
	for (p = ar; p < ar + 100; p++) {
		if (*p == '#') {     // #이 나오면
			break;    // 반복종료
		}
		if (!( * (p - 1) >= 'a' && *(p - 1) <= 'z') && (* p >= 'a' && *p <= 'z')&&p!=ar) {     // *p가 단어의 첫번째 문자라면
			printf("\n");     // 줄바꿈
			q = p;     // q에 p 저장
		}
		if (*p >= 'a' && *p <= 'z') {     // *p가 알파벳이라면
			printf("%c", *p);      // *p 출력
			tmp += 1;    // 단어 길이 1 더함
		}
		if ((*p >= 'a' && *p <= 'z') && (!(*(p+1) >= 'a' && *(p+1) <= 'z'))) {    // *p가 단어의 마지막 문자라면
			if (tmp > n) {    // 해당 단어의 길이가 현재까지의 가장 긴 단어의 길이보다 길면
				n = tmp;     // n에 해당 단어의 길이 저장
				par = q;     // par에 해당 단어의 시작주소 저장

			}
			tmp = 0;    // tmp에 0 저장
		}
	}
	printf("\n%d %c\n", n, *par);   // 가장 긴 단어의 길이와 첫번째문자 출력
	PRT(n, par);    // 함수 호출
	return 0;
}

void PRT(int n, char* p)
{
	char* q;
	for (q = p; q < p + n; q++) {    // 가장 긴 단어 출력
		printf("%c", *q);    // 문자출력
	}
}
