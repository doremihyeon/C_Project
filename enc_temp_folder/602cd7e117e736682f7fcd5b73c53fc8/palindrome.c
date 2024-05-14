#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//배열 스택 정의
typedef struct ArrayStack {
	int top; //꼭대기
	char in_str[100]; //배열의 크기 MAX_SIZE
} ArrayStack;

int palindrome(char in_str[]) {
	ArrayStack s;
	int i;
	char ch, chs;
	int len = strlen(in_str);

	s.top = -1;//초기값 -1(스택 초기화)
	for (i = 0; i < len; i++) {
		ch = in_str[i];
		// 만약 ch가 스페이스거나 구두점이면
		if (ch > 31 && ch < 48) continue;
		ch = tolower(ch); // ch를 소문자로 변경
		s.in_str[++s.top] = ch; //top을 먼저 +1하고, ch값을 저장한다.
	}
	for (i = 0; i < len; i++) {
		ch = in_str[i];
		// 만약 ch가 스페이스거나 구두점이면
		if (ch > 31 && ch < 48) continue;
		ch = tolower(ch); // ch를 소문자로 변경
		chs = s.in_str[s.top--]; // ch값을 chs에 저장하고, top을 -1한다.
		if (ch != chs) return false; // 실패(0)
	}
	return true; // 성공(1)
}
int main(void) {
	ArrayStack s;
	int a;
	scanf_s("%[^\n]s", s.in_str);
	a = palindrome(s.in_str);
	if (a == 1) printf("회문입니다.");
	else printf("회문이 아닙니다.");
}