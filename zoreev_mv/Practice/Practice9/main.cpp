#include "includes.h"

int main()
{
    list note;
    int control;
    cout << "Add , Remove, Print, Writre to file, Read from file, Exit" << endl;
    do {
        do {
            cin >> control;
        } while (control > 6);

        switch (control)
        {
        case 1:
            note.create();
            break;
        case 2:
            note.remove();
            break;
        case 3:
            note.print();
            break;
        case 4:
            note.fread();
            break;
        case 5:
            note.fwrite();
            break;
        }
    } while (control != 5);
}