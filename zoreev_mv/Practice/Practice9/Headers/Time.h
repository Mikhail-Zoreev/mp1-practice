#pragma once
#include <iostream>

using namespace std;

class time
{
    unsigned minutes;

public:
    time();
    time(const time&);
    time(unsigned);
    time(unsigned, unsigned);

    time& operator=(const time&);
    time operator+(const time&);

    unsigned getHours();
    unsigned getMinutes();

    void input();
    void setTime(unsigned, unsigned);
};