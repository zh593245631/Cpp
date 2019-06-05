#include<iostream>
#include"Map.hpp"
#include"Set.hpp"
using namespace std;
int main()
{
	Map<int, int> m;
	Set<int> n;
	
	m.insert(pair<int, int>(1, 2));
	m.insert(pair<int, int>(1, 2));
	m.insert(pair<int, int>(2, 2));
	m.insert(pair<int, int>(3, 2));
	m.insert(pair<int, int>(4, 2));
	//cout << (*m.begin()).first <<"-----------"<<m.begin()->second<< endl;

	auto vit = m.end();
	while (vit != m.begin())
	{
		--vit;
		cout << vit->first << endl;
	}
	cout << "-------------------------------" << endl;
	n.insert(4);
	n.insert(3);
	n.insert(2);
	n.insert(1);
	n.insert(8);
	auto vit1 = n.begin();
	while (vit1 != n.end())
	{
		cout << *vit1 << endl;
		++vit1;
	}

	return 0;
}