#pragma once

class time
{
    unsigned minutes;

public:
    time();
    time(const time&);
    time(unsigned _minutes);
    time(unsigned _hours, unsigned _minutes);

    time operator+(const time&);

    unsigned getHours();
    unsigned getMinutes();
};