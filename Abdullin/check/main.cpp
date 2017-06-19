#include <iostream>
#include <string>
using namespace std;

int main()
{
    string j;
    cout<<"Vvedite chislo ";
    cin>>j;
    try {
    for (int i =0; i<j.size (); i++)
    {
        if (j[i]<48 || j[i]>58) {throw 228;}

    }
    }
    catch (int i)
    {
        cout<<"Simvol "<<i;
        return 0;
    }

    cout<<"Chislo ";

    return 0;
}
