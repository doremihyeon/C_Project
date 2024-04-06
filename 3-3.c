#include <stdio.h>

void main()
{
	char* pc;
	int* pi;
	float* pf;
	double* pd;

	char c;
	int i;
	float f;
	double d;

	pc = NULL;
	printf("pc = %lu\n", pc);
	*pc = 100;//절차지향 언어기 때문에 마지막에 값을 지정해줘도 의미가 없음
}