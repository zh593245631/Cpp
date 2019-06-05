#include<iostream>
using namespace std;

//class Person {
//public:
//	virtual ~Person() { cout << "~Person()" << endl; }
//};
//class Student : public Person {
//public:
//	 virtual ~Student() { cout << "~Student()" << endl; }
//};
//// 只有派生类Student的析构函数重写了Person的析构函数，下面的delete对象调用析构函数，才能构成多
////态，才能保证p1和p2指向的对象正确的调用析构函数。
//int main()
//{
//	Person* p1 = new Person;
//	Person* p2 = new Student;
//	delete p1;
//	delete p2;
//	return 0;
//}
//抽象类
//class Car
//{
//public:
//	virtual void Drive() = 0;
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "Benz-舒适" << endl;
//	}
//};
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW-操控" << endl;
//	}
//};
//void Test()
//{
//	Car* pBenz = new Benz;
//	pBenz->Drive();
//	Car* pBMW = new BMW;
//	pBMW->Drive();
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

//class Car
//{
//public:
//	virtual void Drive() final {}
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive() { cout << "Benz-舒适" << endl; }
//};
//class Car{
//public:
//	virtual void Drive(){}
//};
//// 2.override 修饰派生类虚函数强制完成重写，如果没有重写会编译报错
//class Benz :public Car {
//public:
//	virtual void Drive() override { cout << "Benz-舒适" << endl; }
//};

// 这里常考一道笔试题：sizeof(Base)是多少？
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//private:
//	int _b = 1;
//};
//
//int main()
//{
//	Base a;
//	cout << sizeof(a) << endl;
//	return 0;
//}
//
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Base::Func2()" << endl;
//	}
//	void Func3()
//	{
//		cout << "Base::Func3()" << endl;
//	}
//private:
//	int _b = 1;
//};
//class Derive : public Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Derive::Func1()" << endl;
//	}
//private:
//	int _d = 2;
//};
//int global = 2;
//int main()
//{
//	//Base b;
//	//Derive d;
//
//	//cout << sizeof(b) << endl;
//	//cout << sizeof(d) << endl;
//
//	Derive d;
//	int tmp = 2;
//
//	int* ptr = new int;
//	*ptr = 1;
//	cout << "栈 " << &tmp << endl;
//	cout << "堆 " << ptr << endl;
//	printf("%x\n", ptr);
//	cout << "数据段 " << &global << endl;
//	//cout << "代码段 " << &Derive::Func2 << endl;
//	printf("代码段 %p\n",&Derive::Func2);
//
//	return 0;
//}//
int main()
{
	char stack_addr = 'a';
	char *a = "1234";
	char *b;
	b = (char *)malloc(5);
	b[0] = '1'; b[1] = '2'; b[2] = '3'; b[3] = '4';
	char c[] = "1234";

	printf("%x\n", (int)&stack_addr);
	printf("%x %x\n", (int)&a, (int)&a[0]);
	printf("%x %x\n", b, (int)&b[0]);
	printf("%x %x\n", (int)&c, (int)&c[0]);
}
