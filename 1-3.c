#include<stdio.h>
#include<stdlib.h> //rand�Լ��� ���� ��� ����

#define SIZE 10 //�迭�� ũ�⸦ �����ϴ� ��ũ��

int main() {
	//�迭 ����
	int arr[SIZE];

	//�迭�� ������ �� �Ҵ� 
	for (int i = 0; i < SIZE; i++) {
		arr[i] = rand(); // 0���� RAND_MAX ������ ���� �Ҵ�
	}

	//�ִ� �ּڰ� �ʱ�ȭ
	int max = arr[0];
	int min = arr[0];

	//�迭 ��ȸ�ϸ� �ִ� �ּڰ� ã��
	for (int i = 0; i < SIZE; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
		if (arr[i] < min) {
			min = arr[i];
		}
	}

	//�ִ񰪰� �ּڰ� ���
	printf("�ִ� : %d\n", max);
	printf("�ּڰ� : %d\n", min);

	return 0;
}