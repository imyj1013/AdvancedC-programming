#include<stdio.h>

int* mid(int ar[3])
{
	int* p=ar;
	if (*ar <= *(ar + 1) && *(ar + 1) <= *(ar + 2)) {     // 중앙값이 *(ar+1)이라면
		p = ar + 1;          // p에 ar+1 저장
	}
	if (*ar >= *(ar + 1) && *(ar + 1) >= *(ar + 2)) {     // 중앙값이 *(ar+1)이라면
		p = ar + 1;          // p에 ar+1 저장
	}
	if (*ar <= *(ar + 2) && *(ar + 2) <= *(ar + 1)) {     // 중앙값이 *(ar+2)이라면
		p = ar + 2;          // p에 ar+2 저장
	}
	if (*ar >= *(ar + 2) && *(ar + 2) >= *(ar + 1)) {     // 중앙값이 *(ar+2)이라면
		p = ar + 2;          // p에 ar+2 저장
	}
	if (*(ar + 1) <= *(ar) && *(ar) <= *(ar + 2)) {     // 중앙값이 *(ar)이라면
		p = ar;          // p에 ar 저장
	}
	if (*(ar + 1) >= *(ar) && *(ar) >= *(ar + 2)) {     // 중앙값이 *(ar)이라면
		p = ar;          // p에 ar 저장
	}
	return p;
}


int main()
{
	int x[3];    // 변수 선언
	int* p;     // 포인터 선언
	for (p = x; p < x + 3; p++) {     // 3개의 정수 입력받음
		scanf("%d", p);
	}
	printf("%d", *mid(x));     // 중앙값 출력
	return 0;
}
