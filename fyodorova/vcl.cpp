// vcl.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex mut;
int g=0;
void foo(int i)
{   for (i=0; i<5; i++) {
	mut.lock();
	g++;
	cout << i << " " << g << endl;
	system("pause");
	mut.unlock();}
	
}

int main()
{
	
	thread tr1(foo,0);
	thread tr2(foo,1);
	tr1.join();
	tr2.join();
	system("pause");
	return 0;
}

