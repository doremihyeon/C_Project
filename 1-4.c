#include <stdio.h>

#define SIZE 10 //배열의 크기를 정의하는 매크로

//배열에서 특정 값의 위치를 찾는 함수
void search(int arr[], int* target, int* index) {
	//배열을 순회하며 값을 찾음
	for (int i = 0; i < SIZE; i++) {
		//배열의 요소와 찾는 값이 같은 경우
		if (arr[i] == *target) {
			//해당 위치를 인덱스에 저장하고 함수 종료
			*index = i;
			return;
		}
	}
	//값을 못찾으면 -1을 인덱스에 저장
	*index = -1;
}

int main() {
	//배열 선언
	int arr[10] = { 23, 45, 12, 34, 65, 25, 89, 61, 26, 11 };
	//찾고자 하는 값
	int target = 0;
	//결과를 저장하는 변수
	int index;

	//search 함수 호출해 위치 찾기
	scanf("%d", &target);

	search(arr, &target, &index);

	//결과출력
	if (index != -1) {
		printf("값 %d는 배열에서 %d번째 위치에 있습니다.\n", target, index);
	}
	else {
		printf("값 %d는 배열에 존재하지 않습니다.\n", target);
	}
	return 0;
}