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

class Test
{
public:
	Test()
		: _data(0)
	{
		cout << "Test():" << this << endl;
	}
	~Test()
	{
		cout << "~Test():" << this << endl;
	}

private:
	int _data;
};
int main()
{
	Test* t = new Test;
	delete t;
	cout << "--------------" << endl;
	Test* t1 = (Test*)malloc(sizeof(Test));
	free(t1);
	getchar();
	return 0;
}