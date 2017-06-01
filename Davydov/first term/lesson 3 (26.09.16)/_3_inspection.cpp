#include<iostream>
#include<cstdlib>
using namespace std;


int main()
{
	char x;
	
	cin>>x;
	if ((x<='9')&&(x>='0')) cout<<"You entered a count"<<endl;
	else cout<<"You entered a letter"<<endl;
 
	system("pause");
	return 0;
}

