#include <stdio.h>
#include <math.h>

#define MAX_STUDENTS 1000

typedef struct //����ü ����
{
	char name[100];//�̸�
	int student_number;//�й�
	int score;//����

} Student;//type�� �̸� student

// ����� ����ϴ� �Լ�
double get_mean(Student students[], int num_students) {
	int sum = 0;
	for (int i = 0; i < num_students; i++) {
		sum += students[i].score;
	}
	return (double)sum / num_students;
}

// ǥ�� ������ ����ϴ� �Լ�
double get_deviation(Student students[], int num_students) {
	double mean = get_mean(students, num_students);
	double deviation = 0;

	for (int i = 0; i < num_students; i++) {
		deviation += pow(students[i].score - mean, 2);
	}

	return sqrt(deviation / num_students);
}

int main() {

	//�л� ������ ������ �迭 ����
	Student students[MAX_STUDENTS];

	//�л� �� �Է�
	int	num_students;
	printf("�л����� �Է��ϼ���:");
	scanf("%d", &num_students);

	//�л� ���� �Է�
	for (int i = 0; i < num_students; i++) {
		printf("�̸��� �Է��ϼ���: ");
		scanf("%s", students[i].name);

		printf("�й��� �Է��ϼ���: ");
		scanf("%d", &students[i].student_number);

		printf("������ �Է��ϼ���: ");
		scanf("%d", &students[i].score);
	}

	// ��հ� ǥ�� ���� ���
	double mean = get_mean(students, num_students);
	double deviation = get_deviation(students, num_students);

	// ��� ���
	printf("\n���: %.2lf\n", mean);
	printf("ǥ�� ����: %.2lf\n", deviation);

	return 0;
}