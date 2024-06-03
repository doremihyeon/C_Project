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

	//printf("%lu %lu %lu\n", pi, pf, pd);//메모리 주소가 할당되지 않고 호출하기 때문에 오류가 발생한다. 
	//메모리 할당
	pi = &i;
	pf = &f;
	pd = &d;
	Aprintf("%lu %lu %lu\n", pi, pf, pd);
	//i, f, d에 100할당
	*pi = 100;
	*pf = 100;
	*pd = 100;
	printf("i = %d\nf = %d\nd = %d\n", i, f, d);
}