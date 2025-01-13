#include<stdio.h>

struct score {    // 구조체 정의
	char n[20];
	int s1, s2, s3;
};

int main()
{
	int N;   // 학생 수 선언
	float avg;    // 평균 선언
	struct score stu;    // 구조체 선언
	scanf("%d", &N);    // 학생 수 입력
	for (int i = 1; i <= N; i++) {
		scanf("%s %d %d %d", &stu.n, &stu.s1, &stu.s2, &stu.s3);    // 이름과 점수 입력 받음
		avg = (stu.s1 + stu.s2 + stu.s3) / 3.0;   // 평균 계산
		if (90 <= avg) {    //  평균이 90이하이면
			printf("%s %.1f A\n", stu.n, avg);    // 이름, 평균, A학점 출력
		}
		else if (80 <= avg) {    //  평균이 80이하이면
			printf("%s %.1f B\n", stu.n, avg);    // 이름, 평균, B학점 출력
		}
		else if (70 <= avg) {    //  평균이 70이하이면
			printf("%s %.1f C\n", stu.n, avg);    // 이름, 평균, C학점 출력
		}
		else {    //  평균이 70 미만이면
			printf("%s %.1f F\n", stu.n, avg);    // 이름, 평균, F학점 출력
		}
	}
	return 0;
}
