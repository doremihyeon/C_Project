#include <stdio.h>
#include <memory.h> // �޸� ���� �Լ��� ����ϱ� ���� ��� ���� ����
#include <stdlib.h> // ǥ�� ���̺귯�� �Լ��� �����ϱ� ���� ��� ����


typedef struct test {
	int data;
	struct test* link;
} test_str;

void main()
{
	int i;
	test_str* ptest;
	ptest = (double*)malloc(sizeof(test_str));
	
	for (i = 0; i < 5; i++)
	{
		printf("%d", ptest[i].data);
	}

	ptest->data = 100; //����ü test�� data�� 100����
	printf("%d", ptest->data);
	free(ptest);
}