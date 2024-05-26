#define _CRT_SECURE_NO_WARNINGS // �������� ���� ǥ�� C ���̺귯�� �Լ� ����� ���
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100 // ť�� �ִ� ũ�⸦ ����
#define Datatype student // ť�� ������ Ÿ���� student�� ����

// �л� ������ ������ ����ü ����
typedef struct student {
    char name[max]; // �л� �̸�
    char gender; // �л� ����
} student;

// ��ȯ ť�� ���� ����ü ����
typedef struct arrayQueue {
    int front; // ť�� ���� �ε���
    int rear; // ť�� ���� �ε���
    Datatype queue[max]; // ť �迭
} arrayQueue;

// ť �ʱ�ȭ �Լ�
void init(arrayQueue* p) {
    p->front = p->rear = 0; // ť�� �հ� �� �ε����� 0���� �ʱ�ȭ
}

// ť�� ���� á���� Ȯ���ϴ� �Լ�
int full(arrayQueue* p) {
    return (p->rear + 1) % max == p->front; // rear ���� ��ġ�� front���� Ȯ��
}

// ť�� ������� Ȯ���ϴ� �Լ�
int empty(arrayQueue* p) {
    return p->front == p->rear; // front�� rear�� ������ Ȯ��
}

// ť�� �����͸� �߰��ϴ� �Լ�
int enqueue(arrayQueue* p, Datatype data) {
    if (full(p)) {
        exit(1); // ť�� ���� �� ��� ���α׷� ����
    }
    else {
        p->rear = (p->rear + 1) % max; // rear �ε����� ��ȯ������ ����
        p->queue[p->rear] = data; // ť�� ������ �߰�
    }
    return 0; // ���������� �߰��� ��� 0 ��ȯ
}

// ť���� �����͸� �����ϴ� �Լ�
Datatype dequeue(arrayQueue* p) {
    if (empty(p)) {
        exit(1); // ť�� ��� �ִ� ��� ���α׷� ����
    }
    else {
        p->front = (p->front + 1) % max; // front �ε����� ��ȯ������ ����
        return p->queue[p->front]; // ť���� ������ ���� �� ��ȯ
    }
}

int main(void) {
    arrayQueue M, F; // ����(M)�� ����(F) ť ����
    student S; // �Է¹��� �л� ����
    init(&M); // ���� ť �ʱ�ȭ
    init(&F); // ���� ť �ʱ�ȭ
    printf("���� �ּ� ���α׷��Դϴ�.\n\n");
    while (1) {
        printf("���̸�(0�� �Է��ϸ� ����) : ");
        scanf("%s", S.name); // �� �̸� �Է¹ޱ�

        if (strcmp(S.name, "0") == 0) {
            break; // �Է¹��� �̸��� "0"�̸� ����
        }

        // �Է� ���� ����
        while (getchar() != '\n');

        printf("������ �Է��ϼ���(F or M): ");
        scanf("%c", &S.gender); // �� ���� �Է¹ޱ�

        // �Է� ���� ����
        while (getchar() != '\n');

        if (S.gender == 'M') { // ������ ������ ���
            if (empty(&F)) { // ���� ť�� ��� ������
                enqueue(&M, S); // ���� ť�� �߰�
                printf("���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�.\n\n");
            }
            else { // ���� ť�� ��� ���� ������
                Datatype female = dequeue(&F); // ���� ť���� �����͸� ������
                printf("Ŀ���� ź���߽��ϴ�! %s�� %s\n\n", female.name, S.name); // Ŀ�� ź�� �޽��� ���
            }
        }
        else if (S.gender == 'F') { // ������ ������ ���
            if (empty(&M)) { // ���� ť�� ��� ������
                enqueue(&F, S); // ���� ť�� �߰�
                printf("���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�.\n\n");
            }
            else { // ���� ť�� ��� ���� ������
                Datatype male = dequeue(&M); // ���� ť���� �����͸� ������
                printf("Ŀ���� ź���߽��ϴ�! %s�� %s\n\n", male.name, S.name); // Ŀ�� ź�� �޽��� ���
            }
        }
        else {
            printf("�߸��� ���� �Է��Դϴ�. �ٽ� �õ��� �ּ���.\n"); // �߸��� ���� �Է� �� �޽��� ���
        }
    }
    return 0; // ���α׷� ����
}