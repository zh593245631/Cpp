//#include<iostream>
//using namespace std;
//int globalVar = 1;       //���ݶ�
//static int staticGlobalVar = 1; //���ݶ�
//void Test()
//{
//	static int staticVar = 1;  //���ݶ�
//	int localVar = 1;       //ջ
//
//
//	//ջ
//	int num1[10] = { 1, 2, 3, 4 };
//	cout << sizeof(num1) << endl;
//	char char2[] = "abcd";   // "abcd"�����
//	cout << sizeof(char2) << endl;
//	char* pChar3 = "abcd";
//	cout << sizeof(pChar3) << endl;
//	int* ptr1 = (int*)malloc(sizeof (int)* 4);   //��
//	cout << sizeof(ptr1) << endl;
//	int* ptr2 = (int*)calloc(4, sizeof(int));
//	cout << sizeof(ptr2) << endl;
//	int* ptr3 = (int*)realloc(ptr2, sizeof(int)* 4);
//	cout << sizeof(ptr3) << endl;
//	free(ptr1);
//	free(ptr3);
//}
//int main()
//{
//	Test();
//	getchar();
//	return 0;
//}
//*************************************************************
//c++�ڴ����ʽ
//new/delete
//void Test()
//{
//	//��̬����һ��int���͵Ŀռ�
//	int* ptr1 = new int;
//
//	//��̬����һ��int���͵Ŀռ䲢��ʼ��Ϊ10
//	int* ptr2 = new int(10);
//
//	//��̬����10��int���͵Ŀռ�
//	int* ptr3 = new int[10];
//
//	delete ptr1;
//	delete ptr2;
//	delete[] ptr3;
//}
//
//class Test
//{
//public:
//	Test()
//		: _data(0)
//	{
//		cout << "Test():" << this << endl;
//	}
//	~Test()
//	{
//		cout << "~Test():" << this << endl;
//	}
//
//private:
//	int _data;
//};
//int main()
//{
//	Test* t = new Test;
//	delete t;
//	cout << "--------------" << endl;
//	Test* t1 = (Test*)malloc(sizeof(Test));
//	free(t1);
//	getchar();
//	return 0;
//}
//operator new / operator delete
//struct ListNode
//{
//	ListNode* _next;
//	ListNode* _prev;
//	int _data;
//	void* operator new(size_t n)
//	{
//		void* p = nullptr;
//		p = allocator<ListNode>().allocate(1);
//		cout << "memory pool allocate" << endl;
//		return p;
//	}
//	void operator delete(void* p)
//	{
//		allocator<ListNode>().deallocate((ListNode*)p, 1);
//		cout << "memory pool deallocate" << endl;
//	}
//};
//class List
//{
//private:
//	ListNode* _head;
//public:
//	List()
//	{
//		_head = new ListNode;
//		_head->_next = _head;
//		_head->_prev = _head;
//	}
//	~List()
//	{
//		cout << 111 << endl;
//		ListNode* cur = _head->_next;
//		while (cur != _head)
//		{
//			_head->_next = cur->_next;
//			delete cur;
//			cur = _head->_next;
//		}
//		delete _head;
//		_head = nullptr;
//	}
//};
//int main()
//{
//	List l;
//	List* p = new List;
//	delete p;
//	getchar();
//	return 0;
//}
//��λnew���ʽ
//class Test
//{
//public:
//	Test()
//		: _data(0)
//	{
//		cout << "Test():" << this << endl;
//	}
//	~Test()
//	{
//		cout << "~Test():" << this << endl;
//	}
//
//private:
//	int _data;
//};
//void Test1()
//{
//	// pt����ָ���ֻ��������Test������ͬ��С��һ�οռ䣬����������һ��������Ϊ���캯��û��ִ��
//	Test* pt = (Test*)malloc(sizeof(Test));
//
//	new(pt)Test; // ע�⣺���Test��Ĺ��캯���в���ʱ���˴���Ҫ����
//}


//int globalVar = 1; //������
//static int staticGlobalVar = 1;//������
//void Test()
//{
//	static int staticVar = 1; //������
//	int localVar = 1; //ջ
//
//	int num1[10] = { 1, 2, 3, 4 };//ջ
//	char char2[] = "abcd";   //���ݴ����
//	char* pChar3 = "abcd";		// ����
//	int* ptr1    = (int*)malloc(sizeof(int) * 4); //����Ŀռ��ڶ���
//	int* ptr2    = (int*)calloc(4, sizeof(int));
//	int* ptr3    = (int*)realloc(ptr2, sizeof(int) * 4);
//	
//	
//	cout << sizeof(ptr1) << endl;
//	cout << sizeof(ptr2) << endl;
//	cout << sizeof(ptr3) << endl;
//
//	free(ptr1);
//	free(ptr3);
//}
//void Test2()
//{
//	// ��̬����һ��int���͵Ŀռ�
//	int* ptr4 = new int;
//
//	// ��̬����һ��int���͵Ŀռ䲢��ʼ��Ϊ10
//	int* ptr5 = new int(10);
//
//	// ��̬����10��int���͵Ŀռ�
//	int* ptr6 = new int[3];
//
//	delete ptr4;
//	delete ptr5;
//	delete[] ptr6;
//}
//
//class TT
//{
//public:
//	TT()
//		: _data(0)
//	{
//		cout << "TT():" << this << endl;
//	}
//
//	~TT()
//	{
//		cout << "~TT():" << this << endl;
//	}
//
//private:
//	int _data;
//};
//
//void Test3()
//{
//	// ���뵥��Test���͵Ŀռ�
//	TT* p1 = (TT*)malloc(sizeof(TT));
//	free(p1);
//
//	// ����10��TT���͵Ŀռ�
//	TT* p2 = (TT*)malloc(sizeof(TT) * 10);
//	free(p2);
//}
//void Test4()
//{
//	// ���뵥��TT���͵Ķ���
//	TT* p1 = new TT;
//	delete p1;
//
//	// ����10��TT���͵Ķ���
//	TT* p2 = new TT[10];
//	delete[] p2;
//}
//
//int main()
//{
//	cout << "Test3: " << endl;
//	Test3();
//
//	cout << "Test4: " << endl;
//	Test4();
//	return 0;
//}
#include<iostream>
#include<cstddef>
using namespace std;

class Screen
{
public:
	Screen(int x) :_x(x) {};

	 void* operator new(size_t);
	 void operator delete(void*, size_t);
	~Screen() { cout << i << endl; }
private:
	Screen* next;
	static Screen* freeStore;
	static const int screenChunk;
private:
	int _x;
	static int i;
};
int Screen::i = 0;
Screen* Screen::freeStore = 0;
const int Screen::screenChunk = 24;

void* Screen::operator new(size_t size)
{
	Screen* p;
	if (!freeStore)
	{
		size_t chunk = screenChunk * size;
		freeStore = p = reinterpret_cast<Screen*>(new char[chunk]);
		for (; p != &freeStore[chunk - 1]; ++p)
		{
			p->next = p + 1;
		}
		p->next = nullptr;
	}
	p = freeStore;
	freeStore = freeStore->next;
	return p;
}

void Screen::operator delete(void* p, size_t)
{
	(static_cast<Screen*>(p))->next = freeStore;
	freeStore = static_cast<Screen*>(p);
}

int main()
{
	cout << sizeof(Screen) << endl;
	size_t const n = 100;
	Screen* p[n];

	for (int i = 0; i < n; ++i)
		p[i] = new Screen(i);

	for (int i = 0; i < 10; ++i)
		cout << p[i] << endl;
	
	delete[] p;
	return 0;
}

