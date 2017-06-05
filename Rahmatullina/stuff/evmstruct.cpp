// ConsoleApplication12.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
 struct telephone
{ 
  char surname[10];
  char number[10];
  int day;
  int month;
  int year;
  float tarif;
  float begin;
  float end;
	};
int _tmain(int argc, _TCHAR* argv[])

{telephone t;
t.day = 5;
 
system("pause");
return 0;
}

