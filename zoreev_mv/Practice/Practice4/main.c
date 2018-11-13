#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#define N 10000

int number = 0;
int discont[N], price[N];
int added_code[N] = { 0 }, count[N] = { 0 };
int translated_code[4];
double sum = 0, final_discont = 0;

//Служебные функции

void data_generation() {
    int i;

    srand((unsigned) time(0));
    for (i = 1; i < N; i++) {
        price[i] = rand() % 1000;
        discont[i] = rand() % 50 + 1;
    }
}

void code_translation(int code) {
    int i, temp = code;

    for (i = 3; i >= 0; i--) {
        translated_code[i] = temp % 10;
        temp /= 10;
    }
}

void name_printer(kind,country,color,type) {
    setlocale(LC_ALL, "Russian");

    switch (color) {
    case 0: printf("Красный "); break;
    case 1: printf("Оранжевый "); break;
    case 2: printf("Жёлтый "); break;
    case 3: printf("Зелёный "); break;
    case 4: printf("Синий "); break;
    case 5: printf("Голубой "); break;
    case 6: printf("Фиолетовый "); break;
    case 7: printf("Чёрный "); break;
    case 8: printf("Розовый "); break;
    case 9: printf("Коричневый "); break;
    }
    switch (country) {
    case 0: printf("Российский "); break;
    case 1: printf("Немецкий "); break;
    case 2: printf("Итальянский "); break;
    case 3: printf("Американский "); break;
    case 4: printf("Японский "); break;
    case 5: printf("Китайский "); break;
    case 6: printf("Индийский "); break;
    case 7: printf("Бразильский "); break;
    case 8: printf("Польский "); break;
    case 9: printf("Вьетнамский "); break;
    }
    switch (kind) {
    case 0: printf("стол "); break;
    case 1: printf("стул "); break;
    case 2: printf("стул "); break;
    case 3: printf("шкаф "); break;
    case 4: printf("шкаф "); break;
    case 5: printf("диван "); break;
    case 6: printf("диван "); break;
    case 7: printf("ящик "); break;
    case 8: printf("ящик "); break;
    case 9: printf("стол "); break;
    }
    switch (kind) {
    case 0: printf(" из берёзы "); break;
    case 1: printf("из берёзы "); break;
    case 2: printf("из осины "); break;
    case 3: printf("из осины "); break;
    case 4: printf("из липы "); break;
    case 5: printf("из липы "); break;
    case 6: printf("из ясеня "); break;
    case 7: printf("из ясеня "); break;
    case 8: printf("из ели"); break;
    case 9: printf("из ели "); break;
    }
}

//Оперативные функции

void information(int code) {
    printf("\n***\n Информация о товаре\n");
    printf("Номер:  %d\n", code, price[code], discont[code]);
    printf("Цена:   %d р\nСкидка: %d\n***\n", price[code], discont[code]);
}

void adding(int code) {
    int i=0;

    added_code[number] = code;

    while (added_code[i] != code) {
        i++;
    }
    
    count[i]++;
    if ((i == number) || (number < 1)) number++;

    sum = (sum + price[code]);
    final_discont = (final_discont + (((double) discont[code]) / 100) * price[code]);
}

void printing() {
    int i;
    printf("\nМебельный магазин\n");

    for (i = 0; i < number; i++) {
        code_translation(added_code[i]);
        name_printer(translated_code[0], translated_code[1], translated_code[2], translated_code[3]);
        printf("%d   %d\n", added_code[i], count[i]);
    }

    printf("\nИтог     %lf\n", sum);
    printf("Скидка   %lf\n", final_discont);
    printf("К оплате %lf\n", sum-final_discont);
}

void main() {
    int code = 0, input = 0;
    setlocale(LC_ALL, "Russian");
    data_generation();

    printf("Сеанс запущен, сканируйте код\n");

    while (input != 4) {

        do {
            scanf("%d", &code);
        } while ((code < 1) || (code > 9999));

        input = 0;

        while (input != 3) {

            printf("\nЧтобы вывести описание товара нажмите 1\n");
            printf("Чтобы добавить товар в чек нажмите 2\n");
            printf("Чтобы сканировать следующий товар нажмите 3\n");
            printf("Чтобы напечатать чек нажмите 4\n");

            do {
                scanf("%d", &input);
            } while ((input < 1) || (input>4));

            if (input == 1) information(code);
            if (input == 2) adding(code);
            if (input == 4) { printing(code); break; }

        }

    }

}