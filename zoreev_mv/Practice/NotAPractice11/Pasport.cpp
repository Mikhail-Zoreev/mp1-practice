#include "Pasport.h"

pasport::pasport()
{

}

pasport::pasport(const pasport& temp)
{
	serial = temp.serial;
	number = temp.number;
	issuer = temp.issuer;
	date_released = temp.date_released;
	date_birth = temp.date_birth;
	address = temp.address;
}

pasport::~pasport()
{

}

void pasport::input()
{
	cout << "Serial ";
	getline(cin, serial);
	cout << "Number ";
	getline(cin, number);
	cout << "Issuer ";
	getline(cin, issuer);
	cout << "Release date ";
	date_released.input();
	cout << "Birth date ";
	date_birth.input();
	cout << "Address";
	getline(cin, address);
}

ostream& operator<<(ostream& stream, pasport temp)
{
	stream << temp.serial << endl << temp.number << endl << temp.issuer;
	stream << temp.date_released.getDay << "." << temp.date_released.getMonth << "." << temp.date_released.getYear << endl;
	stream << temp.date_birth.getDay << "." << temp.date_birth.getMonth << "." << temp.date_birth.getYear << endl;
	stream << temp.address;
}