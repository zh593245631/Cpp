#include<iostream>

using namespace std;

class Caa
{
public:
	Caa()
	{
		cout << "Caa()" << endl;
	}
	Caa(const Caa& a)
	{
		cout << "Caa(const Caa& )" << endl;
	}

	Caa& operator=(const Caa & a)
	{
		cout << "operator=" << endl;
		return *this;
	}
};

int main()
{
	Caa a;
	Caa b(a);
	//a c = b;
	a = b;

	return 0;
}