#include <stdio.h>

#include <string.h>

#include <stdlib.h>

typedef struct student {
	char* p;
	int ko, en, ma;
	double avg;
}ss;

int main() {
	ss* x;
	char tmp[8];
	int N;
	scanf("%d", &N);
	getchar();
	x = (ss*)malloc(N * sizeof(ss));
	if (x == NULL) {      // 메모리 할당 실패하면,
		printf("Not enough memory!");      // 오류 상황 알리고,
		return -1;      // 함수 종료
	}
	for (int i = 0; i < N; i++) {
		scanf("%s %d %d %d", tmp, &x[i].ko, &x[i].en, &x[i].ma);
		x[i].p = (char*)malloc((strlen(tmp) + 1) * sizeof(char));
		strcpy(x[i].p, tmp);
		x[i].avg = (x[i].ko + x[i].en + x[i].ma) / 3.0;
	}
	for (int i = 0; i < N; i++) {
		printf("%s %.1f ", (x + i)->p, (x + i)->avg);
		if (x[i].ko >= 90 || x[i].en >= 90 || x[i].ma >= 90) {
			printf("GREAT ");
		}
		if (x[i].ko < 70 || x[i].en < 70 || x[i].ma < 70) {
			printf("BAD ");
		}
		printf("\n");
	}
	return 0;
}
