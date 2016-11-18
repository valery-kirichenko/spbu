#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

const double pi =3.14;
class figure
{
private :
	double size;
	double square;
	double perimeter;
public :
	figure() 
	{
	char x;
	cout<<"--------Welcome to constructor of figures.--------"<<endl;
	cout<<"Would you like to enter the parameters of"<<endl;
	cout<<"figure by yourself or generate random?"<<endl;
	cout<<"enter 1 - to enter the parameters of figure by yourself."<<endl;
	cout<<"enter 2 - to generate random."<<endl;
	cout<<"Your choice: ";
	cin>>x;
	switch (x)
		{
	case '1':
		cout<<"The leng of side: ";
		cin>>size;
		break;
	case '2':
		size=rand()%100+1;
		cout<<"Size = "<<size<<endl;
		break;
		}
	system("cls");
	}
	double getsize() {return size;}
	double getsquare() {return square;}
	double getperimeter() {return perimeter;}
	void putsize(double size) {this->size = size;}
	void putsquare(double square) {this->square = square;}
	void putperimeter(double perimeter) {this->perimeter = perimeter;}
};
class triangle : public figure
{
public :
	triangle()
	{
	putsquare(getsize()*getsize()*sqrt(3.00)/2);
	}
};
class circle : public figure
{
public :
	circle()
	{
	putsquare(getsize()*getsize()*pi);
	}
};
class quadrate : public figure
{
public :
	quadrate()
	{
	putsquare(getsize()*getsize());
	}
};

int main()
{
	triangle a;
	circle b;
	quadrate c;
	cout<<"Square of triangle: "<<(double) a.getsquare()+a.getsquare()/100<<endl;
	cout<<"Square of circle: "<<(double) b.getsquare()+b.getsquare()/100<<endl;
	cout<<"Square of quadrate: "<<(double) c.getsquare()+c.getsquare()/100<<endl;
	system("pause");
	return 0;
}
