#pragma once
#include "Exeption.h"
#include "Container.h"

int main()
{
	Container<int, 10> a;
	a.Add(5);
	a.Add(6);
	a.Add(10);
	a[0] = 4;
	a.Print();
}