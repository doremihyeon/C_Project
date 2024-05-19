#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> // bool 타입과 true, false 값을 사용하기 위해 추가

// 배열 스택 정의
typedef struct ArrayStack {
	int top; // 스택의 꼭대기를 나타내는 인덱스
	char in_str[100]; // 스택에 저장되는 문자열, 최대 100자
} ArrayStack;

// 회문을 검사하는 함수
int palindrome(char in_str[]) {
	ArrayStack s;
	int i;
	char ch, chs;
	int len = strlen(in_str); // 입력 문자열의 길이를 계산

	s.top = -1; // 스택 초기화
	for (i = 0; i < len; i++) { // 입력 문자열의 각 문자를 순회
		ch = in_str[i]; // 현재 문자를 ch에 저장
		// 만약 ch가 스페이스이거나 구두점이면
		if (ch > 31 && ch <= 47) continue;
		ch = tolower(ch); // ch를 소문자로 변경
		s.in_str[++s.top] = ch; // top을 증가시키고 ch를 스택에 저장
	}

	for (i = 0; i < len; i++) { // 입력 문자열의 각 문자를 다시 순회
		ch = in_str[i]; // 현재 문자를 ch에 저장
		// 만약 ch가 스페이스이거나 구두점이면
		if (ch > 31 && ch <= 47) continue;
		ch = tolower(ch); // ch를 소문자로 변경
		chs = s.in_str[s.top--]; // 스택의 최상위 문자를 chs에 저장하고 top을 감소
		if (ch != chs) return false; // 문자가 다르면 회문이 아님, false(0) 반환
	}
	return true; // 모든 문자가 일치하면 회문임, true(1) 반환
}

// 메인 함수
int main(void) {
	ArrayStack s; // 스택 변수 선언
	int a;
	scanf("%[^\n]", s.in_str); // 공백을 포함하여 문자열 입력
	a = palindrome(s.in_str); // 입력된 문자열이 회문인지 검사

	if (a == true) { // 회문인 경우
		printf("회문입니다.");
	}
	else { // 회문이 아닌 경우
		printf("회문이 아닙니다.");
	}
	return 0;
}
