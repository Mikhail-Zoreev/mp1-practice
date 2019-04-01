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

//Сложение векторов
vector operator+(const vector& a, const vector& b);

//Складывание вектора с числом
vector operator+(const vector& a, const double b);

//Вычитание векторов
vector operator-(const vector& a, const vector& b);

//Вычитание числа из вектора
vector operator-(const vector& a, const double b);

//Скаляроне произведение
double operator*(const vector& a, const vector& b);

//Умножение вектора на число
vector operator*(const vector& a, const double m);