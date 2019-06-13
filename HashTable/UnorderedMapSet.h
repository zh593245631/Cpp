#pragma once
#include"hash.h"

template<class K, class V>
class UnorderedMap
{
	struct KeyOfValue
	{
		const K& operator()(const pair<K, V>& data)
		{
			return data.first;
		}
	};
public:
	typedef typename HashTable<K, pair<K, V>, KeyOfValue>::iterator iterator;
	iterator begin()
	{
		return _ht.begin();
	}
	iterator end()
	{
		return _ht.end();
	}
	pair<iterator,bool> insert(const pair<K, V>& data)
	{
		return _ht.insert(data);
	}
	iterator Find(const K& k)
	{
		//cout << (_ht.Find(k)->_data).second << endl;
		return _ht.Find(k);
	}
	bool Erase(const K& k)
	{
		return _ht.Erase(k);
	}
private:
	HashTable<K, pair<K,V>, KeyOfValue> _ht;
};

template<class K>
class UnorderedSet
{
	struct KeyOfValue
	{
		const K& operator()(const K& data)
		{
			return data;
		}
	};
public:
	typedef typename HashTable<K, K, KeyOfValue>::iterator iterator;
	iterator begin()
	{
		return _ht.begin();
	}
	iterator end()
	{
		return _ht.end();
	}
	pair<iterator,bool> insert(const K& data)
	{
		return _ht.insert(data);
	}
	iterator Find(const K& k)
	{
		//cout << _ht.Find(k)->_data << endl;
		return _ht.Find(k);
	}
	bool Erase(const K& k)
	{
		return _ht.Erase(k);
	}
private:
	HashTable<K, K, KeyOfValue> _ht;
};