// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

vector<int> Multiply(vector<int> first, vector<int> second){
	vector<int> Result = vector<int>();
	for (int i = 0; i < first.size(); i++){
			Result[i] = first[i]*second[i];
	}
	return Result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	vector<int> vect = vector<int>();
	vector<int> vect2 = vector<int>();
	vector<int> MultVect = vector<int>();
	for (int i = 0; i < 10; i++){
		vect.push_back(rand()%10+1);
		vect2.push_back(rand()%10+1);
	}
	MultVect = Multiply(vect, vect2);
    cout << "Сoдержимое вектора : " ;
    copy(MultVect.begin(), MultVect.end(), std::ostream_iterator<int>(std::cout, " "));
    cout << endl;
	system("pause");
	return 0;
}

