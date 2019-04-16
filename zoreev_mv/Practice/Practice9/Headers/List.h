#pragma once
#include "Task.h"
#include "Task_Day.h"
#include "Task_Std.h"

class list_item
{
public:
    task* value;
    list_item* next;

    list_item();
    list_item(task*);
};

class list
{
public:
    list_item* head;

    list();
    list(const list&);

    void create();
    void remove();
    void print();
    void fprint();
    void fread();
    void fwrite();
};