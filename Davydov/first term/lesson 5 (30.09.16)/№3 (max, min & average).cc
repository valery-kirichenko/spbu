#include <iostream>
#include <vector> 
#include <cstdlib>
#include <iterator> 
using namespace std;

int inspection();

int main()
{
	int min, max, s, i, n = 0, average = 0;

	setlocale(LC_ALL, "");
	cout << "Enter size of array: ";
	n = inspection();
    vector<int> Vector(n);
	if (Vector.size()!=0)
	{
		cout << "Enter your array: "<<endl;
		cout<<"Vector[0] = ";
		cin>>Vector[0];
		average = Vector[0];
		min = Vector[0];
		max = Vector[0];

		for(int i = 1; i < Vector.size(); i++) 
		{
		cout<<"Vector["<<i<<"] = ";
		cin>>Vector[i];
		average += Vector[i];
		if (Vector[i] < min) min = Vector[i];
		if (Vector[i] > max) max = Vector[i];
		}
		cout<<endl;
		cout<<"Your array"<<endl;
		copy(Vector.begin(), Vector.end(), ostream_iterator<int>(cout," ") );
		cout<<endl;
		cout<<"The biggest element = "<<max<<endl;
		cout<<"The smallest element = "<<min<<endl;
		cout<<"Arithmetical mean = "<<(double) average/n<<endl;
	}

	system("pause");
	return 0;
}

int inspection()
{
	char x[10];
	int i, n;

	scanf("%s", &x);
	for (i=0;i<strlen(x);i++)
		{
			if ((x[i]>='0')&&(x[i]<='9'))
			{
			s = x[i]-'0';
			n = n*10+s;
			}
			else
			{cout <<"count!!!"<<endl; n=0; break;}
		}
	return n;
}