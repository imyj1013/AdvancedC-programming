#include<stdio.h>

struct score {    // 구조체 정의
	char n[10];
	int s;
};

int main()
{
	int avg;   // 평균 변수 선언
	struct score one;    // 구조체 선언
	struct score two;    // 구조체 선언
	struct score three;    // 구조체 선언
	struct score four;    // 구조체 선언
	struct score five;    // 구조체 선언
	scanf("%s %d", &one.n, &one.s);    // 이름과 점수 입력받음
	scanf("%s %d", &two.n, &two.s);    // 이름과 점수 입력받음
	scanf("%s %d", &three.n, &three.s);    // 이름과 점수 입력받음
	scanf("%s %d", &four.n, &four.s);    // 이름과 점수 입력받음
	scanf("%s %d", &five.n, &five.s);    // 이름과 점수 입력받음
	avg = (one.s + two.s + three.s + four.s + five.s) / 5;   // 평균 계산하여 저장
	if (one.s <= avg) {     // 평균 점수 이하이면
		printf("%s\n", one.n);     // 이름 출력
	}
	if (two.s <= avg) {    // 평균 점수 이하이면
		printf("%s\n", two.n);     // 이름 출력
	}
	if (three.s <= avg) {    // 평균 점수 이하이면
		printf("%s\n", three.n);     // 이름 출력
	}
	if (four.s <= avg) {    // 평균 점수 이하이면
		printf("%s\n", four.n);     // 이름 출력
	}
	if (five.s <= avg) {    // 평균 점수 이하이면
		printf("%s\n", five.n);     // 이름 출력
	}
	return 0;
}
