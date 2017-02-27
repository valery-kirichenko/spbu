#include <iostream>
#include <iterator>

#include <map>
#include <list>
#include <queue>
#include <deque>

#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_ELEMENTS = 10;

int main(){
    srand(time(NULL));

    list<int> l;
    deque<int> d;
    queue<int> q;
    map<int, int> m;

    for(int i = 0; i < MAX_ELEMENTS; i++){
        l.push_back(rand() % 9 + i * 10 + 1);
        d.push_back(rand() % 9 + i * 10 + 1);
        q.push(rand() % 9 + i * 10 + 1);
        m[rand() % 9 + i * 10] = rand() % 9 + i * 10 + 1;

    }

    cout << "List, Deque, Queue: " << endl << endl;
	copy(l.begin(), l.end(), ostream_iterator<int>(cout, " ")); cout << endl;
	copy(d.begin(), d.end(), ostream_iterator<int>(cout, " ")); cout << endl;

	while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
	}

	cout << "\n\nMap {key, value}: \n\n";

	int cendl = 0;

	for(map<int, int>::iterator it = m.begin(); it != m.end(); ++it){
        cout << "{" << it->first << ", " << it->second << "} ";
        if(++cendl % 5 == 0) cout << endl;
	}

	cout << endl << "Reversed map: \n\n";

	for(map<int, int>::reverse_iterator it = m.rbegin(); it != m.rend(); ++it){
        cout << "{" << it->first << ", " << it->second << "} ";
        if(++cendl % 5 == 0) cout << endl;
	}

	cout << endl;
    return 0;
}
