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

//	printf("�ʱ�ȭ�ϱ����� pc = %lu\n", *pc); //�ʱ�ȭ ���� �ʰ� ȣ���Ͽ� ������ �߻��Ѵ�. 
	pc = &c;
	printf("�ʱ�ȭ�ϱ����� pc = %lu\n", *pc);
	*pc = 100;
	printf("c = %d\n", c);

}