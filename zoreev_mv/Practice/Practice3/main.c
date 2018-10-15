#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void main() {
	setlocale(LC_ALL, "Russian");
	srand((unsigned int) time(0));
	int mode, input=0, answer=-1, i=0;
	char output = '>';

	while (1) {
		printf("Выберите режим игры 1 или 2\n");
		scanf("%d",&mode);
		if ((mode == 1) || (mode == 2)) break;
		printf("Ошибка. ");
	}

	//Режим 1

	input = rand() % 1000 + 1;
	printf("%d",input);

	while ((mode == 1) && (answer != input)) {
		
		while (1) {
			printf("Введите число ");
			scanf("%d", &answer);
			if ((answer > 0) && (answer < 1001)) break;
			printf("Ошибка. ");
		}
		
		i++;
		
		if (answer < input)
			printf("Меньше\n\n");
		else if (answer > input)
			printf("Больше\n\n");
		else {
			printf("Вы угадали за %d попыток", i);
			return;
		}
	}

	//Режим 2

	answer = 500;
	
	while (1) {
		printf("Введите загаданное число ");
		scanf("%d",&input);
		if ((input > 0) && (input < 1001)) break;
		printf("Ошибка. ");
	}
	
	while (1) {

		i++;

		printf("Это число %d?\n", answer);
		scanf("%c",&output);
		if (output == '<')
			answer = answer + answer / 2;
		else if (output == '>')
			answer = answer - answer / 2;
		else {
			printf("Компьютер угадал за %d попыток",i);
		}
	}

}