#include <stdio.h>

int main() {
	char *pc;
	int *pi;
	float *pf;
	double *pd;

	char c;
	int i;
	float f;
	double d;

	//printf("%lu %lu %lu\n", pi, pf, pd);//�޸� �ּҰ� �Ҵ���� �ʰ� ȣ���ϱ� ������ ������ �߻��Ѵ�. 
	//�޸� �Ҵ�
	pi = &i;
	pf = &f;
	pd = &d;
	Aprintf("%lu %lu %lu\n", pi, pf, pd);
	//i, f, d�� 100�Ҵ�
	*pi = 100;
	*pf = 100;
	*pd = 100;
	printf("i = %d\nf = %d\nd = %d\n", i, f, d);
}