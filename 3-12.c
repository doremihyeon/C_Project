#include <stdio.h>
#include <memory.h> // �޸� ���� �Լ��� ����ϱ� ���� ��� ���� ����
#include <stdlib.h> // ǥ�� ���̺귯�� �Լ��� �����ϱ� ���� ��� ����

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
		printf("���� �޸� �Ҵ� ����");
		exit(1);
	}
	else {
		*pc = 100;// ������ ���� 100 ����
		printf("c = %d\n", *pc); // ���
	}
	if (pi == NULL) {
		printf("���� �޸� �Ҵ� ����");
		exit(1);
	}
	else {
		*pi = 100;// ������ ���� 100 ����
		printf("i = %d\n", *pi);// ���
	}
	if (pf == NULL) {
		printf("float �޸� �Ҵ� ����");
		exit(1);
	}
	else
	{
		*pf = 100; // �����Ͱ��� 100 ����
		printf("f = %f\n", *pf);// ���
	}
	if (pd == NULL) {
		printf("double �޸� �Ҵ� ����");
		exit(1);
	}
	else {
		*pd = 100; // �����Ͱ��� 100 ����
		printf("d = %lf\n", pd);// ���
	}

	free(pc);
	free(pi);
	free(pf);
	free(pd);
}
