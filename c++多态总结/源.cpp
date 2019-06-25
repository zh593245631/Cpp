#include<iostream>
using namespace std;

class A
{
public:
	virtual void Fun1()
	{
		cout << "Fun1()" << endl;
	}
	virtual void Fun2()
	{
		cout << "Fun2()" << endl;
	}
	virtual void Fun3()
	{
		cout << "Fun3()" << endl;
	}

};

class B:public A
{
public:
	virtual void Fun1()
	{
		cout << "Fun1()" << endl;
	}
};
int main()
{
	A a;
	B b;
	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;

	return 0;
}