#include <iostream>
#include <math.h>
#include <stdlib.h>
#include "vector.h"
using namespace std;

int main() {
    vector a, b, c;
    int control;
    double m;
    a.input();
    b.input();
    cout << "1 to operate 0 to exit" << endl;
    do {
        cin >> control;
        // Подставь желаемую операцию
        try
        {
            c = a + b;
            c.print();
            cout << c.length() << endl;
            cout << a * b << endl;
        }
        catch (ExeptionBadLength)
        {
            cout << "|a| != |b|" << endl;
        }
        catch (ExeptionBadIndex)
        {
            cout << "Bad index" << endl;
        }
    } while (control != 0);
}