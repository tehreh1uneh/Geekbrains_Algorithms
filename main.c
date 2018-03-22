/*
* ==================================================
* == Lesson 6. Homework
* == Student: Andrei Solovetov
* == Date: 17-mar-2018
* "==================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define T int

typedef struct Stack {
    int size;
    struct GraphNode *head;
} Stack;

typedef struct GraphNode {
    T data;
    int index;
    bool used;
    struct Stack *children;

    struct GraphNode *next;
    struct GraphNode *prev;
} GraphNode;

typedef struct Queue {
    GraphNode *head;
    GraphNode *tail;
    int size;
} Queue;

void pushQ(Queue *q, GraphNode *value) {
    GraphNode *tmp = (GraphNode *) malloc(sizeof(GraphNode));
    if (tmp == NULL) return;

    tmp->data = value->data;
    tmp->index = q->size++;
    tmp->prev = q->tail;
    tmp->next = NULL;

    if (q->tail != NULL)
        q->tail->next = tmp;
    else
        q->head = tmp;

    q->tail = tmp;
}

GraphNode popQ(Queue *q) {
    if (q->size < 1) return NULL;

    GraphNode *current = q->head;
    GraphNode *result = q->head;

    q->head = q->head->next;

    if (q->size-- > 1)
        q->head->prev = NULL;
    else
        q->tail = NULL;

    free(current);
    return *result;
}

void pushS(Stack *stack, T value) {
    GraphNode *tmp = (GraphNode *) malloc(sizeof(GraphNode));
    if (tmp == NULL) return;

    tmp->data = value;
    tmp->prev = stack->head;

    stack->head = tmp;
    stack->size++;
}

GraphNode popS(Stack *stack) {
    if (stack->size < 1) return NULL;

    GraphNode *current = stack->head;

    stack->head = current->prev;
    stack->size--;

    free(current);
    return *current;
}

void depthTravers(GraphNode *node) {
    /*
     * Помечаем как пройденный
     */
    node->used = true;
    /*
     * Для каджого дочернего связанного узла вызываем рекурсивно
     * и убираем дочерний узел из стека дочерних
     */
    while (node->children){
        GraphNode child = popS(node->children);
        depthTravers(&child);
    }
}

void widthTravers(GraphNode *start, Queue *q) {
    /*
     * Добавляем начальный узел в очередь и помечаем его как использованный
     */
    pushQ(q, start);
    start->used = true;
    /*
     * Пока в очереди есть узлы выполняем обход
     */
    while (q->size) {
        /*
         * Достаем узел из очереди
         */
        GraphNode current = popQ(q);
        /*
         * Каждый дочерний элемент полученного узла достаём из
         * списка дочерних элементов узла и если он не был ранее отправлен в очередь -
         * кладем его в очередь для дальнейшей обработки, помечая как пройденный
         */
        while (current.children) {
            GraphNode child = popS(current.children);
            if (child.used == false) {
                pushQ(q, &child);
                child.used = true;
            }
        }
    }
}

void readAndPrint(const char *path) {
    FILE *file = fopen(path, "r");

    int size;
    fscanf(file, "%d", &size);

    T matrix[size][size];
    T res;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            fscanf(file, "%d", &res);
            matrix[i][j] = res;
        }
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    readAndPrint("C:\\MyData\\CLionProjects\\Geekbrains_Algorithms\\data.txt");
}