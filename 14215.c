#include <stdio.h>

int max(int a, int b, int c) {
    if (a > b) {
        if (a > c)
            return 1;
        else
            return 3;
    }

    else {
        if (b > c)
            return 2;
        else
            return 3;
    }
} // 세 값 중 가장 큰 값을 구하는 함수

int main(void) {
    int a, b, c;
    int circum = 0;
    scanf_s("%d %d %d", &a, &b, &c);
    for (int i = 1; i <= a; i++) {
        int Max, Sum;
        for (int j = 1; j <= b; j++) {
            for (int k = 1; k <= c; k++) {
                Max = max(i, j, k);
                Sum = i + j + k;

                if (Max == 1) {
                    if (j + k > i && circum < Sum)
                        circum = Sum;
                } // 최댓값이 i일 경우

                else if (Max == 2) {
                    if (i + k > j && circum < Sum)
                        circum = Sum;
                } // 최댓값이 j일 경우

                else if (Max == 3) {
                    if (i + j > k && circum < Sum)
                        circum = Sum;
                } // 최댓값이 k일 경우
            }
        }
    }
    printf("%d", circum);
    return 0;
}