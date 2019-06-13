#pragma once
//闭散列
#include<vector>
#include<iostream>
using namespace std;

namespace CLOSE
{
	enum STATA
	{
		EMPTY,
		DELETE,
		EXIST
	};

	template<class K, class V>
	struct HashNode
	{
		pair<K, V> _kv;
		STATA _stata = EMPTY;
	};

	template<class K, class V>
	class HashTable
	{
	public:
		typedef HashNode<K, V> Node;
		typedef Node* pNode;
	public:
		HashTable(size_t size = 5)
		{
			_table.resize(size);
			_size = 0;
		}
		bool insert(const pair<K, V>& kv)
		{
			CheckCapcity();
			//位置映射
			size_t index = kv.first % _table.size();
			//找个地方插
			while (_table[index]._stata != EMPTY)
			{
				//key不能重复
				if (_table[index]._kv.first == kv.first)
					return false;
				++index;
				if (index == _table.size())
					index = 0;
			}
			_table[index]._kv = kv;
			_table[index]._stata = EXIST;
			++_size;
			return true;
		}
		pNode Find(const K & k)
		{
			size_t index = k % _table.size();
			while (_table[index]._stata != EMPTY)
			{
				if (_table[index]._stata == EXIST && _table[index]._kv.first == k)
					return &_table[index];
				++index;
				if (index == _table.size())
					index = 0;
			}
			return nullptr;
		}
		bool Erase(const K & k)
		{
			pNode ret = Find(k);
			if (ret)
			{
				ret->_stata = DELETE;
				--_size;
				return true;
			}
			return false;
		}
	private:
		void CheckCapcity()
		{
			if (_table.size() == 0
				|| _size * 10 / _table.size() >= 7)
			{
				size_t newS = _table.size() == 0 ? 10 : 2 * _table.size();
				HashTable newT(newS);
				for (int i = 0; i < _table.size(); ++i)
				{
					if (_table[i]._stata == EXIST)
					{
						newT.insert(_table[i]._kv);
					}
				}
				_table.swap(newT._table);
			}
		}
	private:
		vector<Node> _table;
		size_t _size;
	};
}


//开散列
template<class V>
struct HashNode
{
	HashNode<V>* _next;
	V _data;

	HashNode(const V& data)
		:_next(nullptr)
		,_data(data)
	{}
};
//前置声明
template <class K, class V, class KeyOfValue>
class HashTable;
template<class K, class V,class KeyOfValue>
struct HIterator
{
	typedef HashNode<V> Node;
	typedef Node* pNode;
	typedef HIterator<K, V, KeyOfValue> Self;
	typedef HashTable<K, V, KeyOfValue> HT;
	
	pNode _node;
	HT* _ht;
	HIterator(pNode node,HT* ht)
		:_node(node)
		,_ht(ht)
	{}

	V& operator*()
	{
		return _node->_data;
	}
	V* operator->()
	{
		return &_node->_data;
	}
	bool operator!=(const Self& it)
	{
		return _node != it._node;
	}
	//前置++
	Self& operator++()
	{
		if (_node->_next) {
			_node = _node->_next;
		}
		else {
			KeyOfValue kov;
			size_t index = kov(_node->_data) % (_ht->_table.size());
			++index;
			while (index < (_ht->_table.size()))
			{
				if (_ht->_table[index]) {
					_node = _ht->_table[index];
					break;
				}
				++index;
			}
			if (index == _ht->_table.size())
				_node = nullptr;

		}
		return *this;
	}
};

template<class K, class V,class KeyOfValue>
class HashTable
{
public:
	//泛型友元声明，迭代器需要访问哈希表的私有成员
	template <class K, class V, class KeyOfValue>
	friend struct HIterator;
public:
	typedef HashNode<V> Node;
	typedef Node* pNode;
	typedef HIterator<K, V, KeyOfValue> iterator;
public:
	iterator begin()
	{
		for (size_t i = 0; i < _table.size(); ++i)
		{
			if (_table[i])
				return iterator(_table[i],this);
		}
		return iterator(nullptr,this);
	}
	iterator end()
	{
		return iterator(nullptr,this);
	}
	pair<iterator,bool> insert(const V& data)
	{
		CheckCapacity();
		KeyOfValue kov;
		size_t index = kov(data) % _table.size();
		pNode cur = _table[index];
		while (cur)
		{
			if(kov(cur->_data) == kov(data))
				return make_pair(iterator(cur,this),false);
			cur = cur->_next;
		}
		cur = new Node(data);
		//头插
		cur->_next = _table[index];
		_table[index] = cur;
		++_size;
		return make_pair(iterator(cur,this),true);
	}
	iterator Find(const K& k)
	{
		size_t index = k % _table.size();
		pNode cur = _table[index];
		KeyOfValue kov;
		while (cur)
		{
			if (kov(cur->_data) == k)
				return iterator(cur,this);
			cur = cur->_next;
		}
		return iterator(nullptr,this);
	}
	bool Erase(const K& k)
	{
		size_t index = k % _table.size();
		pNode cur = _table[index];
		KeyOfValue kov;
		pNode prev = nullptr;
		while (cur)
		{
			if (kov(cur->_data) == k) {
				if (prev) 
					prev->_next = cur->_next;
				else 
					_table[index] = cur->_next;
				
				--_size;
				delete cur;
				return true;
			}
			prev = cur;
			cur = cur->_next;
		}
		return false;
	}
private:
	void CheckCapacity()
	{
		if (_size >= _table.size()*3)
		{
			size_t newS = _table.size() == 0 ? 4 : _table.size() * 2;
			vector<pNode> newV;
			newV.resize(newS);
			KeyOfValue kov;
			//遍历旧表
			for (size_t i = 0; i < _table.size(); ++i)
			{
				pNode cur = _table[i];
				while (cur)
				{
					pNode next = cur->_next;
					size_t index = kov(cur->_data) % newS;
					cur->_next = newV[index];
					newV[index] = cur;
					cur = next;
				}
				_table[i] = nullptr;
			}
			_table.swap(newV);
		}
	}
private:
	vector<pNode> _table;
	size_t _size = 0;
};