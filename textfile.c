#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>  // 소문자 변환을 위해 추가

#define MAX 100  // 줄 번호를 저장할 최대 크기
#define DATATYPE_SIZE 100  // 단어 길이의 최대 크기

// 이진 탐색 트리 노드 구조체 정의
typedef struct Tnode {
    char data[DATATYPE_SIZE];  // 단어
    int count;  // 단어 등장 횟수
    int lines[MAX];  // 단어가 등장한 줄 번호들
    int lineCount;  // 줄 번호의 개수
    struct Tnode* left;  // 왼쪽 자식 노드
    struct Tnode* right;  // 오른쪽 자식 노드
} Tnode;

// 소문자로 변환하는 함수
void toLowerCase(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

// 새 노드를 생성하는 함수
Tnode* createNode(char* word, int line) {
    Tnode* newNode = (Tnode*)malloc(sizeof(Tnode));  // 새 노드를 위한 메모리 할당
    if (!newNode) {
        perror("메모리 할당 실패");
        exit(EXIT_FAILURE);
    }
    strcpy(newNode->data, word);  // 단어 복사
    newNode->count = 1;  // 단어 등장 횟수를 1로 초기화
    newNode->lines[0] = line;  // 첫 번째 줄 번호 저장
    newNode->lineCount = 1;  // 줄 번호 개수를 1로 초기화
    newNode->left = newNode->right = NULL;  // 자식 노드를 NULL로 초기화
    return newNode;  // 새 노드 반환
}

// 이진 탐색 트리에 단어를 추가하는 함수
void add(Tnode** root, char* word, int line) {
    toLowerCase(word);  // 단어를 소문자로 변환

    if (*root == NULL) {  // 트리가 비어 있는 경우
        *root = createNode(word, line);  // 새 노드를 루트로 설정
        return;
    }

    Tnode* search = *root;  // 탐색을 위한 포인터
    Tnode* parent = NULL;  // 부모 노드를 가리킬 포인터

    // 적절한 위치를 찾기 위한 탐색
    while (search) {
        int cmp = strcmp(word, search->data);  // 단어 비교
        if (cmp == 0) {  // 단어가 이미 존재하는 경우
            search->count++;  // 등장 횟수 증가
            if (search->lineCount < MAX) {  // 줄 번호를 저장할 공간이 남아 있는 경우
                search->lines[search->lineCount++] = line;  // 줄 번호 추가
            }
            return;
        }
        else if (cmp < 0) {  // 단어가 작다면 왼쪽으로 이동
            parent = search;
            search = search->left;
        }
        else {  // 단어가 크다면 오른쪽으로 이동
            parent = search;
            search = search->right;
        }
    }

    // 적절한 위치에 새 노드 추가
    if (strcmp(word, parent->data) < 0) {
        parent->left = createNode(word, line);
    }
    else {
        parent->right = createNode(word, line);
    }
}

// 중위 순회를 통해 트리를 출력하는 함수
void inorder(Tnode* root) {
    if (root) {
        inorder(root->left);  // 왼쪽 서브트리 순회
        // 현재 노드의 데이터 출력
        printf("%s\t%d\t", root->data, root->count);
        for (int i = 0; i < root->lineCount; i++) {  // 줄 번호 출력
            printf("%d", root->lines[i]);
            if (i < root->lineCount - 1) {
                printf(",");  // 줄 번호 사이에 쉼표 추가
            }
        }
        printf("\n");
        inorder(root->right);  // 오른쪽 서브트리 순회
    }
}

// 트리의 모든 단어 수와 단어 등장 횟수를 합산하는 함수
void sumTree(Tnode* root, int* totalCount) {
    if (root) {
        sumTree(root->left, totalCount);  // 왼쪽 서브트리 합산
        (*totalCount) += root->count;  // 단어 등장 횟수 증가
        sumTree(root->right,  totalCount);  // 오른쪽 서브트리 합산
    }
}

// 파일을 처리하여 트리에 단어를 추가하는 함수
void processFile(const char* filePath, Tnode** root) {
    FILE* file = fopen(filePath, "r");  // 파일 열기
    if (!file) {  // 파일 열기 실패 시
        perror("파일 열기 실패");
        return;
    }
    char line[256];  // 한 줄을 저장할 버퍼
    int lineNum = 0;  // 현재 줄 번호
    while (fgets(line, sizeof(line), file)) {  // 파일에서 한 줄 읽기
        lineNum++;
        char* token = strtok(line, " \t\n\r");  // 공백, 탭, 개행으로 단어 분리
        while (token) {
            add(root, token, lineNum);  // 트리에 단어 추가
            token = strtok(NULL, " \t\n,.'?'");  // 다음 단어 추출
        }
    }
    fclose(file);  // 파일 닫기
}

// 메인 함수
int main() {
    Tnode* bst = NULL;  // 이진 탐색 트리의 루트를 NULL로 초기화
    const char* filePath = "C://data.txt";  // 여기에 텍스트 파일 경로를 입력하세요
    processFile(filePath, &bst);  // 파일 처리 및 트리에 단어 추가

    printf("단어\t횟수\t줄\n");
    inorder(bst);  // 트리의 내용을 중위 순회하여 출력
    
    int totalCount = 0;
    sumTree(bst, &totalCount);  // 트리의 단어 수와 등장 횟수 합산


    printf("계\t%d\n", totalCount);

    return 0;
}
