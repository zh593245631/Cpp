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
//������
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
//	virtual void Drive() { cout << "Benz-����" << endl; }
//};
//class Car{
//public:
//	virtual void Drive(){}
//};
//// 2.override �����������麯��ǿ�������д�����û����д����뱨��
//class Benz :public Car {
//public:
//	virtual void Drive() override { cout << "Benz-����" << endl; }
//};

// ���ﳣ��һ�������⣺sizeof(Base)�Ƕ��٣�
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
//	cout << "ջ " << &tmp << endl;
//	cout << "�� " << ptr << endl;
//	printf("%x\n", ptr);
//	cout << "���ݶ� " << &global << endl;
//	//cout << "����� " << &Derive::Func2 << endl;
//	printf("����� %p\n",&Derive::Func2);
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
