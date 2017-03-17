#include <iostream>

using namespace std;

template <typename TYPE>
void fprint(TYPE *arr, const int n){
	for (int i = 0; i < n; i++) cout << arr[i] << " ";
	cout << endl;
}

template <typename TYPE>
void fsort(TYPE *arr, int n){
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			if (arr[i] > arr[j])
                arr[i] ^= arr[j] ^= arr[i] ^= arr[j];

    /*arr[i] += arr[j];
    arr[j] = arr[i] - arr[j];
    arr[i] = arr[i] - arr[j];*/
}

int main(){
    cout << "Enter the size: ";
    int n = 10; cin >> n;

	int *arr = new int[n];
	for (int i = 0; i < n; i++) cin >> arr[i];

	cout << "\nAs is:\n";
	fprint(arr, n);
	fsort(arr, n);

	cout << "\nSorted:\n";
	fprint(arr, n);

	delete[] arr;
	return 0;
}
