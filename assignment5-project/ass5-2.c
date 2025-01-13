#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct infor {      // 구조체 정의
	char* name;
	char* num;
	char* birth;
};


void input(struct infor** pelist, int* cntnow) {
	char sss1[101], sss2[101], sss3[101];
	int ind = *cntnow;

	pelist[*cntnow] = (struct infor*)malloc(sizeof(struct infor));      // 구조체 동적할당
	if (pelist[*cntnow] == NULL) {       // 메모리 할당 여부 검사
		printf("Not enough memory");
		return -1;
	}

	printf("Name:");
	scanf("%s", sss1);      // 이름 입력
	for (int i = 0; i < *cntnow; i++) {
		if (strcmp(sss1, pelist[i]->name) < 0) {       // 사전순 저장을 위한 인덱스 확인
			ind = i;
			break;
		}
	}
	for (int i = *cntnow - 1; i >= ind; i--) {        // 뒤로 한칸씩 미루기
		struct infor* xxx;
		xxx = pelist[i];
		pelist[i] = pelist[i + 1];
		pelist[i + 1] = xxx;
	}
	pelist[ind]->name = (char*)malloc((strlen(sss1) + 1) * sizeof(char));     // 이름 저장할 문자열 동적할당
	if (pelist[ind]->name == NULL) {       // 메모리 할당 여부 검사
		printf("Not enough memory");
		return -1;
	}
	strcpy(pelist[ind]->name, sss1);      // 미리 확인한 인덱스에 이름 저장
	printf("Phone_number:");
	scanf("%s", sss2);      // 전화번호 입력
	pelist[ind]->num = (char*)malloc((strlen(sss2) + 1) * sizeof(char));     // 전화번호 저장할 문자열 동적할당
	if (pelist[ind]->num == NULL) {       // 메모리 할당 여부 검사
		printf("Not enough memory");
		return -1;
	}
	strcpy(pelist[ind]->num, sss2);      // 전화번호 저장
	printf("Birth:");
	scanf("%s", sss3);    // 생년월일 입력
	pelist[ind]->birth = (char*)malloc((strlen(sss3) + 1) * sizeof(char));     // 생년월일 저장할 문자열 동적할당
	if (pelist[ind]->birth == NULL) {       // 메모리 할당 여부 검사
		printf("Not enough memory");
		return -1;
	}
	strcpy(pelist[ind]->birth, sss3);    // 생년월일 저장
	*cntnow += 1;                                  // 저장된 사람 수 1 늘리기
	printf("<<%d>>\n", *cntnow);          // 저장된 사람 수 출력
}

void printlist(struct infor** pelist, int* cntnow) {
	for (int i = 0; i < *cntnow; i++) {
		printf("%s %s %s\n", pelist[i]->name, pelist[i]->num, pelist[i]->birth);       // 저장된 모든 정보 출력
	}
}

void removepe(struct infor** pelist, int* cntnow) {
	char sss[21];
	printf("Name:");
	scanf("%s", sss);       // 지울 이름 입력
	for (int i = 0; i < *cntnow; i++) {
		if (strcmp(sss, pelist[i]->name) == 0) {     // 지울 정보의 인덱스 찾기
			for (int j = i; j < *cntnow - 1; j++) {       // 뒤에 있는 정보들 앞으로 한칸씩 땡기기
				pelist[j] = pelist[j + 1];
			}
			pelist[*cntnow - 1] = NULL;      // 가장 마지막에 저장되어있는 중복된 정보 삭제
			*cntnow -= 1;        // 저장된 사람 수 1 줄이기
			break;
		}
	}

}

void searchbirth(struct infor** pelist, int* cntnow) {
	int mmm = 0;
	printf("Birth:");
	scanf("%d", &mmm);        // 생일 입력
	for (int i = 0; i < *cntnow; i++) {
		int x = 0;
		x += (int)(pelist[i]->birth[4] - '0');     // 문자열로 저장되어있는 생일을 정수로 바꿈(십의자리)
		x *= 10;
		x += (int)(pelist[i]->birth[5] - '0');     // 문자열로 저장되어있는 생일을 정수로 바꿈(일의자리)
		if (mmm == x) {
			printf("%s %s %s\n", pelist[i]->name, pelist[i]->num, pelist[i]->birth);      // 같은 생일인 사람의 정보만 출력
		}
	}
}


void end(struct infor** pelist, int* cntnow) {
	for (int i = 0; i < *cntnow; i++) {
		free(pelist[i]->name);       // 메모리 해제
		free(pelist[i]->num);       // 메모리 해제
		free(pelist[i]->birth);       // 메모리 해제
		free(pelist[i]);       // 메모리 해제
	}
	free(pelist);       // 메모리 해제
}


int main() {
	struct infor** pelist;     // 구조체 선언
	int cntnow = 0, menunow, max_num;
	printf("Max_num:");
	scanf("%d", &max_num);
	pelist = (struct infor**)malloc(max_num * sizeof(struct infor*));      // 구조체 동적할당
	if (pelist == NULL) {        // 메모리 할당 여부 검사
		printf("Not enough memory");
		return -1;
	}


	while (1) {
		menunow = 0;
		printf("*****Menu*****\n");        // 메뉴 출력
		printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");
		printf("Enter_the_menu_number:");

		scanf("%d", &menunow);     // 메뉴 번호 입력


		if (menunow == 1) {        // 메뉴 1 입력시 
			if (cntnow >= max_num) {
				printf("OVERFLOW\n");       // 저장된 정보가 100 이상이면 overflow 출력
			}
			else {
				input(pelist, &cntnow);      // input 함수 호출
			}
		}
		if (menunow == 2) {        // 메뉴 2 입력시
			printlist(pelist, &cntnow);      // printlist 함수 호출
		}
		if (menunow == 3) {      // 메뉴 3 입력시
			if (cntnow == 0) {
				printf("NO MEMBER\n");      // 저장된 정보가 0이면 no member 출력
			}
			else {
				removepe(pelist, &cntnow);       // removepe 함수 호출
			}
		}
		if (menunow == 4) {     // 메뉴 4 입력시
			searchbirth(pelist, &cntnow);      // searchbirth 함수 호출
		}
		if (menunow == 5) {      // 메뉴 5 입력시
			end(pelist, &cntnow);      // end 함수 호출
			return 0;      // 종료
		}

	}

}
