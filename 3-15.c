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
	if (pf == NULL) {
		printf("문자 메모리 할당 실패"); //오류 메세지 출력
		exit(1);
	}
	else {
		*pf = 100;// 포인터 값에 100 대입
		printf("c = %d\n", *pf); // 출력
	}
	if (pd == NULL) {
		printf("정수 메모리 할당 실패");
		exit(1);
	}
	else {
		*pd = 100;// 포인터 값에 100 대입
		printf("i = %d\n", *pd);// 출력
	}

	printf("pf = %lu\n", pf);
	printf("pf+1 = %lu\n", pf + 1);
	printf("pf-1 = %lu\n", pf - 1);

	printf("pd = %lu\n", pd);
	printf("pd+1 = %lu\n", pd + 1);
	printf("pd-1 = %lu\n", pd - 1);
}