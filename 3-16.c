#include <stdio.h>
#include <memory.h> // 메모리 관리 함수를 사용하기 위한 헤더 파일 포함
#include <stdlib.h> // 표준 라이브러리 함수를 포함하기 위한 헤더 파일


typedef struct test {
	int data;
	struct test* link;
} test_str;

void main()
{
	int i;
	test_str* ptest;
	ptest = (double*)malloc(sizeof(test_str));
	
	for (i = 0; i < 5; i++)
	{
		printf("%d", ptest[i].data);
	}

	ptest->data = 100; //구조체 test의 data에 100저장
	printf("%d", ptest->data);
	free(ptest);
}