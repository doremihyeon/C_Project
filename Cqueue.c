#define _CRT_SECURE_NO_WARNINGS // 안전하지 않은 표준 C 라이브러리 함수 사용을 허용
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100 // 큐의 최대 크기를 정의
#define Datatype student // 큐의 데이터 타입을 student로 정의

// 학생 정보를 저장할 구조체 정의
typedef struct student {
    char name[max]; // 학생 이름
    char gender; // 학생 성별
} student;

// 순환 큐를 위한 구조체 정의
typedef struct arrayQueue {
    int front; // 큐의 앞쪽 인덱스
    int rear; // 큐의 뒤쪽 인덱스
    Datatype queue[max]; // 큐 배열
} arrayQueue;

// 큐 초기화 함수
void init(arrayQueue* p) {
    p->front = p->rear = 0; // 큐의 앞과 뒤 인덱스를 0으로 초기화
}

// 큐가 가득 찼는지 확인하는 함수
int full(arrayQueue* p) {
    return (p->rear + 1) % max == p->front; // rear 다음 위치가 front인지 확인
}

// 큐가 비었는지 확인하는 함수
int empty(arrayQueue* p) {
    return p->front == p->rear; // front와 rear가 같은지 확인
}

// 큐에 데이터를 추가하는 함수
int enqueue(arrayQueue* p, Datatype data) {
    if (full(p)) {
        exit(1); // 큐가 가득 찬 경우 프로그램 종료
    }
    else {
        p->rear = (p->rear + 1) % max; // rear 인덱스를 순환적으로 증가
        p->queue[p->rear] = data; // 큐에 데이터 추가
    }
    return 0; // 성공적으로 추가된 경우 0 반환
}

// 큐에서 데이터를 제거하는 함수
Datatype dequeue(arrayQueue* p) {
    if (empty(p)) {
        exit(1); // 큐가 비어 있는 경우 프로그램 종료
    }
    else {
        p->front = (p->front + 1) % max; // front 인덱스를 순환적으로 증가
        return p->queue[p->front]; // 큐에서 데이터 제거 후 반환
    }
}

int main(void) {
    arrayQueue M, F; // 남성(M)과 여성(F) 큐 생성
    student S; // 입력받을 학생 정보
    init(&M); // 남성 큐 초기화
    init(&F); // 여성 큐 초기화
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
        scanf("%c", &S.gender); // 고객 성별 입력받기

        // 입력 버퍼 비우기
        while (getchar() != '\n');

        if (S.gender == 'M') { // 성별이 남성일 경우
            if (empty(&F)) { // 여성 큐가 비어 있으면
                enqueue(&M, S); // 남성 큐에 추가
                printf("아직 대상자가 없습니다. 기다려주십시요.\n\n");
            }
            else { // 여성 큐가 비어 있지 않으면
                Datatype female = dequeue(&F); // 여성 큐에서 데이터를 가져옴
                printf("커플이 탄생했습니다! %s과 %s\n\n", female.name, S.name); // 커플 탄생 메시지 출력
            }
        }
        else if (S.gender == 'F') { // 성별이 여성일 경우
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