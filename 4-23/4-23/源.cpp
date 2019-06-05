#include<iostream>

using namespace std;

//class Person {
//public:
//	Person(){ cout << "person" << endl; }
//	 virtual ~Person() { cout << "~Person()" << endl; }
//};
//class Student : public Person {
//public:
//	Student(){ cout << "student" << endl; }
//	virtual ~Student() { cout << "~Student()" << endl; }
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
//
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
//int main()
//{
//	Test();
//	return 0;
//}
//class Car{
//public:
//	virtual void Drive(){}
//};
//// 2.override 修饰派生类虚函数强制完成重写
//class Benz :public Car {
//public:
//	virtual void Drive() override { cout << "Benz-舒适" << endl; }
//};
//int main()
//{
//	Car* benz = new Benz;
//	benz->Drive();
//	return 0;
//}
// 1.final 修饰基类的虚函数不能被派生类重写
//class Car
//{
//public:
//	virtual void Drive() final {}
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive() { cout << "Benz-舒适" << endl; }//final修饰的函数不能被重写
//};
//class Car
//{
//public:
//	virtual void Drive() final {}
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive() override{ cout << "Benz-舒适" << endl; }
//};
// 这里常考一道笔试题：sizeof(Base)是多少？
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Func2()" << endl;
//	}
//private:
//	int _b = 1;
//};
//
//int main()
//{
//	Base b;
//	cout << sizeof(Base) << endl;
//	return 0;
//}
// 针对上面的代码我们做出以下改造
// 1.我们增加一个派生类Derive去继承Base
// 2.Derive中重写Func1
// 3.Base再增加一个虚函数Func2和一个普通函数Func3
class Base
{
public:
	virtual void Func1()
	{
		cout << "Base::Func1()" << endl;
	}
	virtual void Func2()
	{
		cout << "Base::Func2()" << endl;
	}
	void Func3()
	{
		cout << "Base::Func3()" << endl;
	}
private:
	int _b = 1;
	virtual void Func4()
	{
		cout << "Base::Func4()" << endl;
	}
};
class Derive : public Base
{
public:
	virtual void Func1()override
	{
		cout << "Derive::Func1()" << endl;
	}
private:
	int _d = 2;
};
int main()
{
	//Base b;
	//Derive d;
	typedef void(*p)();
	//Base* b = new Derive;
	//auto bb = *(int*)b;
	//auto bbb = (int*)bb;
	//auto bbbb = *bbb;
	//auto bbbbb = (int*)bbbb;
	//((p)(bbbb))();
	//b->Func2();
	//b->Func1();
	//b->Func4();
	//((p)(*((int*)*(int*)b + 2)))();

	Base b;
	((p)(*((int*)*(int*)&b + 2)))();


	return 0;
}
