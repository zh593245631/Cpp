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
//// ֻ��������Student������������д��Person�����������������delete��������������������ܹ��ɶ�
////̬�����ܱ�֤p1��p2ָ��Ķ�����ȷ�ĵ�������������
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
//		cout << "Benz-����" << endl;
//	}
//};
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW-�ٿ�" << endl;
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
//// 2.override �����������麯��ǿ�������д
//class Benz :public Car {
//public:
//	virtual void Drive() override { cout << "Benz-����" << endl; }
//};
//int main()
//{
//	Car* benz = new Benz;
//	benz->Drive();
//	return 0;
//}
// 1.final ���λ�����麯�����ܱ���������д
//class Car
//{
//public:
//	virtual void Drive() final {}
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive() { cout << "Benz-����" << endl; }//final���εĺ������ܱ���д
//};
//class Car
//{
//public:
//	virtual void Drive() final {}
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive() override{ cout << "Benz-����" << endl; }
//};
// ���ﳣ��һ�������⣺sizeof(Base)�Ƕ��٣�
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
// �������Ĵ��������������¸���
// 1.��������һ��������Deriveȥ�̳�Base
// 2.Derive����дFunc1
// 3.Base������һ���麯��Func2��һ����ͨ����Func3
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
