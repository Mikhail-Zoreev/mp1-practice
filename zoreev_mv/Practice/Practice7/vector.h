#pragma once

struct vector
{
    double* array;
    int size;

    vector() {
        size = 0;
        array = nullptr;
    }
    vector(int _size) {
        size = _size;
        array = new double [size];
        for (int i = 0; i < size; i++)
        {
            array[i] = 0;
        }
    }
    vector(double* _array, int _size)
    {
        size = _size;
        array = new double[size];
        for (int i = 0; i < size; i++)
        {
            array[i] = _array[i];
        }
    }
    ~vector() {
        size = 0;
        if (array != nullptr)
        {
            delete[] array;
        }
    }

    vector& operator=(const vector& temp);
};

//�������� ��������
vector operator+(const vector& a, const vector& b);

//����������� ������� � ������
vector operator+(const vector& a, const double b);

//��������� ��������
vector operator-(const vector& a, const vector& b);

//��������� ����� �� �������
vector operator-(const vector& a, const double b);

//��������� ������������
double operator*(const vector& a, const vector& b);

//��������� ������� �� �����
vector operator*(const vector& a, const double m);