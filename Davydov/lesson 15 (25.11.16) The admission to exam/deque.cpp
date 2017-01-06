#include<iostream>
#include<cstdlib>
using namespace std;


struct list
{
public:
int line;
list *next;
list *prev;
};
bool input(list *first, list *last)
{
	int n, i=1;
	list *ptr;
	cout<<"Enter the number of elements: ";
	cin>>n;
	if (n<2) {cout<<"\nToo small number.\n\n"; return false;}
cout<<i<<" element = ";
cin>>first->line;
list *p = first;
for (i=2; i<(n); i++)
	{
	ptr = p;
	p->next = new list;
	p=p->next;
	p->prev=ptr;
	cout<<i<<" element = ";
	cin>>p->line;
	}
	p->next = last;
	last->prev = p;
	cout<<i<<" element = ";
	cin>>last->line;
	return true;
}

int length(list *first, list *last)
{
	int count=0;
	list *p = first;

while (p)
	{
	p=p->next;
	count++;
	}
return count;
}
void show(list *first, list *last)
{
	list *p = first;
while (p)
	{
	cout<<p->line<<" ";
	p=p->next;
	}
cout<<endl;
}
void show_reverse(list *first, list *last)
{
	list *p = last;
while (p)
	{
	cout<<p->line<<" ";
	p=p->prev;
	}
cout<<endl;
}

void add_begin(list *first, list *last)
{
list *ptr = first;
ptr = ptr->next;
list *addon = new list;
addon->line = first->line;
first->next = addon;
addon->prev = first;
addon->next = ptr;
ptr->prev = addon;
cout<<"Enter your element: ";
cin>>first->line;
}
void add_end(list *first, list *last)
{
list *ptr = last;
ptr = ptr->prev;
list *addon = new list;
addon->line = last->line;
last->prev = addon;
addon->next = last;
addon->prev = ptr;
ptr->next = addon;
cout<<"Enter your element: ";
cin>>last->line;
}
void add (list *first, list *last)
{
	int position;
	cout<<"Enter the number of position: ";
	cin>>position;

	if (position<0) {cout<<"\nWrong number.\n\n"; return;}
	if ((position==1)) {add_begin(first, last); return;}
	if (position>length(first, last)) {add_end(first, last); return;}
	{
		list *p = first;
		list *ptr, *addon = new list;

		for (int i=2; i<position; i++)
		{
		p = p->next;
		}
		ptr = p;
		ptr=ptr->next;
		p->next = addon;
		addon->prev = p;
		addon->next = ptr;
		ptr->prev = addon;
		cout<<"Enter your element: ";
		cin>>addon->line;
	}
}

void remove_begin (list *first, list *last)
{
list *p;
p = first;
p = p->next;
first->line = p->line;
first->next = p->next;
p = p->next;
p->prev = first;
}
void remove_end (list *first, list *last)
{
list *p;
p = last;
p = p->prev;
last->line = p->line;
last->prev = p->prev;
p = p->prev;
p->next = last;
}
void remove (list *first, list *last)
{
int position;
cout<<"Enter the number of position: ";
cin>>position;
if (length(first, last)==2) {cout<<"\nThe lenth of list is too small number.\n\n"; return;}
if (position<1) {cout<<"\nToo small number.\n\n"; return;}
if (position == 1) {remove_begin (first, last); return;}
if (position == length(first, last)) {remove_end(first, last); return;}
if (position>length(first, last)) {cout<<"\nToo big number.\n\n"; return;}
list *p = first;
for (int i=2; i<position; i++)
{p = p->next;}
list *ptr = p;
ptr = ptr->next;
ptr = ptr->next;
ptr->prev = p;
p->next = ptr;
}

int search_begin(list *first, list *last)
{
	int element, leng;
	cout<<"Enter the element: ";
	cin>>element;
	leng = length(first, last);
	list *p = first;
	for (int i=1; i<=leng; i++)
	{
		if (p->line == element) return i;
		p = p->next;
	}
	return 0;
}
int search_end(list *first, list *last)
{
	int element, leng;
	cout<<"Enter the element: ";
	cin>>element;
	leng = length(first, last);
	list *p = last;
	for (int i=1; i<=leng; i++)
	{
		if (p->line == element) return i;
		p = p->prev;
	}
	return 0;
}
void search_center(list *first, list *last)
{
	int i, element, leng = length(first, last)/2;
	cout<<"Enter the element: ";
	cin>>element;
	list *begin = first;
	list *end = last;
	for (i=1; i<=leng; i++)
	{
		if (begin->line == element) {cout<<"The position of this element is: "<<i<<" from the beginning.\n"; return;}
		begin = begin->next;
		if (end->line == element) {cout<<"The position of this element is: "<<i<<" from the end.\n"; return;}
		end = end->prev;
	}
	if (length(first, last)%2) {if (begin->line == element) cout<<"The position of this element is: "<<i<<" from both sides.\n"; return;}
	cout<<"This element was not found.\n";
	return;
}

int main()
{
	list *first = new list;
	list *last = new list;
	first->next=last;
	first->prev=NULL;
	last->next=NULL;
	last->prev=first;
	char x, y;
	bool flug = false;
	int number;

	do
	{
		cout<<"Enter 0 - to leave the programm.\n";
		cout<<"Enter 1 - to enter the list.\n";
		cout<<"Enter 2 - to show length of the list.\n";
		cout<<"Enter 3 - to show the list.\n";
		cout<<"Enter 4 - to show the list in reverse order.\n";
		cout<<"Enter 5 - to insert the element.\n";
		cout<<"Enter 6 - to remove the element.\n";
		cout<<"Enter 7 - to search the element.\n";
		cout<<"-------------------------------------------------------\n";
		cout<<"Your choice: ";
		cin>>x;
		system("cls");
		cout<<"_______________________________________________________\n";
		cout<<"                     Attention.\n";
		cout<<"The numbering of elements is carried out from the unit.\n";
		cout<<"_______________________________________________________\n";
		switch(x)
		{
		case '0': break;
		case '1': flug = input(first, last); break;
		case '2': if (flug) cout<<"The length of list is: "<<length(first, last)<<endl; break;
		case '3': if (flug) show(first, last); break;
		case '4': if (flug) show_reverse(first, last); break;
		case '5': if (flug) add(first, last); break;
		case '6': if (flug) remove(first, last); break;
		case '7': if (flug) 
			{
		system("cls");
			do {
		cout<<"_______________________________________________________\n";
		cout<<"                     Attention.\n";
		cout<<"The numbering of elements is carried out from the unit.\n";
		cout<<"_______________________________________________________\n";
		cout<<"Choose the algorithm of search.\n";
		cout<<"Enter 0 - to leave this menu.\n";
		cout<<"Enter 1 - to search from beginning to end.\n";
		cout<<"Enter 2 - to search from end to beginning.\n";
		cout<<"Enter 3 - to search from beginning and end to center of list.\n";
		cout<<"Your choice: ";
		cin>>y;
		system("cls");
			switch(y)
					{
				case '0': break;
				case '1': number = search_begin(first, last);
						  if (number) 
						  cout<<"The position of this element is: "<<number<<endl; 
						  else cout<<"This element was not found.\n";
						  break;
				case '2': number = search_end(first, last);
						  if (number) 
						  cout<<"The position of this element is: "<<number<<endl; 
						  else cout<<"This element was not found.\n";
						  break;
				case '3': search_center(first, last);
						  break;
				default: cout<<"Wrong number."<<endl;
					}
				} while(y!='0');
			}
		}
	}while(x!='0');

	system("pause");
	return 0;
}
