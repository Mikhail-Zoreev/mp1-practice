#include "../Headers/Task_Day.h"

task_day::task_day() 
{
    description = new char[60];
}

task_day::task_day(const date& _date)
{
    task_date = _date;
    description = new char[60];
}

task_day::task_day(const task_day& temp)
{
    task_date = temp.task_date;
    description = new char[60];
}

time task_day::getTime()
{
    return time(1440);
}

void task_day::input()
{
    cout << "Input task date ";
    task_date.input();
    cout << "Input task description" << endl;
    //cin.getline(description, 60);
}

bool task_day::isStd()
{
    return false;
}

void task_day::print()
{
    cout << description;
}