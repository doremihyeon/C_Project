#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

void main()
{
	int* pi;
	pi = (int*)malloc(100 * sizeof(char));
	if (pi == NULL) {
		printf("�޸� �Ҵ� ����");
		exit(1);
	}
	else
	{
		*pi = 100; //�����Ͱ��� 100 ����
		printf("pi = %d\n", *pi); //���
	}
	for (int i = 0; i < 30; i++)
	{
		printf("%d ", *(pi + i));
	}
	free(pi);
}