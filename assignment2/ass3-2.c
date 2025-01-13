#include <stdio.h>

#include <string.h>

#include <stdlib.h>

int main()
{
    char str1[100], str2[100];    // 문자열 선언
    int i, j, x, a = 0;    // 변수 선언
    gets(str1);     // 문자열 입력받음
    gets(str2);     // 문자열 입력받음

    if (strncmp(str1, str2, strlen(str2)) == 0) {     // 문장의 첫단어와 비교
        if (str1[strlen(str2)] == ' ' || str1[strlen(str2)] == '.' || str1[strlen(str2)] == NULL) {    // 단어의 독립여부 확인
            a += 1;    // 같은 단어라면 a에 1 더함
        }
    }
    for (i = 0; i < strlen(str1); i++) {    // 단어 단위로 비교
        if (str1[i] == ' ' || str1[i] == '.') {     //  공백이나 .이 나오면
            if (strncmp(str1 + i + 1, str2, strlen(str2)) == 0) {     // 단어와 str2 비교
                if (str1[i + strlen(str2) + 1] == ' ' || str1[i+strlen(str2)+1] == '.' || str1[i + strlen(str2) + 1] == NULL) {    // 단어의 독립여부 확인
                    a += 1;     // a에 1 더함
                }
            }
        }
        

    }

    printf("%d", a);    // 중복된 단어의 개수 출력
    return 0;
}
