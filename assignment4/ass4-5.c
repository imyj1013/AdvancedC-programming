#include <stdio.h>

#include <string.h>

#include <stdlib.h>

struct customer {     // 구조체 정의
	char id[5];     // 고객번호
	char* name;     // 이름
	char* phone;    // 휴대폰번호
	struct customer* next;    // 다음 고객 주소
};

int main() {
	int N, result=0;     // 입력받을 사람 수, 몇번째 고객
	char M[5], t1[101], t2[101];   // 고객번호
	struct customer* cus, *p;   // 구조체 포인터
	scanf("%d", &N);      // 입력받을 사람 수 입력
	cus = (struct customer*)malloc(N * sizeof(struct customer));   // 메모리 할당
	if (cus == NULL) {    // 메모리 할당 유무 검사
		printf("Not enough memory");
		return -1;
	}
	for (int i = 0; i < N; i++) {
		scanf("%s %s", t1, t2);      // 이름, 전화번호 입력
		cus[i].name = (char*)malloc((strlen(t1) + 1) * sizeof(char));   // 메모리 할당
		if (cus[i].name == NULL) {    // 메모리 할당 유무 검사
			printf("Not enough memory");
			return -1;
		}
		cus[i].phone = (char*)malloc((strlen(t2) + 1) * sizeof(char));   // 메모리 할당
		if (cus[i].phone == NULL) {     // 메모리 할당 유무 검사
			printf("Not enough memory");
			return -1;
		}
		strcpy(cus[i].name, t1);    // 이름 저장
		strcpy(cus[i].phone, t2);     // 전화번호 저장
		strncpy(cus[i].id, cus[i].phone + strlen(t2) - 4, 5);    // 고객번호 저장
		for (int j = i-1; j >= 0; j--) {
			if (cus[i].id[3] == cus[j].id[3]) {    // 고객번호 마지막 문자가 같으면
				cus[j].next = cus + i;    // 다음주소로 저장
				break;
			}
		}

	}
	scanf("%s", M);    // 고객번호 입력
	for (int i = 0; i < N; i++) {
		if (cus[i].id[3] == M[3]) {   // 고객번호 마지막 문자가 같으면
			for (p = cus+i; p < cus + N; p = p->next) {    // 마지막 문자가 같은 고객 중에 검사
				result++;
				if (strcmp(p->id, M) == 0) {    // 고객 찾으면
					printf("%s %s %d", p->name, p->phone, result);    // 이름, 전화번호, 몇번째 고객인지 출력
					break;
				}
			}
			break;   // 해당 고객을 찾으면 반복종료
		}
	}
	for (int i = 0; i < N; i++) {    // 메모리 해제
		if (cus[i].name != NULL) {
			free(cus[i].name);
		}
		if (cus[i].phone != NULL) {
			free(cus[i].phone);
		}
	}
	if (cus != NULL) {
	    free(cus);    // 메모리 해제
	}
	return 0;
}
