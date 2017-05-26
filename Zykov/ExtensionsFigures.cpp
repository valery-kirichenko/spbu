// Extensions.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#define Pi 3.14; 

class Figure{
	private:

	public:
		int Side;
		int Radius;
		int FigureSquare;
		int Perimeter;
		Figure(){};
};

class Circle : public Figure{
	private:
	public:
		Circle(int Rad){
			Radius = Rad;
		}
		int GetRadius(){
			return Radius;
		}
		void CalculateSquare(){
			FigureSquare = Radius * Radius * Pi;
		}
		int GetSquare(){
			return FigureSquare;
		}
		void CalculatePerimeter(){
			Perimeter = 2 * Radius * Pi;
		}
		int GetPerimeter(){
			return Perimeter;
		}

};

class Square : public Figure{
	private:
	public:
		Square(int Sde){
			Side = Sde;
		}
		int GetSide(){
			return Side;
		}
		void CalculateSquare(){
			FigureSquare = Side * Side;
		}
		int GetSquare(){
			return FigureSquare;
		}
		void CalculatePerimeter(){
			Perimeter = Side * 4;
		}
		int GetPerimeter(){
			return Perimeter;
		}

};

class Triangle : public Figure{
	private:
	public:
		Triangle(int Sde){
			Side = Sde;
		}
		int GetSide(){
			return Side;
		}
		void CalculateSquare(){
			FigureSquare = Side*Side*sqrt(3)/4;
		}
		int GetSquare(){
			return FigureSquare;
		}
		void CalculatePerimeter(){
			Perimeter = Side * 3;
		}
		int GetPerimeter(){
			return Perimeter;
		}

};

int _tmain(int argc, _TCHAR* argv[])
{
	int Int = 5;

	Circle Circ(Int);
	Circ.CalculateSquare();
	Circ.CalculatePerimeter();
	cout << "\nCirc radius = " << Circ.GetRadius() << ".\nCirc square = " << Circ.GetSquare() << ".\nCirc perimeter = " << Circ.GetPerimeter() << ".\n";

	Square Sqr(Int);
	Sqr.CalculateSquare();
	Sqr.CalculatePerimeter();
	cout << "\nSqr side = " << Sqr.GetSide() << ".\nSqr square = " << Sqr.GetSquare() << ".\nSqr perimeter = " << Sqr.GetPerimeter() << ".\n";

	Triangle Trgl(Int);
	Trgl.CalculateSquare();
	Trgl.CalculatePerimeter();
	cout << "\nTrgl side = " << Trgl.GetSide() << ".\nTrgl square = " << Trgl.GetSquare() << ".\nTrgl perimeter = " << Trgl.GetPerimeter() << ".\n";

	system("pause");
	return 0;
}

