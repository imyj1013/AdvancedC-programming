#include <stdio.h>

#include <string.h>

#include <stdlib.h>

int main()
{
	int** p;
	int len = 5, i=0, j=0;
	p = (int**)malloc(6 * sizeof(int*));
	p[0] = (int*)malloc(len * sizeof(int));
	if (p == NULL || p[0] == NULL) {      // 메모리 할당 실패하면,
		printf("Not enough memory!");      // 오류 상황 알리고,
		return -1;      // 함수 종료
	}
	for (j = 0; j < len; j++) {
		scanf("%d", &p[0][j]);
		if (p[0][j] == -1) {
			break;
		}
	}
	if (p[0][j] != -1) {
		len += 3;
		for (i = 1; i < 6; i++) {
			p[i] = (int*)malloc(len * sizeof(int));
			if (p[i] == NULL) {      // 메모리 할당 실패하면,
				printf("Not enough memory!");      // 오류 상황 알리고,
				return -1;      // 함수 종료
			}

			for (j = 0; j < len - 3; j++) {
				p[i][j] = p[i - 1][j];
			}


			for (j = len - 3; j < len; j++) {
				scanf("%d", &p[i][j]);
				if (p[i][j] == -1) {
					break;
				}
			}
			if (p[i][j] == -1) {
				break;
			}
			len += 3;
		}
	}	
	for (int k = 0; k <= j; k++) {
		printf(" %d", p[i][k]);
	}
	for (int k = 0; k <= i; k++) {
		free(p[k]);
	}
	if (p != NULL)      // p가 NULL이 아닌 경우에만
		free(p);      //free() 함수 호출
	return 0;
}
