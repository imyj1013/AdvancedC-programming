#include<stdio.h>

struct score {     // 구조체 정의
  char n[10];
  int s;
};

struct score *select_min(struct score *p) {    // 최하점수 찾기
  struct score *result = p;     // 반환 주소
  struct score* r = p;;
  for (r = p; r < p + 5;r++) {
    if (result->s > r->s) {     // 최하점수 찾기
      result = r;     // 더 작은 값의 주소 result에 저장
    }
  }
  return result;
}

int main() {
  struct score st[5], *p=st;     // 구조체 선언
  for (p = st; p < st+5; p++) {
    scanf("%s %d", p->n, &p->s);    // 이름과 점수 입력
  }
  printf("%s %d", select_min(&st)->n, select_min(&st)->s);    // 이름과 최하점 출력
  return 0;
}
