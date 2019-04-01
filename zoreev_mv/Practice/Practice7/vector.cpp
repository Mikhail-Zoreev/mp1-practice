#include "vector.h"

vector& vector::operator=(const vector& temp)
{
    if (this == &temp)
    {
        return *this;
    }
    size = temp.size;
    if (array != nullptr)
    {
        delete[] array;
    }
    array = new double[size];
    for (int i = 0; i < size; i++)
    {
        array[i] = temp.array[i];
    }
    return *this;
}

vector operator+(const vector& a, const vector& b)
{
    if (a.size != b.size)
    {
        throw 1;
    }
    vector* out = new vector(a.size);
    for (int i = 0; i < a.size; i++)
    {
        out->array[i] = a.array[i] + b.array[i];
    }
    return *out;
}

vector operator+(const vector& a, const double b)
{
    vector* out = new vector(a.size);
    for (int i = 0; i < a.size; i++)
    {
        out->array[i] = a.array[i] + b;
    }
    return *out;
}

vector operator-(const vector& a, const vector& b)
{
    if (a.size != b.size)
    {
        throw 1;
    }
    vector* out = new vector(a.size);
    for (int i = 0; i < a.size; i++)
    {
        out->array[i] = a.array[i] - b.array[i];
    }
    return *out;
}

vector operator-(const vector& a, const double b)
{
    vector* out = new vector(a.size);
    for (int i = 0; i < a.size; i++)
    {
        out->array[i] = a.array[i] - b;
    }
    return *out;
}

double operator*(const vector& a, const vector& b)
{
    if (a.size != b.size)
    {
        throw 1;
    }
    double out;
    for (int i = 0; i < a.size; i++)
    {
        out += a.array[i] * b.array[i];
    }
    return out;
}

vector operator*(const vector& a, const double m)
{
    vector* out = new vector(a.size);
    for (int i = 0; i < a.size; i++)
    {
        out->array[i] = a.array[i] * m;
    }
    return *out;
}

