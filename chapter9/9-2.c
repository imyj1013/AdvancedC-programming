#include<stdio.h>

int main() {
	char ch[20];     // 배열 선언
	char *p, *q;     // 포인터 선언
	for (p = ch; p < ch + 20; p++) {
		scanf("%c", p);    // #을 포함한 문자 입력받음
		if (*p == '\n') {
			break;     // \n을 입력받으면 반복 종료
		}
	}
	for (p = ch; p < ch + 20; p++) {
		if (*p == '#') {     // *p가 #이라면 
			for (q = p-1; q >= ch; q--) {
				printf("%c", *q);    // 그 전까지 입력된 문자 출력
			}
			break;    // 반복 종료
		}
	}
	return 0;
}
