#include<iostream>
#include<cstdlib>
using namespace std;

struct list
{
public:
int inf;
list *next;
};

int counter(list *first)
{
	int number = 0;
	list *p = first;

while (p)
	{	
	p = p->next;
	number++;
	}
return number;
}
void add_list(list *first)
{
	int n;
	cout<<"Enter the number of elemets: ";
	cin>>n;

	list *p = first;
	cin>>p->inf;
	for (int i=0; i<(n-1); i++)
	{
	p->next = new list;
	p = p->next;
	cin>>p->inf;
	}
	p->next = 0;
}

void output(list *first)
{
	list *p = first;
	while (p)
		{
			cout<<p->inf<<" ";
			p = p->next;
		}
	cout<<endl;
}
void add_begin(list *first)
{
list *number = new list;
number->inf = first->inf;
number->next = first->next;
cout<<"Enter the new first element: ";
cin>>first->inf;
first->next = number;
}
void add(list *first, int possetion)
{
	list *p = first;
	list *addon = new list;

	for (int i=1; i<possetion-1; i++)
	{
		p = p->next;
	} 
	addon->next = p->next;
	p->next = addon;
	cout<<"Enter the element: ";
	cin>>addon->inf;
}
void add_end(list *first)
{
	list *p = first;
	list *addon = new list;
	int number = counter(first);

	for (int i=0; i<(number-1); i++)
	{
		p = p->next;
	} 
	p->next = addon;
	cout<<"Enter the element: ";
	cin>>addon->inf;
	addon->next = 0;
}

bool search (list *first)
{
	int element;
	cout<<"Enter the element: ";
	cin>>element;
list *p = first;
while (p)
	{
		if (p->inf == element)
			return true;
		p = p->next;
	}
return false;
}
int main()
{
	bool flug = false;
	list *p, *first = new list;
	char letter = 'q';
	int possetion;

	while (letter != '0')
	{
		cout<<"Enter 0 - to leave the programm.\n";
		cout<<"Enter 1 - to enter the list.\n";
		cout<<"Enter 2 - to show the list.\n";
		cout<<"Enter 3 - to show the number of elements.\n";
		cout<<"Enter 4 - to add element in the list.\n";
		cout<<"Enter 5 - to delete the element from the list.\n";
		cout<<"Enter 6 - to search the element in the list.\n";
		cout<<"Your choise: ";
		cin>>letter;
		system("cls");
		switch (letter)
		{
		case '0': break;
		case '1': flug = true; add_list(first);
				break;
		case '2': if (flug)output(first);
				break;
		case '3': if (flug)cout<<"Number of elements: "<<counter(first)<<endl;
				  else cout<<"Number of elements: 0"<<endl;
				break;
		case '4': 
			if (flug)
			{
				cout<<"Enter the number of position: ";
				cin>>possetion;
				if (counter(first)<1) {cout<<"Error\n"; break;}
				else if (possetion==1) add_begin(first);
				else if (possetion>=counter(first)) add_end(first);
				else if ((possetion>1)&&(possetion<counter(first)))	add(first, possetion);
			}
				else cout<<"Choose enter the list\n";
				break;
		case '5': 
			if (flug)
			{
				cout<<"Enter the number of position: ";
				cin>>possetion;
				if ((possetion<1)||(possetion>counter(first))) {cout<<"Wrong number\n";}
				else if ((possetion==1)&&(counter(first)>0)) first = first->next;
				else
				{
				list *p = first;
					for (int i=2; i<possetion; i++) p = p->next;
				list *ptr = p;
				ptr = ptr->next;
				ptr = ptr->next;
				p->next = ptr;
				}
			}
				else cout<<"Choose enter the list\n";
				break;
		case '6':
			if (flug)
			{
			if (search(first)) cout<<"This element was found.\n";
			else cout<<"Sorry, this element was not found.\n";
			} else cout<<"Choose enter the list\n";
			break;
		default: cout<<"Wrong number.\n";
		}
	}
	system("pause");
return 0;	
}