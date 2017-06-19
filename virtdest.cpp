#include <iostream>
#include <thread>

using namespace std;
void foo(int i)
{i++;};
class A
{
public: 
	A(){cout<<"A const";};
	virtual ~A(){cout<<"A dest";};
	
};
class B: public A
{
public: 
B(){cout<<"B const";};
virtual ~B(){cout<<"B dest";};
	virtual void x()=0;
};

class C: public B
{
public: 
	C(){cout<<"C const";};
	~C(){cout<<"C dest";};
	void x(){};
	//A a;
};

int main()
{
	
	A *ptr = new C;
	delete ptr;

	system ("pause");

	return 0;

}
