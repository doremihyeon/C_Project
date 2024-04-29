#include <stdio.h>
#include <stdlib.h> // malloc �Լ��� ����ϱ� ���� ��� ����
#include <string.h>
#include <time.h>

typedef struct Node { // ��� ����
    char* name;
    struct Node* next; // ������
    struct Node* prev; // ������
} Node;

typedef struct List { // head�� tail ����
    Node* head; // ù ��° �� ����Ŵ
    Node* tail; // ������ �� ����Ŵ
    Node* first; // head, tail�� free�Ǹ� ù ��° ��ġ ����Ŵ
    int count;
} List;

// ���ο� ��� ���� �Լ�
Node* Newnode(char* names) {
    // ����ü 1�� ���� �Ҵ�
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) { // �޸� �Ҵ� ���� �� ���� ó��
        printf("�޸� �Ҵ� ����\n");
        exit(EXIT_FAILURE);
    }
    // �̸� ���̸�ŭ ���� �Ҵ�
    new_node->name = (char*)malloc(strlen(names) + 1);
    // �̸� ����
    strcpy(new_node->name, names);
    // ��ũ �ʱ�ȭ
    new_node->next = new_node->prev = NULL;
    return new_node;
}

// ��� �ʱ� ���� �Լ�
void Setnode(List* list) {
    // head�� tail ����
    list->head = Newnode(" ");
    list->tail = Newnode(" ");
    // head�� ������ tail, head�� ������ tail
    list->head->next = list->tail;
    list->head->prev = list->tail;
    // tail�� ������ head, tail�� ������ head
    list->tail->next = list->head;
    list->tail->prev = list->head;
    // ��� �� �ʱ�ȭ
    list->count = 0;
}

// ������ �߰� �Լ�
void Adddata(List* list, char* names) {
    Node* add = Newnode(names);
    if (list->count == 0) { // ù��° Add
        // add�� ������ head�� next, add�� ������ head
        add->next = list->head->next;
        add->prev = list->head;
        // head�� ������ add, tail�� ������ add
        list->head->next = add;
        list->tail->prev = add;
        // ù ��° �� ���� (Freelist ����� ����)
        list->first = add;
    }
    else { // 2�� �̻� Add
        // add�� ������ head�� next, head�� ����Ű�� ���� ������ add
        add->next = list->head->next;
        list->head->next->prev = add;
        // add�� ������ head, head�� ������ add
        add->prev = list->head;
        list->head->next = add;
        // ù ��° �� ���� (Freelist ����� ����)
        list->first = add;
    }
    // ��� �� ����
    list->count++;
}

// head�� tail �� free�ϱ�
void Freelist(List* list) {
    // head�� tail ������ ����
    Node* heads = list->head;
    Node* tails = list->tail;
    // head�� ������ ������ tail�� ����, tail�� ������ ������ head�� ����
    list->head->next->prev = list->tail->prev;
    list->tail->prev->next = list->head->next;
    // �޸� ����
    free(heads);
    free(tails);
}

// �������� ����� �̴� �Լ�
void Randperson(List* list) {
    Node* person = list->first;
    // ������ ���� ��� ��(count)�� ������ ����
    int n = rand() % list->count + 1;
    // n��° ��� ����
    for (int i = 0; i < n; i++)
    {
        person = person->next;
    }
    // ���� ����� ù ��°�� ����
    list->first = person;
    // ���� ��� ���
    printf("���� ��� : %s\n", person->name);
}

// ��� ��� ��� �Լ�
void Viewall(List* list) {
    Node* check = list->first; // ù ��° ���
    int i = 0;
    printf("�л��� �̸� : ");
    while (i != list->count) // �л� ����ŭ ���� ����
    {
        printf("%s ", check->name); // �̸� ���
        check = check->next; // ���� ���
        i++;
    }
    printf("\n");
}

// n��° ��� ���� �Լ�
void Remove(List* list) {
    Node* person = list->first; // ù��° ��
    Node* explain = person; // ���� ��� ��¿�
    Node* frees = person; // free �뵵
    int n, j, i = 0, t = 0;
    printf("n�� �Է��ϼ���.(n��° ��� ����) : ");
    scanf("%d", &n);
    while (list->count != 1) { // ���� �ʿ���
        if (i == 0) { // �ð����
            for (j = 0; j < n; j++)
            {
                person = person->next; // ������ �� n����ŭ ������
            }
            if (person == list->first) // first���� ���� �� ��
            {
                list->first = person->next; // first�� next�� ����
                list->first->prev = person->prev; // first�� prev�� ����
                explain = list->first; // ��¿뵵 first�� ����
            }
            list->count--; // ��� �� ����
            printf("���� �� ��� : %s\n", person->name);
            person->next->prev = person->prev; // ���Ŵ���� �� �� ����
            person->prev->next = person->next;
            frees = person; // ���� ����� frees�� ����
            person = person->next; // ���Ŵ���� ��������� ����
            free(frees); // ���� ����� free
            i = -1;
        }
        else { // �ݽð����
            for (j = 0; j < n; j++)
            {
                person = person->prev; // �ݽð� �������� n�� �ڷ�
            }
            if (person == list->first) // first���� ���ŵ� ��
            {
                list->first = person->next; // first�� next����
                list->first->prev = person->prev; // first�� prev�� ����
                explain = list->first; // ��¿뵵 ����
            }
            list->count--; // ��� �� ����
            printf("���� �� ��� : %s\n", person->name);
            person->next->prev = person->prev; // ���Ŵ���� �� �� ����
            person->prev->next = person->next;
            frees = person; // ���� ����� frees�� ����
            person = person->prev; // ���Ŵ���� ��������� ����
            free(frees); // ���� ����� free
            i = 0;
        }
        printf("���� ��� : ");
        while (t != list->count) { // ���� ��� �̸� ���
            printf("%s ", explain->name);
            explain = explain->next;
            t++;
        }
        t = 0;
        printf("\n");
    }
    printf("���� ���� �л� : %s", person->name);
    free(person);
}

// ���� �Լ�
int main() {
    char names[10];
    List list;
    int n;
    srand((int)time(NULL)); // �����Լ� �ʱ�ȭ
    Setnode(&list); // �ʱ� ����
    printf("�л��� �̸��� �Է��ϼ���.(���Ḧ ���ϸ� 0�� �Է��ϼ���.)\n");
    while (1) {
        scanf("%s", names);
        if (names[0] == '0') break; // 0 �Է��ϸ� ����
        Adddata(&list, names); // ��� ���� �� �̸� �Է�
    }
    Freelist(&list); // head, tail �� free
    Randperson(&list); // ������ ��� �̱�
    Viewall(&list); // ��� �� ����
    Remove(&list); // ��� ����
    return 0;
}
