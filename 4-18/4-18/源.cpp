#include<iostream>
using namespace std;
//泛型编程：编写与类型无关的通用代码，是代码复用的一种手段。模板是泛型编程的基础。
//template<class T>
//bool IsBig(T& left, T& right)
//{
//	return left > right;
//}
//template<>
//bool IsEqual<char*>(char*& left, char*& right)
//{
//	if (strcmp(left, right) > 0)
//		return true;
//	return false;
//}
//
//void test()
//{
//	char* p2 = "world";//'w'的地址  在字符常量区 从下往上开辟空间
//	char* p1 = "hello";//‘h’的地址
//	
//
//	if (IsBig(p1, p2))
//		cout << p1 << endl;
//	else
//		cout << p2 << endl;
//}
//1001000110100
//10010
//大小端
//void isBig()
//{
//	int a = 1;
//	char* b = (char*)&a;
//
//	if (*b == 1)
//		cout << "小端" << endl;
//	else
//		cout << "大端" << endl;
//}
//int main()
//{
//	test();
//	cout << sizeof(short int) << endl;
//	isBig();
//	return 0;
//}
//类模板特化应用之类型萃取
template<class T>
void Copy(T* dst, const T* src, size_t size)
{
	memcpy(dst, src, sizeof(T)*size);
}

//使用循环赋值拷贝
//效率比较低
template<class T>
void Copy2(T* dst, const T* src, size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		dst[i] = src[i];
	}
}
//增加bool类型区分自定义玉内置类型
template<class T>
void Copy3(T* dst, const T* src, size_t size, bool IsPODType)
{
	if (IsPODType)
		memcpy(dst, src, sizeof(T)*size);
	else
	{
		for (size_t i = 0; i < size; ++i)
			dst[i] = src[i];
	}
}
//使用函数区分内置自定义类型
//但缺陷是：枚举需要将所有类型遍历一遍，每次比较都是字符串的比
//较，效率比较低。
bool IsPODType(const char* strType)
{
	const char* arrType[] = { "char", "short", "int", "long", "long long", "float", "double", "long double" };
	for (size_t i = 0; i < sizeof(arrType) / sizeof(arrType[0]); ++i)
	{
		if (0 == strcmp(strType, arrType[i]))
			return true;
	}
	return false;
}
template<class T>
void Copy4(T* dst, const T* src, size_t size)
{
	if (IsPODType(typeid(T).name()))
		memcpy(dst, src, sizeof(T)*size);
	else
	{
		for (size_t i = 0; i < size; ++i)
			dst[i] = src[i];
	}
}//类型萃取
//内置类型
struct TrueType
{
	static bool Get()
	{
		return true;
	}
};
//自定义类型
struct FalseType
{
	static bool Get()
	{
		return false;
	}
};
template<class T>
struct TypeTraits
{
	typedef  FalseType IsPODType;
};
template<>
struct TypeTraits<char>
{
	typedef TrueType IsPODType;
};
template<>
struct TypeTraits<short>
{
	typedef TrueType IsPODType;
}; template<>
struct TypeTraits<int>
{
	typedef TrueType IsPODType;
}; template<>
struct TypeTraits<long>
{
	typedef TrueType IsPODType;
}; template<>
struct TypeTraits<long long>
{
	typedef TrueType IsPODType;
}; template<>
struct TypeTraits<float>
{
	typedef TrueType IsPODType;
}; template<>
struct TypeTraits<double>
{
	typedef TrueType IsPODType;
};
template<>
struct TypeTraits<long double>
{
	typedef TrueType IsPODType;
}; 

template<class T>
void Copy5(T* dst, const T* src, size_t size)
{
	if (TypeTraits<T>::IsPODType::Get())
	{
		memcpy(dst, src, sizeof(T)*size);
	}
	else{
		for (size_t i = 0; i < size; i++)
		{
			dst[i] = src[i];
		}
	}
}
int main()
{
	//int arr1[] = { 1, 2, 3, 4, 5 };
	//int arr2[] = { 4, 5, 6, 7 };
	//Copy(arr1, arr2, 4);
	string arr1[] = { "11", "22", "33" ,"44"};
	string arr2[4];
	Copy5(arr2, arr1, 4);
	

	return 0;
}