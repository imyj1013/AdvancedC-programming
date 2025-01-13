#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#pragma warning(disable: 4013)

#pragma warning(disable:4996)

int main()
{
    char A[21], a[300], B[21], b[300];    // 배열 선언
    int x = 0, i, result=0;     // 변수 선언
    gets(A);     // 문자열 입력받음
    gets(B);     //  문자열 입력받음
    char* p, * q;     // 포인터 선언
    for (i = 1; i <= 10; i++) {     // A 문자열을 규칙대로 변형하여 a에 저장
        q = a;
        for (p = A; p < A + strlen(A); p++) {
            if (*p >= 'A' && *p <= 'Z') {     // 입력된 문자가 대문자이면
                *q = *p + i;    // i번째 뒤 문자로 바꿈
                q++;
            }
            else if (*p >= 'a' && *p <= 'z') {     // 입력된 문자가 소문자이면
                *q = *p - i;    // i번째 앞 문자로 바꿈
                q++;
            }
            else if (*p > '0' && *p <= '9') {     // 입력된 문자가 숫자라면
                if (*(p + 1) >= '0' && *(p + 1) <= '9') {    //  두자리 숫자라면
                    x += (int)(*p - '0');     // 숫자 x에 저장
                    x *= 10;    // 10을 곱합
                    p++;
                    x += (int)(*p - '0');     // 숫자 x에 저장
                }
                else {     //  한자리 숫자라면 
                    x += (int)(*p - '0');     // 숫자 x에 저장
                }
                for (int j = 0; j < i; j++) {
                    *q = (char)('A' + x - 1);   // 해당 숫자번째의 알파벳 저장
                    q++;
                }
                x = 0;
            }
            else {     // 입력된 문자가 그 외 문자라면
                *q = ' ';     // 공백 저장
                q++;
            }
        }
        *q = NULL;
        if (strcmp(a, B) == 0) {     // 문자열 a, B가 같으면
            result = 1;    // 결과값에 1 저장
            break;
        }
    }
    for (i = 1; i <= 10; i++) {     // B 문자열을 규칙대로 변형하여 b에 저장
        q = b;
        for (p = B; p < B + strlen(B); p++) {
            if (*p >= 'A' && *p <= 'Z') {     // 입력된 문자가 대문자이면
                *q = *p + i;    // i번째 뒤 문자로 바꿈
                q++;
            }
            else if (*p >= 'a' && *p <= 'z') {     // 입력된 문자가 소문자이면
                *q = *p - i;    // i번째 앞 문자로 바꿈
                q++;
            }
            else if (*p > '0' && *p <= '9') {     // 입력된 문자가 숫자이면
                if (*(p + 1) >= '0' && *(p + 1) <= '9') {    //  두자리 숫자라면
                    x += (int)(*p - '0');     // 숫자 x에 저장
                    x *= 10;     // 10을 곱함
                    p++;
                    x += (int)(*p - '0');     // 숫자 x에 저장
                }
                else {
                    x += (int)(*p - '0');     // 숫자 x에 저장
                }
                for (int j = 0; j < i; j++) {
                    *q = (char)('A' + x - 1);   // 해당 숫자번째의 알파벳 저장
                    q++;
                }
                x = 0;
            }
            else {     // 입력된 문자가 그 외 문자라면
                *q = ' ';     // 공백 저장
                q++;
            }
        }
        *q = NULL;
        if (strcmp(A, b) == 0) {    // 문자열 A, b가 같으면
            result = 2;    // 결과값에 2 저장
            break;
        }
    }
    printf("%d", result);   // 결과값 출력
    return 0;
}
