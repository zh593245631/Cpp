#include<iostream>
using namespace std;

namespace zzh
{
	template<class T>
	struct ListNode
	{
		ListNode(const T& val = T())
		:_pPre(nullptr)
		, _pNext(nullptr)
		, _val(val)
		{}

		ListNode<T>* _pPre;
		ListNode<T>* _pNext;
		T _val;
	};

	template<class T,class Ref, class Ptr>
	class ListIterator
	{
		typedef ListNode<T>* PNode;
		typedef ListIterator<T, Ref, Ptr> Self;
	public:
		ListIterator(PNode pNode = nullptr)
			:_pNode(pNode)
		{}
		ListIterator(const Self& l)
			:_pNode(l._pNode)
		{}

		T& operator*()
		{
			return _pNode->_val;
		}

		T* operator->()
		{
			return &(operator*());
		}

		Self& operator++()
		{
			_pNode = _pNode->_pNext;
			return *this;
		}

		Self& operator++(int)
		{
			Self temp(*this);
			_pNode = _pNode->_pNext;

			return temp;
		}

		Self& operator--()
		{
			_pNode = _pNode->_pPre;
			return *this;
		}

		Self& operator--(int)
		{
			Self temp(*this);
			_pNode = _pNode->_pPre;

			return temp;
		}

		bool operator!=(const Self& l)
		{
			return _pNode != l._pNode;
		}

		bool operator==(const Self& l)
		{
			return _pNode == l._pNode;
		}

		PNode _pNode;
	};

	//list的返乡迭代器
	template<class T, class Ref, class Ptr, class Iterator>
	class ListReverseIterator
	{
		typedef ListReverseIterator<T, Ref, Ptr, Iterator> Self;
	public:
		ListReverseIterator(const Iterator& it)
			:_it(it)
		{}

		ListReverseIterator(const Self& s)
			:_it(s._it)
		{}

		Ref operator*()
		{
			Iterator temp = _it;
			return *(--temp);
		}

		Ptr operator->()
		{
			return &(operator*());
		}

		Self& operator++()
		{
			--_it;
			return *this;
		}

		Self operator++(int)
		{
			Self temp(_it);
			--_it;
			return temp;
		}

		Self& operator--()
		{
			++_it;
			return *this;
		}

		Self operator--(int)
		{
			Self temp(_it);
			++_it;
			return temp;
		}

		bool operator==(const Self& s)
		{
			return _it == s._it;
		}

		bool operator!=(const Self& s)
		{
			return _it != s._it;
		}

	private:
		Iterator _it;
	};

	template<class T>
	class List
	{
		typedef ListNode<T> Node;
		typedef Node* PNode;
	public:
		typedef ListIterator<T, T&, T*> Iterator;
		typedef ListIterator<T, const T&, const T&> ConstIterator;
		typedef ListReverseIterator<T, T&, T*, Iterator> ReverseIterator;
		typedef ListReverseIterator<T, const T&, const T*,ConstIterator> ConstReverseIterator;
	public:

		List()
		{
			CreateHead();
		}

		List(int n, const T& value = T())
		{
			CreateHead();
			for (int i = 0; i < n; ++i)
				PushBack(value);
		}

		template <class Iterator>
		List(Iterator first, Iterator last)
		{
			CreateHead();
			while (first != last)
			{
				PushBack(*first);
				++first;
			}
		}

		List(const List<T>& l)
		{
			CreateHead();

			List<T> temp(l.CBegin(), l.CEnd());
			this->Swap(temp);
		}

		List<T>& operator=(const List<T>& l)
		{
			if (this != &l)
			{
				List<T> temp(l);
				this->Swap(temp);
			}

			return *this;
		}

		~List()
		{
			Clear();
			delete _pHead;
			_pHead = nullptr;
		}

		//List Iterator
		Iterator Begin()
		{
			return Iterator(_pHead->_pNext);
		}

		Iterator End()
		{
			return Iterator(_pHead);
		}

		ReverseIterator RBegin()
		{
			return ReverseIterator(End());
		}

		ReverseIterator REnd()
		{
			return ReverseIterator(Begin());
		}

		ConstIterator CBegin()const
		{
			return ConstIterator(_pHead->_pNext);
		}

		ConstIterator CEnd() const
		{
			return ConstIterator(_pHead);
		}

		ConstReverseIterator CRBegin()const
		{
			return ConstReverseIterator(CEnd());
		}

		ConstReverseIterator CREnd()const
		{
			return ConstReverseIterator(CBegin());
		}

		//List Capacity

		size_t Size()const
		{
			size_t count = 0;
			PNode pCur = _pHead->_pNext;
			while (pCur != _pHead)
			{
				++count;
				pCur = pCur->_pNext;
			}

			return count;
		}

		bool Empty()const
		{
			return _pHead->_pNext == _pHead;
		}

		void ReSize(size_t newSize, const T& val = T())
		{
			size_t oldSize = Size();
			if (newSize < oldSize)
			{
				for (size_t i = newSize; i < oldSize; ++i)
					PopBack();
			}
			else{
				for (size_t i = oldSize; i < newSize; i++)
					PushBack(val);
			}
		}

		//list access
		T& Front()
		{
			return _pHead->_pNext->_val;
		}

		const T& Front()const
		{
			return _pHead->_pNext->_val;
		}

		T& Back()
		{
			return _pHead->_pPre->_val;
		}

		const T& Back()const
		{
			return _pHead->_pPre->_val;
		}

		//list modify
		void PushBack(const T& val)
		{
			PNode pNewNode = new Node(val);

			//先插上
			pNewNode->_pPre = _pHead->_pPre;
			pNewNode->_pNext = _pHead;
			//在连接剩余的指针
			_pHead->_pPre = pNewNode;
			pNewNode->_pPre->_pNext = pNewNode;
		}

		void PopBack()
		{
			PNode pDel = _pHead->_pPre;

			if (pDel != _pHead)
			{
				_pHead->_pPre = pDel->_pPre;
				pDel->_pPre->_pNext = _pHead;
				delete pDel;
			}
		}

		void PushFront(const T& val)
		{
			PNode pNewNode = new Node(val);

			pNewNode->_pPre = _pHead;
			pNewNode->_pNext = _pHead->_pNext;

			_pHead->_pNext->_pPre = pNewNode;
			_pHead->_pNext = pNewNode;
		}

		void PopFront()
		{
			PNode pDel = _pHead->_pNext;

			if (pDel != _pHead)
			{
				_pHead->_pNext = pDel->_pNext;
				pDel->_pNext->_pPre = _pHead;
				delete pDel;
			}
		}

		Iterator Insert(Iterator pos, const T& val)
		{
			PNode pNewNode = new Node(val);
			PNode pCur = pos._pNode;

			pNewNode->_pPre = pCur->_pPre;
			pNewNode->_pNext = pCur;

			pCur->_pPre->_pNext = pNewNode;
			pCur->_pPre = pNewNode;

			return Iterator(pNewNode);
		}

		Iterator Erase(Iterator pos)
		{
			PNode pDel = pos._pNode;
			PNode pRet = pDel->_pNext;

			pDel->_pPre->_pNext = pRet;
			pRet->_pPre = pDel->_pPre;
			delete pDel;
			return Iterator(pRet);
		}

		void Clear()
		{
			PNode pCur = _pHead->_pNext;
			while (pCur != _pHead)
			{
				_pHead->_pNext = pCur->_pNext;
				delete pCur;
				pCur = _pHead->_pNext;
			}
			_pHead->_pNext = _pHead;
			_pHead->_pPre = _pHead;
		}

		void Swap(List<T>& l)
		{
			swap(_pHead, l._pHead);
		}
	private:
		void CreateHead()
		{
			_pHead = new Node;
			_pHead->_pPre = _pHead;
			_pHead->_pNext = _pHead;
		}
	private:
		PNode _pHead;
	};
}
using namespace zzh;
//正向打印链表
template<class T>
void PrintList(List<T>& l)
{
	auto it = l.Begin();
	while (it != l.End())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
//反向打印链表
template<class T>
void PrintListReverse(const List<T>& l)
{
	auto rvit = l.CRBegin();
	while (rvit != l.CREnd())
	{
		cout << *rvit << " ";
		rvit++;
	}

	cout << endl;
}

void test1()
{
	List<int> l1;
	List<int> l2(10, 5);
	PrintList(l2);

	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	List<int> l3(arr, arr + sizeof(arr) / sizeof(arr[0]));
	PrintList(l3);

	List<int> l4(l3);
	PrintList(l4);

	l1 = l4;
	PrintList(l1);
	PrintListReverse(l1);

}

//pushback//popback/pushfront/popfront
void test2()
{
	List<int> l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	PrintList(l);

	l.PopBack();
	l.PopBack();
	PrintList(l);

	l.PopBack();
	cout << l.Size() << endl;

	l.PushFront(1);
	l.PushFront(2);
	l.PushFront(3);
	PrintList(l);

	l.PopFront();
	l.PopFront();
	PrintList(l);

	l.PopFront();
	cout << l.Size() << endl;

}
void test3()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	List<int> l(arr, arr + sizeof(arr) / sizeof(arr[0]));

	auto pos = l.Begin();
	l.Insert(pos, 0);
	PrintList(l);

	++pos;
	l.Insert(pos, 3);
	PrintList(l);
	cout << *pos << endl;

	l.Erase(l.Begin());
	l.Erase(pos);
	PrintList(l);

	cout << *pos << endl;

	auto it = l.Begin(); 
	while (it != l.End())
	{
		it = l.Erase(it);
	}
	cout << l.Size() << endl;
}
void test4()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	List<int> l1(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << l1.Size() << endl;
	PrintList(l1);

	l1.ReSize(10, 6);
	cout << l1.Size() << endl;
	PrintList(l1);

	l1.ReSize(4);
	cout << l1.Size() << endl;
	PrintList(l1);

	List<int> l2(arr, arr + sizeof(arr) / sizeof(arr[0]));
	PrintList(l1);
	PrintList(l2);

	l1.Swap(l2);
	PrintList(l1);
	PrintList(l2);

	l2.Clear();
	cout << l2.Size() << endl;


}
int main()
{
	//test1();
	//test2();
	//test3();
	test4();	
	return 0;
}