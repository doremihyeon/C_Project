#include<stdio.h>

#define LIST_SIZE 1000

typedef struct student //student 구조체 생성
{
	char name[100];//이름
	int student_number;//학번
	int score;//성적

} student;//type의 이름 student

int main() {
	
	//학생 정보를 저장할 배열 선언
	student student[LIST_SIZE];
	
	//학생 수 입력
	int	num_student;
	printf("학생수를 입력하세요:");
	scanf＿ｓ("%d", &num_student);
	
	//학생 정보 입력
	for (int i = 0; i < num_student; i++) {
		printf("이름을 입력하세요: ");
		scanf＿ｓ("%s", student[i].name);

		printf("학번을 입력하세요: ");
		scanf＿ｓ("%d", &student[i].student_number);

		printf("성적을 입력하세요: ");
		scanf＿ｓ("%d", &student[i].score);
	}
	
	//입력된 학생 정보 출력
	for (int i = 0; i < num_student; i++) {
		printf("이름: %s, 학번: %d, 성적: %d\n", student[i].name, student[i].student_number, student[i].score);
	}

	return 0;

}