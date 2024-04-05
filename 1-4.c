#include <stdio.h>

#define SIZE 10 //�迭�� ũ�⸦ �����ϴ� ��ũ��

//�迭���� Ư�� ���� ��ġ�� ã�� �Լ�
void search(int arr[], int* target, int* index) {
	//�迭�� ��ȸ�ϸ� ���� ã��
	for (int i = 0; i < SIZE; i++) {
		//�迭�� ��ҿ� ã�� ���� ���� ���
		if (arr[i] == *target) {
			//�ش� ��ġ�� �ε����� �����ϰ� �Լ� ����
			*index = i;
			return;
		}
	}
	//���� ��ã���� -1�� �ε����� ����
	*index = -1;
}

int main() {
	//�迭 ����
	int arr[10] = { 23, 45, 12, 34, 65, 25, 89, 61, 26, 11 };
	//ã���� �ϴ� ��
	int target = 0;
	//����� �����ϴ� ����
	int index;

	//search �Լ� ȣ���� ��ġ ã��
	scanf("%d", &target);

	search(arr, &target, &index);

	//������
	if (index != -1) {
		printf("�� %d�� �迭���� %d��° ��ġ�� �ֽ��ϴ�.\n", target, index);
	}
	else {
		printf("�� %d�� �迭�� �������� �ʽ��ϴ�.\n", target);
	}
	return 0;
}