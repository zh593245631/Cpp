#include<iostream>
using namespace std;

////����ģ�����
//template <class T1, class T2>
//T1 Add(const T1& a, const T2& b)
//{
//	return a + b;
//}
////������ģ���������Ϊ����ʹ��
//template<class T, size_t N>
//class Arr
//{
//private:
//	T a[N];
//};
//
//int main()
//{
//	Arr<int, 10> arr1;
//	Arr<double, 100> arr2;
//	return 0;
//}

template<class T>
bool isEqul(const T& a, const T& b)
{
	return a == b;
}

//const ���δ�λ�� const -> a,b
//template<class T>
//bool isGreater(const T& a,const T& b)
//{
//	return a > b;
//}
////1.��Ҫ��һ���Ѵ��ڵ�ͨ��ģ�庯��
////2.ģ�����Ϊ��
////3.����������Ҫ��ʾд��Ҫ�ػ�������
////4.�ػ������͵ĸ�ʽҪ��ͨ�õ�ģ�������ʽһ��
////5.һ�㲻ȥд����ģ����ػ��汾������ģ����ػ��Ƚϸ��ӣ������һЩ��ֵĴ��󣬽�����ں���ģ�崦���˻򱨴�����ͣ�ȥʵ��һ����Ӧ���͵���ͨ������
//
////template<>
////bool isGreater<char*>(const char*& a, const char*& b)
////{
////	if (strcmp(a, b) > 0)
////		return true;
////	return false;
////}
//
//
//bool isGreater(char*& a, char*& b)
//{
//	if (strcmp(a, b) > 0)
//		return true;
//	return false;
//}
//int main()
//{
//	int a = 10, b = 10;
//
//	char* str1 = "hello";
//	char* str2 = "zzh";
//	
//	
//	cout << isEqul(a, b) << endl;
//	cout << isGreater(a,b)<<endl;
//	cout << isGreater(str1, str2) << endl;
//	return 0;
//}
template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};
//ȫ�ػ�
template<>
class Data<int, char>
{
public:
	Data() { cout << "Data<int, char>" << endl; }
private:
	int _d1;
	char _d2;
};
//���ػ�
template <class T1>
class Data<T1, int>
{
public:
	Data() { cout << "Data<T1, int>" << endl; }
private:
	T1 _d1;
	int _d2;
};//�Բ���������
template <typename T1, typename T2>
class Data <T1*, T2*>
{
public:
	Data() { cout << "Data<T1*, T2*>" << endl; }

private:
	T1* _d1;
	T2* _d2;
};template <typename T1, typename T2>
class Data <T1&, T2&>
{
public:
	Data(const T1& d1, const T2& d2)
		: _d1(d1)
		, _d2(d2)
	{
		cout << "Data<T1&, T2&>" << endl;
	}

private:
	const T1 & _d1;
	const T2 & _d2;
};
void TestVector()
{
	Data<int, float> d1;
	Data<int, char> d2;
	Data<char, int> d3;
	Data<int*, int*> d4;
	Data<int&, int&> d5(1,2);
}int main(){	TestVector();	return 0;}