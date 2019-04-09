#include<iostream>
#include<list>
using namespace std;
void test1()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l(arr, arr + sizeof(arr) / sizeof(arr[0]));

	auto it = l.begin();
	while (it != l.end())
	{
		//erase()����ִ�к�itָ��Ľڵ��ѱ�ɾ�������it��Ч������һ��ʹ��itʱ�������ȸ��丳ֵ
		l.erase(it);
		it++;
	}
}
void test2()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l(arr, arr + sizeof(arr) / sizeof(arr[0]));

	auto it = l.begin();
	while (it != l.end())
	{
		it = l.erase(it);
		it++;
	}
}
int main()
{
	//test1();
	test2();
	return 0;
}