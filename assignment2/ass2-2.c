#include <stdio.h>

#include <string.h>

#include <stdlib.h>

int main()
{
    char sen[201], word[20][200], a[100], plus[200], output[201] = { NULL }, blank[2] = { ' ', NULL };    // 배열 선언
    int start = 0, i = 0, j = 0, k = 0, w = 0, x = 0, g = 0, CNT=0, cnt=0;    // 변수 선언
    gets(sen);     // 문장 입력
    scanf("%s", plus);     // 추가할 단어 입력
    for (i = 0; i < strlen(sen); i++) {
        if (sen[i] >= 'a' && sen[i] <= 'z' && sen[i - 1] == ' ') {    // 단어의 첫문자라면
            start = i;     // 시작인덱스 저장
        }
        if ((sen[i] >= 'a' && sen[i] <= 'z' && sen[i + 1] == ' ') || i == strlen(sen) - 1) {   // 단어의 마지막문자라면
            int tmp = 0;
            CNT++;
            for (j = start, k = 0; j <= i; j++, k++) {     // 해당단어랑 추가할 단어의 중복여부 확인
                if (sen[j] == plus[k]) {    // 문자가 같으면
                    tmp++;    // tmp에 1 더함
                }
            }
            if (tmp != strlen(plus)) {    // 해당 단어와 추가할 단어가 다르면
                cnt++;   // cnt에 1 더함
            }

        }
    }
    if (CNT == cnt) {    // 모든 단어가 추가할 단어와 중복되지 않으면
        strcat(sen, blank);    // 문장 뒤에 공백 추가
        strcat(sen, plus);      // 문장 뒤에 단어 추가
    }

    start = 0;
    for (i = 0; i < strlen(sen); i++) {
        if (sen[i] >= 'a' && sen[i] <= 'z' && sen[i - 1] == ' ') {    // 단어의 첫문자라면
            start = i;     // 시작인덱스 저장
        }
        if ((sen[i] >= 'a' && sen[i] <= 'z' && sen[i + 1] == ' ') || i == strlen(sen) - 1) {   // 단어의 마지막문자라면
            for (j = start, k = 0; j <= i; j++, k++) {
                word[w][k] = sen[j];       // 단어별로 분리하여 이차원배열에 저장
            }
            word[w][k] = NULL;
            w++;    // 단어의 수에 1 더함

        }
    }

    for (i = 0; i < w; i++) {
        printf("%s\n", word[i]);    // 쪼갠 단어 출력
    }

    for (i = 0; i < w - 1; i++) {      // 단어 사전순으로 정렬
        for (j = i + 1; j < w; j++) {
            if (strcmp(word[i], word[j]) > 0) {
                strcpy(a, word[i]);       // a에 word[i] 저장
                strcpy(word[i], word[j]);     //  word[i]에 word[j] 저장
                strcpy(word[j], a);     // word[j]에 word[i] 저장
            }
        }
    }
    for (i = 0; i < w; i++) {
        strcat(output, word[i]);   // 단어 하나의 문자열로 합치기
        strcat(output, blank);     // 공백 추가
    }
    printf("%s", output);     // 문자열 출력
    return 0;
}
