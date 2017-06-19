#include<iostream>
#include<cstdlib>
#include<string>
#include<cstring>
using namespace std;

class list
{
public:
int element;
list *next;
int size;
list() {this->next = NULL; size = 0;}
void add(int x)
	{
		if (size == 0) {this->element = x; size++; return;} 
	list *ptr = this;
	for (int i=1; i<this->size; i++)
		{ptr = ptr->next;}
	list *p = new list;
	ptr->next = p;
	p->element = x;
	p->next = NULL;
	this->size++;
	}
void show()
	{
	list *p = this;
	if (this->size)
		{
		while (p != NULL)
			{
			cout<<p->element<<" ";
			p = p->next;
			}
		cout<<endl;
		}
	}
void readline()
	{
	int x;

	cin>>x;
	while (x)
		{
			this->add(x);
			cin>>x;
		}
	}
void proof()
	{
	int min = 0;
	list *p = this;

	while (p != NULL)
			{
				
				if (p->element < 0) {min = p->element; break;}
			p = p->next;
			}
	

	while (p != NULL)
			{
				
				if ((p->element < 0)&&(p->element > min)) min = p->element;
			p = p->next;
			}
	if (min != 0) cout<<"The biggest negative element is: "<<min<<endl;
	else cout<<"There is not these numbers.\n";
	
	}
};

int main()
{
	char x = 'q';
	list expression;

	cout<<"Welcome to the programm \'\Queue\'\ "<<endl;
	while (x!='0')
	{
		cout<<"----------------------------------------------------------------"<<endl;
		cout<<"Chose the operation from list below.\n";
		cout<<"Enter 0 - to leave the programm.\n";
		cout<<"Enter 1 - to enter the queue.\n";
		cout<<"Enter 2 - to show the queue.\n";
		cout<<"Enter 3 - to find the biggest negative number.\n";
		cout<<"Your choice: ";
		cin>>x;
		system("cls");
		switch(x)
		{
		case '0' : break;
		case '1' : expression.readline(); break;
		case '2' : if (!expression.size) cout<<"The queue is empty.\n"; else {cout<<"Your queue:\n"; expression.show();} break;
		case '3' : if (!expression.size) cout<<"The queue is empty.\n"; else {expression.proof();} break; 
		default : cout<<"Wrong number.\n";
		}
	}

	system("pause");
	return 0;
}
