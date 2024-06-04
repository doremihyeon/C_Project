#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100
#define DataType char

typedef struct word {
	int line[max];
    int ;
    DataType text;
}word;

typedef struct Tnode {
    struct Tnode *left;
    struct Tnode * right;
} Tnode; 

typedef struct Linkedroot {
    Tnode* root;
}Linkedroot;

void add(Tnode** root, char *word, int line) {
    Tnode* search = *root;
    Tnode* parent = NULL;

    while (search) {
        if (strcmp(word, search->data) == 0) {
            if(search->line[text]) ++
        }
    }
}

inorder(Tnode* root) {
    if (root) {
        inorder(root->left);
        inorder(root->right);
    }
}