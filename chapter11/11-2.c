#include<stdio.h>

struct time {    // 구조체 정의
	int h, m, s;
};

int main()
{
	struct time one;    // 구조체 선언
	struct time two;    // 구조체 선언
	struct time three;    // 구조체 선언
	scanf("%d %d %d", &one.h, &one.m, &one.s);    // 시간 입력
	scanf("%d %d %d", &two.h, &two.m, &two.s);    // 시간 입력
	three.s = two.s - one.s;    // 초 단위 계산
	if (three.s < 0) {     // 계산한 초 차이가 음수라면
		three.s = 60 - (one.s - two.s);    // 차이의 양수를 60에서 뺌
		two.m--;    // 분에서 1 뺌
	}
	three.m = two.m - one.m;    //  분 단위 계산
	if (three.m < 0) {    // 계산한 분 차이가 음수라면
		three.m = 60 - (one.m - two.m);    // 차이의 양수를 60에서 뺌
		two.h--;    // 시간에서 1을 뺌
	}
	three.h = two.h - one.h;   // 시간 단위 계산
	printf("%d %d %d", three.h, three.m, three.s);    // 두 시각 차이 출력
	return 0;
}
