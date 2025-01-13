#include <stdio.h>

#include <string.h>

#include <stdlib.h>

struct student{      // 구조체 정의
    char name[21];      // 이름
    int kor, eng, math;    // 각 과목 점수
    double avg;    // 평균
};

void read_data(struct student* st, int N);   // 함수 선언

void sort_score(struct student* st, int N);   // 함수 선언

struct student* select_out(struct student* st, struct student* stst, int N);   // 함수 선언


int main()
{
    int N;   // 학생 수 선언
    struct student st1[49], st2[49];   // 구조체 배열 선언
    struct student* p1 = st1, * p2 = st2, *ppp;   // 구조체 포인터 선언
    scanf("%d", &N);    //  학생 수 입력받음
    read_data(p1, N);   // 함수 호출
    read_data(p2, N);   // 함수 호출
    sort_score(p1, N);   // 함수 호출
    sort_score(p2, N);   // 함수 호출
    for (ppp = select_out(p1, p2, N); ppp < select_out(p1, p2, N) + N; ppp++) {    // 중간 등수인 학생 평균이 더 큰 쪽 출력
        printf("%s %d %d %d %.1f\n", ppp->name, ppp->kor, ppp->eng, ppp->math, ppp->avg);     // 이름, 각 과목 점수, 평균 출력
    }
    return 0;
}

void read_data(struct student* st, int N)
{
    struct student * p;   // 구조체 포인터 선언
    for (p = st; p < st + N; p++) {
        scanf("%s %d %d %d", p->name, &p->kor, &p->eng, &p->math);    // 학생 이름과 각 과목 점수 입력받음
        p->avg = (p->kor + p->eng + p->math) / 3.0;     // 평균 구해서 저장
    }
}

void sort_score(struct student* st, int N)
{
    struct student* p, *pp;    // 구조체 포인터 선언
    struct student xx;      // 구조체 선언
    for (p = st; p < st + N; p++) {       // 정렬
        for (pp = p; pp < st + N; pp++) {
            if (p->avg < pp->avg) {    // 평균을 기준으로 비교
                xx = *p;
                *p = *pp;
                *pp = xx;
            }
            else if (p->avg == pp->avg) {    // 평균이 같으면
                if (p->kor < pp->kor) {    // 국어 점수 기준으로 비교
                    xx = *p;
                    *p = *pp;
                    *pp = xx;
                }
                else if (p->kor == pp->kor) {    // 국어 점수가 같으면
                    if (p->eng < pp->eng) {     // 영어 점수 기준으로 비교
                        xx = *p;
                        *p = *pp;
                        *pp = xx;
                    }
                    else if (p->eng == pp->eng) {    // 영어 점수가 같으면
                        if (p->math < pp->math) {     // 수학 점수 기준으로 비교
                            xx = *p;
                            *p = *pp;
                            *pp = xx;
                        }
                    }
                }
            }
        }
    }
}

struct student* select_out(struct student* st, struct student* stst, int N)
{
    struct student* result;     // 구조체 선언
    if ((st + (N - 1) / 2)->avg > (stst + (N - 1) / 2)->avg) {    // 중간 등수의 학생의 평균 비교
        result = st;    // 더 큰 쪽 저장
    }
    else {
        result = stst;    // 더 큰 쪽 저장
    }
    return result;    // 더 큰 쪽 반환
}
