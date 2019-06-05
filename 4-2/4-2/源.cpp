#include<iostream>
using namespace std;
template <class T>
struct ListNode
{
	ListNode(const T& val = T())
	:_prev(nullptr)
	, _next(nullptr)
	, _val(val)
	{}

	ListNode<T>* _next;
	ListNode<T>* _prev;
	T _val;
};
template <class T>
struct ListIterator
{
	typedef ListNode<T>* pNode;
	pNode _node;

	ListIterator(pNode node)
		:_node(node)
	{}

	ListIterator& operator++()
	{
		_node = _node->_next;

		return *this;
	}
	ListIterator& operator++(int)
	{
		ListIterator tmp(*this);
		_node = _node->_next;

		return tmp;
	}
	ListIterator& operator--()
	{
		_node = _node->_prev;

		return *this;
	}
	ListIterator& operator--(int)
	{
		ListIterator tmp(*this);
		_node = _node->_prev;

		return tmp;
	}
	T& operator*()
	{
		return _node->_val;
	}
	bool operator!=(const ListIterator& it)
	{
		return _node != it._node;
	}
	bool operator==(const ListIterator& it)
	{
		return _node == it._node;
	}

};
template<class T>
class List
{
	typedef ListNode<T> Node;
	typedef ListNode<T>* pNode;
	typedef ListIterator<T> iterator;
public:
	List(const T& val = T())
		:_head(new ListNode<T>(val))
	{
		_head->_next = _head;
		_head->_prev = _head;
	}
	//Î²²å
	void PushBack(const T& val)
	{
		pNode pNewNode = new Node(val);

		pNewNode->_next = _head;
		pNewNode->_prev = _head->_prev;

		_head->_prev = pNewNode;
		pNewNode->_prev->_next = pNewNode;

	}
	void insert(iterator pos, const T& val)
	{
		pNode newNode = new Node(val);
		pNode cur = pos._node;
		
		newNode->_prev = cur->_prev;
		newNode->_next = cur;

		cur->_prev->_next = newNode;
		cur->_prev = newNode;

	}
	iterator Begin()
	{
		return iterator(_head->_next);
	}
	iterator End()
	{
		return iterator(_head);
	}
private:
	pNode _head;
};
int main()
{
	List<int> l;

	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);

	auto vit = l.Begin(); 

	while (vit != l.End())
	{
		cout << *vit<< " ";
		vit++;
	}
	cout << endl;


	return 0;
}