#include <stdio.h>

#include <string.h>

#include <stdlib.h>

struct subject {
	char* name; // 과목 이름
	double score; // 과목 점수
};

struct student {
	char* name; // 학생 이름
	char id[5]; // 학생 학번
	int numSubject; // 과목 개수
	struct subject* psub; // 과목 구조체 포인터
	double avg; // 모든 과목의 평균 점수
};

int main() {
	int N, K, xstart = 0, imax=0;     // 사람 수, 순서, 시작인덱스, 최대점수과목 인덱스
	struct student* xxx;    // 구조체 포인터
	scanf("%d", &N);    // 사람 수 입력
	getchar();
	xxx = (struct student*)malloc(N * sizeof(struct student));    //동적할당
	if (xxx == NULL) {    // 메모리 할당 여부 검사
		printf("Not enough memory!");
		return -1;
	}
	for (int i = 0; i < N; i++) {
		char ttt[101];    // 입력받을 문자열
		gets(ttt);      // 학생 정보 입력
		xxx[i].numSubject = 0;    // 과목수 초기화
		xstart = 0;
		for (int j = 0; j < strlen(ttt); j++) {
			if (ttt[j] == ' ' && xxx[i].numSubject == 0) {    // 공백을 기준으로 나눔
				xxx[i].numSubject++;    // 과목수 늘리기
				xxx[i].name = (char*)malloc((j - xstart + 1) * sizeof(char));   // 동적할당
				if (xxx[i].name == NULL) {     // 메모리 할당 여부 검사
					printf("Not enough memory!");
					return -1;
				}
				strncpy(xxx[i].name, ttt + xstart, j - xstart);    // 문자열에서 이름 따와서 저장
				xxx[i].name[j - xstart] = '\0';   // 널문자 입력
				xstart = j + 1;   // 시작주소 저장
			}
			else if (ttt[j] == ' ' && xxx[i].numSubject == 1) {    // 공백을 기준으로 나눔
				xxx[i].numSubject++;    // 과목수 늘리기
				strncpy(xxx[i].id, ttt + xstart, j - xstart);    // 문자열에서 학번 따와서 저장
				xxx[i].id[j - xstart] = '\0';   // 널문자 입력
				xstart = j + 1;   // 시작주소 저장

			}
			else if (ttt[j] == ' ') {    // 공백을 기준으로 나눔
				xxx[i].numSubject++;    // 과목수 늘리기
			}
		}
		xxx[i].numSubject -= 1;
		xxx[i].numSubject /= 2;   // 과목수 계산

		xxx[i].psub = (struct subject*)malloc(xxx[i].numSubject * sizeof(struct subject));   // 동적할당
		if (xxx[i].psub == NULL) {      // 메모리 할당 여부 검사
			printf("Not enough memory!");
			return -1;
		}
		int npsub = 0;   // 과목수 인덱스 초기화
		xxx[i].avg = 0;    // 과목 평균 초기화
		for (int j = xstart; j < strlen(ttt); j++) {
			if (ttt[j] == ' ') {     // 공백기준으로 나눔
				xxx[i].psub[npsub].name = (char*)malloc((j - xstart + 1) * sizeof(char));    // 과목이름 동적 할당
				if (xxx[i].psub[npsub].name == NULL) {      // 메모리 할당 여부 검사
					printf("Not enough memory!");
					return -1;
				}
				strncpy(xxx[i].psub[npsub].name, ttt + xstart, j - xstart);     // 문자열에서 과목이름 따와서 저장
				xxx[i].psub[npsub].name[j - xstart] = '\0';    // 널문자저장
				xstart = j + 1;    // 시작주소 저장
				xxx[i].psub[npsub].score = 0;   // 과목점수 초기화
				for (int k = 1; k <= 4; k++) {      // 문자열인 과목점수 정수형으로 바꾸기
					if (ttt[j + k] == ' ' || (j+k) == strlen(ttt)) {     // 공백 기준으로 나눔
						xstart = j + k + 1;
						j = j + k;
						break;    // 공백이면 반복 종료
					}
					xxx[i].psub[npsub].score *= 10;     // 점수 정수형으로 계산
					xxx[i].psub[npsub].score += (int)ttt[j + k] - '0';
				}
				xxx[i].avg += xxx[i].psub[npsub].score;    // 평균에 과목당 점수 더하기
				npsub++;
			}
		}
		xxx[i].avg /= (double)xxx[i].numSubject;    // 평균 계산

	}
	scanf("%d", &K);    // 찾을 순서 입력
	for (int i = 0; i < N - 1; i++) {    // 평균점수 순으로 배열
		for (int j = 0; j < N - i - 1; j++) {
			if (xxx[j].avg < xxx[j + 1].avg) {    // xxx[j].avg가 xxx[j + 1].avg보다 작으면
				struct student tempp;
				tempp = xxx[j];
				xxx[j] = xxx[j + 1];    // xxx[j]에 xxx[j+1] 저장
				xxx[j + 1] = tempp;     // xxx[j+1]에 xxx[j] 저장
			}
			else if (xxx[j].avg == xxx[j + 1].avg) {    // 평균점수가 같으면
				if (strcmp(xxx[j].id, xxx[j + 1].id) > 0) {   // id가 빠른 순으로 배열
					struct student tempp;
					tempp = xxx[j];
					xxx[j] = xxx[j + 1];     // xxx[j]에 xxx[j+1] 저장
					xxx[j + 1] = tempp;      // xxx[j+1]에 xxx[j] 저장
				}
			}
		}
	}

	for (int i = 0; i < xxx[K-1].numSubject; i++) {    // K번째 순서의 학생의 최고점 과목 찾기
		if (xxx[K-1].psub[i].score > xxx[K-1].psub[imax].score) {
			imax = i;   // 최고점 과목의 인덱스 저장
		}
	}
	printf("%s %s %.2lf %s %.2lf", xxx[K-1].name, xxx[K-1].id, xxx[K-1].avg, xxx[K-1].psub[imax].name, xxx[K-1].psub[imax].score);    // K번째순서의 학생정보 출력

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < xxx[i].numSubject; j++) {
			if (xxx[i].psub[j].name != NULL) {
				free(xxx[i].psub[j].name);     // 메모리 해제
			}
		}
	}
	for (int i = 0; i < N; i++) {
		if (xxx[i].psub != NULL) {
			free(xxx[i].psub);    // 메모리 해제
		}
		if (xxx[i].name != NULL) {
			free(xxx[i].name);    // 메모리 해제
		}
	}
	if (free != NULL) {
	    free(xxx);    // 메모리 해제
	}
	return 0;
}
