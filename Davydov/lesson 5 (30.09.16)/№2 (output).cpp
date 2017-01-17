#include "stdafx.h"
#include<iostream> 
#include<vector>
#include<iterator>
#include<cstdlib>
using namespace std; 
 
int main()
{
    vector<int> vec1(10), vec2(10);
    
    for (int i = 0; i < 10; i++)
    {
    	vec1[i] = rand() % 10;
    	cout<<vec1[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < 10; i++) 
	{
    	vec2[i] = rand() % 10;
    	cout<<vec2[i]<<" ";
    	vec1[i] *= vec2[i];
    }
    cout<<endl;
    
    copy(vec1.begin(), vec1.end(), ostream_iterator<int>(cout, " " ) ) ;
 	cout<<endl;
 	
    system("pause");
    return 0;
}
