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
#include<assert.h>
typedef int DataType;
class SeqList
{
public:
	SeqList(int capacity = 10)
	{
		_pData = (DataType*)malloc(capacity * sizeof(DataType));
		assert(_pData);

		_size = 0;
		_capacity = capacity;
	}
	~SeqList()
	{
		if (_pData)
		{
			free(_pData);
			_pData = NULL;
			_capacity = 0;
			_size = 0;
		}
	}
private:
	int* _pData;
	size_t _size;
	size_t _capacity;
};