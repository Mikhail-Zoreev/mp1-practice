#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void main() {
    setlocale(LC_ALL, "Russian");
    srand((unsigned int) time(0));
    int mode, input, answer, i=0, dif,b1,b2;
    char out;

    while (1) {
        printf("Выберите режим игры 1 или 2\n");
        scanf("%d",&mode);
        if ((mode == 1) || (mode == 2)) break;
        printf("Ошибка. ");
    }

    if (mode == 2) {
        while (1) {
            printf("Выберите сложность 1 или 2\n");
            scanf("%d", &dif);
            if ((mode == 1) || (mode == 2)) break;
            printf("Ошибка. ");
        }
    }



    //Режим 1

    if (mode == 1) {
        
        input = rand() % 1000 + 1;

        while (answer != input) {

            i++;
            
            while (1) {
                printf("Введите число ");
                scanf("%d", &answer);
                if ((answer > 0) && (answer < 1001)) break;
                printf("Ошибка. ");
            }

            if (answer < input)
                printf("Введённое меньше\n\n");
            if (answer > input)
                printf("Введённое больше\n\n");
            if (answer == input) {
                printf("Вы угадали за %d попыток", i);
                return;
            }
        }
    }
    
    
    //Режим 2. Простая сложность

    if (dif == 1) {

        while (1) {
            printf("Введите загаданное число ");
            scanf("%d", &input);
            if ((input > 0) || (input < 1001)) break;
            printf("Ошибка ввода\n");
        }

        b1 = 1; b2 = 1001;

        while (1) {

            answer = rand() % (b2 - b1) + b1;
            i++;

            while (1) {
                printf("Число %d ... загаданного ", answer);
                scanf("%*c%c", &out);
                if ((out == '>') || (out == '<') || (out == '=')) break;
                printf("Ошибка ввода\n");
            }

            if (out == '>') b2 = answer - 1;
            if (out == '<') b1 = answer + 1;
            if (out == '=') {
                printf("Компьютер выиграл за %d попыток\n", i);
                return;
            }
        }
    }

    //Режим 2. Высокая сложность

    if (dif == 2) {

        while (1) {
            printf("Введите загаданное число ");
            scanf("%d", &input);
            if ((input > 0) || (input < 1001)) break;
            printf("Ошибка ввода\n");
        }

        b1 = 0; b2 = 1001;

        while (1) {

            i++;

            while (1) {
                printf("Число %d ... загаданного ", (b2 - b1) / 2 +b1);
                scanf("%*c%c", &out);
                if ((out == '>') || (out == '<') || (out == '=')) break;
                printf("Ошибка ввода\n");
            }

            if (out == '>') b2 = (b2-b1) / 2 +b1 ;
            if (out == '<') b1 = (b2-b1) / 2 +b1 ;
            if (out == '=') {
                printf("Компьютер выиграл за %d попыток\n", i);
                return;
            }
        }

    }
}