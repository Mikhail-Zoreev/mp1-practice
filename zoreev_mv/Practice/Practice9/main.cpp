#include "includes.h"

int main()
{
    calendar note;
    int control;
    cout << "Add , Remove, Print, Writre calendar to file, Read calendar from file, Exit" << endl;
    do {
        do {
            cin >> control;
        } while (control > 7);

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
            note.fwrite();
            break;
        case 5:
            note.fread();
            break;
        }
    } while (control != 6);
}