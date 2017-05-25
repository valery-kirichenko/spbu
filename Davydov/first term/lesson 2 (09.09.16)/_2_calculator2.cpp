#include<iostream>
#include<cstdlib>
using namespace std;


int main()
{
	int a, b;
	char c;

    cout<<"Enter your first number ";
	cin>>a;
	cout<<"Enter your second number ";
	cin>>b;
	c = '+';

	switch (c)
	{
		case '+' : cout<<"a+b= "<<a+b<<endl;
	    case '-' : cout<<"a-b= "<<a-b<<endl;
		case '*' : cout<<"a*b= "<<a*b<<endl;
		case '/' : 
				   if (b==0) cout <<"Impossible to divide by zero!"<<endl;
				   else
				   {cout<<"a/b= "<<a/b<<" integer part"<<endl;
			       cout<<"The residue is "<<a%b<<endl;}
	}

	system("pause");
	return 0;
}

