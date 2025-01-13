#include <stdio.h>

#include <string.h>

#include <stdlib.h>

int s_check(char* p, char* q);      // 함수 원형 선언

int main()
{
    int M, K1, K2;       // 변수 선언
    char ssss[10][201];      // 배열 선언
    scanf("%d", &M);     // 입력받을 문자열 수 입력받음
    scanf("%d %d", &K1, &K2);     // 확인할 문자의 범위 입력받음
    getchar();
    for (int i = 0; i < M; i++) {
        gets(ssss[i]);      // M개의 문자열 입력받음
    }
    for (int i = 0; i < M; i++) {
        if (s_check(&ssss[i][K1], &ssss[i][K2]) != 0 && strlen(ssss[i]) >= K1) {     // 함수 반환값이 0 이 아니면
            printf("%d\n", s_check(&ssss[i][K1], &ssss[i][K2]));      // 함수 반환값 출력
        }
    }
    return 0;
}

int s_check(char* p, char* q)
{
    int result = 0;
    char* r;
    for (r = p; r <= q; r++) {     // 검사할 범위
        if (*r >= 'a' && *r <= 'z') {     // 소문자이면
            result += 1;    // result에 1 더함
        }
    }
    return result;     // 소문자 개수 반환
}
