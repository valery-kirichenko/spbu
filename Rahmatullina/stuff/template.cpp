#include <iostream>
using namespace std;
template<typename T>
void func(const  T * a, int b)
{
	for (int i=0;i < b;i++)
    std::cout << a[i] << " " ;
}
template<typename P>
void sort( P * a,int b)
{
	for (int j=0; j < b; j++)
	for (int i=0; i < b-1; i++)
	{
		if (a[i]>a[i+1])
		{	P tmp;
			tmp=a[i];
			a[i]=a[i+1];
			a[i+1]=tmp;
		}
    }
}
int main ()
{	
    const int t=5;
	const int p=6; 
	const int s=3;
	int ar[t]={1,2,5,4,3};
	float arr[p]={1.3 , 4.5 , 6.7 , 8.9 , 3.7 , 6.6};
	char arrr[s]={'1','8','3'};
	sort(ar,t);
	sort(arr,p);
	sort(arrr,s);
	func(arr,p);
	cout << endl;
	func(arrr,s);
	cout << endl;
	func(ar,t);
    system("pause");
	return 0;
}