#include<stdio.h>

int main() {
	char ch[10], A;   // 배열, 빈도수가 가장 높은 문자 선언
	int B=0, b;     // 가장 높은 빈도수, 그냥 빈도수 선언
	char *p, *q;    // 포인터 선언
	for (p = ch; p < ch + 10; p++) {
		scanf("%c", p);    // 문자 10개 입력받음
	}
	for (p = ch; p < ch + 10; p++) {
		b = 0;
		for (q = ch; q < ch + 10; q++) {
			if (*p == *q) {    // *p가 *q와 같으면
				b += 1;    // b에 1을 더함 
			}
		}
		if (B < b) {    // B가 b보다 작으면
			A = *p;     // A에 *p를 저장
			B = b;     // B에 b를 저장
		}
	}
	printf("%c %d", A, B);    // 가장 빈도수 높은 문자와 그의 빈도수 출력
	return 0;
}
