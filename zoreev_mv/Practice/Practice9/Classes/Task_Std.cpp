#include "../Headers/Task_Std.h"

task_std::task_std()
{

}

task_std::task_std(const task_std& temp)
{
    task_date = temp.task_date;
    beginning_time = temp.beginning_time;
    end_time = temp.end_time;
    description = temp.description;
}

void task_std::input()
{
    
    
}

bool task_std::isStd()
{
    return true;
}

void task_std::print()
{

}