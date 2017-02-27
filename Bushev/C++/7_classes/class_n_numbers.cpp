#include <iostream>

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

class Numbers{
public: 
	int a, b;

	Numbers(int &a, int &b){
		this->a = a * 2;
		this->b = b * 2;

		cout << "C: a = " << this->a << "&b = " << this->b << endl;
	}

	~Numbers(){
		this->a = 0;
		this->b = 0;
		
		cout << "D: a = " << this->a << "&b = " << this->b << endl;
	}
};

int main(){
	int a, b;
	cout << "Enter 2 nums: "; cin >> a;
	cout << " "; cin >> b;
	cout << endl;

	Numbers *mC = new Numbers(a, b);
	delete mC;

	system("pause");

	return 0;
}