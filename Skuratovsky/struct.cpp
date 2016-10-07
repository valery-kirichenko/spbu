#include <iostream>
using namespace std;
	struct STUDENT

{
	char first [20];
	char last [20];
	int id;
	
	
	
};
void setid (STUDENT *ptr, int value)
{ptr->id=value;
};
int main()
{



STUDENT group [10];
for (int i=0; i<10; i++)
setid(&group[i], i+1);
for (int i=0; i<10; i++)
cout<<group[i].id<<"\n";
	// your code goes here
	return 0;
}
