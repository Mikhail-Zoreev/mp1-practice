//��� ������� ����� �������������� ������ ���� ������

#pragma once
#include <stdio.h>
#include <math.h>

typedef struct {
    double* array;
    int size;
} vector;

//�������� ������� ��� �������������
void vector_create(vector* temp, int size);

//���� �������
void vector_input(vector* temp);

//�������� �������� 
int vector_add(vector* result,vector a, vector b);

//��������� �� ������� a ������� b
int vector_sub(vector* result, vector a, vector b);

//���������� ������������ ��������
int vector_scalar(double* result, vector a, vector b);

//��������� ������� �� �����
int vector_multiply(vector* result, vector a, double m);

//���������� ������ ��������
int vector_length(double* result, vector temp);

//���������� ���� ����� ���������
int vector_angle(double* result, vector a, vector b);

//������ �������
void vector_print(vector a);