#pragma once
#include "Exeption.h"
#include <iostream>

template<typename Type, unsigned max_size>
class Container
{
	Type* arr;
	unsigned size;

public:
	Container();
	Container(const Container& temp);
	~Container();

	//Добавление элемента
	void Add(const Type& temp);
	//Добавление элемента по указателю
	void Add(const Type* temp);
	//Поиск элемента
	unsigned Find(const Type& temp);
	//Поиск и удаление элемента
	void FindAndRemove(const Type& temp);
	//Удаление элемента по индексу
	void Remove(unsigned index);
	//Вывод содержимого на экран
	void Print();
	//Проверка на полноту
	bool IsFull();
	//Провепка на пустоту
	bool IsEmpty();

	Container<Type, max_size>& operator=(const Container<Type, max_size>& temp);
	Type& operator[](unsigned index);
};

template<typename Type, unsigned max_size>
Container<Type, max_size>::Container()
{
	size = 0;
	arr = nullptr;
}

template<typename Type, unsigned max_size>
Container<Type, max_size>::Container(const Container& temp)
{
	size = temp.size;
	for (unsigned i = 0; i < size; i++)
	{
		arr[i] = temp.arr[i];
	}
}

template<typename Type, unsigned max_size>
Container<Type, max_size>::~Container()
{
	size = 0;
	delete[] arr;
}

template<typename Type, unsigned max_size>
void Container<Type, max_size>::Add(const Type& temp)
{
	if (size + 1 <= max_size)
	{
		Type* temp_arr = new Type[size + 1];
		for (int i = 0; i < size; i++)
		{
			temp_arr[i] = arr[i];
		}
		if (arr != nullptr) delete[] arr;
		arr = temp_arr;
		size++;
		arr[size - 1] = temp;
		return;
	}
	throw Exeption(ContainerIsFull);
	return;
}

template<typename Type, unsigned max_size>
void Container<Type, max_size>::Add(const Type* temp)
{
	if (size + 1 <= max_size)
	{
		Type* temp_arr = new Type[size + 1];
		for (int i = 0; i < size; i++)
		{
			temp_arr[i] = arr[i];
		}
		if (arr != nullptr) delete[] arr;
		arr = temp_arr;
		size++;
		arr[size - 1] = *temp;
		return;
	}
	throw Exeption(ContainerIsFull);
	return;
}

template<typename Type, unsigned max_size>
unsigned Container<Type, max_size>::Find(const Type& temp)
{
	for (unsigned i = 0; i < size; i++)
	{
		if (temp == arr[i]) return i;
	}
	return -1;
}

template<typename Type, unsigned max_size>
void Container<Type, max_size>::FindAndRemove(const Type& temp)
{
	if (size == 0) return;
	unsigned del;
	del = Find(temp);
	if (del == -1) return;
	Type* temp_arr = new Type[size - 1];
	unsigned i = 0, j = 0;
	while (i < size)
	{
		if (i != del)
		{
			temp_arr[j] = arr[i];
			i++;
			j++;
		}
		else
		{
			i++;
		}
	}
	if (arr != nullptr) delete[] arr;
	size--;
	arr = temp_arr;
}

template<typename Type, unsigned max_size>
void Container<Type, max_size>::Remove(unsigned index)
{
	if (size == 0) return;
	if ((index < 0) || (index >= size))
	{
		throw Exeption(BadIndex);
	}
	Type* temp_arr = new Type[size - 1];
	unsigned i = 0, j = 0;
	while (i < size)
	{
		if (i != index)
		{
			temp_arr[j] = arr[i];
			i++;
			j++;
		}
		else
		{
			i++;
		}
	}
	delete[] arr;
	size--;
	arr = temp_arr;
}

template<typename Type, unsigned max_size>
Container<Type, max_size>& Container<Type, max_size>::operator=(const Container<Type, max_size>& temp)
{
	if (&temp == this) return *this;
	if (temp.size > max_size)
	{
		throw Exeption(BadContainerSize);
		return *this;
	}
	if (arr != nullptr) delete[] arr;
	size = temp.size;
	arr = new Type[size];
	for (unsigned i; i < size; i++)
	{
		arr[i] = temp.arr[i];
	}
	return *this;
}

template<typename Type, unsigned max_size>
Type& Container<Type, max_size>::operator[](unsigned index)
{
	if ((index < 0) || (index >= size))
	{
		throw Exeption(BadIndex);
	}
	return arr[index];
}

template<typename Type, unsigned max_size>
void Container<Type, max_size>::Print()
{
	for (unsigned i = 0; i < size; i++)
	{
		std::cout << arr[i] << std::endl;
	}
}

template<typename Type, unsigned max_size>
bool Container<Type, max_size>::IsFull()
{
	if (size == max_size) return true;
	return false;
}

template<typename Type, unsigned max_size>
bool Container<Type, max_size>::IsEmpty()
{
	if (size == 0) return true;
	return false;
}