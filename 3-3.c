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
	*pc = 100;//�������� ���� ������ �������� ���� �������൵ �ǹ̰� ����
}