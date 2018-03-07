/*
* ==================================================
* == Lesson 3. Homework
* == Student: Andrei Solovetov
* == Date: 07-mar-2018
* "==================================================
*/

#include <stdio.h>
#include <stdlib.h>

void fillArray(int *arr, int len) {
    int i;
    for (i = 0; i < len; i++)
        arr[i] = rand() % 100;
}

void printArray(int *arr, int len) {
    int i;
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    puts("");
}

void swap(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

int bubbleSort(int *arr, int len) {
    int operations = 0;
    int i;
    int j;
    for (i = 0; i < len; i++)
        for (j = 0; j < len - 1; j++)
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                operations++;
            }

    return operations;
}

int modifiedBubbleSort(int *arr, int len) {
    int operations = 0;
    int i;
    int j;
    /*
     * Отступ от правого края массива. На каждой итерации внешнего цикла в правую часть
     * "всплывает" максимальный элемент, а значит есть смысл двигать правую границу влево
     */
    int offset = 0;

    for (i = 0; i < len - offset; i++){
        for (j = 0; j < len - offset - 1; j++) {
            /*
             * А почему бы не двигать значения через один элемент дополнительно ?
             */
            if (j < len - offset - 2 && arr[j] > arr[j + 2]) {
                swap(&arr[j], &arr[j + 2]);
                operations++;
            }

            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                operations++;
            }
        }
        offset++;
    }
    return operations;
}

int main(void) {
    const int SIZE = 40;
    int arr[SIZE];
    int arr2[SIZE];
    fillArray(arr, SIZE);
    fillArray(arr2, SIZE);
    printArray(arr, SIZE);
    printArray(arr2, SIZE);

    printf("\n");

    printf("Bubble sort:\nMax number of operations: %d\nFact: %d\n", SIZE * SIZE, bubbleSort(arr, SIZE));
    printArray(arr, SIZE);

    printf("Modified bubble sort:\nMax number of operations: %d\nFact: %d\n", SIZE * SIZE, modifiedBubbleSort(arr2, SIZE));
    printArray(arr2, SIZE);
}
