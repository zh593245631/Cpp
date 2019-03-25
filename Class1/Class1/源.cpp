//类和对象1
#include<iostream>
using namespace std;
//类的作用域
//class Person
//{
//public:
//	void PrintPersonInfo();
//private:
//	char _name[20];
//	char _gender[3];
//	int _age;
//};
//void Person::PrintPersonInfo()
//{
//	cout << _name << " "<<_gender << ""<<_age << endl;
//}
//int main()
//{
//	Person p;
//	p.PrintPersonInfo();
//	getchar();
//	return 0;
//}
//********************************************************************************
//class A
//{
//public:
//	void PrintA()
//	{
//		  cout << _a << endl;
//	}
//private:
//	char _a;
//};
//class A1
//{
//public:
//	void f1(){}
//private:
//	int _a;
//};
//class A2
//{
//public:
//	void f2(){}
//};
//class A3
//{};
//int main()
//{
//	cout << sizeof(A1) << endl; //4
//	cout << sizeof(A2) << endl; //1
//	cout << sizeof(A3) << endl; //1
//
//	getchar();
//	return 0;
//}
//******************************************************************************
//this指针
//class Date
//{
//public:
//	void Display()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	void SetDate(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1, d2;
//	d1.SetDate(2019, 3, 25);
//	d2.SetDate(2020, 3, 25);
//	d1.Display();
//	d2.Display();
//
//	getchar();
//	return 0;
//}
//*********************************************************************************
class A
{
public:
	void PrintA()
	{
		cout << _a << endl;
	}

	void Show()
	{
		cout << "Show()" << endl;
	}
private:
	int _a;
};
int main()
{
	A* p = NULL;
	p->PrintA(); 
	p->Show();

	getchar();
	return 0;
}