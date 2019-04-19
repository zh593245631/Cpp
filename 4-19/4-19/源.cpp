#include<iostream>
using namespace std;
//class copy1
//{
//public:
//	copy1()
//	:_a(nullptr)
//	{
//		_a = new int();
//	}
//	copy1(const copy1& c)
//	{
//		_a = c._a;
//	}
//	~copy1()
//	{
//		if (_a!=nullptr)
//		delete _a;
//	}
//private:
//	int* _a;
//};
//void test1()
//{
//	copy1 c;
//	copy1 b(c);
//}
//
//class copy2
//{
//public:
//	copy2()
//		:_a(nullptr)
//	{
//		_a = new int();
//	}
//	copy2(const copy2& c)
//		:_a(nullptr)
//	{
//		_a = new int();
//		*_a = *c._a;
//	}
//	~copy2()
//	{
//		if (_a != nullptr)
//			delete _a;
//		_a = nullptr;
//	}
//private:
//	int* _a;
//};
//void test2()
//{
//	copy2 c;
//	copy2 b(c);
//}
//
//int main()
//{
//	//test1();
//	test2();
//	return 0;
//}
//int main()
//{
//	int a = 10;
//	int* aa = new int();
//	*aa = a;
//	
//	int* p ;
//	p = aa;
//
//	delete p;
//	delete aa;
//
//	return 0;
//}
int main()
{
	int a = 10;
	int* aa = new int();
	*aa = a;


	int* p = new int();
	*p = *aa;

	delete aa;
	delete p;

	return 0;
}