#include <stdio.h>
#include <locale.h>

void main() {
	int n, cow, bull, i;
	long a;
	setlocale(LC_ALL, "Russian");

	//����
	
	do {
		printf("������� ���������� ���� ");
		scanf("%d",&n);
	} while ((n < 0) || (n > 10));

	//��������� �����

	for (i = 0;i <= n;i++) {

	}

	//�������� ����������
	
	do {
		//���� �����
		
		do {
			printf("������� ����� ");
			scanf("%l", &a);
		} while ((a < 0) || (a < (10 * (n - 1))) || (a >= (10 * n)));

		
		//����� ����������

		if (bull < n) {
			printf("����� - %d\n ����� -%d\n", cow, bull);
		}
		else {
			printf("����������, �� ������� �����!");
		}

	} while (bull < n);
}
