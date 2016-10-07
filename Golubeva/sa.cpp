#include "stdafx.h"
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
	int b;
	int max,min,s;
	cout << "What is the size of your massive? \n";
	cin >> b;
	vector <int>  v (b);
	cout << "Enter your massive: \n";
	for (int i=0; i<v.size(); i++)
	{
		cin >> v[i];
		s+=v[i];
	}
	max=v[0];
	min=v[0];

	for (int i=0; i<v.size(); i++)
	{
		if (v[i]>max)
			max=v[i];
		if (v[i]<min)
			min=v[i];
	}
	cout << "Maximum of your massive is: " << max << endl;
	cout << "Minimum of your massive is: " << min << endl;
	cout << "Arithmetical mean is: " << s/(b-1) << endl;

	int a;
	cin >> a;
	return 0;
}