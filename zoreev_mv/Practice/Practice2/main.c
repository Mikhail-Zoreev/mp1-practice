#include <stdio.h>
#include <locale.h>

void main() {
	int n, cow, bull, i;
	long a;
	setlocale(LC_ALL, "Russian");

	//Ввод
	
	do {
		printf("Введите количество цифр ");
		scanf("%d",&n);
	} while ((n < 0) || (n > 10));

	//Генерация числа

	for (i = 0;i <= n;i++) {

	}

	//Проверка совпадений
	
	do {
		//Ввод числа
		
		do {
			printf("Введите число ");
			scanf("%l", &a);
		} while ((a < 0) || (a < (10 * (n - 1))) || (a >= (10 * n)));

		
		//Поиск совпадений

		if (bull < n) {
			printf("Коров - %d\n Быков -%d\n", cow, bull);
		}
		else {
			printf("Поздравляю, вы угдадли число!");
		}

	} while (bull < n);
}
