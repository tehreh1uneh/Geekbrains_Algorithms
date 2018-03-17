/*
* ==================================================
* == Lesson 6. Homework
* == Student: Andrei Solovetov
* == Date: 17-mar-2018
* "==================================================
*/

#include <stdio.h>
#include <stdlib.h>

#define T int

typedef struct Node {
    T data;
/*
 * На занятии прописали parent, но он нигде не используется, а нужен ли вообще?
 * Логично было бы заполнять, но в примерах в методичке этого нет.
 */
//    struct Node *parent;
    struct Node *left;
    struct Node *right;
} Node;

// На занятии здесь было FILE file, странно, что компилятор не подсветил
FILE *file;

int simpleHash(const char *string, int length) {
    int result = 0;
    for (int i = 0; i < length; ++i) {
        result += string[i];
    }
    return result;
}

// Копипаст с лекции
Node *tree(int n) {
    Node *newNode;
    int nL;
    int nR;
    if (n == 0)
        newNode = NULL;
    else {
        int value;
        fscanf(file, "%d", &value);
        nL = n / 2;
        nR = n - nL - 1;
        newNode = (Node *) malloc(sizeof(Node));
        newNode->data = value;
        newNode->left = tree(nL);
        newNode->right = tree(nR);
    }
    return newNode;
}

// Копипаст с лекции
void preOrderTravers(Node *root) {
    if (root) {
        printf("%d ", root->data);
        preOrderTravers(root->left);
        preOrderTravers(root->right);
    }
}

void inOrderTravers(Node *root) {
    if (root) {
        inOrderTravers(root->left);
        printf("%d ", root->data);
        inOrderTravers(root->right);
    }
}

void postOrderTravers(Node *root) {
    if (root) {
        postOrderTravers(root->left);
        postOrderTravers(root->right);
        printf("%d ", root->data);
    }
}

Node *find(Node *root, T value) {
    if (!root)
        return NULL;

    if (root->data == value)
        return root;
    else if (value > root->data)
        return find(root->right, value);
    else if (value < root->data)
        return find(root->left, value);
}

int main(void) {
    char *strHello = "Hello";
    char *strSf = "San Francisco";

    printf("Hello: %d\n", simpleHash(strHello, 5));
    printf("San Francisco: %d\n", simpleHash(strSf, 13));
}