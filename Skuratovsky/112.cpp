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
void bubblesortif (int* arr, int size)
{


};
int main()
{
	int a[]={10,9,8,7,6,5,4,3,2,1};
	cout<<search(a, 10, 7);
	cout<<binary_search(a,10,7);
	system("pause");

	return 0;
}
