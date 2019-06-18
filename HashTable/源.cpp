#include"hash.h"
#include"UnorderedMapSet.h"

using namespace std;

//void test()
//{
//	using namespace CLOSE;
//	HashTable<int, int> h;
//	h.insert(pair<int, int>(1, 2));
//	h.insert(pair<int, int>(1, 2));
//	h.insert(pair<int, int>(2, 2));
//	h.insert(pair<int, int>(3, 2));
//	h.insert(pair<int, int>(4, 2));
//	h.insert(pair<int, int>(5, 2));
//	h.insert(pair<int, int>(6, 2));
//	h.insert(pair<int, int>(14, 2));
//	h.Erase(4);
//	h.insert(pair<int, int>(14, 2));
//
//}
void test1()
{
	UnorderedMap<int, int> m;
	m.insert(pair<int, int>(1, 1));
	m.insert(pair<int, int>(2, 10));
	m.insert(pair<int, int>(3, 3));
	m.insert(pair<int, int>(4, 4));
	m.insert(pair<int, int>(4, 4));
	m.Erase(4);
	m.insert(pair<int, int>(4, 4));
	cout<<(*m.Find(2)).second<<endl;
	m[5] = 5;
	auto vit = m.begin();
	while (vit != m.end())
	{
		cout << (*vit).second << endl;
		++vit;
	}
}
void test2()
{
	UnorderedSet<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(9);
	s.insert(3);
	s.insert(4);
	s.insert(5);
	s.insert(7);
	s.insert(6);
	s.insert(9);
	s.insert(11);
	s.Erase(3);
	s.Find(2);

	auto vit = s.begin();
	while (vit != s.end())
	{
		cout << *vit << endl;
		++vit;
	}
}
int main()
{
	test1();
	test2();
	return 0;
}