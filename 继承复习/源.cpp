#include<iostream>
using namespace std;

//class A
//{
//public:
//	int aa()
//	{
//		return a;
//	}
//
//private:
//	int a;
//	void test()
//	{
//		cout << "A" << endl;
//	}
//};
//class B : public A
//{
//public:
//	B(){}
//	void testB()
//	{
//		//int c = a;
//		//test();
//		int c = aa();
//	}
//};
//int main()
//{
//	//B a;
//	//a.aa();
//	//a.testB();
//	B b;
//	A a = b;
//	A* pa = &b;
//	A& rb = b;
//	//B c = a;
//	B* c = (B*)&a;
//	B& cc = (B&)a;
//	return 0;
//}

//class A
//{
//private:
//	int a;
//public:
//	int b;
//	void test()
//	{
//		cout << "A" << endl;
//		cout << a << endl;
//		cout << b << endl;
//	}
//};
//
//class B :public A
//{
//private:
//	int a = 1;
//public:
//	//int b = 1;
//	B(){}	
//	void test()
//	{
//		cout << "B" << endl;
//		cout << a << endl;
//		cout << b << endl;
//	}
//};
//
//int main()
//{
//	A a;
//	B b;
//	a.test();
//	b.test();
//	return 0;
//}
////隐藏  成员函数名字相同就构成隐藏

//class A
//{
//public:
//	A() { cout << "A()" << endl; }
//	A(const A& a) { cout << "A(const A&)" << endl; }
//	A& operator=(const A& a) { cout << "operator=(const A&)" << endl; return *this; }
//	~A() { cout << "~A()" << endl; }
//};
//
//class B :public A
//{
//public:
//	B() { cout << "B()" << endl; }
//	B(const B& B):A(B) { cout << "B(const B&)" << endl; }
//	B& operator=(const B& b) { A::operator=(b); cout << "operator=(const B&)" << endl; return *this; }
//	~B() { cout << "~B()" << endl; }
//};
//
//int main()
//{
//	B a;
//	B b = a;
//	b = a;
//	//A c = a;
//	//A* d = &a;
//	//A& e = a;
//	//c = a;
//	return 0;
//}

//实现一个不能被继承的类
//c++98
class NoInherit
{
public:
	static NoInherit GetInstance()
	{
		return NoInherit();
	}
private:
	NoInherit(){}
};
//c++11
class A final
{};