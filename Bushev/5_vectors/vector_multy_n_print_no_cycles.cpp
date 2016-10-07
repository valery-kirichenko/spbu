#include <iostream>
#include <vector>
#include <ctime>
#include <iterator>

using namespace std;

int main(){
	srand(time(NULL));
	
	vector<int> v, v2; 

	int size;
	cout << "Enter the first size: " << endl;
	cin >> size;

	v.resize(size);

	cout << "Enter the second size: " << endl;
	cin >> size;

	v2.resize(size);
	
	for(int i = 0; i < v.size(); i++) v[i] = rand() % 10 + 1;
	for(int i = 0; i < v2.size(); i++) v2[i] = rand() % 10 + 1;

	copy(v.rbegin(), v.rend(), ostream_iterator<int>(cout," ")); cout << endl;
	copy(v2.rbegin(), v2.rend(), ostream_iterator<int>(cout," ")); cout << endl;

	for(int i = 0; i < min(v.size(), v2.size()); i++){
		if(v.size() < v2.size()){
			v[i] *= v2[v2.size()-v.size()+i];
		}else{
			v[v.size()-v2.size()+i] *= v2[i];
		}
	}
	
	cout << "Result: " << endl;
	copy(v.rbegin(), v.rend(), ostream_iterator<int>(cout," ")); cout << endl;

	system("pause");
	return 0;
}