#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>  // �ҹ��� ��ȯ�� ���� �߰�

#define MAX 100  // �� ��ȣ�� ������ �ִ� ũ��
#define DATATYPE_SIZE 100  // �ܾ� ������ �ִ� ũ��

// ���� Ž�� Ʈ�� ��� ����ü ����
typedef struct Tnode {
    char data[DATATYPE_SIZE];  // �ܾ�
    int count;  // �ܾ� ���� Ƚ��
    int lines[MAX];  // �ܾ ������ �� ��ȣ��
    int lineCount;  // �� ��ȣ�� ����
    struct Tnode* left;  // ���� �ڽ� ���
    struct Tnode* right;  // ������ �ڽ� ���
} Tnode;

// �ҹ��ڷ� ��ȯ�ϴ� �Լ�
void toLowerCase(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

// �� ��带 �����ϴ� �Լ�
Tnode* createNode(char* word, int line) {
    Tnode* newNode = (Tnode*)malloc(sizeof(Tnode));  // �� ��带 ���� �޸� �Ҵ�
    if (!newNode) {
        perror("�޸� �Ҵ� ����");
        exit(EXIT_FAILURE);
    }
    strcpy(newNode->data, word);  // �ܾ� ����
    newNode->count = 1;  // �ܾ� ���� Ƚ���� 1�� �ʱ�ȭ
    newNode->lines[0] = line;  // ù ��° �� ��ȣ ����
    newNode->lineCount = 1;  // �� ��ȣ ������ 1�� �ʱ�ȭ
    newNode->left = newNode->right = NULL;  // �ڽ� ��带 NULL�� �ʱ�ȭ
    return newNode;  // �� ��� ��ȯ
}

// ���� Ž�� Ʈ���� �ܾ �߰��ϴ� �Լ�
void add(Tnode** root, char* word, int line) {
    toLowerCase(word);  // �ܾ �ҹ��ڷ� ��ȯ

    if (*root == NULL) {  // Ʈ���� ��� �ִ� ���
        *root = createNode(word, line);  // �� ��带 ��Ʈ�� ����
        return;
    }

    Tnode* search = *root;  // Ž���� ���� ������
    Tnode* parent = NULL;  // �θ� ��带 ����ų ������

    // ������ ��ġ�� ã�� ���� Ž��
    while (search) {
        int cmp = strcmp(word, search->data);  // �ܾ� ��
        if (cmp == 0) {  // �ܾ �̹� �����ϴ� ���
            search->count++;  // ���� Ƚ�� ����
            if (search->lineCount < MAX) {  // �� ��ȣ�� ������ ������ ���� �ִ� ���
                search->lines[search->lineCount++] = line;  // �� ��ȣ �߰�
            }
            return;
        }
        else if (cmp < 0) {  // �ܾ �۴ٸ� �������� �̵�
            parent = search;
            search = search->left;
        }
        else {  // �ܾ ũ�ٸ� ���������� �̵�
            parent = search;
            search = search->right;
        }
    }

    // ������ ��ġ�� �� ��� �߰�
    if (strcmp(word, parent->data) < 0) {
        parent->left = createNode(word, line);
    }
    else {
        parent->right = createNode(word, line);
    }
}

// ���� ��ȸ�� ���� Ʈ���� ����ϴ� �Լ�
void inorder(Tnode* root) {
    if (root) {
        inorder(root->left);  // ���� ����Ʈ�� ��ȸ
        // ���� ����� ������ ���
        printf("%s\t%d\t", root->data, root->count);
        for (int i = 0; i < root->lineCount; i++) {  // �� ��ȣ ���
            printf("%d", root->lines[i]);
            if (i < root->lineCount - 1) {
                printf(",");  // �� ��ȣ ���̿� ��ǥ �߰�
            }
        }
        printf("\n");
        inorder(root->right);  // ������ ����Ʈ�� ��ȸ
    }
}

// Ʈ���� ��� �ܾ� ���� �ܾ� ���� Ƚ���� �ջ��ϴ� �Լ�
void sumTree(Tnode* root, int* totalCount) {
    if (root) {
        sumTree(root->left, totalCount);  // ���� ����Ʈ�� �ջ�
        (*totalCount) += root->count;  // �ܾ� ���� Ƚ�� ����
        sumTree(root->right,  totalCount);  // ������ ����Ʈ�� �ջ�
    }
}

// ������ ó���Ͽ� Ʈ���� �ܾ �߰��ϴ� �Լ�
void processFile(const char* filePath, Tnode** root) {
    FILE* file = fopen(filePath, "r");  // ���� ����
    if (!file) {  // ���� ���� ���� ��
        perror("���� ���� ����");
        return;
    }
    char line[256];  // �� ���� ������ ����
    int lineNum = 0;  // ���� �� ��ȣ
    while (fgets(line, sizeof(line), file)) {  // ���Ͽ��� �� �� �б�
        lineNum++;
        char* token = strtok(line, " \t\n\r");  // ����, ��, �������� �ܾ� �и�
        while (token) {
            add(root, token, lineNum);  // Ʈ���� �ܾ� �߰�
            token = strtok(NULL, " \t\n,.'?'");  // ���� �ܾ� ����
        }
    }
    fclose(file);  // ���� �ݱ�
}

// ���� �Լ�
int main() {
    Tnode* bst = NULL;  // ���� Ž�� Ʈ���� ��Ʈ�� NULL�� �ʱ�ȭ
    const char* filePath = "C://data.txt";  // ���⿡ �ؽ�Ʈ ���� ��θ� �Է��ϼ���
    processFile(filePath, &bst);  // ���� ó�� �� Ʈ���� �ܾ� �߰�

    printf("�ܾ�\tȽ��\t��\n");
    inorder(bst);  // Ʈ���� ������ ���� ��ȸ�Ͽ� ���
    
    int totalCount = 0;
    sumTree(bst, &totalCount);  // Ʈ���� �ܾ� ���� ���� Ƚ�� �ջ�


    printf("��\t%d\n", totalCount);

    return 0;
}
