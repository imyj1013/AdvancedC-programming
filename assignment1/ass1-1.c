#include<stdio.h>

int* MAX(int ar[]);     // 함수 원형 선언
int* MIN(int ar[]);     // 함수 원형 선언

int main()
{
	int N, ar[100];     // 변수 선언
	int* p, *a, *b;      // 포인터 선언
	scanf("%d", &N);     // 입력받을 줄의 수 N을 입력받음
	for (int i = 1; i <= N; i++) {
		p = ar;
		while (1) {
			scanf("%d", p);     // 값을 입력받아 배열에 저장
			if (*p == 0) {
				break;        // 0이 입력되면 반복 종료
			}
			p++;
		}
		if (MAX(ar) > MIN(ar)) {      // 최솟값의 주소가 더 빠를 때
			a = MIN(ar);     // 함수 호출
			b = MAX(ar);     // 함수 호출
			for (p = a+1; p < b; p++) {
				printf("%d ", *p);     // 최댓값과 최솟값 사이에 있는 수 출력
			}
			a++;
			if (a == b) {     // 최댓값과 최솟값이 연이어 있을 때
				printf("none");     // none 출력
			}
		}
		else if (MAX(ar) < MIN(ar)) {      // 최댓값의 주소가 더 빠를 때
			a = MAX(ar);     // 함수 호출
			b = MIN(ar);     // 함수 호출
			for (p = a+1; p < b; p++) {
				printf("%d ", *p);     // 최댓값과 최솟값 사이에 있는 수 출력
			}
			a++;
			if (a == b) {     // 최댓값과 최솟값이 연이어 있을 때
				printf("none");     // none 출력
			}
		}
		else {     // 출력할 수가 없을 경우
			printf("none");     // none 출력
		}
	}
	return 0;
}

int* MAX(int ar[])
{
	int* p=ar, *result=ar;    // 포인터 선언
	int max=*ar;
	while (1) {
		if (*p == 0) {    // *p가 0이라면
			break;     // 반복 종료
		}
		if (*p > max) {     // *p가 max보다 크면
			max = *p;     // max에 *p를 저장
			result = p;    // result에 p를 저장
		}
		p++;
	}
	return result;      // 최댓값의 주소 반환
}

int* MIN(int ar[])
{
	int* p = ar, * result = ar;    // 포인터 선언
	int min = *ar;
	while (1) {
		if (*p == 0) {    // *p가 0이라면
			break;     // 반복 종료
		}
		if (*p < min) {     // *p가 min보다 작으면
			min = *p;     // min에 *p를 저장
			result = p;    // result에 p를 저장
		}
		p++;
	}
	return result;     // 최솟값의 주소 반환
}
