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

list::list()
{
    head = NULL;
}

list::list(const list& temp)
{

}

void list::create()
{
    date temp_date;
    time temp_time;
    cout << "Input task date ";
    temp_date.input();
    int control;
    cout << "You whant to add full day task? 1 for yes, 0 for no ";
    do
    {
        cin >> control;
    } while ((control != 1) && (control != 0));

    //Если вставляем первый
    if (head == NULL)
    {
        head = new list_item;
        if (control)
        {
            head->value = new task_day(temp_date);
            head->value->input();
        }
        else
        {
            cout << "Input beggining time ";
            temp_time.input();
            head->value = new task_std(temp_date, temp_time);
            head->value->input();
        }
        return;
    }

    //Если надо заменить первого
    if (control)
    {
        if (temp_date < head->value->getDate())
        {
            list_item* ins_item = new list_item;
            ins_item->next = head;
            head = ins_item;
            ins_item->value = new task_day(temp_date);
            ins_item->value->input();
            return;
        }
    }
    else
    {
        
        if ((temp_date < head->value->getDate()) || ((temp_date == head->value->getDate()) && (temp_time < head->value->getTime())))
        {
            cout << "Input beggining time ";
            temp_time.input();
            list_item* ins_item = new list_item;
            ins_item->next = head;
            head = ins_item;
            ins_item->value = new task_std(temp_date, temp_time);
            ins_item->value->input();
            return;
        }
    }

    //Тот случай когда надо подогнать по времени и дате
    list_item* i = head;
    if (control)
    {
        for (; (i->next != nullptr) && (temp_date > i->next->value->getDate()); i = i->next)
        {
        }
        list_item* ins_item = new list_item;
        ins_item->next = i->next;
        i->next = ins_item;
        ins_item->value = new task_day(temp_date);
        ins_item->value->input();
        return;
    }
    else
    {
        cout << "Input beggining time ";
        temp_time.input();
        for (; ((i->next != nullptr) && ((temp_date > i->next->value->getDate()) || ((temp_date == i->next->value->getDate()) && (temp_time > i->next->value->getTime())))); i = i->next)
        {
        }
        list_item* ins_item = new list_item;
        ins_item->next = i->next;
        i->next = ins_item;
        ins_item->value = new task_std(temp_date, temp_time);
        ins_item->value->input();
        return;
    }
}

void list::remove()
{
    
}

void list::print()
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
        cout << "Tasks for this day unfounded";
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

void list::fread()
{

}

void list::fwrite()
{
    
}