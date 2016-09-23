#include<iostream>
#include<cstdlib>
using namespace std;

void max(int a, int b);

int main()
{
	

	int a, b;
	cout<<"a = ";
	cin>>a;
	cout<<"b = ";
	cin>>b;
	max(a, b);

	return 0;
}

void max (int a, int b)
{

	cout<<"a+b="<<a+b<<endl;
	system("pause");
}
