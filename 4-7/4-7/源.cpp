#include<queue>
#include<iostream>
using namespace std;
//215. 数组中的第K个最大元素
//class Solution {
//public:
//	int findKthLargest(vector<int>& nums, int k) {
//		priority_queue<int> p(nums.begin(), nums.end());
//
//		for (size_t i = 0.; i<k - 1; i++)
//		{
//			p.pop();
//		}
//		return p.top();
//	}
//};
template <class T, class Container = deque<T>>
class Queue
{
public:
	Queue(){}
	void Push(const T& x)
	{
		_con.push_back(x);
	}
	void Pop()
	{
		_con.pop_front();
	}
	T& Front()
	{
		return _con.front();
	}
	size_t Size()
	{
		return _con.size();
	}
	bool Empty()
	{
		return _con.empty();
	}
	T& Back()
	{
		return _con.back();
	}
private:
	Container _con;
};
//int main()
//{
//	Queue<int> q;
//	q.Push(1);
//	q.Push(2);
//	q.Push(3);
//	q.Push(4);
//
//	while (!q.Empty())
//	{
//		cout << q.Front() << " ";
//		q.Pop();
//	}
//	cout << endl;
//
//	return 0;
//}
template<class T>
class Greater
{
public:
	bool operator()(const T& a, const T& b)
	{
		return a > b;
	}
};
template <class T>
class Less
{
public:
	bool operator()(const T& a, const T& b)
	{
		return a < b;
	}
};
//int main()
//{
//	//Greater g;
//	//Less l;
//	//cout << g(1, 2) << endl;
//	//cout << l(1, 2) << endl;
//
//	priority_queue<int, vector<int>, Less<int>> d;
//	d.push(1);
//	d.push(3);
//	d.push(2);
//	d.push(4);
//	while (!d.empty())
//	{
//		cout << d.top() << " ";
//		d.pop();
//	}
//
//	return 0;
//}
template<class T, class Container = vector<T>>
class PriortyQueue
{
public:
	void Push(const T& val)
	{
		_con.push_back(val);
		shiftUp(_con.size() - 1);
	}
	void shiftUp(size_t child)
	{
		size_t parent = (child - 1) / 2;
		while (child > 0)
		{
			if (_con[child] > _con[parent])
			{
				swap(_con[child], _con[parent]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else{
				break;
			}
		}
	}
	void shiftDown(size_t parent)
	{
		size_t child = 2 * parent + 1;
		while (child < _con.size())
		{
			if (child + 1 < _con.size() && _con[child + 1] > _con[child])
				child++;
			if (_con[child]>_con[parent])
			{
				swap(_con[child], _con[parent]);
				parent = child;
				child = 2 * parent + 1;
			}
			else{
				break;
			}
		}
	}
	void Pop()
	{
		swap(_con[0], _con[_con.size() - 1]);
		_con.pop_back();
		shiftDown(0);
	}
	T& Top()
	{
		return _con[0];
	}
	bool Empty()
	{
		return _con.empty();
	}
private:
	Container _con;
};
int main()
{
	PriortyQueue<int> p;

	p.Push(1);
	p.Push(2);
	p.Push(3);
	p.Push(4);

	while (!p.Empty())
	{
		cout << p.Top() << " ";
		p.Pop();
	}
	cout << endl;
	return 0;
}