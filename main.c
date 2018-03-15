/*
* ==================================================
* == Lesson 5. Homework
* == Student: Andrei Solovetov
* == Date: 15-mar-2018
* "==================================================
*/

#include <stdio.h>
#include <stdlib.h>

#define T int

typedef struct Node {
    T data;
    int index;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct Queue {
    int size;
    Node *head;
    Node *tail;
} Queue;

typedef struct StackNode {
    T data;
    struct StackNode *prev;
} StackNode;

typedef struct Stack {
    int size;
    StackNode *head;
} Stack;

void push(Queue *queue, T value) {
    Node *tmp = (Node *) malloc(sizeof(Node));
    if (tmp == NULL) return;

    tmp->data = value;
    tmp->index = queue->size++;
    tmp->prev = queue->tail;
    tmp->next = NULL;

    if (queue->tail != NULL)
        queue->tail->next = tmp;
    else
        queue->head = tmp;

    queue->tail = tmp;
}

T pop(Queue *queue) {
    if (queue->size < 1) return -1;

    Node *current = queue->head;
    T result = queue->head->data;

    queue->head = queue->head->next;

    if (queue->size-- > 1)
        queue->head->prev = NULL;
    else
        queue->tail = NULL;

    free(current);
    return result;
}

void pushToStack(Stack *stack, T value) {
    StackNode *tmp = (StackNode *) malloc(sizeof(StackNode));
    if (tmp == NULL) return;

    tmp->data = value;
    tmp->prev = stack->head;

    stack->head = tmp;
    stack->size++;
}

T popFromStack(Stack *stack) {
    if (stack->size < 1) return -1;

    StackNode *current = stack->head;
    T result = stack->head->data;

    stack->head = current->prev;
    stack->size--;

    free(current);
    return result;
}

Stack decToBin(int value) {

    Stack stack;
    stack.head = NULL;
    stack.size = 0;

    while (value / 2 > 1){
        pushToStack(&stack, value % 2);
        value /= 2;
    }

    pushToStack(&stack, value % 2);
    pushToStack(&stack, value / 2);

    return stack;
}


int main(void) {

    printf("Queue test:\n");

    Queue queue;
    queue.head = NULL;
    queue.tail = NULL;
    queue.size = 0;

    push(&queue, 7);
    push(&queue, 9);
    push(&queue, 18);
    push(&queue, 4);
    push(&queue, 6);

    while (queue.size)
        printf("%d ", pop(&queue));
    printf("\n\n");

    printf("Stack test:\n");
    Stack stack;
    stack.head = NULL;
    stack.size = 0;

    pushToStack(&stack, 1);
    pushToStack(&stack, 2);
    pushToStack(&stack, 3);
    pushToStack(&stack, 4);
    pushToStack(&stack, 5);

    while (stack.size)
        printf("%d ", popFromStack(&stack));
    printf("\n\n");

    printf("Dec to bin test:\n");

    int num = 42317;
    printf("%d -> ", num);
    Stack bin = decToBin(num);

    while (bin.size)
        printf("%d", popFromStack(&bin));

    printf("\n\n");
}
