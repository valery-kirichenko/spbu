#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    int n;
    cout << "Razmer massivov: ";
    cin >> n;
    vector <int> v(n);
    cout << "Perviy massiv: \n";
    for (int i = 0; i< n; i++)
        cin >> v[i];
    cout << "Vot vash massiv: ";
    copy(v.begin(), v.end(), ostream_iterator<int>(cout," "));
    cout << endl;
    vector <int> v1(n);
    cout << "Vtoroy massiv: \n";
    for (int i = 0; i<n; i++)
        cin >> v1[i];
    for (int i = 0; i<n; i++)
        v[i] = v[i]*v1[i];
    cout << "Proizvedeniye elementov pervogo i vtorogo massivov: ";
    copy(v.begin(), v.end(), ostream_iterator<int>(cout," "));
}
