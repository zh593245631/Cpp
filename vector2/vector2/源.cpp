#include<iostream>
#include<assert.h>
#include<string>
using namespace std;
namespace zzh
{
	template<class T>
	class Vector
	{
	public:
		typedef T* Iterator;
		typedef const T* ConstIterator;
		Iterator Begin(){ return _start; }
		Iterator End(){ return _finish; }
		Iterator CBegin()const { return _start; }
		Iterator CEnd()const { return _finish; }
		Iterator RBegin(){ return _finish; }
		Iterator REnd(){ return _start; }

		size_t Size()const { return _finish - _start; }
		size_t Capacity()const { return _endOfStorage - _start; }

		Vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{}
		Vector(int n, const T& value = T())
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			Reserve(n);
			while (n--)
			{
				PushBack(value);
			}
		}
		template<class InputIterator>
		Vector(InputIterator first, InputIterator last)
		{
			Reserve(last - first);
			while (first != last)
			{
				PushBack(*first);
				++first;
			}
		}
		Vector(const Vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			Reserve(v.Capacity());
			Iterator it = Begin();
			ConstIterator vit = v.CBegin();

			while (vit != v.CEnd())
			{
				*it++ = *vit++;
			}

			_finish = _start + v.Size();
			_endOfStorage = _start + v.Capacity();
		}
		Vector<T>& operator= (Vector<T> v)
		{
			Swap(v);
			return *this;
		}
		~Vector()
		{
			delete[] _start;
			_start = _finish = _endOfStorage = nullptr;
		}
		void Reserve(size_t n)
		{
			if (n > Capacity())
			{
				size_t size = Size();
				T* tmp = new T[n];

				if (_start)
				{
					for (size_t i = 0; i < size; i++)
						tmp[i] = _start[i];
				}

				_start = tmp;
				_finish = _start + size;
				_endOfStorage = _start + n;
			}
		}
		void Resize(size_t n, const T& value = T())
		{
			if (n <= Size())
			{
				_finish = _start + n;
				return;
			}
			if (n > Capacity())
			{
				Reserve(n);
			}

			Iterator it = _finish;
			_finish = _start + n;
			while (it != _finish)
			{
				*it = value;
				++it;
			}
		}

		void Swap(Vector<T>& v)
		{
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_endOfStorage, v._endOfStorage);
		}

		void PushBack(const T& x)
		{
			/*Insert(End(), x);*/
			size_t size = Size();
			if (_finish == _endOfStorage)
			{
				size_t newCapacity = Capacity() == 0 ? 1 : Capacity() * 2;
				Reserve(newCapacity);
			}
			_start[size] = x;
			_finish++;
		}

		void PopBack()
		{
			_finish--;
		}
		
		Iterator Insert(Iterator pos, const T& x)
		{
			assert(pos <= _finish);

			if (_finish == _endOfStorage)
			{
				size_t size = Size();
				size_t newCapacity = Capacity() == 0 ? 1 : Capacity() * 2;

				Reserve(newCapacity);
				pos = _start + size;
			}
			Iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;
			return pos;
		}
		Iterator Erase(Iterator pos)
		{
			Iterator begin = pos + 1;
			while (begin != _finish)
			{
				*(begin - 1) = *begin;
				++begin;
			}
			_finish--;

			return pos;
		}

		T& operator[](size_t pos)
		{
			return _start[pos];
		}
	private:
		Iterator _start;
		Iterator _finish;
		Iterator _endOfStorage;
	};
}
using namespace zzh;
void Test1()
{
	Vector<int> v;
	Vector<int> v1(4,100);
	Vector<int> v2(v1.Begin(), v1.End());
	Vector<int> v3(v2);

	int arr[] = { 16, 7, 8, 9 };
	Vector<int> v4(arr, arr + sizeof(arr) / sizeof(arr[0]));
	zzh::Vector<int>::Iterator it = v4.Begin();
	while (it != v4.End())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	Vector<string> str;
	str.PushBack("111");
	str.PushBack("222");
	str.PopBack();
	for (size_t i = 0; i < str.Size(); i++)
	{
		cout << str[i] << " ";
	}
	cout << endl;
}
void Test2()
{
	//capacity
	//size_t sz;
	//Vector<int> v;

	//sz = v.Capacity();

	//for (size_t i = 0; i < 100; i++)
	//{
	//	v.PushBack(1);
	//	if (sz != v.Capacity())
	//	{
	//		sz = v.Capacity();
	//		cout << sz << endl;
	//	}
	//}
	////resverse
	//Vector<int> v1;
	//sz = v1.Capacity();
	//v1.Reserve(100);
	//for (size_t i = 0; i < 100; i++)
	//{
	//	v1.PushBack(1);
	//	if (sz != v1.Capacity())
	//	{
	//		sz = v1.Capacity();
	//		cout << sz << endl;
	//	}
	//}
	//resize
	Vector<int> v2;
	for (size_t i = 0; i < 10; i++)
		v2.PushBack(1);
	v2.Resize(5);
	cout << v2.Size()<< endl;
	v2.Resize(8, 100);
	cout << v2.Size() << endl;
	for (size_t i = 0; i < v2.Size(); i++)
		cout << v2[i] << " ";
	cout << endl;
	v2.Resize(20);
	for (size_t i = 0; i < v2.Size(); i++)
		cout << v2[i] << " ";
	cout << endl;

}
int main()
{
	//Test1();
	Test2();
	return 0;
}