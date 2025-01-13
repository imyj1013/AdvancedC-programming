#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_NUM 100

struct infor {      // 구조체 정의
	char name[21];
	char num[16];
	char birth[9];
};

void input(struct infor* pelist, int* cntnow) {
	char sss[21];
	int ind = *cntnow;
	printf("Name:");
	scanf("%s", sss);      // 이름 입력
	for (int i = 0; i < *cntnow; i++) {
		if (strcmp(sss, (pelist + i)->name) < 0) {       // 사전순 저장을 위한 인덱스 확인
			ind = i;
			break;
		}
	}
	for (int i = *cntnow - 1; i >= ind; i--) {        // 뒤로 한칸씩 미루기
		strcpy((pelist + i + 1)->name, (pelist + i)->name);
		strcpy((pelist + i + 1)->num, (pelist + i)->num);
		strcpy((pelist + i + 1)->birth, (pelist + i)->birth);
	}
	strcpy((pelist + ind)->name, sss);      // 미리 확인한 인덱스에 이름 저장 
	printf("Phone_number:");
	scanf("%s", (pelist + ind)->num);      // 전화번호 입력
	printf("Birth:");
	scanf("%s", (pelist + ind)->birth);    // 생년월일 입력
	*cntnow += 1;                                  // 저장된 사람 수 1 늘리기
	printf("<<%d>>\n", *cntnow);          // 저장된 사람 수 출력
}

void printlist(struct infor* pelist, int* cntnow) {
	for (int i = 0; i < *cntnow; i++) {
		printf("%s %s %s\n", (pelist + i)->name, (pelist + i)->num, (pelist + i)->birth);     // 저장된 모든 정보 출력
	}
}

void removepe(struct infor* pelist, int* cntnow) {
	char sss[21];
	printf("Name:");
	scanf("%s", sss);       // 지울 이름 입력
	for (int i = 0; i < *cntnow; i++) {
		if (strcmp(sss, (pelist + i)->name) == 0) {      // 지울 정보의 인덱스 찾기
			for (int j = i; j < *cntnow - 1; j++) {        // 뒤에 있는 정보들 앞으로 한칸씩 땡기기
				strcpy((pelist + j)->name, (pelist + j + 1)->name);
				strcpy((pelist + j)->num, (pelist + j + 1)->num);
				strcpy((pelist + j)->birth, (pelist + j + 1)->birth);
			}
			strcpy((pelist + *cntnow - 1)->name, "\0");      // 가장 마지막에 저장되어있는 중복된 정보 삭제
			strcpy((pelist + *cntnow - 1)->num, "\0");
			strcpy((pelist + *cntnow - 1)->birth, "\0");
			*cntnow -= 1;         // 저장된 사람 수 1 줄이기
			break;
		}
	}

}

void searchbirth(struct infor* pelist, int* cntnow) {
	int mmm = 0;
	printf("Birth:");
	scanf("%d", &mmm);        // 생일 입력
	for (int i = 0; i < *cntnow; i++) {
		int x = 0;
		x += (int)((pelist + i)->birth[4] - '0');     // 문자열로 저장되어있는 생일을 정수로 바꿈(십의자리)
		x *= 10;
		x += (int)((pelist + i)->birth[5] - '0');     // 문자열로 저장되어있는 생일을 정수로 바꿈(일의자리)
		if (mmm == x) {
			printf("%s %s %s\n", (pelist + i)->name, (pelist + i)->num, (pelist + i)->birth);      // 같은 생일인 사람의 정보만 출력
		}
	}
}


int main() {
	struct infor pelist[MAX_NUM];     // 구조체 선언
	int cntnow = 0, menunow;

	while (1) {
		menunow = 0;
		printf("*****Menu*****\n");         // 메뉴 출력
		printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");
		printf("Enter_the_menu_number:");

		scanf("%d", &menunow);     // 메뉴 번호 입력


		if (menunow == 1) {      // 메뉴 1 입력시 
			if (cntnow >= MAX_NUM) {
				printf("OVERFLOW\n");      // 저장된 정보가 100 이상이면 overflow 출력
			}
			else {
				input(pelist, &cntnow);     // input 함수 호출
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
		if (menunow == 5) {      // 메뉴 5 입력시 종료
			return 0;
		}


	}

}
