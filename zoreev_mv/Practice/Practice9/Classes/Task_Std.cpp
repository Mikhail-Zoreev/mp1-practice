#include "../Headers/Task_Std.h"

task_std::task_std()
{
}

task_std::task_std(const task_std& temp)
{
    task_date = temp.task_date;
    beginning_time = temp.beginning_time;
    end_time = temp.end_time;
}

task_std::~task_std()
{

}

time task_std::getTime()
{
    return beginning_time;
}

void task_std::input()
{
    cout << "Input task date ";
    task_date.input();
    cout << "Input beggining time ";
    beginning_time.input();
    cout << "Input end time ";
    end_time.input();
    getchar();
    cout << "Input task description" << endl;
    getline(cin, description);
}

bool task_std::isStd()
{
    return true;
}

void task_std::print()
{
    cout << beginning_time.getHours() << ":" << beginning_time.getMinutes() << " -- " << end_time.getHours() << ":" << end_time.getMinutes() << "   " << description;
}