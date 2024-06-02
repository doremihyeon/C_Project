#define _CRT_SECURE_NO_WARNINGS // �������� ���� ǥ�� C ���̺귯�� �Լ� ����� ���
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100 // ť�� �ִ� ũ�⸦ ����
#define Datatype student // ť�� ������ Ÿ���� student�� ����

typedef struct student {
	char name[max];
	char gen;
}student;

typedef struct Qnode {
	Datatype data;
	struct Qnode* link;
}Qnode;

typedef struct LinkedQueue {
	Qnode* front;
	Qnode* rear;
}LinkedQueue;

void init_queue(LinkedQueue* LQ) {
	LQ->front = LQ->rear = NULL;
}

int full(Qnode* node) {
	return node == NULL;
}

int empty(LinkedQueue* LQ) {
	return LQ->front == NULL;
}

void enqueue(LinkedQueue* LQ, Datatype data) {
	Qnode* new = (Qnode*)malloc(sizeof(Qnode));
	if (full(new)) {
		exit(1);
	}
	else {
		new->data = data;
		new->link = NULL;
		if (empty(LQ)) LQ->front = new;
		else LQ->rear->link = new;
		LQ->rear = new;
	}
}

Datatype dequeue(LinkedQueue* LQ) {
    if (empty(LQ)) {
        exit(1);
    }
    else {
        Qnode* deleted = LQ->front;
        Datatype data = deleted->data;
        LQ->front = LQ->front->link;
        if (empty(LQ)) LQ->rear = NULL;
        free(deleted);
        return data;
    }
}

int main(void) {
    LinkedQueue M, F; // ����(M)�� ����(F)
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
                printf("Ŀ���� ź���߽��ϴ�! %s�� %s\n\n", male.name, S.name); // Ŀ�� ź�� �޽��� ���
            }
        }
        else {
            printf("�߸��� ���� �Է��Դϴ�. �ٽ� �õ��� �ּ���.\n"); // �߸��� ���� �Է� �� �޽��� ���
        }
    }
    return 0; // ���α׷� ����
}