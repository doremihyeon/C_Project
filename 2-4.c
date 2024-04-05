#include <stdio.h>
#include <math.h>

#define MAX_STUDENTS 1000

// �л� ������ �����ϴ� ����ü ����
typedef struct {
    char name[50];
    int student_number;
    int score;
} Student;

// ����� ����ϴ� �Լ�
double get_mean(Student* students, int num_students) {
    int sum = 0;
    for (int i = 0; i < num_students; i++) {
        sum += students[i].score;
    }
    return (double)sum / num_students;
}

// ǥ�� ������ ����ϴ� �Լ�
double get_deviation(Student* students, int num_students) {
    double mean = get_mean(students, num_students);
    double deviation = 0;

    for (int i = 0; i < num_students; i++) {
        deviation += pow(students[i].score - mean, 2);
    }

    return sqrt(deviation / num_students);
}

int main() {
    // �л� ������ ������ �迭 ����
    Student students[MAX_STUDENTS];
    int num_students;

    // �л� �� �Է�
    printf("�л� ���� �Է��ϼ���: ");
    scanf("%d", &num_students);

    // �л� ���� �Է�
    for (int i = 0; i < num_students; i++) {
        printf("�л��� �̸��� �Է��ϼ���: ");
        scanf("%s", students[i].name);

        printf("�л��� �й��� �Է��ϼ���: ");
        scanf("%d", &students[i].student_number);

        printf("�л��� ������ �Է��ϼ���: ");
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
