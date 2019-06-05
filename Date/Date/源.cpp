#include<iostream>
using namespace std;

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
	Date(const Date& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{}
	Date& operator=(const Date& d)
	{
		if(&d != this)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	//判断闰年  普通闰年:能被4整除但不能被100整除的年份为普通闰年；
	//			世纪闰年:能被400整除的为世纪闰年。
	bool LeapYear(int year)
	{
		return (year % 400 == 0)||(year%4==0&&year%100);
	}
	//判断该月有几天
	int GetMonthDay(int year, int month)
	{
		
		if (LeapYear(year) && month == 2)
			return 29;
		else if (month == 2)
			return 28;
		else{
			if ((month % 2&&month<8)||(month%2 == 0&&month>=8))
				return 31;
			return 30;
		}

	}
	//Date operator+(int days)
	//{
	//	int Cday = days;
	//	while (1)
	//	{
	//		int Tday = GetMonthDay(_year, _month);
	//		if ((_day + Cday) > Tday)
	//		{
	//			Cday = Cday+_day - Tday;
	//			_month++;
	//			if (_month == 13){
	//				_month = 1;
	//				_year++;
	//			}
	//			_day = 0;	
	//		}
	//		else{
	//			_day += Cday;
	//			return *this;
	//		}

	//	}
	//}
	Date operator+(int days)
	{
		_day += days;
		while (_day > GetMonthDay(_year, _day))
		{
			_day -= GetMonthDay(_year, _day);
			_month++;
			if (_month == 13)
			{
				_year++;
				_month = 1;
			}
		}
		return *this;
	}
	Date operator-(int days)
	{
		_day -= days;
		while (_day < 1)
		{
			_month--;
			if (_month < 1){
				_month = 12;
				_year--;
			}
			_day += GetMonthDay(_year, _month);
		}
		return *this;
	}
	int operator-(const Date& d)
	{
		if (*this == d)
			return 0;
		Date max = *this;
		Date min = d;
		if (max < d){
			max = d;
			min = *this;
		}
		int count = 0;
		while (min < max)
		{
			min++;
			max--;
			count++;
		}
		return count;
	}
	Date& operator++()
	{
		operator+(1);
		return *this;
	}
	Date operator++(int)
	{
		Date tmp = *this;
		operator+(1);
		return tmp;
	}
	Date& operator--()
	{
		operator-(1);
		return *this;
	}
	Date operator--(int)
	{
		Date tmp = *this;
		operator-(1);
		return tmp;
	}
	bool operator>(const Date& d)const
	{
		if (_year > d._year)
			return true;
		if (_year == d._year&& _month > d._month)
			return true;
		if (_year == d._year&&_month == d._month&&_day > d._day)
			return true;
		return false;
	}
	bool operator>=(const Date& d)const
	{
		if (*this > d || *this == d)
			return true;
		return false;
	}
	bool operator<(const Date& d)const
	{
		if (*this >= d)
			return false;
		return true;
	}
	bool operator<=(const Date& d)const
	{
		if (*this > d)
			return false;
		return true;
	}
	bool operator==(const Date& d)const
	{
		return (_year == d._year&&_month == d._month&&_day == d._day);
	}
	bool operator!=(const Date& d)const
	{
		return *this == d;
	}
	void print()
	{
		cout << _year << " " << _month << " " << _day << ""<<endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d(2018, 9, 28);
	Date d1(2018, 10, 8);
	Date d2(d);
	d = d + 1;
	d1 = d1 - 9;
	cout <<(d == d2)<< endl;
	d.print();
	d1.print();
	//d++;
	//d1++;
	cout << (d1 - d) << endl;
	return 0;
}