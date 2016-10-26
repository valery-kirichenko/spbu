#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

mutex mut;
int g = 0;
vector <int> v(5,0);
void foo1(int id)
{
    mut.lock();
    v[2] = 1;
    if (v[2] == 2) mut.unlock();
}
void foo2(int id)
{
    mut.lock();
	v[2] = 2;
	if (v[2] == 1) mut.unlock();
}
int main()
{
    int i = 0;
    thread tr1(foo1);
    thread tr2(foo2);
	tr1.join();
	tr2.join();
	return 0;
}


