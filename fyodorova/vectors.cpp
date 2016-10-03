// vectors.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;


int main()
{
	int i;
  vector<int> v(10);
	  for (i=0; i < v.size(); i++)
	  { 
		  v[i] = rand() % 10;
	  }
	   copy( v.begin(),  
          v.end(),     
          ostream_iterator<int>(cout," ")   
        );
	   cout << endl;
  vector<int> v2(10);
   for (i=0; i < v2.size(); i++)
	  { 
		  v2[i] = rand() % 10;
	  }
	   copy( v2.begin(),  
          v2.end(),     
          ostream_iterator<int>(cout," ")   
        );
	   cout << endl;
	vector<int> v3(10);
	for (i=0; i < v.size(); i++)
	  { 
		  v3[i] = v[i] * v2[i];
	}
	 copy( v3.begin(),  
          v3.end(),     
          ostream_iterator<int>(cout," ")   
        );

	  return(0);
}



