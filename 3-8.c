#include <stdio.h>

//int* pa[20]; //int로 선언이 되어있지만, 입력값은 char이라 오류가 발생

char* pa[] = {
	"에러 1",
	"에러 2",
	"에러 3",
	"에러 4",
	"에러 5",
	"에러 6"
};
void error(int err_num)
{
	printf(pa[err_num]); //pa[1]
}
main()
{
	error(1);
}