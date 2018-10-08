#include <stdio.h>
#include <locale.h>

void main() {
	int n, cow, bull, i, j, out;
	long a;
	setlocale(LC_ALL, "Russian");

	//Ввод
	
	do {
		printf("Введите количество цифр ");
		scanf("%d",&n);
	} while ((n < 0) || (n > 10));

	//Генерация числа

	for (i = 0;i < n;i++) { //Помещает в ячейку i
		out = 0;

		for (j = 0;j < i;j++) {

		}

		if (out == 1) i--;
	}

	//Проверка совпадений
	
	do {
		//Ввод числа
		
		do {
			out = 0;
			printf("Введите число ");
			scanf("%l", &a);
			for (i = 1;i <= n;i++) { //Помещает в ячейку n-i

			}
		} while ((out == 0) || (a < 0) || (a < (10 * (n - 1))) || (a >= (10 * n)));
		
		//Поиск совпадений

		bull = 0;
		cow = 0;


		if (bull < n) {
			printf("Коров - %d\n Быков -%d\n", cow, bull);
		}
		else {
			printf("Поздравляю, вы угдадли число!");
		}

	} while (bull < n);
}
