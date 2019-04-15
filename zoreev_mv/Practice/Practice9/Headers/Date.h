#pragma once

class date
{
    unsigned day;
    unsigned month;
    unsigned year;

public:
    date();
    date(const date&);
    date(unsigned, unsigned, unsigned);

    date& operator=(const date&);

    unsigned getDay();
    unsigned getMonth();
    unsigned getYear();
};