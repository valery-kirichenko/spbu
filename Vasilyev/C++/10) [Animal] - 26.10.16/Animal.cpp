#include "stdafx.h"
#include <iostream>


class Animal {
public:
	virtual void print()
	{
		std::cout << "Animal " << 0 << std::endl;
	}
};

class Dog : public Animal {
public:
	void print()
	{
		std::cout << "Dog " << 4 << std::endl;
	}
};

class Cat : public Animal {
public:
	void print()
	{
		std::cout << "Cat " << 4 << std::endl;
	}
};

class Human : public Animal {
public:
	void print()
	{
		std::cout << "Human " << 2 << std::endl;
	}
};

int main()
{
	Animal P;
	Animal *ptr = &P;
	Dog dog;
	Cat cat;
	Human human;
	ptr->print();
	ptr = &dog;
	ptr->print();
	ptr = &cat;
	ptr->print();
	ptr = &human;
	ptr->print();
	std::system("pause");
    return 0;
}