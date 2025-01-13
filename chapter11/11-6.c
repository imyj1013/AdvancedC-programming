#include<stdio.h>

struct num {    // 구조체 정의
	int n, c;
};

int main()
{
	struct num a[10];    // 구조체 선언
	for (int i = 0; i < 10; i++) {
		scanf("%d", &a[i].n);    // 10개의 정수 입력받음
		a[i].c = 1;     // 순위 초기화
	}
	for (int i = 0; i < 10; i++) {     // 순위 계산
		for (int j = 0; j < 10; j++) {
			if (a[i].n < a[j].n) {     // a[i].n이 a[j].n보다 크면
				a[i].c++;     // a[j].n에 1 더함
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		if (a[i].c == 3) {     // 3번째 순위 찾음
			printf("%d ", a[i].n);     // 해당 순위의 정수 출력
			break;
		}
	}
	for (int i = 0; i < 10; i++) {
		if (a[i].c == 7) {      // 7번째 순위 찾음
			printf("%d ", a[i].n);     // 해당 순위의 정수 출력
			break;
		}
	}
	return 0;
}
