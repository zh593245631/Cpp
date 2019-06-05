#pragma once
#include"RBTree.hpp"

template<class K, class V>
class Map
{
	typedef TreeIterator<pair<K, V>> Iterator;

	struct KeyOfValue
	{
		const K& operator()(const pair<K, V>& data)
		{
			return data.first;
		}
	};
public:
	Map(){}
	pair<Iterator,bool> insert(const pair<K,V>& data)
	{
		return m.insert(data);
	}
	Iterator begin()
	{
		return m.begin();
	}
	Iterator end()
	{
		return m.end();
	}
private:
	RBTree<K, pair<K, V>, KeyOfValue> m;
};