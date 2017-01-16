#include <iostream>
using namespace std;
bool search(int* arr, int size, int val)
{
	for (int i=0; i<size; i++)
	{
		if (arr[i]=val) return true;
	}
	return false;
};
bool binary_search(int* arr, int size, int val)
{
	
		int lo=0;
		int hi=size;
		int mid;
		while (lo<=hi)
			{
				mid=(lo+hi)/2;
				if (arr[mid] == val)
         return mid;            
      else if (arr[mid] > val) 
         lo = mid+1;
      else
		 hi = mid-1;}
	return false;

};
void bubblesort(int A[], int col){
	int temp;
	for (int i = 0; i < col; i++)
	for (int j = 0; j < col - 1; j++){ 
		if (A[j] > A[j + 1]){
			temp = A[j];
			A[j] = A[j + 1];
			A[j + 1] = temp; 
		}
	}

};
void insertion_sort (int arr[], int length){
	 	int j, temp;
		
	for (int i = 0; i < length; i++){
		j = i;
		
		while (j > 0 && arr[j] < arr[j-1]){
			  temp = arr[j];
			  arr[j] = arr[j-1];
			  arr[j-1] = temp;
			  j--;
			  }
		}
};
void selectionSort(int arr[], int n) {
      int i, j, minIndex, tmp;    
      for (i = 0; i < n - 1; i++) {
            minIndex = i;
            for (j = i + 1; j < n; j++)
                  if (arr[j] < arr[minIndex])
                        minIndex = j;
            if (minIndex != i) {
                  tmp = arr[i];
                  arr[i] = arr[minIndex];
                  arr[minIndex] = tmp;
            }
      }
};
int main()
{
	int a[]={10,9,8,7,6,5,4,3,2,1};
	cout<<search(a, 10, 7);
	cout<<binary_search(a,10,7);
	system("pause");

	return 0;
}
