#include <stdio.h>
#include <stdlib.h> // malloc 함수를 사용하기 위한 헤더 파일
#include <string.h>
#include <time.h>

typedef struct Node { // 노드 생성
    char* name;
    struct Node* next; // 다음값
    struct Node* prev; // 이전값
} Node;

typedef struct List { // head와 tail 정의
    Node* head; // 첫 번째 값 가리킴
    Node* tail; // 마지막 값 가리킴
    Node* first; // head, tail이 free되면 첫 번째 위치 가리킴
    int count;
} List;

// 새로운 노드 생성 함수
Node* Newnode(char* names) {
    // 구조체 1개 공간 할당
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) { // 메모리 할당 실패 시 오류 처리
        printf("메모리 할당 실패\n");
        exit(EXIT_FAILURE);
    }
    // 이름 길이만큼 공간 할당
    new_node->name = (char*)malloc(strlen(names) + 1);
    // 이름 저장
    strcpy(new_node->name, names);
    // 링크 초기화
    new_node->next = new_node->prev = NULL;
    return new_node;
}

// 노드 초기 설정 함수
void Setnode(List* list) {
    // head와 tail 설정
    list->head = Newnode(" ");
    list->tail = Newnode(" ");
    // head의 다음은 tail, head의 이전은 tail
    list->head->next = list->tail;
    list->head->prev = list->tail;
    // tail의 다음은 head, tail의 이전은 head
    list->tail->next = list->head;
    list->tail->prev = list->head;
    // 노드 수 초기화
    list->count = 0;
}

// 데이터 추가 함수
void Adddata(List* list, char* names) {
    Node* add = Newnode(names);
    if (list->count == 0) { // 첫번째 Add
        // add의 다음은 head의 next, add의 이전은 head
        add->next = list->head->next;
        add->prev = list->head;
        // head의 다음은 add, tail의 이전은 add
        list->head->next = add;
        list->tail->prev = add;
        // 첫 번째 값 정함 (Freelist 사용을 위함)
        list->first = add;
    }
    else { // 2번 이상 Add
        // add의 다음은 head의 next, head가 가리키던 값의 이전은 add
        add->next = list->head->next;
        list->head->next->prev = add;
        // add의 이전은 head, head의 다음은 add
        add->prev = list->head;
        list->head->next = add;
        // 첫 번째 값 정함 (Freelist 사용을 위함)
        list->first = add;
    }
    // 노드 수 증가
    list->count++;
}

// head와 tail 값 free하기
void Freelist(List* list) {
    // head와 tail 포인터 저장
    Node* heads = list->head;
    Node* tails = list->tail;
    // head의 다음의 이전은 tail의 이전, tail의 이전의 다음은 head의 다음
    list->head->next->prev = list->tail->prev;
    list->tail->prev->next = list->head->next;
    // 메모리 해제
    free(heads);
    free(tails);
}

// 무작위로 사람을 뽑는 함수
void Randperson(List* list) {
    Node* person = list->first;
    // 랜덤한 값을 사람 수(count)로 범위를 정함
    int n = rand() % list->count + 1;
    // n번째 사람 선택
    for (int i = 0; i < n; i++)
    {
        person = person->next;
    }
    // 뽑힌 사람을 첫 번째로 설정
    list->first = person;
    // 뽑힌 사람 출력
    printf("뽑힌 사람 : %s\n", person->name);
}

// 모든 사람 출력 함수
void Viewall(List* list) {
    Node* check = list->first; // 첫 번째 사람
    int i = 0;
    printf("학생들 이름 : ");
    while (i != list->count) // 학생 수만큼 돌면 정지
    {
        printf("%s ", check->name); // 이름 출력
        check = check->next; // 다음 사람
        i++;
    }
    printf("\n");
}

// n번째 사람 제거 함수
void Remove(List* list) {
    Node* person = list->first; // 첫번째 값
    Node* explain = person; // 남은 사람 출력용
    Node* frees = person; // free 용도
    int n, j, i = 0, t = 0;
    printf("n을 입력하세요.(n번째 사람 제거) : ");
    scanf("%d", &n);
    while (list->count != 1) { // 정렬 필요함
        if (i == 0) { // 시계방향
            for (j = 0; j < n; j++)
            {
                person = person->next; // 제거할 값 n번만큼 앞으로
            }
            if (person == list->first) // first값이 제거 될 때
            {
                list->first = person->next; // first값 next값 설정
                list->first->prev = person->prev; // first의 prev값 설정
                explain = list->first; // 출력용도 first값 적용
            }
            list->count--; // 사람 수 제거
            printf("제거 될 사람 : %s\n", person->name);
            person->next->prev = person->prev; // 제거대상의 앞 뒤 연결
            person->prev->next = person->next;
            frees = person; // 제거 대상을 frees에 저장
            person = person->next; // 제거대상의 다음사람이 기준
            free(frees); // 제거 대상을 free
            i = -1;
        }
        else { // 반시계방향
            for (j = 0; j < n; j++)
            {
                person = person->prev; // 반시계 방향으로 n번 뒤로
            }
            if (person == list->first) // first값이 제거될 때
            {
                list->first = person->next; // first의 next설정
                list->first->prev = person->prev; // first의 prev값 설정
                explain = list->first; // 출력용도 설정
            }
            list->count--; // 사람 수 감소
            printf("제거 될 사람 : %s\n", person->name);
            person->next->prev = person->prev; // 제거대상의 앞 뒤 연결
            person->prev->next = person->next;
            frees = person; // 제거 대상을 frees에 저장
            person = person->prev; // 제거대상의 다음사람이 기준
            free(frees); // 제거 대상을 free
            i = 0;
        }
        printf("남은 사람 : ");
        while (t != list->count) { // 남은 사람 이름 출력
            printf("%s ", explain->name);
            explain = explain->next;
            t++;
        }
        t = 0;
        printf("\n");
    }
    printf("최종 남은 학생 : %s", person->name);
    free(person);
}

// 메인 함수
int main() {
    char names[10];
    List list;
    int n;
    srand((int)time(NULL)); // 랜덤함수 초기화
    Setnode(&list); // 초기 설정
    printf("학생의 이름을 입력하세요.(종료를 원하면 0을 입력하세요.)\n");
    while (1) {
        scanf("%s", names);
        if (names[0] == '0') break; // 0 입력하면 종료
        Adddata(&list, names); // 노드 생성 및 이름 입력
    }
    Freelist(&list); // head, tail 값 free
    Randperson(&list); // 무작위 사람 뽑기
    Viewall(&list); // 모든 값 보기
    Remove(&list); // 사람 제거
    return 0;
}
