#include <vector>
#include<iostream>
#include <mutex>
#include<memory>
#include <thread>
using namespace std;

//void _MergeSort(int* a, int left, int right, int* tmp)
//{
//	if (left >= right) return;
//
//	int mid = left + ((right - left) >> 1);
//	// [left, mid]
//	// [mid+1, right]
//	_MergeSort(a, left, mid, tmp);
//	_MergeSort(a, mid + 1, right, tmp);
//	int begin1 = left, end1 = mid;
//	int begin2 = mid + 1, end2 = right;
//	int index = left;
//	while (begin1 <= end1 && begin2 <= end2)
//	{
//		if (a[begin1] < a[begin2])
//			tmp[index++] = a[begin1++];
//		else
//			tmp[index++] = a[begin2++];
//	}
//	while (begin1 <= end1)
//		tmp[index++] = a[begin1++];
//	while (begin2 <= end2)
//		tmp[index++] = a[begin2++];
//	memcpy(a + left, tmp + left, sizeof(int) * (right - left + 1));
//}
//
//void MergeSort(int* a, int n)
//{
//	int* tmp = (int*)malloc(sizeof(int) * n);
//	_MergeSort(a, 0, n - 1, tmp);
//
//	// ������账����һЩ�����߼�
//	//vector<int> v(1000000000, 10);
//	// ...
//
//	// free(tmp);
//}
//int main()
//{
//	int a[5] = { 4, 5, 2, 3, 1 };
//	MergeSort(a, 5);
//	return 0;
//}

//int main()
//{
//	//string* pd = new string;
//	//shared_ptr<string> sp1(pd);
//	//shared_ptr<string> sp2(pd);
//	shared_ptr<string> sp1(new string);
//	*sp1 = "haha";
//	cout << *sp1 << endl;
//	cout << sp1.use_count() << endl;
//	cout << sp1 << endl;
//	{
//		shared_ptr<string> sp2(sp1);
//		*sp2 = "hehe";
//		cout << *sp2 << endl;
//		cout << sp2.use_count() << endl;
//		cout << sp2 << endl;
//	}
//
//	cout << *sp1 << endl;
//
//
//	return 0;
//}
// ʹ��RAII˼����Ƶ�SmartPtr��
//template<class T>
//class SmartPtr {
//public:
//	SmartPtr(T* ptr = nullptr)
//		: _ptr(ptr)
//	{}
//	~SmartPtr()
//	{
//		if (_ptr)
//			delete _ptr;
//	}
//private:
//	T* _ptr;
//};
//void MergeSort(int* a, int n)
//{
//	int* tmp = (int*)malloc(sizeof(int) * n);
//	// ��tmpָ��ί�и���sp������ʱ��ʦ�Ļ�˵��tmpָ������һ�����µ�Ů���ѣ���������㣬ֱ����go
//	//die^^
//		SmartPtr<int> sp(tmp);
//	// _MergeSort(a, 0, n - 1, tmp);
//
//
//	// ������账����һЩ�����߼�
//	vector<int> v(1000000000, 10);
//	// ...
//}
//
//int main()
//{
//	try {
//		int a[5] = { 4, 5, 2, 3, 1 };
//		MergeSort(a, 5);
//	}
//	catch (const exception & e)
//	{
//		cout << e.what() << endl;
//	}
//	return 0;
//}
////////////////////////////////////////////////////////////////////////////////
//SmartPtr
//template<class T>
//class SmartPtr {
//public:
//	SmartPtr(T* ptr = nullptr)
//		: _ptr(ptr)
//	{}
//	~SmartPtr()
//	{
//		if (_ptr)
//		{
//			cout <<typeid(*_ptr).name()<< endl;
//			delete _ptr;
//		}
//	}
//
//	T& operator*() { return *_ptr; }
//	T* operator->() { return _ptr; }
//private: 
//	T* _ptr;
//};
//struct Date
//{
//	int _year = 10;
//	int _month = 10;
//	int _day = 10;
//	~Date() { cout << "~Date()"<<endl; };
//};
////void bbb(Date* d)
////{	
////
////	d->_day = 1;
////	cout << d->_day << endl;
////}
//int main()
//{
//		/*SmartPtr<int> sp1(new int);*/
//
//		//cout << typeid(sp1).name() << endl;
//
//		//*sp1 = 10;
//		//cout << *sp1 << endl;
//		
//		SmartPtr<Date>sparray = new Date;
//		sparray->_year = 2018;
//		sparray->_month = 1;
//		sparray->_day = 1;
//
//	//SmartPtr<Date> sp2(sparray);
//	//int a = 0;
//	//cout << typeid(a).name() << endl;
//	return 0;
//}

//#include <thread>
//#include <mutex>
// C++11�Ŀ���Ҳ��һ��lock_guard�������LockGuard��������ʵ����Ϊ��ѧϰ����ԭ��
//template<class Mutex>
//class LockGuard
//{
//public:
//	LockGuard(Mutex& mtx)
//		:_mutex(mtx)
//	{
//		_mutex.lock();
//	}
//	~LockGuard()
//	{
//		_mutex.unlock();
//	}
//	LockGuard(const LockGuard<Mutex>&) = delete;
//private:
//	// ע���������ʹ�����ã��������ľͲ���һ������������
//	Mutex& _mutex;
//	//Mutex& a;
//};
//mutex mtx;
//static int n = 0;
//void Func()
//{
//	for (size_t i = 0; i < 1000000; ++i)
//	{
//		LockGuard<mutex> lock(mtx);
//		++n;
//	}
//}
//
//int main()
//{
//	int begin = clock();
//	thread t1(Func);
//	thread t2(Func);
//	t1.join();
//	t2.join();
//	int end = clock();
//	cout << n << endl;
//	cout << "cost time:" << end - begin << endl;
//
//	return 0;
//}
//
//RAll
//ʹ��RALL˼����Ƶ�SmartPtr
//template<class T>
//class SmartPtr{
//public:
//	SmartPtr(T* ptr = nullptr)
//		:_ptr(ptr)
//	{}
//
//	~SmartPtr()
//	{
//		cout << "~SmartPtr()" << endl;
//		if (_ptr) {
//			delete _ptr;
//			_ptr = nullptr;
//		}
//	}
//
//	T& operator*() { return *_ptr; }
//	T* operator->() { return _ptr; }
//
//private:
//	T* _ptr;
//};
//
//
//int main()
//{
//	int* tmp = new int;
//	SmartPtr<int> sp(tmp);
//
//	//*sp = 10;
//	return 0;
//}

/////////////////////////////////////////////////
//int main()
//{
//	int i = 0;
//	int j = 1;
//	const int& ri = i;
//	int* pj = &j;
//	const int* ppj = pj;
//	ppj = &i;
//	//const int* const pppj = &j;
//	//pppj = &i;
//	//int& rj = (int&)ri;
//	//rj = 20;
//	cout << ri << endl;
//	i = 10;
//	cout << i << endl;
//	cout << ri << endl;
//	return 0;
//}
////////////////////////////////////////////////
//auto_ptr

//class Date
//{
//public:
//	Date() { cout << "Date()" << endl; }
//	~Date() { cout << "~Date()" << endl; }
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	auto_ptr<Date> ap(new Date);
//	auto_ptr<Date> copy(ap);
//
//	//ap->_day = 10;
//
//	return 0;
//
//}
///////////////////////////////////////////////////////////////
//unique_ptr

//int main()
//{
//	unique_ptr<int> up(new int);
//
//	//������
//	//unique_ptr<int> op(up);
//	//unique_ptr<int> ip = up;
//
//	return 0;
//}
//ģ��ʵ�� unique_ptr
// ģ��ʵ��һ�ݼ���UniquePtr,�˽�ԭ��
//template<class T>
//class UniquePtr
//{
//public:
//	UniquePtr(T* ptr = nullptr)
//		:_ptr(ptr)
//	{}
//
//	~UniquePtr()
//	{
//		if (_ptr)
//		{
//			delete _ptr;
//			_ptr = nullptr;
//		}
//	}
//
//	T& operator*() { return *_ptr; }
//	T* operator->() { return _ptr; }
//
//private:
//	UniquePtr(UniquePtr<T> const &) = delete;
//	UniquePtr& operator=(UniquePtr<T> const&) = delete;
//
//	T* _ptr;
//};
//
//int main()
//{
//	UniquePtr<int> a(new int);
//
//	//UniquePtr<int> b(a);
//
//	return 0;
//}
/////////////////////////////////////////////////////////////////
//shared_ptr
//int main()
//{
//	shared_ptr<int> sp(new int);
//	cout << sp.use_count() << endl;
//	{
//		shared_ptr<int> sb(sp);
//		cout << sb.use_count() << endl;
//	}
//	cout << sp.use_count() << endl;
//	return 0;
//}

////��ͨ��ģ��ʵ��
//template<class T>
//class SharePtr
//{
//public:
//	SharePtr(T* ptr = nullptr)
//		: _ptr(ptr)
//		, use_count(1)
//	{}
//	
//	SharePtr(const SharePtr<T>& sp)
//		:_ptr(sp._ptr)
//		,use_count(sp.use_count)
//	{
//		use_count++;
//	}
//
//	SharePtr<T>& operator=(const SharePtr<T>& sp)
//	{
//		if (_ptr != sp._ptr)
//		{
//			this->~SharePtr();
//			_ptr = sp._ptr;
//			use_count = sp.use_count;
//			use_count++;
//		}
//
//		return *this;
//	}
//	T& operator*() { return *_ptr; }
//	T* operator->() { return _ptr; }
//
//	int UseCount() { return use_count; }
//	~SharePtr()
//	{
//		if (_ptr)
//		{
//			if (--use_count == 0)
//			{
//				delete _ptr;
//				_ptr = nullptr;
//			}
//		}
//	}
//private:
//	T* _ptr;
//	int use_count;
//};
//
//int main()
//{
//	SharePtr<int> a(new int);
//	cout << a.UseCount() << endl;
//	SharePtr<int> b(a);
//	cout << b.UseCount() << endl;
//	SharePtr<int> c(new int);
//	cout << c.UseCount() << endl;
//	c = a;
//	cout << c.UseCount() << endl;
//
//
//	return 0;
//}
//int main()
//{
//	shared_ptr<int> a(new int);
//	auto count = a.use_count();
//
//	cout << typeid(count).name() << endl;
//	return 0;
//}
// ģ��ʵ��һ�ݼ���SharedPtr,�˽�ԭ��


template<class T>
class SharedPtr
{
public:
	SharedPtr(T* ptr = nullptr)
		:_count(new int(1))
		,_ptr(ptr)
		,_pMutex(new mutex)
	{}
	~SharedPtr()
	{
		Release();
	}

	SharedPtr(const SharedPtr<T>& sp)
		:_count(sp._count)
		, _ptr(sp._ptr)
		, _pMutex(sp._pMutex)
	{
		AddRefCount();
	}

	SharedPtr<T>& operator=(const SharedPtr<T>& sp)
	{
		if (_ptr != sp._ptr)
		{
			//�ͷŹ���ľ���Դ
			Release();

			//�����������Դ
			_ptr = sp._ptr;
			_count = sp._count;
			_pMutex = sp._pMutex;

			AddRefCount();
		}

		return *this;
	}

	T& operator*() { return *_ptr; }
	T* operator->() { return _ptr; }
	int use_count() { return *_count; }
	T* get() { return _ptr; }
	void AddRefCount()
	{
		_pMutex->lock();
		++(*_count);
		_pMutex->unlock();
	}

	void Release()
	{
		bool deleteflag = false;

		_pMutex->lock();
		if (--(*_count) == 0)
		{
			delete _ptr;
			delete _count;
			deleteflag = true;
		}
		_pMutex->unlock();

		if (deleteflag)
			delete _pMutex;
	}
private:
	int* _count;
	T* _ptr;
	mutex* _pMutex; //������
};

//int main()
//{
//	//SharedPtr<int> a(new int);
//	//cout << a.use_count() << endl;
//	//SharedPtr<int> b(a);
//	//cout << b.use_count() << endl;
//	//SharedPtr<int> c(new int);
//	//cout << c.use_count() << endl;
//	//c = a;
//	//cout << c.use_count() << endl;
//	SharedPtr<int> sp1(new int(10));
//	SharedPtr<int> sp2(sp1);
//	*sp2 = 20;
//	cout << sp1.use_count() << endl;
//	cout << sp2.use_count() << endl;
//	SharedPtr<int> sp3(new int(10));
//	sp2 = sp3;
//	cout << sp1.use_count() << endl;
//	cout << sp2.use_count() << endl;
//	cout << sp3.use_count() << endl;
//	sp1 = sp3;
//	cout << sp1.use_count() << endl;
//	cout << sp2.use_count() << endl;
//	cout << sp3.use_count() << endl;
//	return 0;
//}

class Date
{
public:
	int _year;
	int _month;
	int _day;
};
void SharePtrFunc(SharedPtr<Date> sp, size_t n)
{
	cout << sp.get() << endl;
	for (size_t i = 0; i < n; ++i)
	{
		// ��������ָ�뿽����++����������ָ��������--�������������̰߳�ȫ�ġ�
		SharedPtr<Date> copy(sp);
		// ��������ָ����ʹ������Դ�������̰߳�ȫ�ġ��������ǿ�����Щֵ�����߳�++��2n�Σ�������
		//�տ����Ľ������һ���Ǽ���2n
			copy->_year++;
		copy->_month++;
		copy->_day++;
	}
}
int main()
{
	SharedPtr<Date> p(new Date);

	cout << p.get() << endl;

	const size_t n = 100;
	thread t1(SharePtrFunc, p, n);
	thread t2(SharePtrFunc, p, n);
	t1.join();
	t2.join();
	cout << p->_year << endl;
	cout << p->_month << endl;
	cout << p->_day << endl;
	return 0;
}
