#include<iostream>
#include<cstdlib>
using namespace std;


int main()
{
	int a, b;
	char c;

    cout<<"Enter your first number ";
	cin>>a;
	cout<<"Enter your operation ";
	cin>>c;
	cout<<"Enter your second number ";
	cin>>b;

	switch (c)
	{
		case '+' : cout<<"a+b= "<<a+b<<endl;
	               break;
	    case '-' : cout<<"a-b= "<<a-b<<endl;
			       break;
		case '*' : cout<<"a*b= "<<a*b<<endl;
			       break;
		case '/' : cout<<"a/b= "<<a/b<<" integer part"<<endl;
			       cout<<"The residue is "<<a%b<<endl;
				   break;
	}

	system("pause");
	return 0;
}
