/*
 * ==================================================
 * == Lesson 2. Homework
 * == Student: Andrei Solovetov
 * == Date: 04-mar-2018
 * "==================================================
 */

/*
 * Ответ к задаче из ЕГЭ:
 * G(6) = 13
 */

#include <stdio.h>

#define INT_LENGTH 32

void decToBin(int num);
void decToBinStep(int num, int *res, int position);
int powerLoop(int num, int power);
int powerRecursion(int num, int power);

int main(void) {

    /*
     * 1. Реализовать функцию перевода из 10 системы в двоичную используя рекурсию
    */
    int num = 0;
    printf("Enter an integer number, please: ");
    scanf("%d", &num);
    decToBin(num);
    printf("\n");

    /*
     * 2. Реализовать функцию возведения числа a в степень b без рекурсии
     */
    int power = 0;
    num = 0;
    printf("Enter an integer number and power, please: ");
    scanf("%d", &num);
    scanf("%d", &power);

    printf("%d in %d power is %d", num, power, powerLoop(num, power));
    printf("\n");

    /*
     * 2. Реализовать функцию возведения числа a в степень b рекуривно
     */
    printf("%d in %d power is %d", num, power, powerRecursion(num, power));
    printf("\n");

}

void decToBin(int num) {
    int result[INT_LENGTH] = {0};
    decToBinStep(num, result, INT_LENGTH);

    for (int i = 0; i < INT_LENGTH; ++i) {
        printf("%d", result[i]);
    }
}

void decToBinStep(int num, int *res, int position) {
    if (num != 0) {
        res[--position] = num % 2;
        decToBinStep(num >> 1, res, position);
    }
}

int powerLoop(int num, int power){
    if(power == 0)
        return 1;

    int result = 1;
    for (int i = 0; i < power; ++i) {
        result *= num;
    }

    return result;
}

int powerRecursion(int num, int power){
    if (power == 0)
        return 1;
    else if (power > 1)
        return num * powerRecursion(num, --power);
}