#include <stdio.h>


#define LIST_SIZE 10// 배열의 크기를 정의하는 매크로

// 주어진 배열 선언
int list[LIST_SIZE] = { 23, 45, 12, 34, 65, 25, 89, 61, 26, 11 };

// 메인 함수
int main() {
    int i;

    // 배열의 각 원소의 주소를 출력
    for (i = 0; i < LIST_SIZE; i++) {
        // 배열의 i번째 원소의 주소 출력
        printf("list[%d]의 주소 = %p\n", i, &list[i]);
    }

    return 0;
}