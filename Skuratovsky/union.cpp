#include <iostream>
#include <string>
using namespace std;

	typedef struct
	{
		int id;
		union
		{
			struct {char fn[20];};
			struct {char ls[20];};
			struct {int pp;};
		};
		
		
	}
_employee;

void setid (_employee *t, int val)
{
	t->id = val;
	
	
};


int main() {

	_employee st, lt, ad;
setid(&st, 5);
	// your code goes here
	return 0;
}
