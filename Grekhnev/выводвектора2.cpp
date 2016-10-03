#include "stdafx.h"
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> vec(10);
	vector<int> vecc(10);
	vector<int> veccc(10);
	for (int i=0; i<vec.size(); i++)
	{
		vec[i]=i+10;
		vecc[i]=i;
		veccc[i]=vec[i]*vecc[i];
	}
	std::copy(veccc.begin(), veccc.end(), std::ostream_iterator<int>(std::cout, " "));

	
	system("pause");
	return 0;
}