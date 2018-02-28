/*
 * ==================================================
 * == Lesson 1. Homework
 * == Student: Andrei Solovetov
 * == Date: 28-feb-2018
 * "==================================================
 */

#include <stdio.h>
#include <malloc.h>
#include <time.h>

void menu();
double BMI(double m, double h);
void swapSlowly(int *a, int *b);
void swap(int *a, int *b);
void seasonbymonth();
void printage();
int cmpchessboardcolor(int x1, int y1, int x2, int y2);
void qandr(int N, int K);
void containsodddigit(int num);
void printautomorphic();
void todigits(unsigned long long n, int *arr);
void todigitsl(int n, int *arr, int *length);
int rndh();
void initRnd();

int main(void) {

    menu();
    int ans = 0;
    int a = 12, b = 45;
    int posx1, posy1, posx2, posy2;

    while (1) {
        printf("== Enter a number of exercise: ");
        scanf("%i", &ans);
        printf("\n\n");

        switch (ans) {
            case 0:
                printf("Have a good day!");
                return 0;
            case 1:
                /*
                 * Задание 1.
                 * Ввести вес и рост человека. Рассчитать и вывести индекс массы тела по формуле I=m/(h*h);
                 * где m-масса тела в килограммах, h - рост в метрах.
                 *
                 * Вес = 74 кг, рост = 176 см
                 * Результат должен быть 23,889463
                 */
                printf("Ex.1\nHeight is 1.76 m., weight is 74 kg, BMI is %lf\n\n", BMI(74, 1.76));
                break;
            case 2:
                /*
                 * Задание 2
                 * Написать программу обмена значениями двух целочисленных переменных:
                 * a. с использованием третьей переменной;
                 */
                printf("Ex.2\nSwap values:\na = %i, b = %i\n", a, b);

                swapSlowly(&a, &b);
                printf("Swap slowly: a = %i, b = %i\n", a, b);

                /*
                 * b. *без использования третьей переменной.
                */
                swap(&a, &b);
                printf("Swap back (optimized): a = %i, b = %i\n\n", a, b);

                break;
            case 3:
                /*
                 * Задание 3
                 * Написать программу нахождения корней заданного квадратного уравнения.
                 */

                break;

            case 4:
                /*
                 * Задание 4
                 * С клавиатуры вводится номер месяца. Требуется определить, к какому времени года он
                 * относится
                 */
                printf("Ex.4\n");
                seasonbymonth();
                printf("\n");
                break;
            case 5:
                /*
                 * Задание 5
                 * Ввести возраст человека (от 1 до 150 лет) и вывести его вместе с последующим словом
                 * «год», «года» или «лет»
                 */
                printf("Ex.5\n");
                printage();
                printf("\n");
                break;
            case 6:
                /*
                 * Задание 6
                 * С клавиатуры вводятся числовые координаты двух полей шахматной доски (x1,y1,x2,y2).
                 * Требуется определить, относятся ли к поля к одному цвету или нет.
                 */
                posx1 = 6;
                posy1 = 3;
                posx2 = 3;
                posy2 = 8;

                printf("Ex.6\n");
                printf("Point 1(x:%i, y:%i), Point 2(x:%i, y:%i) have %s color.\n\n", posx1, posy1, posx2, posy2,
                       cmpchessboardcolor(posx1, posy1, posx2, posy2) ? "same" : "different");
                break;
            case 7:
                /*
                 * Задание 7
                 * Даны целые положительные числа N и K. Используя только операции сложения и вычитания,
                 * найти частное от деления нацело N на K, а также остаток от этого деления.
                 */
                printf("Ex.7\n");
                qandr(17, 3);
                printf("\n");
                break;
            case 8:
                /*
                 * Задание 8
                 * Дано целое число N (> 0). С помощью операций деления нацело и взятия остатка от деления
                 * определить, имеются ли в записи числа N нечетные цифры. Если имеются, то вывести True,
                 * если нет — вывести False.
                 */
                printf("Ex.8\n");
                printf("Number 2864 contains odd digit: ");
                containsodddigit(2864);
                printf("Number 786210138 contains odd digit: ");
                containsodddigit(786210138);
                printf("\n");
                break;
            case 9:
                /*
                 * Задание 9
                 * Написать функцию, генерирующую случайное число от 1 до 100
                 * без использования стандартной функции rand()
                 */
                printf("\nSome of my random values:");
                initRnd();
                for (int i = 0; i < 30; i++) {
                    printf("%i ", rndh());
                }
                printf("\n\n");
                break;
            case 10:
                /*
                 * Задание 10
                 * Автоморфные числа. Натуральное число называется автоморфным, если оно равно
                 * последним цифрам своего квадрата. Например, 25
                 * 2 = 625. Напишите программу, которая
                 * вводит натуральное число N и выводит на экран все автоморфные числа, не превосходящие
                 * N.
                 */
                printf("Ex.10\n");
                printautomorphic();
                printf("\n");
                break;
            case 99:
                menu();
                break;
            default:
                printf("Unknown input. Enter 99 for help.\n");
        }
    }
}

void menu() {
    printf("==================================================\n");
    printf("== Lesson 1. Homework\n");
    printf("== Student: Andrei Solovetov\n");
    printf("== Date: 28-feb-2018\n");
    printf("==================================================\n");
    printf("== Menu\n");
    printf("==== 1.  BMI calculation\n");
    printf("==== 2.  Swaping of 2 integers\n");
    printf("==== 4.  Season by month number\n");
    printf("==== 5.  Age description\n");
    printf("==== 6.  Color equation of two chessboard's points\n");
    printf("==== 7.  Division result with remainder\n");
    printf("==== 8. Finding odd digits in number\n");
    printf("==== 9. Random numbers\n");
    printf("==== 10. Automorphic numbers in range from 1 to x\n\n");
    printf("==== 99. MENU\n");
    printf("==== 0.  EXIT\n");
    printf("==================================================\n\n");
}

/*
 * Ввести вес и рост человека. Рассчитать и вывести индекс массы тела по формуле I=m/(h*h);
 * где m-масса тела в килограммах, h - рост в метрах.
 */
double BMI(double m, double h) {
    return m / (h * h);
}

/*
 * Написать программу обмена значениями двух целочисленных переменных:
 * a. с использованием третьей переменной;
 */
void swapSlowly(int *a, int *b) {
    int *tmp = (int *) malloc(sizeof(int));

    *tmp = *a;
    *a = *b;
    *b = *tmp;

    free(tmp);
}

/*
 * Написать программу обмена значениями двух целочисленных переменных:
 * b. *без использования третьей переменной.
 */
void swap(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

/*
 * Задание 4
 * С клавиатуры вводится номер месяца. Требуется определить, к какому времени года он
 * относится
 */
void seasonbymonth() {
    int *month = (int *) malloc(sizeof(int));
    printf("Enter month (1-12), please: ");
    scanf("%i", month);

    switch (*month) {
        case 12:
        case 1:
        case 2:
            printf("Season is winter");
            break;

        case 3:
        case 4:
        case 5:
            printf("Season is spring");
            break;

        case 6:
        case 7:
        case 8:
            printf("Season is summer");
            break;

        case 9:
        case 10:
        case 11:
            printf("Season is autumn");
            break;

        default:
            printf("Wrong input");
    }
    free(month);
}

/*
 * Ввести возраст человека (от 1 до 150 лет) и вывести его вместе с последующим словом
 * «год», «года» или «лет»
 */
void printage() {

    int age;
    printf("Enter your age (1-150), please: ");
    scanf("%i", &age);
    printf("%i", age);

    int rem = age % 100;

    if (rem > 10 && rem < 15) {
        printf(" лет\n");
    } else {
        switch (age % 10) {
            case 1:
                printf(" год\n");
                break;
            case 2:
            case 3:
            case 4:
                printf(" года\n");
                break;
            default:
                printf(" лет\n");
        }
    }
}

/*
 * Задание 6
 * С клавиатуры вводятся числовые координаты двух полей шахматной доски (x1,y1,x2,y2).
 * Требуется определить, относятся ли к поля к одному цвету или нет.
 */
int cmpchessboardcolor(int x1, int y1, int x2, int y2) {
    return (x1 % 2 == y1 % 2 && x2 % 2 == y2 % 2) || (x1 % 2 != y1 % 2 && x2 % 2 != y2 % 2);
}

/*
 * Задание 7
 * Даны целые положительные числа N и K. Используя только операции сложения и вычитания,
 * найти частное от деления нацело N на K, а также остаток от этого деления.
 */
void qandr(int N, int K) {
    printf("%i", N);
    int quotient = 0;
    int remainder = 0;

    while (1) {
        if (K > N) {
            remainder = N;
            break;
        }
        quotient++;
        N -= K;
    }

    printf("/%i = %i (remainder: %i)\n", K, quotient, remainder);
}

/*
 * Задание 8
 * Дано целое число N (> 0). С помощью операций деления нацело и взятия остатка от деления
 * определить, имеются ли в записи числа N нечетные цифры. Если имеются, то вывести True,
 * если нет — вывести False.
 */
void containsodddigit(int num) {
    int digits[10] = {0};

    int amount;

    for (amount = 0; num > 0; amount++) {
        digits[amount] = num % 10;
        num /= 10;
    }

    for (int i = 0; i < amount; i++) {
        if (digits[i] % 2 != 0) {
            printf("True\n");
            return;
        }
    }
    printf("False\n");
}

/*
 * Задание 10
 * Автоморфные числа. Натуральное число называется автоморфным, если оно равно
 * последним цифрам своего квадрата. Например, 25
 * 2 = 625. Напишите программу, которая
 * вводит натуральное число N и выводит на экран все автоморфные числа, не превосходящие
 * N.
 */
void printautomorphic() {

    int N;
    printf("AutomorphicNumbers. Enter a number, please:");
    scanf("%i", &N);

    for (int i = 1; i <= N; i++) {

        int digitsi[20] = {0};
        int length = 0;

        todigitsl(i, digitsi, &length);

        unsigned long long sq = (unsigned long long) i * (unsigned long long) i;
        int digitssq[20] = {0};
        todigits(sq, digitssq);

        for (int j = 0; j < length; j++) {
            if (digitsi[j] == digitssq[j])
                if (j == length - 1) printf("number %i is automorphic: %i..%llu\n", i, i, sq);
                else continue;
            else
                break;
        }
    }
}

void todigits(unsigned long long n, int *arr) {
    int i = 0;
    while (n > 0) {
        arr[i++] = (int) (n % 10);
        n /= 10;
    }
}

void todigitsl(int n, int *arr, int *length) {
    while (n > 0) {
        arr[(*length)++] = n % 10;
        n /= 10;
    }
}

/*
 * Задание 9
 * Написать функцию, генерирующую случайное число от 1 до 100
 * без использования стандартной функции rand()
 */
int previousRnd = 12;

void initRnd() {
    previousRnd = time(NULL) % 10000;
}

int rndh() {
    previousRnd = (321 * previousRnd + 21) % 100 + 1;
    return previousRnd;
}