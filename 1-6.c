#include <stdio.h>

void printArrayAddress(int[][3]);

void main(){
int array[2][3] = {{1, 2, 3}, {4, 5, 6}};//배열(행, 열) 임의의 값으로 초기화
printf("배열 array의 출력 : \n");
printArrayAddress(array);//printArrayAddress함수에 배열 array전달
}

void printArrayAddress(int a[][3]){
	int i, j;
	for (i = 0; i <= 1; i++) {
		for (j = 0; j <= 2; j++)
			printf("%p ", &a[i][j]); //%p를 사용해 주소를 출력
		printf("\n");
	}
}