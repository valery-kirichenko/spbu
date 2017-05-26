#include <iostream>

using namespace std;

int main()
{
    int i,j;
    cout<<"Vvedite 2 chisla ";
    cin>>i;
    cin>>j;
    try
    {
        if (j==0) {throw 228;}
    }
    catch (int i)
    {
        cout<<"Error "<<i;
        return 0;
    }
    cout<<"Delenie = "<<i/j;

    return 0;
}
