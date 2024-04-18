#include <stdio.h>
#include <memory.h> // 메모리 관리 함수를 사용하기 위한 헤더 파일 포함
#include <stdlib.h> // 표준 라이브러리 함수를 포함하기 위한 헤더 파일

void main()
{
	char* pc;
	int* pi;
	float* pf;
	double* pd;
	pc = (char*)malloc(100 * sizeof(char)); //문자(1byte)*100 = 100byte 할당
	pi = (int*)malloc(100 * sizeof(int)); //정수(4byte)*100 = 400byte 할당
	pf = (float*)malloc(100 * sizeof(float)); //float(4byte)*100 = 400byte 할당
	pd = (double*)malloc(100 * sizeof(double)); //double(8byte)*100 = 800byte 할당
	if (pc == NULL) {
		printf("문자 메모리 할당 실패"); //오류 메세지 출력
		exit(1);
	}
	else {
		*pc = 100;// 포인터 값에 100 대입
		printf("c = %d\n", *pc); // 출력
	}
	if (pi == NULL) {
		printf("정수 메모리 할당 실패");
		exit(1);
	}
	else {
		*pi = 100;// 포인터 값에 100 대입
		printf("i = %d\n", *pi);// 출력
	}

	printf("pc = %lu\n", pc);
	printf("pc+1 = %lu\n", pc + 1);
	printf("pc-1 = %lu\n", pc - 1);

	printf("pi = %lu\n", pi);
	printf("pi+1 = %lu\n", pi + 1);
	printf("pi-1 = %lu\n", pi - 1);
}