#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 큐의 최대 크기를 정의
#define max 100

// 큐의 데이터 타입을 student로 정의
#define Datatype student

// 학생 정보를 담는 구조체 정의
typedef struct student {
    char name[max]; // 학생 이름
    char gen;       // 학생 성별
} student;

// 큐의 노드 구조체 정의
typedef struct Qnode {
    Datatype data;      // 데이터
    struct Qnode* link; // 다음 노드를 가리키는 링크
} Qnode;

// 연결 리스트 기반 큐 구조체 정의
typedef struct LinkedQueue {
    Qnode* front; // 큐의 맨 앞을 가리키는 포인터
    Qnode* rear;  // 큐의 맨 뒤를 가리키는 포인터
} LinkedQueue;

// 큐 초기화 함수
void init_queue(LinkedQueue* LQ) {
    LQ->front = LQ->rear = NULL; // 큐의 front와 rear를 NULL로 초기화
}

// 큐가 가득 차 있는지 확인하는 함수
int full(Qnode* node) {
    return node == NULL; // 노드가 NULL이면 큐가 가득 찬 상태
}

// 큐가 비어 있는지 확인하는 함수
int empty(LinkedQueue* LQ) {
    return LQ->front == NULL; // front가 NULL이면 큐가 비어 있는 상태
}

// 큐에 데이터를 추가하는 함수
void enqueue(LinkedQueue* LQ, Datatype data) {
    Qnode* new = (Qnode*)malloc(sizeof(Qnode)); // 새 노드 생성
    if (full(new)) {
        exit(1); // 메모리 할당 실패 시 프로그램 종료
    }
    else {
        new->data = data; // 데이터 저장
        new->link = NULL; // 새 노드의 link는 NULL로 설정

        // 큐가 비어 있는 경우
        if (empty(LQ)) {
            LQ->front = new; // 새 노드를 큐의 front로 설정
        }
        else {
            LQ->rear->link = new; // 기존 rear의 link를 새 노드로 연결
        }
        LQ->rear = new; // rear를 새 노드로 설정
    }
}

// 큐에서 데이터를 제거하고 반환하는 함수
Datatype dequeue(LinkedQueue* LQ) {
    if (empty(LQ)) {
        exit(1); // 큐가 비어 있는 경우 프로그램 종료
    }
    else {
        Qnode* deleted = LQ->front; // 제거할 노드를 가리키는 포인터
        Datatype data = deleted->data; // 제거할 데이터 저장
        LQ->front = LQ->front->link; // front를 다음 노드로 이동
        if (empty(LQ)) {
            LQ->rear = NULL; // 큐가 비어 있는 경우 rear도 NULL로 설정
        }
        free(deleted); // 노드 메모리 해제
        return data; // 제거한 데이터 반환
    }
}

int main(void) {
    LinkedQueue M, F; // 남성(M)과 여성(F) 큐 생성
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
                printf("커플이 탄생했습니다! %s과 %s\n\n", male.name, S.name); // 커플 탄생
            }
        }
        return 0; // 프로그램 종료
    }