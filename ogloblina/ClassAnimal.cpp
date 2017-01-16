// ConsoleApplication6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void print(){cout << "This is animal.";}
    virtual void Legs(){cout << 0 << " Legs.";}
    virtual void Speach(){cout <<"It says "<< "nothing";}
};

class Duck: public Animal
{
public:
    void print(){cout << "This is duck.";}
	void Legs(){cout << 2 << " Legs.";}
	void Speach(){cout <<"It says "<< "Quack!";}
};

class Dog: public Animal
{
public:
    void print(){cout << "This is dog.";}
	void Legs(){cout << 4 << " Legs.";}
	void Speach(){cout <<"It says "<< "Bow-wow!";}
};

class Rak: public Animal
{
public:
    void print(){cout << "This is cancer.";}
    void Legs(){cout << 6 << " Legs.";}
};

int main()
{
	Duck duck;
	Dog dog;
	Rak rak;
	duck.print();
	cout << ' ';
	duck.Legs();
	cout << ' ';
	duck.Speach();
	cout << endl;
	dog.print();
	cout << ' ';
	dog.Legs();
	cout << ' ';
	dog.Speach();
	cout << endl;
	rak.print();
	cout << ' ';
	rak.Legs();
	cout << ' ';
	rak.Speach();
	cout << endl;
	return 0;
}

