#include<list>
#include<iostream>
#include<vector>
using namespace std;
//int main()
//{
//	list<int> l1;
//	list<int> l2(2, 100);
//	list<int> l3(l2.begin(), l2.end());
//	list<int> l4(l3);
//
//	int arr[] = { 1, 2, 3, 4, 5 }; 
//	list<int> l5(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	auto it = l5.begin();
//	while (it != l5.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//	for (auto& e : l5)
//		cout << e << " ";
//	cout << endl;
//	return 0;
//}
//list iterator的使用
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
//	list<int> l(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	//正向迭代器打印
//	auto it = l.begin();
//	while (it != l.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//	//正向const迭代器打印
//	auto vit = l.cbegin();
//	while (vit != l.cend())
//	{
//		cout << *vit << " ";
//		vit++;
//	}
//	cout << endl;
//	//反向迭代器打印
//	auto rit = l.rbegin();
//	while (rit != l.rend())
//	{
//		cout << *rit << " ";
//		rit++;
//	}
//	cout << endl;
//	//返向const迭代器
//	auto rvit = l.crbegin();
//	while (rvit != l.crend())
//	{
//		cout << *rvit << " ";
//		rvit++;
//	}
//	cout << endl;
//
//}
//list capacity
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6 };
//	list<int> l(arr, arr + sizeof(arr) / sizeof(arr[0]));
//
//	cout << l.size() << endl;
//	if (l.empty())
//		cout << "空链表" << endl;
//	else{
//		for (auto& e : l)
//			cout << e << " ";
//		cout << endl;
//	}
//	return 0;
//}
//list element access
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6 };
//	list<int> l1(arr, arr + sizeof(arr) / sizeof(arr[0]));
//
//	for (auto& e : l1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	l1.front() = 10;
//	l1.back() = 10;
//	for (auto& e : l1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	const list<int> l2(arr, arr + sizeof(arr) / sizeof(arr[0]));
//
//	//int& ccc = l2.front();
//	const int& ca = l2.front();
//	return 0;
//}
//list modifiers
void printList(list<int>& l)
{
	for (auto& e : l)
	{
		cout << e << " ";
	}
	cout << endl;
}
//push_back/pop_back/push_front/pop_front
void test1()
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_front(0);
	printList(l);
	//删除尾节点和头节点
	l.pop_back();
	l.pop_front();
	printList(l);
}
//emplace_back/emplace_front/emplace
class Date
{
	int _year;
	int _month;
	int _day;
public:
	Date(int year = 2019, int month = 4, int day = 9)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << this << endl;
	}
	Date(const Date& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		cout << "const date" << endl;
	}
};
void test2()
{
	list<Date> l;
	Date d(2019, 4, 10);
	l.push_back(d);
	l.emplace_back(2019, 4.11);
	l.emplace_front(2019, 4, 9);
	
}
void test3()
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	//获取链表第二个节点
	auto pos = ++l.begin();
	cout << *pos << endl;

	//在pos前插入值为4的元素
	l.insert(pos, 4);
	printList(l);

	//在pos前插入5个值为5的元素
	l.insert(pos, 5, 5);
	printList(l);

	//在pos前插入[]中的元素
	vector<int> v{ 7, 8, 9 };
	l.insert(pos,v.begin(), v.end());
	printList(l);

	//删除pos位置上的元素
	l.erase(pos);
	printList(l);

	//删除list中[]的元素
	l.erase(l.begin(), l.end());
	printList(l);
}
//resize/swap/clear
void test4()
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	printList(l);

	l.resize(10);
	printList(l);

	l.resize(20, 2);
	printList(l);

	l.resize(1);
	printList(l);

	vector<int> v{ 4, 5, 6 };
	list<int> l1(v.begin(), v.end());
	printList(l1);

	l1.swap(l);
	printList(l);
	printList(l1);

	l1.clear();
	cout << l1.size() << endl;
}
int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}