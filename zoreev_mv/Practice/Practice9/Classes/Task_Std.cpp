#include "../Headers/Task_Std.h"

task_std::task_std()
{
    description = new char[60];
}

task_std::task_std(const date& _date, const time& _time)
{
    task_date = _date;
    beginning_time = _time;
    description = new char[60];
}

task_std::task_std(const task_std& temp)
{
    task_date = temp.task_date;
    beginning_time = temp.beginning_time;
    end_time = temp.end_time;
    description = new char[60];
}

time task_std::getTime()
{
    return beginning_time;
}

void task_std::input()
{
    cout << "Input end time ";
    end_time.input();
    cout << "Input task description" << endl;
    //cin.getline(description, 60);
}

bool task_std::isStd()
{
    return true;
}

void task_std::print()
{
    cout << beginning_time.getHours() << ":" << beginning_time.getMinutes() << " -- " << end_time.getHours() << ":" << end_time.getMinutes() << endl;
    cout << description;
}