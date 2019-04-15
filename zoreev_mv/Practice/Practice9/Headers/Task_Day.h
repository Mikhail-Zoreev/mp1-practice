#pragma once
#include "Task.h"
#include "Time.h"

class task_day : public task
{

public:
    task_day();
    task_day(const date&);
    task_day(const task_day&);
    
    time getTime();
    void input();
    bool isStd();
    void print();
};