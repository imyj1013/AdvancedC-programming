#include<stdio.h>

struct test {    // 구조체 정의
  int s1, s2, std, dif;
  char pnp;
};

void passorfail (struct test *p)   // 함수 정의
{
  p->dif = p->s1 - p->s2;    // 가장 높은 점수와 가장 낮은 점수의 차이를 저장
  if (p->dif <= p->std) {     // 점수차가 기준 점수차 이하이면
	p->pnp = 'P';    // P 저장
  }
  else {     // 점수차가 기준 점수차 이상이면
	p->pnp = 'F';     // F 저장
  }
}

int main() {
  struct test x, *p=&x;    // 구조체 선언
  scanf("%d %d %d", &p->s1, &p->s2, &p->std);    // 가장 높은 점수, 가장 낮은 점수, 기준 점수차 입력
  passorfail(p);     // 함수 호출
  printf("%d %c", p->dif, p->pnp);    // 점수차와 통과 여부 출력
  return 0;
}
