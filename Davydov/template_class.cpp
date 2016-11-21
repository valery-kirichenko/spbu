#include "stdafx.h"
#include<iostream>
#include<cstdlib>
using namespace std;

template <typename T>
	class list 
	{
	public:
		int size;
		T element;
		list *next;
		
		list()
		{
			size = 0;
			next = NULL;
		}
		void add()
		{
			list *ptr = this;
			for (int i=1; i<=size; i++)
				{
					ptr = ptr->next;
				}
			cout<<"Enter the element: ";
			cin>>ptr->element;
			list *newlist  = new list <int>;
			ptr->next = newlist;
			newlist->next = NULL;
			size++;
		}
		void show()
		{
			list *ptr = this;
			while(ptr->next != NULL)
			{
				cout<<ptr->element<<" ";
				ptr = ptr->next;
			}
			cout<<endl;
		}
		void erase()
		{
			list *ptr = this;
			ptr = ptr->next;
			this->element = ptr->element;
			this->next = ptr->next;
		}
	};

int main()
{
	list <int> mylist;
	char x = 'q';

	while (x!='0')
	{
		cout<<"Enter 0 - to leave the programm\n";
		cout<<"Enter 1 - add element to the list\n";
		cout<<"Enter 2 - show the list\n";
		cout<<"Enter 3 - erase thirst element\n";
		cout<<"Your choice: ";
		cin>>x;
		system("cls");
		switch(x)
		{
		case '0' : break;
		case '1' : mylist.add();
					break;
		case '2' : mylist.show();
					break;
		case '3' : mylist.erase();
					break;
		}
	}
	system("pause");
	return 0;
}

