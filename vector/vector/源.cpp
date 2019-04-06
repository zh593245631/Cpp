#include<iostream>
#include<vector>
using namespace std;
void PrintVector(const vector<int>& v)
{
	auto vit = v.cbegin();
	while (vit != v.end())
	{
		cout << *vit << " ";
		vit++;
	}
	cout << endl;
}
//int main()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//
//	PrintVector(v);
//
//	//使用迭代器进行修改
//	auto vit = v.begin();
//	while (vit != v.end())
//	{
//		*vit *= 2;
//		vit++;
//	}
//	PrintVector(v);
//	return 0;
//}
//vector空间增长问题
//int main()
//{
//	vector<int> v;
//	size_t sz = v.capacity();
//	//v.reserve(100);
//	//for (size_t i = 0; i < 100; i++)
//	//{
//	//	v.push_back(1);
//	//	if (sz != v.capacity())
//	//	{
//	//		sz = v.capacity();
//	//		cout << sz << endl;
//	//	}
//	//}
//	v.resize(10);
//	cout << v.capacity() << endl;
//	cout << v.size() << endl;
//	v.resize(5, 10);
//	cout << v.capacity() << endl;
//	cout << v.size() << endl;
//	v.resize(12);
//	cout << v.capacity() << endl;
//	cout << v.size() << endl;
//	return 0;
//}
//增删查改
//int main()
//{
//	int a[] = { 1, 2, 3, 4 };
//	vector<int> v(a, a + sizeof(a) / sizeof(a[0]));
//
//	//auto vit = v.cbegin();
//	//while (vit != v.cend())
//	//{
//	//	cout << *vit << " ";
//	//	vit++;
//	//}
//	//cout << endl;
//	//v.pop_back();
//	//v.pop_back();
//	//PrintVector(v);
//
//	auto pos = find(v.begin(), v.end(), 3);
//	v.insert(pos, 2);
//	PrintVector(v);
//
//	//迭代器失效
//	//v.erase(pos);
//	//PrintVector(v);
//	return 0;
//}
//insert/erase导致的迭代器失效
//int main()
//{
//	int a[] = { 1, 2, 3, 4 };
//	vector<int> v(a, a + sizeof(a) / sizeof(a[0]));
//
//	auto pos = find(v.begin(), v.end(), 3);
//	//v.erase(pos);
//	//cout << *pos << endl;//非法访问
//
//	/*pos = find(v.begin(), v.end(), 2);*/
//	v.insert(pos, 2);
//	PrintVector(v);
//	//cout << *pos << endl;
//	return 0;
//}
//int main()
//{
//	int a[] = { 1, 2, 3, 4 };
//	vector<int> v(a, a + sizeof(a) / sizeof(a[0]));
//
//	auto vit = v.begin();
//	while (vit != v.end())
//	{
//		if (*vit % 2 == 0)
//			vit = v.erase(vit);
//		else
//			vit++;
//	}
//	PrintVector(v);
//	return 0;
//}