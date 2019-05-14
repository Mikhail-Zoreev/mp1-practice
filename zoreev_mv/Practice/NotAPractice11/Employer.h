#pragma once
#include <iostream>
#include <string>
#include "Pasport.h"

class employer
{
public:
	pasport data;
	string education;
	string specialization;
	string subdivision;
	string position;
	unsigned salary;
	date date_employment;
	date date_appointment;

	employer();
	employer(const employer& temp);
	~employer();

	void input();
};