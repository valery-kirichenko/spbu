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
		//template <typename T>
		void add()
		{
			list *ptr = this;
			for (int i=1; i<=size; i++)
				{
					ptr = ptr->next;
				}
			cout<<"Enter the element: ";
			cin>>ptr->element;
			list *newlist  = new list <T>;
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
	list <int> intlist;
	list <char> charlist;
	list <double> doublelist;
	char x;
	char y = 'q';

	while (y!='0')
	{
		x = 'q';
		cout<<"Enter 0 - to leave the programm\n";
		cout<<"Enter 1 - to int\n";
		cout<<"Enter 2 - to char\n";
		cout<<"Enter 3 - to double\n";
		cout<<"Your choice: ";
		cin>>y;
		system("cls");
		switch (y)
		{
		case '0' : break;
		case '1' :
			while (x!='0')
			{
			cout<<"Enter 0 - to leave menu of INT\n";
			cout<<"Enter 1 - add element to the list\n";
			cout<<"Enter 2 - show the list\n";
			cout<<"Enter 3 - erase thirst element\n";
			cout<<"Your choice: ";
			cin>>x;
			system("cls");
				switch(x)
				{
				case '0' : break;
				case '1' : intlist.add();
							break;
				case '2' : intlist.show();
							break;
				case '3' : intlist.erase();
							break;
				}
			}		
			break;
		case '2' :
			while (x!='0')
			{
			cout<<"Enter 0 - to leave menu of CHAR\n";
			cout<<"Enter 1 - add element to the list\n";
			cout<<"Enter 2 - show the list\n";
			cout<<"Enter 3 - erase thirst element\n";
			cout<<"Your choice: ";
			cin>>x;
			system("cls");
				switch(x)
				{
				case '0' : break;
				case '1' : charlist.add();
							break;
				case '2' : charlist.show();
							break;
				case '3' : charlist.erase();
							break;
				}
			}		
			break;
		case '3' :
			while (x!='0')
			{
			cout<<"Enter 0 - to leave menu of DOUBLE\n";
			cout<<"Enter 1 - add element to the list\n";
			cout<<"Enter 2 - show the list\n";
			cout<<"Enter 3 - erase thirst element\n";
			cout<<"Your choice: ";
			cin>>x;
			system("cls");
				switch(x)
				{
				case '0' : break;
				case '1' : doublelist.add();
							break;
				case '2' : doublelist.show();
							break;
				case '3' : doublelist.erase();
							break;
				}
			}		
				break;
		default : cout<<"Wrong number.\n";
		}
	}
	system("pause");
	return 0;
}

