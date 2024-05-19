#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//���� ����ü ����
typedef struct Stack {
    int top;
    char word[50];
} Stack;
//���� �ʱ�ȭ
void init(Stack* s) {
    s->top = -1;
}
//���� push�Լ�
void push(Stack* s, char data) {
    if (s->top == 49) {//���� ���� ã���� Ȯ��
        exit(1);//����
    }
    else {
        s->word[++s->top] = data;//top����, �����͸� ���ÿ� ����
    }
}
//���� pop�Լ�
char pop(Stack* s) {
    if (s->top == -1) {//���� ������� Ȯ��
        exit(1);//����
    }
    else {
        return s->word[s->top--];//���ÿ��� ������ ������ top -1
    }
}
//���� �Լ�
int main() {
    Stack s; //���� ���� ����
    int n; //���� �ʱ�ȭ
    scanf("%d", &n);//��ȣ ���� �Է�

    for (int i = 0; i < n; i++) {
        init(&s); // ���� �ʱ�ȭ
        scanf("%s", s.word);//��ȣ ���ڿ� �Է�

        int isValid = 1; // ��ȿ�� �˻� ��� ������ �÷���
    
        //�Էµ� ��ȣ ���ڿ� ��ȸ�ϸ� �˻�
        for (int j = 0; j < strlen(s.word); j++) {
            if (s.word[j] == '(') { //'('�̸� ���ÿ� push
                push(&s, '(');
            }
            else if (s.word[j] == ')') { //')'�� ��� ���ÿ��� pop�ϰ� ��ȣ ¦ �˻�
                if (s.top == -1 || pop(&s) != '(') { //������ ����ְų�, ���ÿ��� pop�� ����'('�ƴϸ�
                    isValid = 0;//�÷��׸� 0���� �����ϰ�
                    break;//�ݺ��� ����
                }
            }
        }
        //��� ��ȣ �˻� ��,, ������ ����ְ� �÷��װ� 1�̸�
        if (isValid && s.top == -1) {
            printf("YES\n"); //YES���
        }
        else {
            printf("NO\n");//�ƴϸ� NO���
        }
    }
    return 0;
}
