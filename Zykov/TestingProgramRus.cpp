// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	int empty;
	std::cout << "Привет, мир!\n\nВведите любое число, чтобы закрыть окно.\n";
	std::cin >> empty;
	return 0;
}

