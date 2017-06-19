#include <iostream>
//#include <cstdlib>
//#include <random>
using namespace std;

class SEG{
	int x,y;
public:
	void set_val(int,int);
	friend void dup(SEG&);
	void show_val();
};
void SEG::set_val(int a, int b)
{
	x=a;
	y=b;

};
void SEG::show_val()
{
	cout<<x<<" "<<y<<"\n";

};
void dup(SEG& a) {
	(a.x)*=2; (a.y)*=2;
	//return;
};
int main()
{
	SEG bloops;

	bloops.set_val(10,20);
	dup(bloops);
	bloops.show_val();
	system("pause");




	return 0;
}
