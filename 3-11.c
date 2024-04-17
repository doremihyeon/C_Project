#include <stdio.h>
#include <memory.h> // 메모리 관리 함수를 사용하기 위한 헤더 파일 포함
#include <stdlib.h> // 표준 라이브러리 함수를 포함하기 위한 헤더 파일

void main()
{
	int i; // 정수형 변수 i 선언
	char* pc; // char 타입의 포인터 변수 pc를 선언
	pc = (char*)malloc(100); // pc에 동적 메모리 할당을 통하여 100바이트의 메모리 할당, 그 주소를 메모리에 저장
	for (i = 0; i < 100; i++) {
		*(pc + i) = 100; //pc[0]에만 100의 정수가 선언
		printf("%d ", *(pc + i));
	}
	free(pc); // 동적으로 할당된 메모리 공간을 해제
}