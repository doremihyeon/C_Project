#include <stdio.h>


#define LIST_SIZE 10// �迭�� ũ�⸦ �����ϴ� ��ũ��

// �־��� �迭 ����
int list[LIST_SIZE] = { 23, 45, 12, 34, 65, 25, 89, 61, 26, 11 };

// ���� �Լ�
int main() {
    int i;

    // �迭�� �� ������ �ּҸ� ���
    for (i = 0; i < LIST_SIZE; i++) {
        // �迭�� i��° ������ �ּ� ���
        printf("list[%d]�� �ּ� = %p\n", i, &list[i]);
    }

    return 0;
}