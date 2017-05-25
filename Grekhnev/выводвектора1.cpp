#include "stdafx.h"
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> vec(10);
	for (int i=0; i<vec.size(); i++)
		vec[i]=i+10;
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));

	
	system("pause");
	return 0;
}