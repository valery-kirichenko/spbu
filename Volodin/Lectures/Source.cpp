#include <iostream>
#include <vector>

using namespace std;

class Seg{
public: 
	int x1, y1, x2, y2;
	void set(int, int, int, int);
	Seg(int a, int b, int c, int d);
	Seg(){}
};
void Seg::set(int _x1, int _y1, int _x2, int _y2){
	x1 = _x1; 
	x2 = _x2;
	y1 = _y1;
	y2 = _y2;
}
Seg::Seg(int a, int b, int c, int d){
	set(a, b, c, d);
}

class C{
	int a, b;
public:
	void out(){
		cout << "a: " << this->a << "  b: " << this->b << endl;
	}
	C(int a, int b):a(a), b(b){
		this->a *= 2; this->b *= 2;
		cout << "Constructor done\n";
		out();
	}
	~C(){
		cout << "Destructor done\n";
		out();
	}

};


int main(){
	int a, b; cin >> a >> b;
	cout << "a: " << a << "  b: " << b << endl;
	C c(a, b);

}