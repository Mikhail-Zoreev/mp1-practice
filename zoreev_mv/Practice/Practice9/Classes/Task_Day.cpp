#include "../Headers/Task_Day.h"

task_day::task_day() 
{
    
}

task_day::task_day(const task_day& temp)
{
    task_date = temp.task_date;
    description = temp.description;
}

void task_day::input()
{

}

bool task_day::isStd()
{
    return false;
}

void task_day::print()
{

}