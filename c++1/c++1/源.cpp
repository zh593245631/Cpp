#include<iostream>
using namespace std;

//***********************************************************************************************************
////�����ռ�
//namespace N1
//{
//	int a = 1;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//}
//namespace N2
//{
//	int a = 2;
//	int b = 3;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//	namespace N3
//	{
//		int c = 4;
//		int d = 5;
//		int Sub(int left, int right)
//		{
//			return left - right;
//		}
//	}
//}
//namespace N1
//{
//	int Mul(int left, int right)
//	{
//		return left*right;
//	}
//}
////�����ռ��ʹ��
//using namespace N2::N3;
//int main()
//{
//	cout << N1::a << endl;
//	cout << N2::a << endl;
//	cout << "N1::a*N2::a = "<<N1::Mul(N1::a, N2::a) << endl;
//	cout << c << endl;
//	getchar();
//	return 0;
//}
//**************************************************************************************************************
////c++�������
//int main()
//{
//	int a;
//	cout << "hello world" << endl;
//	cin >> a;
//	cout << a << endl;
//
//	cin >> a;
//	return 0;
//}
//***********************************************************************************************************
////ȱʡ��������
////1.ȫȱʡ
//void TestFunc1(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//
//}
////2.��ȱʡ
//void TestFunc2(int a, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//
//}
//int main()
//{
//	cout << "TestFunc1: "<<endl;
//	TestFunc1();
//	cout << "TestFunc2: " << endl;
//	TestFunc2(1);
//	getchar();
//	return 0;
//}
//*************************************************************************************************************
////��������
//int Add(int left, int right)
//{
//	return left + right;
//}
//double Add(double left, double right)
//{
//	return left + right;
//}
//long Add(long left, long right)
//{
//	return left + right;
//}
//int main()
//{
//	Add(10, 10);
//	Add(0.1111,0.1111 );
//	Add(10L, 20L);
//
//	return 0;
//}
//***********************************************************************************************************
////����
////1. �����ڶ���ʱ�����ʼ��
////2. һ�����������ж������
////3. ����һ������һ��ʵ�壬�ٲ�����������ʵ��
//void TestRef()
//{
//	int a = 10;
//	int& ra = a;
//
//	cout << &a << endl;
//	cout << &ra << endl;
//
//	cout << ra << endl;
//}
//void TestConstRef()
//{
//	const int a = 10;
//	const int& ra = a;
//	const int& b = 10;
//	double d = 12.34;
//	const int& rd = (int)d;
//}
//void Swap(int& left, int& right)
//{
//	left = left^right;
//	right = left^right;
//	left = left^right;
//}
//int& TestRefReturn(int& a)
//{
//	a += 10;
//	return a;
//}
//
//int& Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//int Add2(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	TestRef();
//	TestConstRef();
//	Swap(a, b);
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//
//	int& ret = Add(1, 2);
//	Add(3, 4);
//	cout << "Add(1,2) is : " << ret << endl;
//
//	int ret2 = Add2(1, 2);
//	Add2(3, 4);
//	cout << "Add2(1,2) is : " << ret2 << endl;
//
//	getchar();
//	return 0;
//}
//��ֵ��������Ч�ʱȽ�
//#include<time.h>
//struct A
//{
//	int a[10000];
//};
//
//void TestFunc1(A a)
//{}
//void TestFunc2(A& a)
//{}
//
//
//void TestRefAndvalue()
//{
//	A a;
//
//	//ֵ����
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//	//���ô���
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//
//	cout << "ֵ���ݣ�" << end1 - begin1 << endl;
//	cout << "���ô��ݣ�" << end2 - begin2 << endl;
//
//}
//
//int main()
//{
//
//	for (int i = 0; i < 10; ++i)
//		TestRefAndvalue();
//	getchar();
//	return 0;
//}
//*************************************************************************************************************
////��������
//inline int Add(int left, int right)
//{
//	return left + right;
//}
//int main()
//{
//	int ret = 0;
//	ret = Add(1, 2);
//	return 0;
//}
//***************************************************************************************************************
////auto�ؼ���
//int TestAuto()
//{
//	return 10;
//}
//
//int main()
//{
//	int a = 10;
//	auto _a = &a;
//	auto* _a1 = &a;
//	auto& _a2 = a;
//	auto b = a;
//	auto c = 'a';
//	auto d = TestAuto();
//	
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//
//	cout << typeid(_a).name() << endl;
//	cout << typeid(_a1).name() << endl;
//	cout << typeid(_a2).name() << endl;
//
//	*_a = 10;
//	*_a1 = 20;
//	_a2 = 30;
//
//	getchar();
//	return 0;
//}
//*****************************************************************************************************************
////���ڷ�Χ��forѭ��
//void TestFor()
//{
//	int arr[] = { 1, 2, 3, 4, 5 };
//	for (auto& e : arr)
//		cout << e << endl;
//}
//int main()
//{
//	TestFor();
//
//	getchar();
//	return 0;
//}
//****************************************************************************************************************
//ָ���ֵnullptr
///����NULL