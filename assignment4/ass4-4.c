#include <stdio.h>

#include <string.h>

#include <stdlib.h>

struct student {     
	char* name; // 이름 저장
	int firstStage; // 1단계 점수 저장 
	int interview; // 면접 점수 저장
	double sum; // 총점 저장
};

int main() {
	struct student* stst, ttt[11];   // 구조체 포인터
	int N, M, result;    // 1단계합격자수, 최종합격자수, 합격인원
	scanf("%d %d", &N, &M);    // 1단계합격자수, 최종합격자수입력
	result = M;     // result 초기화
	stst = (struct student*)malloc(N * sizeof(struct student));    // 동적할당
	if (stst == NULL) {     // 메모리 할당여부 검사
		printf("Not enough memory!");
		return -1;
	}
	for (int i = 0; i < N; i++) {
		scanf("%s", ttt);    // 이름입력
		stst[i].name = (char*)malloc((strlen(ttt) + 1) * sizeof(char));    // 동적할당
		if (stst[i].name == NULL) {    // 동적할당 성공여부
			printf("Not enough memory!");
			return -1;
		}
		strcpy(stst[i].name, ttt);    // 구조체에 이름 저장
		scanf("%d %d", &stst[i].firstStage, &stst[i].interview);    // 점수 입력
		stst[i].sum = stst[i].firstStage * 7 + stst[i].interview * 3;    // 최종점수 입력
	}
	for (int i = 0; i < N-1; i++) {     // 최종점수가 높은 순으로 배열
		for (int j = 0; j < N-1-i; j++) {
			if (stst[j].sum < stst[j + 1].sum) {   // stst[j].sum가 stst[j + 1].sum보다 작으면
				struct student te;
				te = stst[j];    // te에 stst[j] 저장
				stst[j] = stst[j + 1];     // stst[j]에 stst[j+1] 저장
				stst[j + 1] = te;     // stst[j+1]에 te저장
			}
			else if (stst[j].sum == stst[j + 1].sum) {     // 최종점수가 같으면
				if (stst[j].firstStage < stst[j + 1].firstStage) {    // 1단계 점수로 비교
					struct student te;     // 1단계 점수가 높아야 선발
					te = stst[j];
					stst[j] = stst[j + 1];
					stst[j + 1] = te;
				}
				else if (stst[j].firstStage == stst[j + 1].firstStage) {    // 1단계 점수가 같으면
					if (strcmp(stst[j].name, stst[j + 1].name)>0) {    // 이름의 사전순으로 배열
						struct student te;    // 사전순으로 swap
						te = stst[j];
						stst[j] = stst[j + 1];
						stst[j + 1] = te;
					}
				}
			}
		}
	}
	for (int i = M; i < N; i++) {
		if (stst[i - 1].firstStage == stst[i].firstStage && stst[i - 1].sum == stst[i].sum) {    // 동점자가 있으면 합격인원 증가시킴
			result++;
		}
		else {
			break;     // 동점자 없으면 반복 종료
		}
	}
	for (int i = 0; i < result; i++) {
		printf("%s %d %d %.1f\n", stst[i].name, stst[i].firstStage, stst[i].interview, stst[i].sum / 10);    // 합격자의 이름, 1단계, 면접점수, 최종점수 출력
	}
	printf("%d", result);    // 최종합격인원 출력
	for (int i = 0; i < N; i++) {     // 메모리 해제
		if (stst[i].name != NULL) {
			free(stst[i].name);         // 메모리 해제
		}
	}
	if (stst != NULL) {
	    free(stst);       // 메모리 해제
	}
	return 0;
}
