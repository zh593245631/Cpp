#include<iostream>
using namespace std;
//初始化列表
//class Date
//{
//public:
//	Date(int year, int month, int day)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//class Time
//{
//public:
//	Time(int hour = 0)
//		:_hour(hour)
//	{
//		cout << "Time()" << endl;
//	}
//private:
//	int _hour;
//};
//class Date
//{
//public:
//	Date(int day)
//	{}
//private:
//	int _day;
//	Time _t;
//};
//int main()
//{
//	Date d(1);
//	getchar();
//	return 0;
//}
//********************************************************************************************
////explicit关键字
//class Date
//{
//public:
//	Date(int year)
//		: _year(year)
//	{}
//	//explicit Date(int year)
//	//	:_year(_year)
//	//{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//void TestDate()
//{
//	Date d1(2019);
//
//	d1 = 2020;
//}
//
//int main()
//{
//	TestDate();
//
//	getchar();
//	return 0;
//}
//*********************************************************************************************
//class A
//{
//public:
//	A()
//	{
//		++_scount;
//	}
//	A(const A& t)
//	{
//		++_scount;
//	}
//	static int GetCount()
//	{
//		return _scount;
//	}
//private:
//	static int _scount;
//};
//int A::_scount = 0;
//int main()
//{
//	cout << A::GetCount() << endl;
//	A a1, a2;
//	A a3(a1);
//	cout << A::GetCount() << endl;
//	getchar();
//	return 0;
//}
//********************************************************************************************
////友元
////友元函数
//class Date
//{
//	friend ostream& operator<<(ostream& _cout, const Date& d);
//	friend istream& operator>>(istream& _cin, Date& d);
//public:
//	Date(int year, int month, int day)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	//ostream& operator<<(ostream& _cout)
//	//{
//	//	_cout << _year << "-" << _month << "-" << _day;
//	//	return _cout;
//	//}
//	//istream& operator>>(istream& _cin)
//	//{
//	//	_cin >> _year;
//	//	_cin >> _month;
//	//	_cin >> _day;
//	//	return _cin;
//	//}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//ostream& operator<<(ostream& _cout, const Date& d)
//{
//	_cout << d._year << "-" << d._month << "-" << d._day;
//
//	return _cout;
//}
//istream& operator>>(istream& _cin, Date& d)
//{
//	 _cin>>d._year;
//	 _cin >> d._month;
//	 _cin >> d._day;
//
//	 return _cin;
//}
//int main()
//{
//	Date d(2017, 12, 24);
//	//d << cout;
//	//d >> cin;
//	//d << cout;
//	//d >> cin;
//	cout << d<<endl;
//	cin >> d;
//	cout << d;
//	cin >> d;
//	getchar();
//	return 0;
//}
////友元类
//class Date;
//class Time
//{
//	friend class Date;
//public:
//	Time()
//	{}
//	Time(int hour, int minute, int second)
//		:_hour(hour)
//		, _minute(minute)
//		, _second(second)
//	{}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//	void SetTimeOfDate(int hour, int minute, int second)
//	{
//		// 直接访问时间类私有的成员变量
//		_t._hour = hour;
//		_t._minute = minute;
//		_t._second = second;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};
//int main()
//{
//	Date a;
//	a.SetTimeOfDate(1, 1, 1);
//
//	getchar();
//	return 0;
//}
//*******************************************************************************************
//内部类
class A
{
private:
	static int k;
	int h;
public:
	class B
	{
	public:
		void foo(const A& a)
		{
			cout << k << endl;
			cout << a.h << endl;
		}
	};
};
int A::k = 1;

int main()
{
	A::B b;
	b.foo(A());
	getchar();
	return 0;
}
