#include<stdio.h>

struct class {    // 구조체 정의
	int g, w, h;
};

int main()
{
	int n, level1 = 0, level2 = 0, level3 = 0;   // 변수 선언
	struct class stu[10];    // 구조체 선언
	scanf("%d", &n);     // 학생 수 입력
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &stu[i].g, &stu[i].w, &stu[i].h);    // 성별, 체중, 키 입력
		if (stu[i].g == 1) {      // 남자라면 
			if (stu[i].w < 60) {      // 몸무게가 60미만이라면
				if (stu[i].h < 165) {    // 키가 165미만이라면
					level1++;    // level1에 1 더함
				}
				else if (stu[i].h >= 175) {     // 키가 175이상이라면
					level3++;    // level3에 1 더함
				}
				else {
					level2++;    // level2에 1 더함
				}
			}
			else if (stu[i].w >= 70) {     // 몸무게가 70이상이라면
				if (stu[i].h < 165) {    // 키가 165미만이라면
					level2++;    // level2에 1 더함
				}
				else if (stu[i].h >= 175) {     // 키가 175이상이라면
					level1++;    // level1에 1 더함
				}
				else {
					level3++;    // level3에 1 더함
				}
			}
			else {
				if (stu[i].h < 165) {    // 키가 165미만이라면
					level3++;    // level3에 1 더함
				}
				else if (stu[i].h >= 175) {     // 키가 175이상이라면
					level2++;    // level2에 1 더함
				}
				else {
					level1++;    // level1에 1 더함
				}
			}
		}
		if (stu[i].g == 2) {
			if (stu[i].w < 50) {     // 몸무게가 50미만이라면
				if (stu[i].h < 165) {    // 키가 165미만이라면
					level1++;    // level1에 1 더함
				}
				else if (stu[i].h >= 175) {     // 키가 175이상이라면
					level3++;    // level3에 1 더함
				}
				else {
					level2++;    // level2에 1 더함
				}
			}
			else if (stu[i].w >= 60) {     // 몸무게가 70이상이라면
				if (stu[i].h < 165) {    // 키가 165미만이라면
					level2++;    // level2에 1 더함
				}
				else if (stu[i].h >= 175) {     // 키가 175이상이라면
					level1++;    // level1에 1 더함
				}
				else {
					level3++;    // level3에 1 더함
				}
			}
			else {
				if (stu[i].h < 165) {    // 키가 165미만이라면
					level3++;    // level3에 1 더함
				}
				else if (stu[i].h >= 175) {     // 키가 175이상이라면
					level2++;    // level2에 1 더함
				}
				else {
					level1++;    // level1에 1 더함
				}
			}
		}
	}
	printf("%d %d %d", level1, level2, level3);    // 신체등급별 인원 수 출력
	return 0;
}
