#include<iostream>
using namespace std;
//template<class T>
//void _swap(T& a, T& b)
//{
//	T temp = a;
//	a = b;
//	b = temp;
//}
//int main()
//{
//	int a = 1;
//	int b = 2;
//	_swap(a, b);
//	double c = 1.0;
//	double d = 2.0;
//	_swap(c, d);
//	char e = 'e';
//	char f = 'f';
//	_swap(e, f);
//	return 0;
//}
//template <class T,class Y>
//T _Add(const T& a, const Y& b)
//{
//	return a + b;
//}
//int main()
//{
//	int a = 1;
//	double b = 2.0;
//
//	_Add(a, b);
//	//_Add(a, (int)b);
//	//_Add<int>(a, b);
//	return 0;
//}
#include<assert.h>
template<class T>
class Vector
{
public:
	Vector(size_t capcity = 10)
		:_pData(new T[capcity])
		, _size(0)
		, _capacity(capcity)
	{}
	~Vector()
	{
		if (_pData)
		{
			delete[] _pData;
		}
	}
	void PushBack(const T& data)
	{
		_pData[_size++] = data;
	}
	void PopBack()
	{
		--_size;
	}
	size_t Size()
	{
		return _size;
	}
	T& operator[](size_t pos)
	{
		assert(pos < _size);
			return _pData[pos];
	}
private:
	T* _pData;
	size_t _size;
	size_t _capacity;
};
int main()
{
	Vector<int> s1;
	//s1.PushBack(1);
	//s1.PushBack(2);
	//s1.PushBack(3);

	//for (size_t i = 0; i<s1.Size();++i)
	//{
	//	cout << s1[i]<<" ";
	//}
	cout << endl;
	Vector<double> s2;
	s2.PushBack(1.1);
	s2.PushBack(2.1);
	s2.PushBack(3.1);
	for (size_t i = 0; i<s2.Size(); ++i)
	{
		cout << s2[i] << " ";
	}

	getchar();
	return 0;
}