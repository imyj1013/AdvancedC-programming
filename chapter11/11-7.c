#include<stdio.h>

struct student {    // 구조체 정의
	char n[20];
	int s1, s2, s3;
	float avg;
	char score;
};

int main()
{
	int N;    // 학생 수 선언
	struct student st[50], * p = st;    // 구조체 선언
	scanf("%d", &N);     // 학생 수 입력
	for (p = st; p < st + N; p++) {
		scanf("%s %d %d %d", &p->n, &p->s1, &p->s2, &p->s3);   // 이름, 점수 3개 입력
		p->avg = (p->s1 + p->s2 + p->s3) / 3.0;    // 평균 계산
		if (90 <= p->avg) {     // 평균이 90 이상이면
			printf("%s %.1f A\n", p->n, p->avg);    // 이름, 평균, A학점 출력
		}
		else if (80 <= p->avg) {     // 평균이 80 이상이면
			printf("%s %.1f B\n", p->n, p->avg);    // 이름, 평균, B학점 출력
		}
		else if (70 <= p->avg) {     // 평균이 70 이상이면
			printf("%s %.1f C\n", p->n, p->avg);    // 이름, 평균, C학점 출력
		}
		else {
			printf("%s %.1f D\n", p->n, p->avg);    // 이름, 평균, D학점 출력
		}
	}
	return 0;
}
