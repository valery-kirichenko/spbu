// problem1!.cpp: главный файл проекта.

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <conio.h>
#include <math.h>
#include <string>

using namespace std;

const double pi=acos(-1.);

class segment{
protected:
	double l;
public:	double distance(){
		return l;
	}
	segment(){
		cout<<"segment construtor without parametrs\n\n";
	}
	segment(double _l){
		l=_l;
		cout<<"segment construtor with parametrs\n\n";
	}
	segment(double _x,double _y){
		l=sqrt(_x*_x +_y*_y);
	}
	double square();
	double length();
};

class circle:public segment{
public:
	circle():segment(){
		cout<<"circle construtor without parametrs\n\n";
	}
	circle(double _l):segment(_l)
	{
		cout<<"circle construtor with parametrs\n\n";
	}
	double square(){
		return distance()*distance()*pi;
	}
	double length(){
		return 2*pi*distance();
	}
};

class triangle:public segment{
public:
	triangle():segment(){
		cout<<"triangle construtor without parametrs\n\n";
	}
	triangle(double _l):segment(_l)
	{
		cout<<"triangle construtor with parametrs\n\n";
	}
	double square(){
		return distance()*distance()*sin(pi/3)/2;
	}
	double length(){
		return 3*distance();
	}
};

class rectan:public segment{
public:
	rectan():segment(){
		cout<<"rectangular construtor without parametrs\n\n";
	}
	rectan(double _l):segment(_l)
	{
		cout<<"rectangular construtor with parametrs\n\n";
	}
	double square(){
		return distance()*distance();
	}
	double length(){
		return 4*distance();
	}
};

ostream& operator << (ostream& out,circle l){
	out<< "Circle:\nSqeuare is: "<<l.square() <<"\n"<<"Perimiter is: "<<l.length()<<"\n";
	return out;
}
ostream& operator << (ostream& out,rectan l){
	out<< "rectangular:\nSqeuare is: "<<l.square() <<"\n"<<"Perimiter is: "<<l.length()<<"\n";
	return out;
}
ostream& operator << (ostream& out,triangle l){
	out<< "triangle:\nSqeuare is: "<<l.square() <<"\n"<<"Perimiter is: "<<l.length()<<"\n";
	return out;
}

int main()
{
	circle c(1),c1;
	rectan r(1),r1;
	triangle t(1),t1;
	cout<<c<<"\n"<<r<<"\n"<<t<<"\n";
	setlocale(LC_ALL,"rus");
	getch();
	return 0;
}
