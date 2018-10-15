#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

void main() {
	int n, cow, bull, i, j, out;
	int free[10] =  {0,0,0,0,0,0,0,0,0,0}, number[10] = {0,0,0,0,0,0,0,0,0,0}, input[10] = {0,0,0,0,0,0,0,0,0,0}, Cfree[10] = { 0,0,0,0,0,0,0,0,0,0 };
	long a;
	setlocale(LC_ALL, "Russian");
	srand((unsigned int) time(0));

	//����
	
	while (1) {
		printf("������� ���������� ���� ");
		scanf("%d", &n);
		if ((n > 0) && (n < 11)) break;
		printf("������ �����\n");
	}

	//��������� �����

	for (i = 0; i < n; i++) {
		
		do {
			number[i] = rand() % 10;
		} while ((Cfree[number[i]] == 1) || (number[0] == 0));
		
		Cfree[number[i]] = 1;

	}
	
	//�������� ����������

	do {
		
		do {
			
			out = 0;
			free[0] = 0; free[1] = 0; free[2] = 0; free[3] = 0; free[4] = 0; free[5] = 0; free[6] = 0; free[7] = 0; free[8] = 0; free[9] = 0;

			printf("������� ����� ");
			scanf("%ld", &a);
			if ((a < pow(10, (n - 1))) || (a >= pow(10, (n)))) {
				printf("����� �� ��������\n");
				out = 1;
				continue;
			}

			for (i = n-1; i >= 0; i--) {
				if (free[(a % 10)] == 1) {
					out = 1;
					printf("���������� ����\n");
					break;
				}
				input[i] = a % 10;
				free[(a % 10)] = 1;
				a = a / 10;
			}

		} while ((out == 1));
		
		//����� ����������

		bull = 0;
		cow = 0;

		for (i = 0; i < n; i++) {
			if (number[i] == input[i]) bull++;
		}
		for (i = 0; i < 10; i++) {
			if ((free[i] == 1) && (Cfree[i] == 1)) cow++;
		}
		cow = cow - bull;

		if (bull < n) {
			printf("����� %d\n����� %d\n", cow, bull);
		}
		else {
			printf("\n����������, �� ������� �����!\n");
		}

	} while (bull < n);
}
