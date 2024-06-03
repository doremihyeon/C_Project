#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ť�� �ִ� ũ�⸦ ����
#define max 100

// ť�� ������ Ÿ���� student�� ����
#define Datatype student

// �л� ������ ��� ����ü ����
typedef struct student {
    char name[max]; // �л� �̸�
    char gen;       // �л� ����
} student;

// ť�� ��� ����ü ����
typedef struct Qnode {
    Datatype data;      // ������
    struct Qnode* link; // ���� ��带 ����Ű�� ��ũ
} Qnode;

// ���� ����Ʈ ��� ť ����ü ����
typedef struct LinkedQueue {
    Qnode* front; // ť�� �� ���� ����Ű�� ������
    Qnode* rear;  // ť�� �� �ڸ� ����Ű�� ������
} LinkedQueue;

// ť �ʱ�ȭ �Լ�
void init_queue(LinkedQueue* LQ) {
    LQ->front = LQ->rear = NULL; // ť�� front�� rear�� NULL�� �ʱ�ȭ
}

// ť�� ���� �� �ִ��� Ȯ���ϴ� �Լ�
int full(Qnode* node) {
    return node == NULL; // ��尡 NULL�̸� ť�� ���� �� ����
}

// ť�� ��� �ִ��� Ȯ���ϴ� �Լ�
int empty(LinkedQueue* LQ) {
    return LQ->front == NULL; // front�� NULL�̸� ť�� ��� �ִ� ����
}

// ť�� �����͸� �߰��ϴ� �Լ�
void enqueue(LinkedQueue* LQ, Datatype data) {
    Qnode* new = (Qnode*)malloc(sizeof(Qnode)); // �� ��� ����
    if (full(new)) {
        exit(1); // �޸� �Ҵ� ���� �� ���α׷� ����
    }
    else {
        new->data = data; // ������ ����
        new->link = NULL; // �� ����� link�� NULL�� ����

        // ť�� ��� �ִ� ���
        if (empty(LQ)) {
            LQ->front = new; // �� ��带 ť�� front�� ����
        }
        else {
            LQ->rear->link = new; // ���� rear�� link�� �� ���� ����
        }
        LQ->rear = new; // rear�� �� ���� ����
    }
}

// ť���� �����͸� �����ϰ� ��ȯ�ϴ� �Լ�
Datatype dequeue(LinkedQueue* LQ) {
    if (empty(LQ)) {
        exit(1); // ť�� ��� �ִ� ��� ���α׷� ����
    }
    else {
        Qnode* deleted = LQ->front; // ������ ��带 ����Ű�� ������
        Datatype data = deleted->data; // ������ ������ ����
        LQ->front = LQ->front->link; // front�� ���� ���� �̵�
        if (empty(LQ)) {
            LQ->rear = NULL; // ť�� ��� �ִ� ��� rear�� NULL�� ����
        }
        free(deleted); // ��� �޸� ����
        return data; // ������ ������ ��ȯ
    }
}

int main(void) {
    LinkedQueue M, F; // ����(M)�� ����(F) ť ����
    student S; // �Է¹��� �л� ����
    init_queue(&M); // ���� ť �ʱ�ȭ
    init_queue(&F); // ���� ť �ʱ�ȭ
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
        scanf("%c", &S.gen); // �� ���� �Է¹ޱ�

        // �Է� ���� ����
        while (getchar() != '\n');

        if (S.gen == 'M') { // ������ ������ ���
            if (empty(&F)) { // ���� ť�� ��� ������
                enqueue(&M, S); // ���� ť�� �߰�
                printf("���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�.\n\n");
            }
            else { // ���� ť�� ��� ���� ������
                Datatype female = dequeue(&F); // ���� ť���� �����͸� ������
                printf("Ŀ���� ź���߽��ϴ�! %s�� %s\n\n", female.name, S.name); // Ŀ�� ź�� �޽��� ���
            }
        }
        else if (S.gen == 'F') { // ������ ������ ���
            if (empty(&M)) { // ���� ť�� ��� ������
                enqueue(&F, S); // ���� ť�� �߰�
                printf("���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�.\n\n");
            }
            else { // ���� ť�� ��� ���� ������
                Datatype male = dequeue(&M); // ���� ť���� �����͸� ������
                printf("Ŀ���� ź���߽��ϴ�! %s�� %s\n\n", male.name, S.name); // Ŀ�� ź��
            }
        }
        return 0; // ���α׷� ����
    }