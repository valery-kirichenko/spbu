#include <iostream>
using namespace std;

class A{int c [5];
public: A(void)
{
for (int i=0; i<5; i++)
	c[i]=i+1;
	}
bool operator +(int v) 
{
	bool good=false; 
	
	for (int i=0; i<5; i++)
	if (!c[i]%v) good=true;
	
	return good;
	}
};
int main() {
	A res();
	cout<<res+2;
	// your code goes here
	return 0;
}
