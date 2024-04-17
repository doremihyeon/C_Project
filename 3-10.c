#include <stdio.h>
#include <memory.h> // 메모리 관리 함수를 사용하기 위한 헤더 파일 포함
#include <stdlib.h> // 표준 라이브러리 함수를 포함하기 위한 헤더 파일

void main()
{
	char* pc; // char 타입의 포인터 변수 pc를 선언
	pc = (char*)malloc(1); // 동적 메모리 할당을 통하여 1바이트의 메모리 할당, 그 주소를 메모리에 저장
	*pc = 100; // 할당된 메모리에 100값을 저장
	printf("c = %d\n", *pc); // 포인터 pc가 가리키는 메모리의 값을 읽어와 출력
	free(pc); // 동적으로 할당된 메모리 공간을 해제
}