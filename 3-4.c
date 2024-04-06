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

//	printf("초기화하기전의 pc = %lu\n", *pc); //초기화 되지 않고 호출하여 오류가 발생한다. 
	pc = &c;
	printf("초기화하기후의 pc = %lu\n", *pc);
	*pc = 100;
	printf("c = %d\n", c);

}