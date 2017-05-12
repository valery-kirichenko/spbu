#include "stdafx.h"
#include <iostream>
#include <cmath>

class Parent {
public:
	Parent()
	{
		std::cout << "1Constructor without any parametrs" << std::endl;
	}
	Parent(int a)
	{
		std::cout << "1Constructor with 1 parametrs" << std::endl;
	}
	Parent(int a, int b)
	{
		std::cout << "1Constructor with 2 parametrs" << std::endl;
	}
	~Parent()
	{
		std::cout << "1Destructor" << std::endl;
		std::system("pause");
	}
};

class Child : public Parent {
public:
	Child() : Parent()
	{
		std::cout << "2Constructor without any parametrs" << std::endl;
	}
	Child(int a) : Parent(a)
	{
		std::cout << "2Constructor with 1 parametrs" << std::endl;
	}
	Child(int a, int b) : Parent(a, b)
	{
		std::cout << "2Constructor with 2 parametrs" << std::endl;
	}
	~Child()
	{
		std::cout << "2Destructor" << std::endl;
		std::system("pause");
	}
};

int main()
{
	Parent a1;
	Child a2(1, 2);
	std::system("pause");
	return 0;
}