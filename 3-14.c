#include <stdio.h>
#include <memory.h> // �޸� ���� �Լ��� ����ϱ� ���� ��� ���� ����
#include <stdlib.h> // ǥ�� ���̺귯�� �Լ��� �����ϱ� ���� ��� ����

void main()
{
	char* pc;
	int* pi;
	float* pf;
	double* pd;
	pc = (char*)malloc(100 * sizeof(char)); //����(1byte)*100 = 100byte �Ҵ�
	pi = (int*)malloc(100 * sizeof(int)); //����(4byte)*100 = 400byte �Ҵ�
	pf = (float*)malloc(100 * sizeof(float)); //float(4byte)*100 = 400byte �Ҵ�
	pd = (double*)malloc(100 * sizeof(double)); //double(8byte)*100 = 800byte �Ҵ�
	if (pc == NULL) {
		printf("���� �޸� �Ҵ� ����"); //���� �޼��� ���
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

	printf("pc = %lu\n", pc);
	printf("pc+1 = %lu\n", pc + 1);
	printf("pc-1 = %lu\n", pc - 1);

	printf("pi = %lu\n", pi);
	printf("pi+1 = %lu\n", pi + 1);
	printf("pi-1 = %lu\n", pi - 1);
}