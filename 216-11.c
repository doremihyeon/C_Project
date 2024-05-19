#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ���� ����ü ����
typedef struct Stack {
	int top;           // ������ �ֻ��� ����� �ε����� �����ϴ� ����
	char word[100];    // ������ ������ �����, �ִ� 100���� ���ڸ� ����
} Stack;

// ������ �ʱ�ȭ�ϴ� �Լ�
void init(Stack* s) {
	s->top = -1;     // ������ ��� ������ ��Ÿ���� ���� top�� -1�� ����
}

// ���ÿ� �����͸� �߰��ϴ� �Լ�
void push(Stack* s, char data) {
	if (s->top == 99) {  // ������ ���� á���� Ȯ��
		printf("��ȭ�����Դϴ�.");
		exit(1);  // ���α׷� ����
	}
	else {
		s->word[++s->top] = data;  // top�� ������Ű�� �����͸� ���ÿ� �߰�
	}
}

// ���ÿ��� �����͸� ������ �Լ�
char pop(Stack* s) {
	if (s->top == -1) {  // ������ ������� Ȯ��
		printf("���� ������� �ʽ��ϴ�.");
		exit(1);  // ���α׷� ����
	}
	else {
		return s->word[s->top--];  // ���ÿ��� �����͸� ������ top�� ����
	}
}

// �Էµ� ��ȣ ���ڿ��� �ùٸ��� �˻��ϴ� �Լ�
int check(Stack* s) {
	int answer = 0;   // �ùٸ� ��ȣ ���� ������ ����
	char ch;          // ���� �˻� ���� ���ڸ� ����
	int len = strlen(s->word);  // �Է� ���ڿ��� ���̸� ����

	for (int i = 0; i <= len; i++) {  // ���ڿ��� �� ���ڸ� ��ȸ
		ch = s->word[i];  // ���� ���ڸ� ����

		switch (ch) {  // ������ ������ ���� ó��
		case '(':  // ���� ��ȣ�� ��� ���ÿ� �߰�
			push(s, ch);
			break;

		case '{':
			push(s, ch);
			break;

		case '[':
			push(s, ch);
			break;

		case ')':  // ���� ��ȣ�� ��� ���ÿ��� ������ �˻�
			if (ch - 1 == pop(s)) {  // �ùٸ� ������ Ȯ��
				answer++;  // �ùٸ� ��� ������ ����
				continue;
			}
			else {
				return -1;  // �ùٸ��� ���� ��� -1 ��ȯ
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

	if (s->top != -1) return -1;  // ������ ��� ���� ������ ����
	if (answer > 0) return 0;  // �ùٸ� ��ȣ ���� �����ϸ� 0 ��ȯ
	else return -1;  // �ùٸ� ��ȣ ���� ������ -1 ��ȯ
}

// ���� �Լ�
int main() {
	Stack s;  // ���� ���� ����
	init(&s);  // ���� �ʱ�ȭ
	printf("��ȣ�� �Է��ϼ��� :");
	scanf("%[^\n]s", s.word);  // ������ �����Ͽ� ���ڿ� �Է�
	int a = check(&s);  // �Էµ� ���ڿ��� ��ȣ �˻�

	if (a == -1) {  // �ùٸ��� ���� ���
		printf("�ùٸ��� �ʽ��ϴ�.");
	}
	else {  // �ùٸ� ���
		printf("�ùٸ��ϴ�.");
	}
	return 0;
}
