#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//스택 구조체 생성
typedef struct Stack {
    int top;
    char word[50];
} Stack;
//스택 초기화
void init(Stack* s) {
    s->top = -1;
}
//스택 push함수
void push(Stack* s, char data) {
    if (s->top == 49) {//스택 가득 찾는지 확인
        exit(1);//종료
    }
    else {
        s->word[++s->top] = data;//top증가, 데이터를 스택에 넣음
    }
}
//스택 pop함수
char pop(Stack* s) {
    if (s->top == -1) {//스택 비었는지 확인
        exit(1);//종료
    }
    else {
        return s->word[s->top--];//스택에서 데이터 꺼내고 top -1
    }
}
//메인 함수
int main() {
    Stack s; //스택 변수 선언
    int n; //스택 초기화
    scanf("%d", &n);//괄호 갯수 입력

    for (int i = 0; i < n; i++) {
        init(&s); // 스택 초기화
        scanf("%s", s.word);//괄호 문자열 입력

        int isValid = 1; // 유효성 검사 결과 저장할 플래그
    
        //입력된 괄호 문자열 순회하며 검사
        for (int j = 0; j < strlen(s.word); j++) {
            if (s.word[j] == '(') { //'('이면 스택에 push
                push(&s, '(');
            }
            else if (s.word[j] == ')') { //')'일 경우 스택에서 pop하고 괄호 짝 검사
                if (s.top == -1 || pop(&s) != '(') { //스택이 비어있거나, 스택에서 pop한 값이'('아니면
                    isValid = 0;//플래그를 0으로 설정하고
                    break;//반복문 나옴
                }
            }
        }
        //모든 괄호 검사 후,, 스택이 비어있고 플래그가 1이면
        if (isValid && s.top == -1) {
            printf("YES\n"); //YES출력
        }
        else {
            printf("NO\n");//아니면 NO출력
        }
    }
    return 0;
}
