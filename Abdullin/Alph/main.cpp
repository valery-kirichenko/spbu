#include <iostream>

using namespace std;

int main()
{
    for (char a='A'; a<='Z'; a++)
    {
        cout<<a<<" ";
    }
    char a='A';
    cout<<endl;
    while (a<='Z')
    {
        cout<<a<<" ";
        a++;
    }
    a='A';
    cout<<endl;
    do
    {
       cout<<a<<" ";
        a++;
    }
    while (a<='Z');
    return 0;
}
