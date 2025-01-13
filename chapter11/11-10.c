#include<stdio.h>

struct day {     // 구조체 정의
  int y, m, d;
};

struct day *select_min(struct day *p, struct day *q)
{
  if (p->y > q->y) {    // 연도 비교
	return q;     // 더 빠른 날짜 반환
  }
  else if (p->y < q->y) {     // 연도 비교
	return p;    // 더 빠른 날짜 반환
  }
  else {     // 연도가 같으면
	if (p->m > q->m) {   // 달 비교
	  return q;    // 더 빠른 날짜 반환
	}
	else if (p->m < q->m) {   // 달 비교
	  return p;    // 더 빠른 날짜 반환
	}
	else {      // 달이 같으면
	  if (p->d > q->d) {     // 일 비교
		return q;    // 더 빠른 날짜 반환
	  }
	  else if (p->d < q->d) {     // 잉 비교
		return p;    // 더 빠른 날짜 반환
	  }
	}
  }
}

int main()
{
  struct day x, y;     // 구조체 선언
  struct day *px=&x, *py=&y;    // 구조체 포인터 선언
  scanf("%d/%d/%d", &px->y, &px->m, &px->d);    // 날짜 입력
  scanf("%d/%d/%d", &py->y, &py->m, &py->d);    // 날짜 입력
  printf("%d/%d/%d", select_min(px, py)->y, select_min(px, py)->m, select_min(px, py)->d);   // 함수 호출, 빠른 날짜 출력
  return 0;
}
