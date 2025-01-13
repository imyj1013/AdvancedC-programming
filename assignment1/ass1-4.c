#include<stdio.h>

int main()
{
	int a[21], b[11], n = -1, m = -1;     // 변수 선언
	int* p, *q;    // 포인터 선언
	for (p = a; p < a + 11; p++) {    // a 배열에 저장할 값 입력받음
		scanf("%d", p);     // 정수 입력받아 저장
		n += 1;    // n에 1 더함
		if (*p == -1) {     // -1이 입력되면
			break;    // 반복종료
		}
	}
	for (p = b; p < b + 11; p++) {    // b 배열에 저장할 값 입력받음
		scanf("%d", p);     // 정수 입력받아 저장
		m += 1;    // m에 1 더함
		if (*p == -1) {     // -1이 입력되면
			break;    // 반복종료
		}
	}
	for (p = a + n, q = b; p <= a + n + m, q <= b+m; p++, q++) {    // 배열b에 저장된 값을 배열 a에 옮김
		*p = *q;    //*p에 *q저장
	}
	for (int i = 0; i < n; i++) {    // n개의 큰값 출력
		int max = *a;    // 변수 선언
		int* x= a;    // 포인터 선언
		for (p = a; p < a + n + m; p++) {
			if (*p == -1) {     // -1이 입력되면
				break;    // 반복종료
			}
			if (max < *p) {    // *p가 max보다 크면
				max = *p;    // max에 *p 저장
				x = p;    // x에 p 저장
			}
		}
		printf("%d ", max);     // 최댓값 출력
		for (p = x; p <=a + n + m; p++) {
			if (*p == -1) {     // -1이 입력되면
				break;    // 반복종료
			}
			*p = *(p + 1);    // 방금 구한 최댓값의 자리부터 한칸씩 땡김
		}
	}
	printf("\n");   // 줄바꿈
	for (int i = 0; i < m; i++) {     // m개의 작은값 출력
		int min = *a;    // 변수 선언
		int* y = a;    // 포인터 선언
		for (p = a; p < a + n + m; p++) {
			if (*p == -1) {     // -1이 입력되면
				break;    // 반복종료
			}
			if (min > *p) {    // min보다 *p가 더 작으면
				min = *p;    // min에 *p 저장
				y = p;     // y에 p 저장
			}
		}
		printf("%d ", min);    // 최솟값 출력
		for (p = y; p < a + n + m; p++) {
			if (*p == -1) {     // -1이 입력되면
				break;    // 반복종료
			}
			*p = *(p + 1);    // 방금 구한 최솟값의 자리부터 한칸씩 땡김
		}
	}
	return 0;
}
