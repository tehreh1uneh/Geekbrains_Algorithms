/*
* ==================================================
* == Lesson 4. Homework
* == Student: Andrei Solovetov
* == Date: 10-mar-2018
* "==================================================
*/
#include <stdio.h>

#define X 6
#define Y 8

struct point {
    int x, y;
};
typedef struct point Point;
int board[X][Y];

void printBoard() {
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++)
            printf("%4d", board[j][i]);
        printf("\n");
    }
}

void annull() {
    for (int i = 0; i < Y; i++)
        for (int j = 0; j < X; j++)
            board[j][i] = 0;
}

int fillAndReturn(int x, int y, int res) {
    board[x][y] = res;
    return res;
}

void addBarrier(Point *barriers, int index, int x, int y) {
    barriers[index].x = x;
    barriers[index].y = y;
}

int waysNumber(int x, int y, Point barriers[], int barriersNumber) {
    for (int i = 0; i < barriersNumber; ++i) {
        if (barriers[i].x == x && barriers[i].y == y) {
            return fillAndReturn(x, y, 0);
        }
    }

    if (x == 0 && y == 0) {
        return fillAndReturn(x, y, 1);
    } else if (x == 0) {
        return fillAndReturn(x, y, waysNumber(x, y - 1, barriers, barriersNumber));
    } else if (y == 0) {
        return fillAndReturn(x, y, waysNumber(x - 1, y, barriers, barriersNumber));
    } else {
        return fillAndReturn(x, y, waysNumber(x - 1, y, barriers, barriersNumber) +
                                   waysNumber(x, y - 1, barriers, barriersNumber));
    }
}

int main(void) {
    /*
     * Сначала проверяем корректно ли сработает без барьеров
     */
    {
        Point barriers[0];
        annull();
        waysNumber(X, Y, barriers, 0);
        printf("Without barriers:\n");
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
        waysNumber(X, Y, barriers, 1);
        printf("Barrier in {1,1}:\n");
        printBoard();
        printf("\n");
    }

    /*
     * Добавляем барьер в середину
     */
    {
        Point barriers[1];
        addBarrier(barriers, 0, 2, 2);
        annull();
        printf("Barrier in {3,3}:\n");
        waysNumber(X, Y, barriers, 1);
        printBoard();
        printf("\n");
    }

    /*
    * Добавляем барьер в последнюю ячейку
    */
    {
        Point barriers[1];
        addBarrier(barriers, 0, X - 1, Y - 1);
        annull();
        waysNumber(X, Y, barriers, 1);
        printf("Barrier in {%d,%d}:\n", X, Y);
        printBoard();
        printf("\n");
    }

    /*
     * Добавляем несколько барьеров
     */
    {
        Point barriers[3];
        addBarrier(barriers, 0, 0, 3);
        addBarrier(barriers, 1, 1, 3);
        addBarrier(barriers, 2, 4, 2);
        annull();
        waysNumber(X, Y, barriers, 3);
        printf("Barriers in {1,4}, {2,4}, {5,3}:\n");
        printBoard();
        printf("\n");
    }
}