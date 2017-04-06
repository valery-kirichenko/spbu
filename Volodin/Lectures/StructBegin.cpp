#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Man {
	string fname;
	string lname;
	int age;
};

ostream& operator<<(ostream &a, struct Man man) {
	a << man.fname << " " << man.lname << ", " << man.age;
	return a;
}

int main() {
	int n; cin >> n;
	vector <Man> man(n);

	for (int i = 0; i < 5; i++) {
		cout << "First name: ";
		cin >> man[i].fname;
		cout << "Last name: ";
		cin >> man[i].lname;
		cout << "Age: ";
		cin >> man[i].age;
	}

	cout << endl;

	for (int i = 0; i < 5; i++)	
		cout << man[i] << endl;
}