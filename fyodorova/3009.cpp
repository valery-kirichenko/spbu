// 3009.cpp: определяет точку входа для консольного приложения.
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

	  return(0);
}

