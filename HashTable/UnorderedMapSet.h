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
	bool insert(const pair<K, V>& data)
	{
		return _ht.insert(data);
	}
	void Find(const K& k)
	{
		cout << (_ht.Find(k)->_data).second << endl;
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
	bool insert(const K& data)
	{
		return _ht.insert(data);
	}
	void Find(const K& k)
	{
		cout << _ht.Find(k)->_data << endl;
	}
	bool Erase(const K& k)
	{
		return _ht.Erase(k);
	}
private:
	HashTable<K, K, KeyOfValue> _ht;
};