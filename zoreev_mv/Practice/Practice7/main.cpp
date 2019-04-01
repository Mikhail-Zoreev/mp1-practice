#include <iostream>
#include <math.h>
#include <stdlib.h>
#include "vector.h"
using namespace std;

int main() {
    double ar[3];
    for (int i = 0; i < 3; i++)
    {
        cin >> ar[i];
    }
    vector a(ar, 3);
    vector b;
    vector c;
    b = a;
    c = b + a;
    return 0;
}