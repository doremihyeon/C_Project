#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> // bool Ÿ�԰� true, false ���� ����ϱ� ���� �߰�

// �迭 ���� ����
typedef struct ArrayStack {
	int top; // ������ ����⸦ ��Ÿ���� �ε���
	char in_str[100]; // ���ÿ� ����Ǵ� ���ڿ�, �ִ� 100��
} ArrayStack;

// ȸ���� �˻��ϴ� �Լ�
int palindrome(char in_str[]) {
	ArrayStack s;
	int i;
	char ch, chs;
	int len = strlen(in_str); // �Է� ���ڿ��� ���̸� ���

	s.top = -1; // ���� �ʱ�ȭ
	for (i = 0; i < len; i++) { // �Է� ���ڿ��� �� ���ڸ� ��ȸ
		ch = in_str[i]; // ���� ���ڸ� ch�� ����
		// ���� ch�� �����̽��̰ų� �������̸�
		if (ch > 31 && ch <= 47) continue;
		ch = tolower(ch); // ch�� �ҹ��ڷ� ����
		s.in_str[++s.top] = ch; // top�� ������Ű�� ch�� ���ÿ� ����
	}

	for (i = 0; i < len; i++) { // �Է� ���ڿ��� �� ���ڸ� �ٽ� ��ȸ
		ch = in_str[i]; // ���� ���ڸ� ch�� ����
		// ���� ch�� �����̽��̰ų� �������̸�
		if (ch > 31 && ch <= 47) continue;
		ch = tolower(ch); // ch�� �ҹ��ڷ� ����
		chs = s.in_str[s.top--]; // ������ �ֻ��� ���ڸ� chs�� �����ϰ� top�� ����
		if (ch != chs) return false; // ���ڰ� �ٸ��� ȸ���� �ƴ�, false(0) ��ȯ
	}
	return true; // ��� ���ڰ� ��ġ�ϸ� ȸ����, true(1) ��ȯ
}

// ���� �Լ�
int main(void) {
	ArrayStack s; // ���� ���� ����
	int a;
	scanf("%[^\n]", s.in_str); // ������ �����Ͽ� ���ڿ� �Է�
	a = palindrome(s.in_str); // �Էµ� ���ڿ��� ȸ������ �˻�

	if (a == true) { // ȸ���� ���
		printf("ȸ���Դϴ�.");
	}
	else { // ȸ���� �ƴ� ���
		printf("ȸ���� �ƴմϴ�.");
	}
	return 0;
}
