#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//�迭 ���� ����
typedef struct ArrayStack {
	int top; //�����
	char in_str[100]; //�迭�� ũ�� MAX_SIZE
} ArrayStack;

int palindrome(char in_str[]) {
	ArrayStack s;
	int i;
	char ch, chs;
	int len = strlen(in_str);

	s.top = -1;//�ʱⰪ -1(���� �ʱ�ȭ)
	for (i = 0; i < len; i++) {
		ch = in_str[i];
		// ���� ch�� �����̽��ų� �������̸�
		if (ch > 31 && ch < 48) continue;
		ch = tolower(ch); // ch�� �ҹ��ڷ� ����
		s.in_str[++s.top] = ch; //top�� ���� +1�ϰ�, ch���� �����Ѵ�.
	}
	for (i = 0; i < len; i++) {
		ch = in_str[i];
		// ���� ch�� �����̽��ų� �������̸�
		if (ch > 31 && ch < 48) continue;
		ch = tolower(ch); // ch�� �ҹ��ڷ� ����
		chs = s.in_str[s.top--]; // ch���� chs�� �����ϰ�, top�� -1�Ѵ�.
		if (ch != chs) return false; // ����(0)
	}
	return true; // ����(1)
}
int main(void) {
	ArrayStack s;
	int a;
	scanf_s("%[^\n]s", s.in_str);
	a = palindrome(s.in_str);
	if (a == 1) printf("ȸ���Դϴ�.");
	else printf("ȸ���� �ƴմϴ�.");
}