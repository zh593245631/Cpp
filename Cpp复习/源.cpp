#include<iostream>
using namespace std;

//int main()
//{
//	int a = 10;
//	int b = 20;
//	int& c = a;
//	cout << c << endl;
//	c = b;
//	cout << c << endl;
//	return 0;
//}

//int main()
//{
//	int* a = new int(10);
//	char* b = new char(10);
//
//	return 0;
//}

//typedef void (*p)(int);
//int main()
//{
//	cout << sizeof(p) << endl;
//	return 0;
//}

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
	void Fun3()
	{
		cout << "Fun3()" << endl;
	}
};

class B :public A
{
public:
	virtual void Fun1()
	{
		cout << "Fun1()" << endl;
	}
	void Fun3()
	{
		cout << "Fun3()" << endl;
	}
};
int main()
{
	A a;
	B b;
	return 0;
}
