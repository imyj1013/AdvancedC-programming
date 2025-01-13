#include<stdio.h>

int main()
{
	char str[5];    // 배열 선언
	int N, i = 0, j;    // 변수 선언
	scanf("%d", &N);     // 정수 입력받음
	while (N >= 10) {
		str[i] = (N % 10) + '0';   // 정수를 문자로 변환하여 배열에 저장
		N /= 10;    // N을 10으로 나눔
		i += 1;    // i에 1을 더함

	}
	str[i] = (N % 10) + '0';   // 정수를 문자로 변환하여 배열에 저장
	i += 1;    // i에 1을 더함
	str[i] = NULL;
	for (j = i-1; j >= 0; j--) {
		if (str[j] == '1') {     // str[j]가 1이라면
			printf("one ");     // one 출력
		}
		else if (str[j] == '2') {     // str[j]가 2이라면
			printf("two ");    // two 출력
		}
		else if (str[j] == '3') {     // str[j]가 3이라면
			printf("three ");    // three 출력
		}
		else if (str[j] == '4') {     // str[j]가 4이라면
			printf("four ");     // four 출력
		}
		else if (str[j] == '5') {     // str[j]가 5이라면
			printf("five ");     // five 출력
		}
		else if (str[j] == '6') {     // str[j]가 6이라면
			printf("six ");     // six 출력
		}
		else if (str[j] == '7') {     // str[j]가 7이라면
			printf("seven ");    // seven 출력
		}
		else if (str[j] == '8') {     // str[j]가 8이라면
			printf("eight ");      //eight 출력
		}
		else if (str[j] == '9') {     // str[j]가 9이라면
			printf("nine ");     // nine 출력
		}
		if (j == 3 && str[j] !='0') {     // j가 3이고 str[j]가 0이 아니라면
			printf("THO ");     //THO 출력
		}
		else if (j == 2 && str[j] != '0') {     // j가 2이고 str[j]가 0이 아니라면
			printf("HUN ");     //HUN 출력
		}
		else if (j == 1 && str[j] != '0') {     // j가 1이고 str[j]가 0이 아니라면
			printf("TEN ");     //TEN 출력
		}
	}
	return 0;
}
