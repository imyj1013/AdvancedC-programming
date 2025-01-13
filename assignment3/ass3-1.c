#include <stdio.h>

#include <string.h>

#include <stdlib.h>

struct student {      // 구조체 정의
    char n[10], id[11], g;    // 이름, 학번, 학점
};

int main(void) {
    struct student sss[5];    // 구조체 선언
    char name[10], idid[5], grade;    // 찾을 학생 이름, 입학년도, 학점 선언
    int cnt = 0;
    for (int i = 0; i < 5; i++) {
        scanf("%s %s %c", sss[i].n, sss[i].id, &sss[i].g);     // 이름, 학번, 학점 입력받음
    }
    scanf("%s", name);    // 찾을 학생 이름 입력받음
    for (int i = 0; i < 5; i++) {      // 학생 찾기
        if (strcmp(name, sss[i].n) == 0) {    // 학생 찾았으면
            strncpy(idid, sss[i].id, 4);     // 입학년도 idid에 저장
            idid[4] = NULL;
            for (int j = 0; j < 5; j++) {
                if (j == i) {    // 같은 학생이면
                    continue;     // 그냥 넘어감
                }
                if (strncmp(sss[i].id, sss[j].id, 4) == 0 && sss[i].g == sss[j].g) {   // 같은 학번이면서 같은 학점인 학생 찾기
                    printf("%s ", sss[j].n);     // 학점이랑 학번 같은 학생 출력
                    cnt++;    // 학점이랑 학번 같은 학생 수 세기
                }
            }
            if (cnt == 0) {     // 조건에 맞는 학생 없으면
                printf("0\n");      // 0 출력
            }
            else {
                printf("\n");     // 줄바꿈
            }
            break;    // 반복종료
        }
    }
    printf("%s %d", idid, atoi(idid) % 131);    // 입학년도와 131로 나눈 나머지 출력
    return 0;
}
