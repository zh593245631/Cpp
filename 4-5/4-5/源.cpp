#include<iostream>
#include<deque>
#include<vector>
using namespace std;
//template <calss T,class Ref, class Ptr>
//class DequeItertor
//{
//public:
//	Ref operator*()
//	{
//		return *cur;
//	}
//	DequeItertor& operator++()
//	{
//		cur++;
//		if (cur == last)
//		{
//			node++;
//			first = *node;
//			last = first + bufferLen;
//			cur = first;
//		}
//		return cur;
//	}
//private:
//	T* _frist;
//	T* _last;
//	T* _cur;
//	T** _node;
//};
//template <class T>
//class Deque
//{
//public:
//	iterator begin()
//	{
//		return _start;
//	}
//	iterator end()
//	{
//		return _finish;
//	}
//private:
//	iterator _start;
//	iterator _finish;
//	T** map;
//};
//int main()
//{
//	deque<int> d;
//
//	d.push_back(1);
//	d.push_back(2);
//	d.push_back(3);
//	d.push_back(4);
//	d.push_front(3);
//	d.push_front(2);
//	d.push_front(1);
//	d.push_front(0);
//	
//	auto vit = d.begin();
//	while (vit != d.end())
//	{
//		cout << *vit << " ";
//		vit++;
//	}
//	cout << endl;
//
//
//	return 0;
//}
// 5 8 9 1 2
//栈的压出 弹出序列
#include<stack>
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		size_t psz = pushV.size();
		size_t popsz = popV.size();

		if (psz != popsz)
			return false;
		stack<int> s;
		size_t pushIndex = 0;
		size_t popIndex = 0;
		while (pushIndex<psz)
		{
			s.push(pushV[pushIndex++]);
			while (!s.empty() && s.top() == popV[popIndex])
			{
				s.pop();
				popIndex++;
			}
		}
		return s.empty();
	}
};