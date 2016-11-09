#include <iostream>
#include <cmath>

using namespace std;

class Parent {
public:
	Parent(){
		cout << "Parent no params" << endl;
	}

	Parent(int a){
		cout << "Parent + a" << endl;
	}

	Parent(int a, int b){
		cout << "Parent a + b" << endl;
	}

	~Parent(){
		cout << "Parent died" << endl;
	}
};

class Child : public Parent {
public:
	Child() : Parent(){
		cout << "Child no params" << endl;
	}

	Child(int a) : Parent(a){
		cout << "Child + a" << endl;
	}

	Child(int a, int b) : Parent(a, b){
		cout << "Child a + b" << endl;
	}

	~Child(){
		cout << "Child died" << endl;
	}
};

int main(){
	Parent o1;
	Child o2(1);
	Child o3(2, 3);

	return 0;
}
