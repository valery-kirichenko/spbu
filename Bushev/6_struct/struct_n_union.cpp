#include <iostream>
#include <string>

using namespace std;

typedef struct PEOPLE{
	int id;

	union{
		struct{
			string fn;
			string ls;
			int pp[10];
		};
	};
}_employer;

ostream& operator<<(ostream &a, _employer people){
	a << "ID: #" << people.id << ", ";

	switch(people.id){
		case 1: {
			a << people.fn;
			break;
		}case 2:{
			a << people.ls;
			break;
		}case 3:{
			a << endl;
			for(int i = 0; i < 10; i++) a << people.pp[i] << " ";
			break;
		}default:{
			a << "incorrect union";
			break;
		}
	}

	return a;
}

int main(){
	int id = 0;

	_employer people[3];

	people[0].id = ++id;
	people[0].fn = "Student #1";

	people[1].id = ++id;
	people[1].ls = "Math";

	people[2].id = ++id;

	for(int i = 0; i < 10; i++)
		people[2].pp[i] = i+7;

	for(int i = 0; i < 3; i++)	cout << people[i] << endl;
	
	system("pause");
	return 0;
}