#pragma once
#include"RBTree.hpp"

template<class T>
class Set
{
	typedef TreeIterator<T> Iterator;
	struct KeyOfValue
	{
		const T& operator()(const T& data)
		{
			return data;
		}
	};
public:
	Set(){}
	pair<Iterator,bool> insert(const T& data)
	{
		return s.insert(data);
	}
	Iterator begin()
	{
		return s.begin();
	}
	Iterator end()
	{
		return s.end();
	}

private:
	RBTree<T, T, KeyOfValue> s;
};