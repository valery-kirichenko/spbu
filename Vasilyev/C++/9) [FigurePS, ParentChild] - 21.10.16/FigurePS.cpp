#include "stdafx.h"
#include <iostream>
#include <cmath>

class Figure {
private:
	int n;
	float P, S;
public:
	Figure(int n)
	{
		//this->n = n;
		this->P = 0;
		this->S = 0;
	}
	int setN(int n1)
	{
		n = n1;
	}
	float getSizeP()
	{
		return P;
	}
	float getSizeS()
	{
		return S;
	}
	virtual float countP() = 0;
	virtual float countS() = 0;
};

class Triangle : public Figure {
private:
	int n;
	float P, S;
public:
	Triangle(int n) : Figure(n)
	{
		this->n = n;
	}
	float countP()
	{
		P = n * 3;
		return P;
	}
	float countS()
	{
		S = n * n * (sqrt(3)/4);
		return S;
	}
};

class Rectangle : public Figure {
private:
	int n;
	float P, S;
public:
	Rectangle(int n) : Figure(n)
	{
		this->n = n;
	}
	float countP()
	{
		P = n * 4;
		return P;
	}
	float countS()
	{
		S = n * n;
		return S;
	}
};

class Circumerence : public Figure {
private:
	int n;
	float P, S;
public:
	Circumerence(int n) : Figure(n)
	{
		this->n = n;
	}
	float countP()
	{
		P = 2 * (3.14) * n;
		return P;
	}
	float countS()
	{
		S = (3.14) * n * n;
		return S;
	}
};

int main()
{
	int n = 5;
	Triangle triangle(n);
	Rectangle rectangle(n + 1);
	Circumerence circumerence(n - 1);
	std::cout << "Triangle P = " << triangle.countP() << std::endl << "Triangle S = " << triangle.countS() << std::endl << std::endl;
	std::cout << "Rectangle P = " << rectangle.countP() << std::endl << "Rectangle S = " << rectangle.countS() << std::endl << std::endl;
	std::cout << "Circumerence P = " << circumerence.countP() << std::endl << "Circumerence S = " << circumerence.countS() << std::endl << std::endl;
	std::system("pause");
    return 0;
}