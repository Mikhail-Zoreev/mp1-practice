#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void main() {
	setlocale(LC_ALL, "Russian");
	srand((unsigned int) time(0));
	int mode, input, answer, i=0, delta;
	char out,bug1;

	while (1) {
		printf("�������� ����� ���� 1 ��� 2\n");
		scanf("%d",&mode);
		if ((mode == 1) || (mode == 2)) break;
		printf("������. ");
	}

	//����� 1

	if (mode == 1) {
		
		input = rand() % 1000 + 1;

		while (answer != input) {

			i++;
			
			while (1) {
				printf("������� ����� ");
				scanf("%d", &answer);
				if ((answer > 0) && (answer < 1001)) break;
				printf("������. ");
			}

			if (answer < input)
				printf("�������� ������\n\n");
			if (answer > input)
				printf("�������� ������\n\n");
			if (answer == input) {
				printf("�� ������� �� %d �������", i);
				return;
			}
		}
	}
	
	
	//����� 2

	if (mode == 2) {

		answer = 512;
		delta = 256;

		while (1) {
			printf("������� ���������� ����� ");
			scanf("%d", &input);
			if ((input > 0) && (input < 1001)) break;
			printf("������. ");
		}

		while (1) {

			i++;

			if (answer > 1001) {
				answer = answer - delta;
				delta = delta / 2;
				i--;
			}
			else {
				printf("��� ����� %d?\n", answer);
				
				while (1) {
					scanf("%c%c", &bug1,&out);
					if ((out=='>')||(out=='<')||(out=='=')) break;
				}


				if (out == '<') {
					answer = answer + delta;
					delta = delta / 2;
				}
				if (out == '>') {
					answer = answer - delta;
					delta = delta / 2;
				}
				if (out == '=') {
					printf("��������� ������ �� %d �������\n", i);
					return;
				}

			}

		}

	}

}