#include <stdio.h>
#include <memory.h> // 메모리 관리 함수를 사용하기 위한 헤더 파일 포함
#include <stdlib.h> // 표준 라이브러리 함수를 포함하기 위한 헤더 파일

void main()
{
	char* pc;
	int* pi;
	float* pf;
	double* pd;
	pc = (char*)malloc(100 * sizeof(char));
	pi = (int*)malloc(100 * sizeof(int));
	pf = (float*)malloc(100 * sizeof(float));
	pd = (double*)malloc(100 * sizeof(double));
	if (pc == NULL) {
		printf("문자 메모리 할당 실패");
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
	if (pf == NULL) {
		printf("float 메모리 할당 실패");
		exit(1);
	}
	else
	{
		*pf = 100; // 포인터값에 100 대입
		printf("f = %f\n", *pf);// 출력
	}
	if (pd == NULL) {
		printf("double 메모리 할당 실패");
		exit(1);
	}
	else {
		*pd = 100; // 포인터값에 100 대입
		printf("d = %lf\n", pd);// 출력
	}

	free(pc);
	free(pi);
	free(pf);
	free(pd);
}
