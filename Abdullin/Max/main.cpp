#include <iostream>

using namespace std;

int Max (int a, int b)
    {
        if (a>b) cout<<"Max "<<a<<endl;
        else cout<<"Max "<<b<<endl;
    }

int main()
{
    cout << "Vvedite 2 chisla ";
    int a,b;
    cin>>a>>b;
    Max(a,b);
    return 0;
}
