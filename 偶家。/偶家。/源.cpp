#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	while (getline(cin, s))
	{
		size_t pos = s.rfind(' ');
		cout << s.size() - pos - 1 << endl;
	}
	return 0;
}