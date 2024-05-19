#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 스택 구조체 정의
typedef struct Stack {
	int top;           // 스택의 최상위 요소의 인덱스를 저장하는 변수
	char word[100];    // 스택의 데이터 저장소, 최대 100개의 문자를 저장
} Stack;

// 스택을 초기화하는 함수
void init(Stack* s) {
	s->top = -1;     // 스택이 비어 있음을 나타내기 위해 top을 -1로 설정
}

// 스택에 데이터를 추가하는 함수
void push(Stack* s, char data) {
	if (s->top == 99) {  // 스택이 가득 찼는지 확인
		printf("포화상태입니다.");
		exit(1);  // 프로그램 종료
	}
	else {
		s->word[++s->top] = data;  // top을 증가시키고 데이터를 스택에 추가
	}
}

// 스택에서 데이터를 꺼내는 함수
char pop(Stack* s) {
	if (s->top == -1) {  // 스택이 비었는지 확인
		printf("값이 들어있지 않습니다.");
		exit(1);  // 프로그램 종료
	}
	else {
		return s->word[s->top--];  // 스택에서 데이터를 꺼내고 top을 감소
	}
}

// 입력된 괄호 문자열이 올바른지 검사하는 함수
int check(Stack* s) {
	int answer = 0;   // 올바른 괄호 쌍의 개수를 저장
	char ch;          // 현재 검사 중인 문자를 저장
	int len = strlen(s->word);  // 입력 문자열의 길이를 저장

	for (int i = 0; i <= len; i++) {  // 문자열의 각 문자를 순회
		ch = s->word[i];  // 현재 문자를 저장

		switch (ch) {  // 문자의 종류에 따라 처리
		case '(':  // 열린 괄호인 경우 스택에 추가
			push(s, ch);
			break;

		case '{':
			push(s, ch);
			break;

		case '[':
			push(s, ch);
			break;

		case ')':  // 닫힌 괄호인 경우 스택에서 꺼내서 검사
			if (ch - 1 == pop(s)) {  // 올바른 쌍인지 확인
				answer++;  // 올바른 경우 개수를 증가
				continue;
			}
			else {
				return -1;  // 올바르지 않은 경우 -1 반환
			}

		case '}':
			if (ch - 2 == pop(s)) {
				answer++;
				continue;
			}
			else {
				return -1;
			}

		case ']':
			if (ch - 2 == pop(s)) {
				answer++;
				continue;
			}
			else {
				return -1;
			}
		}
	}

	if (s->top != -1) return -1;  // 스택이 비어 있지 않으면 오류
	if (answer > 0) return 0;  // 올바른 괄호 쌍이 존재하면 0 반환
	else return -1;  // 올바른 괄호 쌍이 없으면 -1 반환
}

// 메인 함수
int main() {
	Stack s;  // 스택 변수 선언
	init(&s);  // 스택 초기화
	printf("괄호를 입력하세요 :");
	scanf("%[^\n]s", s.word);  // 공백을 포함하여 문자열 입력
	int a = check(&s);  // 입력된 문자열의 괄호 검사

	if (a == -1) {  // 올바르지 않은 경우
		printf("올바르지 않습니다.");
	}
	else {  // 올바른 경우
		printf("올바릅니다.");
	}
	return 0;
}
