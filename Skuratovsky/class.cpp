#include <iostream>
using namespace std;
class Num{
	
	
public:
	int x,y;
	Num(int, int);
	~Num();
};
Num::Num(int x1, int x2)
{
	this->x=2*x1;
	this->y=2*x2;
	cout<<"Initial values: "<<x1<<" "<<x2<<endl;
	cout<<"Doubled values: "<<this->x<<" "<<this->y<<endl;
};
Num::~Num()
{
	this->x=0;
	this->y=0;
	cout<<"Values set to 0, termination"<<endl;
};
int main()
{
	Num num1(10,34);
	system("pause");






	return 0;
}
