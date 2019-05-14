#pragma once
#include "Employer.h"
#include "Pasport.cpp"

employer::employer()
{

}

employer::employer(const employer& temp)
{

}

employer::~employer()
{

}

void employer::input()
{
	cout << "Eucation ";
	getline(cin, education);
	cout << "Specialization ";
	getline(cin, specialization);
	cout << "Subdivision ";
	getline(cin, subdivizion);
	cout << "Position ";
	getline(cin, );
	cout << "Date ";
	getline(cin, );
	
}

ostream& operator<<(ostream& stream, employer temp)
{
	stream << temp.data << endl << temp.education << endl << temp.specialization << endl << temp.subdivision << endl;
	stream << temp.position << endl << temp.salary << endl;
	stream << temp.date_employment.getDay << "." << temp.date_employment.getMonth << "." << temp.date_employment.getYear << endl;
	stream << temp.date_appointment.getDay << "." << temp.date_appointment.getMonth << "." << temp.date_appointment.getYear << endl;
}