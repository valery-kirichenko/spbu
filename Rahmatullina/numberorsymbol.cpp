// ConsoleApplication5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include<conio.h>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{	
	
	int n=0;
	int k=0;
	char a='A';
	cout << "enter string" << endl;
	while(a != '\r')
	 {
       a = _getche();
	   if(a == '0' || a =='1'|| a == '2' || a == '3' || a == '4' || a == '5' || a == '6' || a == '7' || a == '8' || a == '9') k++;
	   else n++;
	    } 
	if (k>0 && n==0) {
		      cout << "You entered numbers" << endl;
			  	system("pause");
				return 0;
	          }
	if (n>0 && k==0) cout << "you enter symbols" << endl;
	else cout << "You entered sumbols and numbers";
	system("pause");
    return 0;
}

