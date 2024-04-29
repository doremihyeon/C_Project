#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

void main()
{
	int* pi;
	pi = (int*)malloc(100 * sizeof(char));
	if (pi == NULL) {
		printf("메모리 할당 실패");
		exit(1);
	}
	else
	{
		*pi = 100; //포인터값에 100 대입
		printf("pi = %d\n", *pi); //출력
	}
	for (int i = 0; i < 30; i++)
	{
		printf("%d ", *(pi + i));
	}
	free(pi);
}