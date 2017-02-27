#include <iostream>
#include <string>

using namespace std;

struct PEOPLE{
	string fname;
	string lname;
	int age;
};

ostream& operator<<(ostream &a, struct PEOPLE people){
	a << people.fname << " " << people.lname << ", " << people.age;
	return a;
}

int main(){
	struct PEOPLE people[5];

	for(int i = 0; i < 5; i++){
		cout << "Fname: ";
		cin >> people[i].fname;
		cout << "Lname: ";
		cin >> people[i].lname;
		cout << "Age: ";
		cin >> people[i].age;
	}

	cout << endl;

	for(int i = 0; i < 5; i++)	cout << people[i] << endl;
	system("pause");

	return 0;
}