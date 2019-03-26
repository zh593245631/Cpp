#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//class Date
//{
//public:
//	//无参构造函数
//	Date()
//	{
//		cout << 1 << endl;
//	}
//	//带参构造函数
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//		cout << 2 << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//void TestDate()
//{
//	Date d1;
//	Date d2(2019, 3, 25);
//
//	//Date d3();
//}
//int main()
//{
//
//	TestDate();
//	getchar();
//	return 0;
//}
//**************************************************************************************
//#include<assert.h>
//typedef int DataType;
//class SeqList
//{
//public:
//	SeqList(int capacity = 10)
//	{
//		_pData = (DataType*)malloc(capacity * sizeof(DataType));
//		assert(_pData);
//
//		_size = 0;
//		_capacity = capacity;
//	}
//	~SeqList()
//	{
//		if (_pData)
//		{
//			free(_pData);
//			_pData = NULL;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//private:
//	int* _pData;
//	size_t _size;
//	size_t _capacity;
//};
//*******************************************************************************************
//class Date
//{
//public:
//	Date()
//	{
//		_year = 2019;
//		_month = 3;
//		_day = 26;
//	}
//
//	Date(int year = 2019, int month = 3, int day = 26)
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
//	Date d1;
//	return 0;
//}
//*******************************************************************************************
////析构函数
//class String
//{
//public:
//	String(const char* str = "jack")
//	{
//		_str = (char*)malloc(strlen(str) + 1);
//		strcpy(_str, str);
//		cout << "String()" << endl;
//	}
//
//	~String()
//	{
//		cout << "~String()" << endl;
//		free(_str);
//	}
//private:
//	char* _str;
//};
//class Person
//{
//private:
//	String _name;
//	int _age;
//};
//
//int main()
//{
//
//	Person p;
//
//	getchar();
//	return 0;
//}
//********************************************************************************************
////运算符重载
//class Date
//{
//public:
//	Date(int year = 2019, int month = 3, int day = 26)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		return *this;
//	}
//	bool operator==(const Date& d)
//	{
//		return _year == d._year&&_month == d._month&&_day == d._day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	Date d2(2020, 3, 28);
//
//	d1 = d2;
//
//	cout << (d1 == d2) << endl;
//	getchar();
//	return 0;
//}
//**********************************************************************************************
//const成员
class Date
{
public:
	void Display()
	{
		cout << "Display ()" << endl;
		cout << "year:" << _year << endl;
		cout << "month:" << _month << endl;
		cout << "day:" << _day << endl << endl;
	}
	void Display() const
	{
		cout << "Display () const" << endl;
		cout << "year:" << _year << endl;
		cout << "month:" << _month << endl;
		cout << "day:" << _day << endl << endl;
	}
	Date* operator&()
	{
		return this;
	}
	const Date* operator&() const
	{
		return this;
	}
private:
	int _year; // 年
	int _month; // 月
	int _day; // 日
};
void Test()
{
	Date d1;
	d1.Display();

	const Date d2;
	d2.Display();

	Date& d3 = d1;

	d3.Display();
}int main(){	Test();	getchar();	return 0;}