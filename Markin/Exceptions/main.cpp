#include <iostream>
#include <string>

using namespace std;

int main()
{
    string i,j;
    cin >> i >> j;
    try
    {
        for (int l = 0; l<i.size(); l++)
        {
            if (i[l]<48 || i[l]>58) {throw 303;}
        }
        for (int l = 0; l<j.size(); l++)
        {
            if (j[l]<48 || j[l]>58) {throw 303;}
        }
        if (j.size() == 1 && j[0]-48 == 0) {throw 404;}
    }
    catch (int k)
    {
        cout << "Error " << k <<": Can't do this";
        return 0;
    }
    int k = 0,l,g = 0;
    for (int l = 0; l<i.size(); l++)
        k=k*10 + (i[l]-48);
    for (int l = 0; l<j.size(); l++)
        g=g*10 + (j[l]-48);
    cout << (double)(k/g);
}
