#include<stdio.h>

// 두 배열의 차이를 계산하여 새로운 배열에 저장하는 함수
int matrix_diff(int* a, int* b, int* c) {
	// 각 요소별로 두 배열의 차이를 계산하여 배열 c에 저장
	for (int i = 0; i < 10; i++) {
		c[i] = a[i] - b[i];
	}
}

int main() {
	// a,b 배열을 초기화
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int b[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	// 결과를 저장할 배열 c 초기화
	int c[10] = { 0 };

	// 두 배열의 차이 계산하여 결과를 배열 c에 저장
	matrix_diff(a, b, c);

	// 결과 배열 c 출력
	for (int i = 0; i < 10; i++) {
		printf("c[%d] : %d\n", i, c[i]);
	}

	return 0;
}