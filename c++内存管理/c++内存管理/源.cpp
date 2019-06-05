#include<iostream>
using namespace std;
//int globalVar = 1;       //数据段
//static int staticGlobalVar = 1; //数据段
//void Test()
//{
//	static int staticVar = 1;  //数据段
//	int localVar = 1;       //栈
//
//
//	//栈
//	int num1[10] = { 1, 2, 3, 4 };
//	cout << sizeof(num1) << endl;
//	char char2[] = "abcd";   // "abcd"代码段
//	cout << sizeof(char2) << endl;
//	char* pChar3 = "abcd";
//	cout << sizeof(pChar3) << endl;
//	int* ptr1 = (int*)malloc(sizeof (int)* 4);   //堆
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
//c++内存管理方式
//new/delete
//void Test()
//{
//	//动态申请一个int类型的空间
//	int* ptr1 = new int;
//
//	//动态申请一个int类型的空间并初始化为10
//	int* ptr2 = new int(10);
//
//	//动态申请10个int类型的空间
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
//定位new表达式
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
//	// pt现在指向的只不过是与Test对象相同大小的一段空间，还不能算是一个对象，因为构造函数没有执行
//	Test* pt = (Test*)malloc(sizeof(Test));
//
//	new(pt)Test; // 注意：如果Test类的构造函数有参数时，此处需要传参
//}


int globalVar = 1; //数据区
static int staticGlobalVar = 1;//数据区
void Test()
{
	static int staticVar = 1; //数据区
	int localVar = 1; //栈

	int num1[10] = { 1, 2, 3, 4 };//栈
	char char2[] = "abcd";   //内容代码段
	char* pChar3 = "abcd";		// 。。
	int* ptr1    = (int*)malloc(sizeof(int) * 4); //申请的空间在堆上
	int* ptr2    = (int*)calloc(4, sizeof(int));
	int* ptr3    = (int*)realloc(ptr2, sizeof(int) * 4);
	
	
	cout << sizeof(ptr1) << endl;
	cout << sizeof(ptr2) << endl;
	cout << sizeof(ptr3) << endl;

	free(ptr1);
	free(ptr3);
}void Test2()
{
	// 动态申请一个int类型的空间
	int* ptr4 = new int;

	// 动态申请一个int类型的空间并初始化为10
	int* ptr5 = new int(10);

	// 动态申请10个int类型的空间
	int* ptr6 = new int[3];

	delete ptr4;
	delete ptr5;
	delete[] ptr6;
}
class TT
{
public:
	TT()
		: _data(0)
	{
		cout << "TT():" << this << endl;
	}

	~TT()
	{
		cout << "~TT():" << this << endl;
	}

private:
	int _data;
};

void Test3()
{
	// 申请单个Test类型的空间
	TT* p1 = (TT*)malloc(sizeof(TT));
	free(p1);

	// 申请10个TT类型的空间
	TT* p2 = (TT*)malloc(sizeof(TT) * 10);
	free(p2);
}
void Test4()
{
	// 申请单个TT类型的对象
	TT* p1 = new TT;
	delete p1;

	// 申请10个TT类型的对象
	TT* p2 = new TT[10];
	delete[] p2;
}

int main()
{
	cout << "Test3: " << endl;
	Test3();

	cout << "Test4: " << endl;
	Test4();
	return 0;
}
