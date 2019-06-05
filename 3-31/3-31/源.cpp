#include<iostream>
#include<vector>
using namespace std;
//class Solution {
//public:
//	vector<vector<int>> generate(int numRows) {
//
//		vector<vector<int>>   vv;
//		vv.resize(numRows);
//		//·ÖÅä 1
//		for (int i = 0; i<numRows; i++)
//		{
//			vv[i].resize(i + 1, 0);
//
//			vv[i][0] = 1;
//			vv[i][i] = 1;
//		}
//		for (int i = 2; i<numRows; i++)
//		{
//			for (int j = 1; j<i; j++)
//			{
//					vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
//			}
//		}
//
//		return vv;
//	}
//};
//int main()
//{
//	Solution s;
//	s.generate(5);
//	return 0;
//}
template <class T>
class Vector
{
public:
	Vector()
		:_start(nullptr)
		, _finish(nullptr)
		, _endofStorage(nullptr)
	{}
	size_t Size() const
	{
		return _finish - _start;
	}
	size_t Capacity()const
	{
		return _endofStorage - _start;
	}
	//void PushBack(const T& val)
	//{
	//	if (_finish == _endofStorage)
	//	{
	//		4
	//	}
	//}
	void Reserve(size_t n)
	{
		if (n > Capacity())
		{
			size_t Size = Size();
			T* tmp = new T(n);

			if (_start)
			{
				for (size_t i = 0; i < Size; i++)
				{
					tmp[i] = _start[i];
				}
			}
			_start = tmp;
			_finish = _start+Size;
			_endofStorage = _start + n;
		}
		
	}
	typedef T* Iterator;
	typedef const T* ConstIterator;
	Iterator Begin() 
	{ 
		return _start; 
	}
	Iterator End() 
	{ 
		return _finish; 
	}
	ConstIterator CBegin() const 
	{ 
		return _start; 
	}
	ConstIterator CEnd() const 
	{ 
		return _finish; 
	}
	Iteratoor insert(Iterator pos, const T& x)
	{
		assert(pos <= _finish);

	}

private:
	T* _start;
	T* _finish;
	T* _endofStorage;
};
int main()
{
	Vector<int> v;

	

	return 0;
}