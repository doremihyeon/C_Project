#include<stdio.h>

#define LIST_SIZE 1000

typedef struct student //student ����ü ����
{
	char name[100];//�̸�
	int student_number;//�й�
	int score;//����

} student;//type�� �̸� student

int main() {
	
	//�л� ������ ������ �迭 ����
	student student[LIST_SIZE];
	
	//�л� �� �Է�
	int	num_student;
	printf("�л����� �Է��ϼ���:");
	scanf�ߣ�("%d", &num_student);
	
	//�л� ���� �Է�
	for (int i = 0; i < num_student; i++) {
		printf("�̸��� �Է��ϼ���: ");
		scanf�ߣ�("%s", student[i].name);

		printf("�й��� �Է��ϼ���: ");
		scanf�ߣ�("%d", &student[i].student_number);

		printf("������ �Է��ϼ���: ");
		scanf�ߣ�("%d", &student[i].score);
	}
	
	//�Էµ� �л� ���� ���
	for (int i = 0; i < num_student; i++) {
		printf("�̸�: %s, �й�: %d, ����: %d\n", student[i].name, student[i].student_number, student[i].score);
	}

	return 0;

}