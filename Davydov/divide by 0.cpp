#include<iostream>
#include<cstdlib>
using namespace std;


int main()
{
	int a, b;
	
	cout<<"a = ";
	cin>>a;
	cout<<"b = ";
	cin>>b;
	try
	{if (b == 0) throw 1;
	 else 
		{
			cout<<"a / b = "<<a/b<<endl;
		}
	}
	catch (int c)
	{
		cout<<"You can not divide by 0"<<endl;
	}

 
	system("pause");
	return 0;
}

