#pragma once
#include <iostream>
#include "Date.h"

using namespace std;

class task
{
protected:
    date task_date;
    string description;

public:
    task();
    task(const task&);

    date getDate();
    virtual bool isStd() = 0;
    virtual void print() = 0;
};