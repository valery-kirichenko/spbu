// ConsoleApplication15.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include<queue>
#include<list>
#include<map>
#include<deque>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	queue<int>que;
	deque<int>dec;
	list<int>list;
	map<int,int>map;
	for (int i=0;i!=10;i++){
		que.push(i+1);
		dec.push_back(i+2);
		list.push_front(i+3);
	    map.insert( pair<int,int> (i,i*2) );
	};
	cout << "queue= "  ;
	while(!que.empty()){cout << que.front()<<" ";que.pop();}
	cout <<endl << "deque= " ;
    while(!dec.empty()){cout << dec.front()<<" ";dec.pop_front();}
    cout << endl <<"list= " ;
    while(!list.empty()){cout << list.front()<<" ";list.pop_front();}
	cout << endl << "map= " ;
	for (auto i=map.begin();i!=map.end();i++)
	cout << i->first << "_" << i->second << " ";
	system("pause");
    return 0;
}

