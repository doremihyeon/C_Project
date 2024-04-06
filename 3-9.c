#include <stdio.h >
void swap1(int i, int j);
void swap2(int* i, int* j);
//
void main()
{
	int num1, num2;
	num1 = 100;
	num2 = 200;
	swap1(num1, num2); //반환값이 없어서 똑같이 100, 200이 출력된다.
	printf("num1 : %d num2 : %d\n", num1, num2);
	swap2(&num1, &num2); //&주소값을 가져오기 때문에 200, 100이 출력된다.
	printf("num1 : %d num2 : %d\n", num1, num2);
}
//
void swap1(int i, int j)
{
	int temp;
	temp = i;
	i = j;
	j = temp;
}
//
void swap2(int* i, int* j)
{
	int temp;
	temp = *i;
	*i = *j;
	*j = temp;
}