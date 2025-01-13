#include<stdio.h>

int passengerN(int n);     // 함수 원형 선언
void rebooking(int* ar);     // 함수 원형 선언
int changeseat(int* ar);     // 함수 원형 선언

int main()
{
	int N, ar[21];     // 변수 선언
	int* p;      // 포인터 선언
	scanf("%d", &N);     // 승객 수 입력받음
	for (p = ar; p < ar + N; p++) {
		scanf("%d", p);     // 좌석번호 입력받음
	}
	printf("%d\n", passengerN(N));     // 함수호출
	if (passengerN(N) == -1) {
		return 0;      // 승객수가 부족하면 종료
	}
	rebooking(ar);      // 함수 호출
	for (p = ar; p < ar + N; p++) {
		printf("%d ", *p);       // 바뀐 좌석번호 출력
	}
	return 0;
}

int passengerN(int n)
{
	int result;
	if (n >= 5) {     // 승객수가 5명 이상이면
		result = 0;     // result에 0 저장
	}
	else {     // 승객수가 5명 미만이면
		result = -1;      // result에 -1 저장
	}
	return result;     // result 반환
}

void rebooking(int* ar)
{
	int* p, * q;
	int n = 0;
	for (p = ar; p < ar + 21; p++) {    // 승객수 계산
		if (*p > 21 || *p < 1) {    // 입력된 좌석 번호가 더이상 없으면
			break;     // 반복 종료
		}
		n += 1;     // n에 1을 더함
	}
	for (p = ar; p < ar+n; p++) {     // 중복된 좌석번호 빈 좌석으로 교환
		for (q = p+1; q < ar+n; q++) {
			if (*p == *q) {      // 중복된 좌석 번호가 있다면
				*q = changeseat(ar);     // 함수호출
			}
		}
	}
}

int changeseat(int* ar)
{
	int result;
	int n = 0;
	int* p;
	for (p = ar; p < ar + 21; p++) {    // 승객수 계산
		if (*p > 21 || *p < 1) {    // 입력된 좌석 번호가 더이상 없으면
			break;     // 반복 종료
		}
		n += 1;     // n에 1을 더함
	}
	for (int i = 1; i <= 21; i++) {    // 빈 좌석 찾기
		int a=0;
		for (p = ar; p < ar + n; p++) {
			if (i == *p) {     // 해당 좌석이 입력받은 좌석이면
				a += 1;     // a에 1을 더함
			}
		}
		if (a == 0) {     // a가 0이면
			result = i;     // result에 해당 좌석 번호 저장
			break;    // 반복 종료
		}
	}
	return result;    // 빈 좌석 번호 반환
}
