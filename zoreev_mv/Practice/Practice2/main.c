#include <stdio.h>
#include <locale.h>

void main() {
	int n, cow, bull, i, j, out;
	long a;
	setlocale(LC_ALL, "Russian");

	//����
	
	while (1) {
		printf("������� ���������� ���� ");
		scanf("%d", &n);
		if ((n > 0) && (n < 11)) break;
		printf("������ �����\n");
	}

	//��������� �����

	for (i = 0;i < n;i++) { //�������� � ������ i
		out = 0;

		for (j = 0;j < i;j++) {

		}

		if (out == 1) i--;
	}

	//�������� ����������
	
	do {
		//���� �����
		
		do {
			out = 0;
			printf("������� ����� ");
			scanf("%l", &a);
			for (i = 1;i <= n;i++) { //�������� � ������ n-i

			}
		} while ((out == 0) || (a < 0) || (a < (10 * (n - 1))) || (a >= (10 * n)));
		
		//����� ����������

		bull = 0;
		cow = 0;


		if (bull < n) {
			printf("����� - %d\n ����� -%d\n", cow, bull);
		}
		else {
			printf("����������, �� ������� �����!");
		}

	} while (bull < n);
}
