#include<stdio.h>

struct stu {     // 구조체 정의
	char n[10];
	int s1, s2, s3;
	float avg;
};

void read_data(struct stu s[])     //    이름과 점수 입력
{
	for (int i = 0; i < 10; i++) {
		scanf("%s %d %d %d", s[i].n, &s[i].s1, &s[i].s2, &s[i].s3);    //    이름과 점수 입력
	}
}

void cal_avg(struct stu s[])       // 평균 계산
{
	for (int i = 0; i < 10; i++) {
		s[i].avg = (s[i].s1 + s[i].s2 + s[i].s3) / 3.0;     // 점수 모두 더해서 3으로 나눔
	}
}

void sort(struct stu s[])    // 내림차순으로 정렬
{
	for (int i = 0; i < 9; i++) {
		for (int j = i; j < 10; j++) {
			if (s[i].avg < s[j].avg) {    // s[i].avg이 s[j].avg보다 작으면
				float tmp = s[i].avg;     // float tmp에 s[i].avg 저장
				s[i].avg = s[j].avg;      // s[i].avg에  s[j].avg 저장
				s[j].avg = tmp;    // s[j].avg에 tmp 저장
				char a[10];
				strcpy(a, s[i].n);     // a에 s[i].n 복사
				strcpy(s[i].n, s[j].n);      // s[i].n에 s[j].n 복사
				strcpy(s[j].n, a);      // s[j].n에 a 복사
			}
		}
	}
}

void printf_score(struct stu s[])
{
	printf("%s %.2f\n", s[0].n, s[0].avg);      // 최고점 학생 이름과 평균 출력
	printf("%s %.2f\n", s[9].n, s[9].avg);      // 최저점 학생 이름과 평균 출력
	printf("%s %.2f\n", s[7].n, s[7].avg);      // 하위 30% 학생 이름과 평균 출력
	printf("%s %.2f\n", s[8].n, s[8].avg);      // 하위 30% 학생 이름과 평균 출력
	printf("%s %.2f", s[9].n, s[9].avg);      // 하위 30% 학생 이름과 평균 출력
}

int main()
{
	struct stu s[10];    // 구조체 선언
	read_data(s);    // 함수 호출
	cal_avg(s);     // 함수 호출
	sort(s);       // 함수 호출
	printf_score(s);     // 함수 호출
	return 0;
}
