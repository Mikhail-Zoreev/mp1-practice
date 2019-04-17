#include <iostream>
#include <fstream>
#include "../Headers/List.h"
#include "../Headers/Time.h"
#include "../Headers/Date.h"


using namespace std;

list_item::list_item()
{
    value = NULL;
    next = NULL;
}

list_item::list_item(task* temp)
{
    value = temp;
    next = NULL;
}

list_item::~list_item()
{
    delete[] value;
}

calendar::calendar()
{
    head = NULL;
}

calendar::calendar(const calendar& temp)
{

}

calendar::~calendar()
{
    list_item *con, *del;
    for (list_item* i = head; i; i = con)
    {
        con = i->next;
        del = i;
        delete[] del;
    }
}
void calendar::create()
{
    task* temp_task;
    int control;
    cout << "You whant to add full day task? 1 for yes, 0 for no ";
    do
    {
        cin >> control;
    } while ((control != 1) && (control != 0));

    if (control)
    {
        temp_task = new task_day();
        temp_task->input();
    }
    else
    {
        temp_task = new task_std();
        temp_task->input();
    }

    //Если вставляем первый
    if (head == NULL)
    {
        head = new list_item;
        if (control)
        {
            head->value = temp_task;
        }
        else
        {
            head->value = temp_task;
        }
        return;
    }

    //Если надо заменить первого
    if ((temp_task->getDate() < head->value->getDate()) || ((temp_task->getDate() == head->value->getDate()) && (temp_task->getTime() < head->value->getTime())))
    {
        list_item* ins_item = new list_item;
        ins_item->next = head;
        head = ins_item;
        ins_item->value = temp_task;
        return;
    }

    //Тот случай когда надо подогнать по времени и дате
    list_item* i = head;
    for (; ((i->next != nullptr) && ((temp_task->getDate() > i->next->value->getDate()) || ((temp_task->getDate() == i->next->value->getDate()) && (temp_task->getTime() > i->next->value->getTime())))); i = i->next)
    {
    }
    list_item* ins_item = new list_item;
    ins_item->next = i->next;
    i->next = ins_item;
    ins_item->value = temp_task;
    return;
}

void calendar::remove()
{
    
}

void calendar::print()
{
    date print_date;
    cout << "Input day to show ";
    print_date.input();
    list_item* i = head;
    if (i == NULL)
    {
        cout << "Your to do list is empty" << endl;
        return;
    }
    for (; (i != NULL) && !(i->value->getDate() == print_date); i = i->next);
    {
    }
    if (i == NULL)
    {
        cout << "Tasks for this day unfounded" << endl;
        return;
    }

    for (;(i != NULL) && (i->value->getDate() == print_date && i->value->isStd()); i = i->next)
    {
        i->value->print();
        cout << endl;
    }
    if ((i != NULL) && (i->value->getDate() == print_date))
    {
        cout << "Whole day tasks" << endl;
    }
    for (; (i != NULL) && (i->value->getDate() == print_date); i = i->next)
    {
        i->value->print();
        cout << endl;
    }
}

void calendar::fread()
{

}

void calendar::fwrite()
{
    
}