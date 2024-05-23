#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100
#define Datatype char

typedef struct student {
	char name;
	int gender;
}student;

typedef struct arrayQueue{
	int front;
	int rear;
	Datatype queue[max];
}arrayQueue;

void init(arrayQueue* p) {
	p->front = p->rear = 0;
}

int full(arrayQueue* p) {
	return (p->rear + 1) % max == p->front;
}

int empty(arrayQueue* p) {
	return p->front == p->rear;
}

int enqueue(arrayQueue* p, Datatype data) {
	if (full(p)) {
		exit(1);
	}
	else {
		p->rear = (p->rear + 1) % max;
		p->queue[p->rear] = data;
	}
}

Datatype dequeue(arrayQueue* p, Datatype data) {
	if (empty(p)) {
		exit(1);
	}
	else {
		p->front = (p->front + 1) % max;
		return p->queue[p->front];
	}
}

void delete(arrayQueue* M, arrayQueue* F) {

	M->front = (M->front + 1) % max;
	F->front = (F->front + 1) % max;
	printf("Ŀ���� ź���߽��ϴ�! %s�� %s\n\n", M->queue[M->front], F->queue[F->front]);
}

void meeting(arrayQueue* M, arrayQueue* F) {
	if (empty(M) == 0 && empty(F) == 0) delete(M, F);
	else printf("���� ����ڰ� �����ϴ�. ��ٷ� �ֽʽÿ�.\n\n");
}

int main(void) {
	arrayQueue M, F;
	char name[100];
	char gen = ' ';
	init(&M);
	init(&F);
	int a;
	print("���� �ּ� ���α׷��Դϴ�.\n\n");
	while (1) {
		print("���̸� : ");
		scanf("%s", &name);
		if (gen == 'M') {
			a = enqueue(&M, name);
			if (name[0] == '0')return 0;

			printf("������ �Է��ϼ���(F or M)");
			scanf("%s", &gen);
			if (gen == 'm') {
				a = add(&M, name);
				if (a == 0)meeting(&M, &F);
				else printf("�ο��� �ʰ��Ǿ����ϴ�.\n\n");
			}
			else printf("�ùٸ� ������ �Է��� �ּ���.\n\n");
		}
		return 0;
	}
}