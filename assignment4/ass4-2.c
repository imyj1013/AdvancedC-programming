#include <stdio.h>

#include <string.h>

#include <stdlib.h>

int main() {
	char A[101], B[101], result[101][101];    // 문자열 저장할 배열
	int alen = 0, blen = 0, astart = 0, bstart=0, r=0;
	char**aaa, **bbb;   // 이중포인터
	gets(A);    // 문자열 입력
	gets(B);    // 문자열 입력


	for (int i = 0; i < strlen(A); i++) {
		if (A[i] == ' ' || i == strlen(A) - 1) {
			alen++;    // A문자열의 단어수 계산
		}
	}
	for (int i = 0; i < strlen(B); i++) {
		if (B[i] == ' ' || i == strlen(B) - 1) {
			blen++;     // B문자열의 단어수 계산
		}
	}

	aaa = (char**)malloc(alen * sizeof(char*));     // 동적할당
	bbb = (char**)malloc(blen * sizeof(char*));    // 동적할당
	if (aaa == NULL) {     // 메모리 할당 여부 조사
		printf("Not enough memory!");
		return -1;
	}
	if (bbb == NULL) {     // 메모리 할당 여부 조사
		printf("Not enough memory!");
		return -1;
	}

	for (int i = 0, k = 0; i <= strlen(A); i++) {
		if (A[i] == ' ' || i == strlen(A)) {
			aaa[k] = (char*)malloc((i - astart+1) * sizeof(char));    // 동적할당
			if (aaa[k] == NULL) {     // 메모리 할당여부 조사
				printf("Not enough memory!");
				return -1;
			}
			strncpy(aaa[k], A+astart, i - astart);    // 단어단위로 분리하여 저장
			aaa[k][i-astart]='\0';    // 널문자 입력
			astart = i+1;    // 시작위치 저장
			k++;
		}
	}
	for (int i = 0, k = 0; i <= strlen(B); i++) {
		if (B[i] == ' ' || i == strlen(B)) {
			bbb[k] = (char*)malloc((i - bstart + 1) * sizeof(char));    // 동적할당
			if (bbb[k] == NULL) {    // 메모리 할당 여부 조사
				printf("Not enough memory!");
				return -1;
			}
			strncpy(bbb[k], B+bstart, i - bstart);     // 단어단위로 분리하여 저장
			bbb[k][i - bstart] = '\0';    // 널문자 입력
			bstart = i + 1;    // 시작위치 저장
			k++;
		}
	}

	for (int i = 0; i < alen-1; i++) {    // 합성된 문자열의 존재여부 검사
		for (int j = i+1; j < alen; j++) {
			char t1[101], t2[101];    // 합성된 문자열 저장할 배열
			strcpy(t1, aaa[i]);      // t1에 aaa[i] 접합
			strcat(t1, aaa[j]);      // t1에 aaa[j] 접합
			strcat(t1, "\0");
			strcpy(t2, aaa[j]);      // t1에 aaa[j] 접합
			strcat(t2, aaa[i]);      // t1에 aaa[i] 접합
			strcat(t2, "\0");
			for (int k = 0; k < blen; k++) {
				if (strcmp(t1, bbb[k]) == 0 || strcmp(t2, bbb[k]) == 0) {   // 합성된 문자열이 존재하면

					int x = 0;
					for (int g = 0; g < r; g++) {
						if (strcmp(result[g], bbb[k]) == 0) {    // 결과배열에 이미 저장된 합성단어인지 검사
							x++;
						}
					}
					if (x == 0) {     // 겹치지 않는 단어라면
						strcpy(result[r], bbb[k]);                  // 결과배열에 저장
						r++;
					}


				}
			}
		}
	}

	for (int i = 0; i < r - 1; i++) {    // 결과 배열에 저장된 단어들 정렬
		for (int j = 0; j < r - i - 1; j++) {
			if (strlen(result[j]) < strlen(result[j + 1])) {    // 단어 길이가 긴순으로 정렬
				char temp[101];
				strcpy(temp, result[j]);
				strcpy(result[j], result[j + 1]);     // result[j]에 result[j+1] 저장
				strcpy(result[j + 1], temp);      // result[j+1]에 result[j] 저장
			}
			else if (strlen(result[j]) == strlen(result[j + 1])) {     // 길이가 같으면
				if (strcmp(result[j], result[j+1]) > 0) {     //단어를 사전순으로 정렬
					char temp[101];
					strcpy(temp, result[j]);
					strcpy(result[j], result[j + 1]);     // result[j]에 result[j+1] 저장
					strcpy(result[j + 1], temp);     // result[j+1]에 result[j] 저장
				}
			}
		}
	}


	for (int i = 0; i < r; i++) {
		printf("%s\n", result[i]);    // 겹치는 합성단어 모두 출력
	}

	for (int i = 0; i < alen; i++) {
		if (aaa[i] != NULL) {
			free(aaa[i]);     // 메모리 해제
		}
	}
	for (int i = 0; i < blen; i++) {
		if (bbb[i] != NULL) {
			free(bbb[i]);    // 메모리 해제
		}
	}
	if (aaa != NULL) {
	    free(aaa);    // 메모리 해제
	}
	if (bbb != NULL) {
	    free(bbb);    // 메모리 해제
	}
	return 0;
}
