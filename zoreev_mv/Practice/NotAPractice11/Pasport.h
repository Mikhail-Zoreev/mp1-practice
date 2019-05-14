#pragma once
#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

class pasport
{
public:
	string serial;
	string number;
	string issuer;
	date date_released;
	date date_birth;
	string address;

public:
	pasport();
	pasport(const pasport& temp);
	~pasport();

	void input();
};