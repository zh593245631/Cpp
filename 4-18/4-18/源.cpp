#include<iostream>
using namespace std;
//���ͱ�̣���д�������޹ص�ͨ�ô��룬�Ǵ��븴�õ�һ���ֶΡ�ģ���Ƿ��ͱ�̵Ļ�����
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
//	char* p2 = "world";//'w'�ĵ�ַ  ���ַ������� �������Ͽ��ٿռ�
//	char* p1 = "hello";//��h���ĵ�ַ
//	
//
//	if (IsBig(p1, p2))
//		cout << p1 << endl;
//	else
//		cout << p2 << endl;
//}
//1001000110100
//10010
//��С��
//void isBig()
//{
//	int a = 1;
//	char* b = (char*)&a;
//
//	if (*b == 1)
//		cout << "С��" << endl;
//	else
//		cout << "���" << endl;
//}
//int main()
//{
//	test();
//	cout << sizeof(short int) << endl;
//	isBig();
//	return 0;
//}
//��ģ���ػ�Ӧ��֮������ȡ
template<class T>
void Copy(T* dst, const T* src, size_t size)
{
	memcpy(dst, src, sizeof(T)*size);
}

//ʹ��ѭ����ֵ����
//Ч�ʱȽϵ�
template<class T>
void Copy2(T* dst, const T* src, size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		dst[i] = src[i];
	}
}
//����bool���������Զ�������������
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
//ʹ�ú������������Զ�������
//��ȱ���ǣ�ö����Ҫ���������ͱ���һ�飬ÿ�αȽ϶����ַ����ı�
//�ϣ�Ч�ʱȽϵ͡�
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
}//������ȡ
//��������
struct TrueType
{
	static bool Get()
	{
		return true;
	}
};
//�Զ�������
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