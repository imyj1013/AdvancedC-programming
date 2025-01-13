#include <stdio.h>

#include <string.h>

#include <stdlib.h>

struct hotel_info {   // 구조체 정의
    char name[31];   // 호텔 이름
    int grade;    // 등급
    double reput, dist;    // 평판도, 거리
    char breakfast;    // 조식 포함 여부
};


int in_hotel_info(struct hotel_info* p);    // 함수 선언
void out_hotel_info(struct hotel_info* p, int N, int G, double D);    // 함수 선언

int main()
{
    struct hotel_info h[100], *ph = h;    // 구조체 선언
    int hcnt, G;    // 호텔 수, 기준 등급
    double D;     // 기준 거리
    hcnt = in_hotel_info(ph);    // 함수 호출
    scanf("%d %lf", &G, &D);    // 기준 등급과 기준 거리 입력 받음
    out_hotel_info(ph, hcnt, G, D);     // 함수 호출
    return 0;
}

int in_hotel_info(struct hotel_info* p)
{
    int result=0;    // 호텔 수 선언
    char zero[2] = { '0' };    // zero 배열 선언
    while (1) {
        scanf("%s", p->name);    // 이름 입력받음
        if (strcmp(p->name, zero) == 0) {    // 0 입력되면
            break;    // 반복 종료
        }
        scanf("%d %lf %lf %c", &p->grade, &p->reput, &p->dist, &p->breakfast);    // 등급, 평판도, 거리, 조식포함여부 입력받음
        result++;   // 호텔수에 1 더함
        p++;
    }
    return result;    // 호텔 수 반환
}

void out_hotel_info(struct hotel_info* p, int N, int G, double D)
{
    struct hotel_info* pp, *ppp;    // 구조체 선언
    struct hotel_info pr[100], * ppr = pr;    // 구조체 선언
    struct hotel_info xx;     // 구조체 선언
    int prcnt = 0;   // 조건을 만족하는 호텔 수
    for (pp = p; pp < p + N; pp++) {
        if (pp->grade >= G && pp->dist <= D) {   // 조건을 만족하는지 판단
            *ppr = *pp;    // 조건 만족하는 호텔 따로 배열에 저장
            ppr++;
            prcnt++;
        }
    }
    ppr = pr;
    for (pp = ppr; pp < ppr + prcnt; pp++) {     // 정렬
        for (ppp = pp+1; ppp < ppr + prcnt; ppp++) {
            if (pp->reput < ppp->reput) {    // 평판도에 따라 정렬
                xx = *pp;
                *pp = *ppp;
                *ppp = xx;
            }
            else if (pp->reput == ppp->reput) {     // 평판도가 같다면
                if (strcmp(pp->name, ppp->name) > 0) {   // 이름에 따라 정렬
                    xx = *pp;
                    *pp = *ppp;
                    *ppp = xx;
                }
            }
        }
    }
    for (pp = ppr; pp < ppr + prcnt; pp++) {    // 조건에 맞는 호텔 출력
        printf("%s %d %.1f %.1f %c\n", pp->name, pp->grade, pp->reput, pp->dist, pp->breakfast);    // 호텔 이름과 등급, 평판도와 거리, 조식포함 여부 출력
    }
}
