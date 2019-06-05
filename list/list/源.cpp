#include<list>
#include<iostream>
#include<vector>
using namespace std;
	template<class T>
	void printList(const list<T>& l)
	{
		auto llit = l.cbegin(); 
	
		while (llit != l.cend())
		{
			cout << *llit << " ";
			llit++;
		}
		cout << endl;
	}
	//int main()
	//{
	//	list<int> l1;
	//	list<int> l2(10, 3);
	//	list<int> l3(l2.begin(), l2.end());
	//
	//	vector<int> v1(5, 5);
	//	list<int> l4(v1.begin() + 1, v1.end() - 1);
	//
	//	auto lit = l4.begin();
	//	while (lit != l4.end())
	//	{
	//		cout << *lit << " ";
	//		++lit;
	//	}
	//	cout << endl;
	//
	//	printList(l4);
	//	list<int> l5;
	//	l5.push_back(1);
	//	l5.push_back(2);
	//	l5.push_back(3);
	//	l5.push_back(4);
	//	l5.push_back(5);
	//
	//	auto l5lit = l5.rbegin();
	//	while (l5lit != l5.rend())
	//	{
	//		cout << *l5lit << " ";
	//		l5lit++;
	//	}
	//	cout << endl;
	//	return 0;
	//}
	class Date
	{
	private:
		int _year;
		int _month;
		int _day;
	public:
		Date(int year = 2019, int month = 3, int day = 31)
			:_year(year)
			, _month(month)
			, _day(day)
		{
			cout << "Date(int,int,int)" << this << endl;
		}
		Date(Date& d)
			:_year(d._year)
			, _month(d._month)
			, _day(d._day)
		{
			cout << "Date(Date& )" << this << endl;
		}
	};
	int main()
	{
		//list<int> l1;
		//l1.push_back(1);
		//l1.push_back(2);
		//l1.push_back(3);
		//l1.push_back(4);
		//l1.push_back(5);
		//printList(l1);
	
		//l1.pop_front();
		//printList(l1);
	
		//list<int> l2;
		//l2.insert(l2.begin(), 1);
		//l2.insert(l2.begin(), 3);
		//printList(l2);
		//auto lit = l2.begin();
		//l2.insert(l2.end(), 5, 10);
		//printList(l2);
		////cout << *lit << endl;
	
		//l2.insert(l2.begin(), l1.begin(), l1.end());
		//printList(l2);
		//cout << *lit << endl;
		Date d(2019,4,1);
	
	
	
	
		return 0;
	}