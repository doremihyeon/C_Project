#include <stdio.h>
#include <math.h>

#define MAX_STUDENTS 1000

typedef struct //구조체 생성
{
	char name[100];//이름
	int student_number;//학번
	int score;//성적

} Student;//type의 이름 student

// 평균을 계산하는 함수
double get_mean(Student students[], int num_students) {
	int sum = 0;
	for (int i = 0; i < num_students; i++) {
		sum += students[i].score;
	}
	return (double)sum / num_students;
}

// 표준 편차를 계산하는 함수
double get_deviation(Student students[], int num_students) {
	double mean = get_mean(students, num_students);
	double deviation = 0;

	for (int i = 0; i < num_students; i++) {
		deviation += pow(students[i].score - mean, 2);
	}

	return sqrt(deviation / num_students);
}

int main() {

	//학생 정보를 저장할 배열 선언
	Student students[MAX_STUDENTS];

	//학생 수 입력
	int	num_students;
	printf("학생수를 입력하세요:");
	scanf("%d", &num_students);

	//학생 정보 입력
	for (int i = 0; i < num_students; i++) {
		printf("이름을 입력하세요: ");
		scanf("%s", students[i].name);

		printf("학번을 입력하세요: ");
		scanf("%d", &students[i].student_number);

		printf("성적을 입력하세요: ");
		scanf("%d", &students[i].score);
	}

	// 평균과 표준 편차 계산
	double mean = get_mean(students, num_students);
	double deviation = get_deviation(students, num_students);

	// 결과 출력
	printf("\n평균: %.2lf\n", mean);
	printf("표준 편차: %.2lf\n", deviation);

	return 0;
}