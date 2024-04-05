#include<stdio.h>
#include<stdlib.h> //rand함수를 위한 헤더 파일

#define SIZE 10 //배열의 크기를 정의하는 매크로

int main() {
	//배열 선언
	int arr[SIZE];

	//배열에 랜덤한 값 할당 
	for (int i = 0; i < SIZE; i++) {
		arr[i] = rand(); // 0부터 RAND_MAX 사이의 난수 할당
	}

	//최대 최솟값 초기화
	int max = arr[0];
	int min = arr[0];

	//배열 순회하며 최대 최솟값 찾기
	for (int i = 0; i < SIZE; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
		if (arr[i] < min) {
			min = arr[i];
		}
	}

	//최댓값과 최솟값 출력
	printf("최댓값 : %d\n", max);
	printf("최솟값 : %d\n", min);

	return 0;
}