#include <stdio.h>

#include <string.h>

#include <stdlib.h>

struct st {
	char* str; // 문자열 저장
	int cnt1; // 자음 수 저장
	int cnt2; // 총 문자 수 저장
	int num; // 숫자 저장
	int pos; // 위치 저장
	int result; // 곱셈결과 저장
};

int main() {
	struct st* stst;    // 구조체 포인터
	int N;   // 입력받을 문자열수
	scanf("%d", &N);    // N 입력받기
	stst = (struct st*)malloc(N * sizeof(struct st));    // 동적할당
	if (stst == NULL) {    // 메모리 할당 여부 검사
		printf("Not enough memory!");
		return -1;
	}
	for (int i = 0; i < N; i++) {
		char temp[101];     // 입력받을 문자열
		scanf("%s", temp);    // 문자열 입력
		stst[i].str = (char*)malloc((strlen(temp) + 1) * sizeof(char));    // 동적할당
		if (stst[i].str == NULL) {    // 메모리 할당 여부 검사
			printf("Not enough memory!");
			return -1;
		}
		strcpy(stst[i].str, temp);    // 문자열 구조체에 저장

		stst[i].cnt1 = 0;    // 자음 수 초기화
		stst[i].cnt2 = strlen(stst[i].str);    // 문자열 길이 저장
		stst[i].result = 1;    // 곱셈결과 초기화

		for (int j = 0; j < strlen(stst[i].str); j++) {
			if (stst[i].str[j] >= '0'&& stst[i].str[j] <= '9') {
				stst[i].num = (int)stst[i].str[j]-'0';    // 문자형 숫자를 정수형 숫자로 저장
				stst[i].pos = j + 1;    // 숫자의 위치 저장
			}
			else if (stst[i].str[j] != 'a' && stst[i].str[j] != 'e' && stst[i].str[j] != 'i' && stst[i].str[j] != 'o' && stst[i].str[j] != 'u' && stst[i].str[j] != 'A' && stst[i].str[j] != 'E' && stst[i].str[j] != 'I' && stst[i].str[j] != 'O' && stst[i].str[j] != 'U') {
				stst[i].cnt1++;    // 자음일 경우 1을 더함
			}
		}

		stst[i].result = stst[i].cnt1 * stst[i].cnt2 * stst[i].num * stst[i].pos;    // 곱셈결과 저장
	}
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (stst[j].result < stst[j + 1].result) {    // 곱셈결과의 내림차순으로 배열
				struct st temp;
				temp = stst[j];
				stst[j] = stst[j + 1];    // stst[j]에 stst[j+1] 저장
				stst[j + 1] = temp;     // stst[j+1]에 stst[j] 저장
			}
		}
	}
	for (int i = 0; i < N; i++) {
		printf("%s\n", stst[i].str);    // 정렬한 문자열 출력
	}
	for (int i = 0; i < N; i++) {
		if (stst[i].str != NULL) {
			free(stst[i].str);    // 메모리 해제
		}
	}
	if (stst != NULL) {
	    free(stst);     // 메모리 해제
	}
	return 0;
}
