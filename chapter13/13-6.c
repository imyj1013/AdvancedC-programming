#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ABC(int(*p)[20], int k1, int k2) {
	for (int i = 0; i < k1; i++) {
		for (int j = 0; j < k2; j++) {
			(*(p + i))[j] = i + j;
		}
	}
}

int main() {
	int arr[20][20], N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[i][j] = 0;
		}
	}
	ABC(arr, N, N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf(" %d", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
