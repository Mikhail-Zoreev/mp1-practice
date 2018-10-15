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
		printf("�������� ����� ���� 1 ��� 2\n");
		scanf("%d",&mode);
		if ((mode == 1) || (mode == 2)) break;
		printf("������. ");
	}

	//����� 1

	input = rand() % 1000 + 1;
	printf("%d",input);

	while ((mode == 1) && (answer != input)) {
		
		while (1) {
			printf("������� ����� ");
			scanf("%d", &answer);
			if ((answer > 0) && (answer < 1001)) break;
			printf("������. ");
		}
		
		i++;
		
		if (answer < input)
			printf("������\n\n");
		else if (answer > input)
			printf("������\n\n");
		else {
			printf("�� ������� �� %d �������", i);
			return;
		}
	}

	//����� 2

	answer = 500;
	
	while (1) {
		printf("������� ���������� ����� ");
		scanf("%d",&input);
		if ((input > 0) && (input < 1001)) break;
		printf("������. ");
	}
	
	while (1) {

		i++;

		printf("��� ����� %d?\n", answer);
		scanf("%c",&output);
		if (output == '<')
			answer = answer + answer / 2;
		else if (output == '>')
			answer = answer - answer / 2;
		else {
			printf("��������� ������ �� %d �������",i);
		}
	}

}