#include <stdio.h>

#include <string.h>

#include <stdlib.h>

struct parking_info {      // 구조체 정의
    int carnum, tellnum, subtype, time;
    char prod, sub;
    double price;
};

void input(struct parking_info* p, int N);    // 함수 선언

void compute(struct parking_info* p);    // 함수 선언

void display(struct parking_info* p, int N);    // 함수 선언

void parking_info_sort(struct parking_info* p, int N);    // 함수 선언

int main()
{
    struct parking_info user[100], * p = user;    // 구조체 선언
    int N, Dsum=0, Ssum=0, sumsum=0;   // 자동차수, 일일권 총액, 정기권 총액, 전체 합 선언
    scanf("%d", &N);    // 자동차 수 입력받음
    input(p, N);    // 함수 호출
    for (p = user; p < user + N; p++) {    // 요금 계산
        compute(p);   // 함수 호출
    }
    p = user;
    parking_info_sort(p, N);    // 함수 호출
    display(p, N);     // 함수 호출
    for (p = user; p < user + N; p++) {
        if (p->prod == 'D') {    // 일일권이면
            Dsum += p->price;    // 일일권 총액에 더함
        }
        else {     // 정기권이면 
            Ssum += p->price;     // 정기권 총액에 더함
        }
        sumsum += p->price;    // 모든 요금 다 더함
    }
    printf("%d %d %d", Dsum, Ssum, sumsum);    // 일일권 총액, 정기권 총액, 전체 합 출력
    return 0;
}

void input(struct parking_info* p, int N)
{
    struct parking_info* pp;    // 구조체 선언
    for (pp = p; pp < p + N; pp++) {
        scanf("%d %d %c", &pp->carnum, &pp->tellnum, &pp->prod);    // 차번호, 전화번호, 상품 입력받음
        if (pp->prod == 'S') {    // 정기권이라면
            getchar();
            scanf("%c %d %d", &pp->sub, &pp->subtype, &pp->time);     // 정기권 유무와 정기권 가입 종류, 주차시간 입력받음
        }
        else {    // 일일권이면
            scanf("%d", &pp->time);     // 시간 입력받음
        }
    }
}

void compute(struct parking_info* p)
{
    p->price = 0;    // 요금 초기화
    if (p->prod == 'S' && p->sub == 'N') {    // 정기권 선택이고 가입 안되어있으면
        if (p->subtype == 7) {    // 가입 종류가 7일권이면
            p->price += 30000;     // 요금에 3만원 더함
        }
        else if (p->subtype == 30) {    // 가입 종류가 30일권이면
            p->price += 100000;    // 요금에 10만원 더함
        }
        else {    // 가입 종류가 180일권이면
            p->price += 500000;     // 요금에 50만원 더함
        }
        if (p->time > 240) {    // 시간이 4시간 초과면
            p->price += ((p->time - 240) / 10) * 200;    //10분에 200원 부과
        }
    }
    else if (p->prod == 'S' && p->sub == 'Y') {    // 정기권 선택이고 가입 되어있으면
        if (p->time > 240) {    // 시간이 4시간 초과면
            p->price += ((p->time - 240) / 10) * 200;    // 10분에 200원 부과
        }
    }
    else {     // 일일권이면
        if (p->time > 240) {    // 시간이 4시간 초과면
            p->price += 5000;     // 5천원 부과
            p->price += ((p->time - 240) / 10) * 200;    // 10분에 200원 부과
        }
        else {
            p->price += 5000;    // 5천원 부과
        }
    }
}

void display(struct parking_info* p, int N)
{
    struct parking_info* pp;    // 구조체 선언
    for (pp = p; pp < p + N; pp++) {
        printf("%d %d %c %.0f\n", pp->carnum, pp->tellnum, pp->prod, pp->price);   // 차번호랑 전화번호랑 상품종류랑 요금 출력
    }
}

void parking_info_sort(struct parking_info* p, int N)
{
    struct parking_info* pp, *ppp;    // 구조체 포인터 선언
    struct parking_info xx;    // 구조체 선언
    for (pp = p; pp < p + N; pp++) {    // 상품 종류에 따라 정렬
        for (ppp = pp; ppp < p + N; ppp++) {
            if (pp->prod > ppp->prod) {
                xx = *ppp;
                *ppp = *pp;
                *pp = xx;
            }
        }
    }
    for (pp = p; pp < p + N; pp++) {    // 차 번호에 따라 정렬
        for (ppp = pp; ppp < p + N; ppp++) {
            if (pp->prod == 'D' && ppp->prod == 'D') {    // 두 차의 상품 종류가 모두 일일권이면
                if (pp->carnum > ppp->carnum) {    // 차 번호 기준으로 정렬
                    xx = *ppp;
                    *ppp = *pp;
                    *pp = xx;
                }
            }
            if (pp->prod == 'S' && ppp->prod == 'S') {    // 두 차의 상품 종류가 모두 정기권이라면
                if (pp->carnum > ppp->carnum) {    // 차 번호 기준으로 정렬
                    xx = *ppp;
                    *ppp = *pp;
                    *pp = xx;
                }
            }
        }
    }
}
