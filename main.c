/*
* ==================================================
* == Lesson 4. Homework
* == Student: Andrei Solovetov
* == Date: 10-mar-2018
* "==================================================
*/
#include <stdio.h>

#define X 5
#define Y 8
int board[Y][X];

struct point {
    int x, y;
};
typedef struct point Point;

void printBoard() {
    for (int y = 0; y < Y; y++) {
        for (int x = 0; x < X; x++) {
            printf("%4d", board[y][x]);
        }
        printf("\n");
    }
}

void annull() {
    for (int y = 0; y < Y; y++)
        for (int x = 0; x < X; x++)
            board[y][x] = 0;
}

int fillAndReturn(int y, int x, int res) {
    board[y][x] = res;
    return res;
}

int waysNumber(int y, int x, Point *barriers, int barriersNumber) {
    for (int i = 0; i < barriersNumber; i++) {
        if (barriers[i].y == y && barriers[i].x == x) {
            return fillAndReturn(y, x, 0);
        }
    }

    if (x == 0 && y == 0) {
        return fillAndReturn(y, x, 1);
    } else if (x == 0) {
        return fillAndReturn(y, x, waysNumber(y - 1, x, barriers, barriersNumber));
    } else if (y == 0) {
        return fillAndReturn(y, x, waysNumber(y, x - 1, barriers, barriersNumber));
    } else {
        return fillAndReturn(y, x, waysNumber(y - 1, x, barriers, barriersNumber) +
                                   waysNumber(y, x - 1, barriers, barriersNumber));
    }
}

void addBarrier(Point* barriers, int index, int y, int x){
    barriers[index].y = y;
    barriers[index].x = x;
}

int main(void) {
    int lastXIndex = X - 1;
    int lastYIndex = Y - 1;

    /*
     * Сначала проверяем корректно ли сработает без барьеров
     */
    {
        Point barriers[0];
        annull();
        int res = waysNumber(lastYIndex, lastXIndex, barriers, 0);
        printf("Without barriers: %d\n", res);
        printBoard();
        printf("\n");
    }

    /*
     * Добавляем барьер в первую ячейку
     */
    {
        Point barriers[1];
        addBarrier(barriers, 0, 0, 0);
        annull();
        int res = waysNumber(lastYIndex, lastXIndex, barriers, 1);
        printf("Barrier in {1,1}: %d\n", res);
        printBoard();
        printf("\n");
    }

    /*
     * Добавляем барьер в середину
     */
    {
        Point barriers[1];
        addBarrier(barriers, 0, 3, 2);
        annull();
        int res = waysNumber(lastYIndex, lastXIndex, barriers, 1);
        printf("Barrier in {3,4}: %d\n", res);
        printBoard();
        printf("\n");
    }

    /*
    * Добавляем барьер в последнюю ячейку
    */
    {
        Point barriers[1];
        addBarrier(barriers, 0, lastYIndex, lastXIndex);
        annull();
        int res = waysNumber(lastYIndex, lastXIndex, barriers, 1);
        printf("Barrier in {%d,%d}: %d\n", X, Y, res);
        printBoard();
        printf("\n");
    }

    /*
     * Добавляем несколько барьеров
     */
    {
        Point barriers[3];
        addBarrier(barriers, 0, 3, 0);
        addBarrier(barriers, 1, 3, 1);
        addBarrier(barriers, 2, 2, 4);
        annull();
        int res = waysNumber(lastYIndex, lastXIndex, barriers, 3);
        printf("Barriers in {1,4} {2,4} {5,3}: %d\n", res);
        printBoard();
        printf("\n");
    }
}