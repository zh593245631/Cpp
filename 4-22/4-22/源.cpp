#include<iostream>
#include<deque>
using namespace std;
template < class T, class Con = deque<T>>
class Stack
{
public:
	Stack()
	{}
	void Push(const T& x)
	{
		_c.push_back(x);
	}
	void Pop()
	{
		_c.pop_back();
	}
	T& Top()
	{
		return _c.back();
	}
	const T& Top()const
	{
		return _c.back();
	}
	size_t Size()const
	{
		return _c.size();
	}
	bool Empty()const
	{
		return _c.empty();
	}
private:
	Con _c;
};

void TestStack()
{
	// ���������ڵڶ���ģ���������ʹ�ò�ͬ��������Ȼ���������ɵ�stackЧ����һ���ġ�
	//Stack<int, deque<int>> s;
	//Stack<int, vector<int>> s;
	//Stack<int, list<int>> s;

	Stack<int> s;
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);
	cout << s.Size() << endl;
	cout << s.Top() << endl;
	s.Pop();
	s.Pop();
	cout << s.Size() << endl;
	cout << s.Top() << endl;
}template < class T, class Con = deque<T>>
class Queue
{
public:
	Queue(){}
	void Push(const T& x)
	{
		_c.push_back(x);
	}
	void Pop()
	{
		_c.pop_front();
	}
	T& Back()
	{
		return _c.back();
	}
	const T& Back()const
	{
		return _c.back();
	}
	T& Front()
	{
		return _c.front();
	}
	const T& Front()const
	{
		return _c.front();
	}
	size_t Size()const
	{
		return _c.size();
	}
	bool Empty()const
	{
		return _c.empty();
	}
private:
	Con _c;
};
void TestQueue()
{
	// ���������ڵڶ���ģ���������ʹ�ò�ͬ��������Ȼ���������ɵ�queueЧ����һ���ġ�
	//Queue<int, deque<int>> q;
	//Queue<int, list<int>> q;

	Queue<int> q;
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	cout << q.Size() << endl;
	cout << q.Front() << endl;
	cout << q.Back() << endl;
	q.Pop();
	q.Pop();
	cout << q.Size() << endl;
	cout << q.Front() << endl;
	cout << q.Back() << endl;
}
int main()
{
	//TestStack();
	TestQueue();
	return 0;
}

//class A{
//public:
//	int a1()
//	{
//		_a = 10;
//		return _a;
//	}
//	int a2()const
//	{
//		return _a;
//	}
//	int a3()const
//	{
//		//_a = 30;  //���� const�ĺ������ܶ������ݳ�Ա�����޸Ĳ�����
//		return _a;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	A a;
//	a.a1();
//	a.a2();
//	a.a3();
//	const A b;
//	b.a1(); //���� const�Ķ��󣬲������÷�const�ĳ�Ա����
//	b.a2();
//	b.a3();
//
//	return 0;
//}