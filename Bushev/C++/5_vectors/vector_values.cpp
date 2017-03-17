#include <iostream>
#include <vector>
#include <ostream>

using namespace std;

ostream& operator<<(ostream& a, vector<int> v){
	for(int i = 0; i < v.size(); i++)
		a << v[i] << " ";

	return a;
}

int vmax(vector<int> v){
	int mmax = v[0];

	for(int i = 1; i < v.size(); i++){
		mmax = max(v[i], mmax);
	}

	return mmax;
}

int vmin(vector<int> v){
	int mmin = v[0];

	for(int i = 1; i < v.size(); i++){
		mmin = min(v[i], mmin);
	}

	return mmin;
}

int vav(vector<int> v){
	int sum = 0;

	for(int i = 0; i < v.size(); i++){
		sum += v[i];
	}

	return sum / v.size();
}


int main(){
	vector<int> v(10); 

	int size;
	cout << "Enter size (min - 1, defaul - 10): " << endl;
	cin >> size;
	
	if(size > 1) v.resize(size);

	cout << "Fill in the vector: " << endl;

	for(int i = 0; i < v.size(); i++)
		cin >> v[i];

	cout << endl << v << endl;

	cout << "Max: " << vmax(v) << endl;
	cout << "Min: " << vmin(v) << endl;
	cout << "Average num: " << vav(v) << endl;

	system("pause");
	return 0;
}