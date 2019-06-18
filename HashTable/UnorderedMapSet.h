#pragma once
#include"hash.h"

template<class K>
struct HFun
{
	const K& operator()(const K& a)
	{
		return a;
	}
};
template<>
struct HFun<string>
{
	size_t operator()(const string& str)
	{
		size_t hash = 0;
		for (const auto& e : str)
		{
			hash = hash * 131 + e;
		}
		return hash;
	}
};
template<class K, class V, class HashFun = HFun<K>>
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
	typedef typename HashTable<K, pair<K, V>, KeyOfValue, HashFun>::iterator iterator;
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
	V& operator[](const K& key)
	{
		pair<iterator, bool> ret = insert(make_pair(key, V()));
		return ret.first->second;
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
	HashTable<K, pair<K,V>, KeyOfValue, HashFun> _ht;
};

template<class K, class HashFun = HFun<K>>
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
	typedef typename HashTable<K, K, KeyOfValue, HashFun>::iterator iterator;
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
	HashTable<K, K, KeyOfValue, HashFun> _ht;
};