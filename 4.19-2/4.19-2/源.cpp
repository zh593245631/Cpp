#include <vector>
#include <queue>
#include <functional> // greater算法的头文件
#include<iostream>
using namespace std;
//// priority_queue
////void TestPriorityQueue()
////{
////	// 默认情况下，创建的是大堆，其底层按照小于号比较
////	vector<int> v{ 3, 2, 7, 6, 0, 4, 1, 9, 8, 5 };
////	priority_queue<int,vector<int>> q1;
////	for (auto& e : v)
////		q1.push(e);
////	cout << q1.top() << endl;
////	// 如果要创建小堆，将第三个模板参数换成greater比较方式
////	priority_queue<int, vector<int>, greater<int>> q2(v.begin(), v.end());
////	cout << q2.top() << endl;
////}
////
////int main()
////{
////	TestPriorityQueue();
////	return 0;
////}
////如果在priority_queue中放自定义类型的数据，用户需要在自定义类型中提供> 或者< 的重载
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	bool operator<(const Date& d)const
//	{
//		return (_year < d._year) ||
//			(_year == d._year && _month < d._month) ||
//			(_year == d._year && _month == d._month && _day < d._day);
//	}
//	bool operator>(const Date& d)const
//	{
//		return (_year > d._year) ||
//			(_year == d._year && _month > d._month) ||
//			(_year == d._year && _month == d._month && _day > d._day);
//	}
//	friend ostream& operator<<(ostream& _cout, const Date& d)
//	{
//		_cout << d._year << "-" << d._month << "-" << d._day;
//		return _cout;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
////void TestPriorityQueue()
////{
////	// 大堆，需要用户在自定义类型中提供<的重载
////	priority_queue<Date> q1;
////	q1.push(Date(2018, 10, 29));
////	q1.push(Date(2018, 10, 28));
////	q1.push(Date(2018, 10, 30));
////	cout << q1.top() << endl;
////	// 如果要创建小堆，需要用户提供>的重载
////	priority_queue<Date, vector<Date>, greater<Date>> q2;
////	q2.push(Date(2018, 10, 29));
////	q2.push(Date(2018, 10, 28));
////	q2.push(Date(2018, 10, 30));
////	cout << q2.top() << endl;
////}
////int main()
////{
////	TestPriorityQueue();
////	return 0;
////}
//// 有些情况下，用户可能需要提供比较器规则
//class Less
//{
//public:
//	bool operator()(const Date* pLeft, const Date* pRight)
//	{
//		return *pLeft < *pRight;
//	}
//};
//void TestPriorityQueue()
//{
//	// 自己定制比较的规则
//	priority_queue<Date*, vector<Date*>, Less> q;
//	q.push(&Date(2018, 10, 29));
//	q.push(&Date(2018, 10, 28));
//	q.push(&Date(2018, 10, 30));
//	cout << *q.top() << endl;
//}
//
//int main()
//{
//	TestPriorityQueue();
//	return 0;
//}
//class Solution {
//public:
//	vector<int> topKFrequent(vector<int>& nums, int k) {
//
//		priority_queue<int> p(nums.begin(), nums.end());
//		int max = p.top();
//		vector<int> hash;
//		hash.resize(max + 1, 0);
//		priority_queue<int> q;
//		vector<int> result;
//
//		while (!p.empty())
//		{
//			int tmp = p.top();
//			p.pop();
//			hash[tmp]++;
//			while (tmp == p.top())
//			{
//				hash[tmp]++;
//				p.pop();
//			}
//			q.push[hash[tmp]];
//		}
//
//		for (size_t i = 0; i<k - 1; i++)
//		{
//			for (size_t j = 0; j<max + 1; j++)
//			{
//				if (q.top() == hash[j])
//					result.push_back(j);
//			}
//		}
//
//		return result;
//
//	}
//};

//int main()
//{
//	priority_queue<int> q;
//	q.push(1);
//	q.push(2);
//
//	return 0;
//}
struct Ret{
public:
	int num;
	int count;
	bool operator<(const Ret& a)const{
		return count < a.count;
	}
};

class Less{
public:
	bool operator()(const Ret& a, const Ret& b)const{
		return a.count>b.count;
	}
};

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		vector<int> a(nums);
		sort(a.begin(), a.end());
		priority_queue<Ret, vector<Ret>, Less> q;

		Ret r = { 0, 0 };

		for (size_t i = 0; i < a.size() - 1; i++)
		{
			r.count = 1;
			r.num = a[i];
			while (i < a.size() - 1 && a[i] == a[i + 1])//1 1 1 2 2 3
			{
				r.count++;
				i++;
			}
			if (k == q.size()){

				if (r.count > q.top().count){
					q.pop();
				}
				else
					continue;
			}
			q.push(r);

		}

		vector<int> result;
		result.resize(k);
		while (!q.empty())
		{
			result[--k] = q.top().num;
			q.pop();
		}
		return result;

	}
};

int main()
{
	priority_queue<Ret*,vector<Ret*>,Less> q;


	//q.push({ 1, 2 });
	//q.push({ 1, 3 });

	Solution s;
	vector<int> v;
	v.push_back(4);
	v.push_back(1);
	v.push_back(-1);
	v.push_back(2);
	v.push_back(-1);
	v.push_back(2);
	v.push_back(3);


	s.topKFrequent(v, 2);


	return 0;
}