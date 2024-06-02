#define _CRT_SECURE_NO_WARNINGS // 안전하지 않은 표준 C 라이브러리 함수 사용을 허용
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100 // 큐의 최대 크기를 정의
#define Datatype student // 큐의 데이터 타입을 student로 정의

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
    LinkedQueue M, F; // 남성(M)과 여성(F)
    student S; // 입력받을 학생 정보
    init_queue(&M); // 남성 큐 초기화
    init_queue(&F); // 여성 큐 초기화
    printf("미팅 주선 프로그램입니다.\n\n");
    while (1) {
        printf("고객이름(0을 입력하면 종료) : ");
        scanf("%s", S.name); // 고객 이름 입력받기

        if (strcmp(S.name, "0") == 0) {
            break; // 입력받은 이름이 "0"이면 종료
        }

        // 입력 버퍼 비우기
        while (getchar() != '\n');

        printf("성별을 입력하세요(F or M): ");
        scanf("%c", &S.gen); // 고객 성별 입력받기

        // 입력 버퍼 비우기
        while (getchar() != '\n');

        if (S.gen == 'M') { // 성별이 남성일 경우
            if (empty(&F)) { // 여성 큐가 비어 있으면
                enqueue(&M, S); // 남성 큐에 추가
                printf("아직 대상자가 없습니다. 기다려주십시요.\n\n");
            }
            else { // 여성 큐가 비어 있지 않으면
                Datatype female = dequeue(&F); // 여성 큐에서 데이터를 가져옴
                printf("커플이 탄생했습니다! %s과 %s\n\n", female.name, S.name); // 커플 탄생 메시지 출력
            }
        }
        else if (S.gen == 'F') { // 성별이 여성일 경우
            if (empty(&M)) { // 남성 큐가 비어 있으면
                enqueue(&F, S); // 여성 큐에 추가
                printf("아직 대상자가 없습니다. 기다려주십시요.\n\n");
            }
            else { // 남성 큐가 비어 있지 않으면
                Datatype male = dequeue(&M); // 남성 큐에서 데이터를 가져옴
                printf("커플이 탄생했습니다! %s과 %s\n\n", male.name, S.name); // 커플 탄생 메시지 출력
            }
        }
        else {
            printf("잘못된 성별 입력입니다. 다시 시도해 주세요.\n"); // 잘못된 성별 입력 시 메시지 출력
        }
    }
    return 0; // 프로그램 종료
}