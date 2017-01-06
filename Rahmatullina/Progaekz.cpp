// Progaekz.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
void show (int b[],int n){
		for (int i=0;i<n;i++)
		cout  <<  b[i] << " ";
		cout << endl;
	}
void bubblesort(int * b, int n){
	for (int i=0;i<n;i++) // сортировка по возрастанию
			for (int j=0;j<(n-1);j++)
				if (b[j] > b[j+1]){
					int temp = b[j];
					b[j]=b[j+1];
					b[j+1]=temp;
				}//close if
		show(b,n);
}
	void quicksort(int *b,int l,int r){
		int p = b[1 + (r - l)/2];
		int i = l;
		int j = r;
	    while(i<=j){ 
			while (b[i] < p) i++;
			while (b[j] > p) j--;
			if (i<=j){
				swap(b[i],b[j]);
				 i++;
				 j--;
				}
		}
		if (i < r )quicksort(b,i,r);
		if (j > l)quicksort(b,l,j);
}
	void insertsort(int * a, int n){
		for (int i=1;i<n;i++){
		int x = a[i];
		for (int j=i-1;j>=0 && a[j]>x;j--){
			a[j+1] = a[j];
				a[j]=x;
			}
		}


	}
	void choicesort(int * a, int n ){
		for (int i=0;i<n;i++){
			int x = a[i];
			int k = i;
			for (int j=i+1;j<n;j++)
				if (a[j] < x) {
					k = j;
					x = a[j];
				}
            a[k] = a[i];
			a[i] = x;
		}
	}
	void linesearch(int * b, int n){
		int max=b[0];
		for (int i=0;i<n;i++)
			if (b[i] > max ) max = b[i];
		 cout << " the biggest element is " << max << endl;
		 
	}
	void binsearch(int * a, int n){
		choicesort(a,n);
		int val;
		cout << "Enter the element you want to find " << endl;
		cin >> val;
		int first = 0;
		int last = n-1;
		while(first < last){
		int mid = (first + last) /2 ;
		val <= a[mid] ? last = mid : first = mid +1;
		}
		if (a[last] == val) cout << " YES!!! " << endl;
		else cout << " NO! " << endl;
	}
int _tmain(int argc, _TCHAR* argv[])
{
	
	int n ;
	cout << "Enter N " << endl;
	cin >> n;
	int * a = new int [n];
	cout << "Enter n elements of massive which you need to sort " << endl;
	for (int i=0;i<n;i++)
	cin >> a[i];
	cout << "Massive : " << endl;
	show(a,n);
	int k;
	cout << "Press 1 - to  bubblesort " << endl
		 << "Press 2 - to quicksort "  << endl
		 << "Press 3 - to insertsort " << endl
		 << "Press 4 - to choicesort " << endl 
		 << "Press 5 - to find the biggest element (linesearch) " << endl
		 << "Press 6 - to  search an element " << endl;
	cin >> k;
	switch(k) {
	case 1 : {
			bubblesort(a,n);
			break;
	}//close case 1
	case 2 : {
		quicksort(a,0,n-1);
		show(a,n);
		break;
	}//close case 2
	case 3 : {
		insertsort(a,n);
		show(a,n);
		break;
			 }
	case 4 : {
		choicesort(a,n);
		show(a,n);
		break;
			 }
	case 5 : {
		linesearch(a,n);
		break;
			 }
	case 6 : {
		binsearch(a,n);
		break;
			 }
}// close switch
	system("pause" );

	return 0;
}

