#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> v;
	for (size_t i = 0; i < 10; i++)
	{
		v.push_back(1);
	}
	v.resize(5);
	for (size_t i = 0; i < v.size(); i++)
		cout << v[i];
	cout << endl;
	v.resize(20, 100);
	for (size_t i = 0; i < v.size(); i++)
		cout << v[i]<<" ";
	cout << endl;
	v.resize(21);
	for (size_t i = 0; i < v.size(); i++)
		cout << v[i]<<" ";
	cout << endl;

	return 0;
}