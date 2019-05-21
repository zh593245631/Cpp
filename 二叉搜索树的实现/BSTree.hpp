#ifndef __BSTREE_HPP__
#define __BSTREE_HPP__
#include<iostream>
using namespace std;
template <class T>
struct BSTNode
{
	BSTNode(const T& val = T())
		: _pLeft(nullptr)
		, _pRight(nullptr)
		, _val(val)
	{}
	BSTNode* _pLeft;
	BSTNode* _pRight;
	T _val;
};

template <class T>
class BST
{
	typedef BSTNode<T> Node;
	typedef Node* pNode;
public:
	BST(pNode root = nullptr)
		: _root(root)
	{}

	~BST()
	{
		Destory(_root);
	}
	//²éÕÒ
	pNode find(const T& val)
	{
		pNode cur = _root;
		while (cur)
		{
			if (cur->_val == val)break;
			else if (cur->_val > val)
				cur = cur->_pLeft;
			else
				cur = cur->_pRight;
		}
		return cur;
	}
	//²åÈë
	bool insert(const T& val)
	{
		if (!_root) {
			_root = new Node(val);
			return true;
		}
		pNode cur = _root;
		pNode parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->_val > val)
				cur = cur->_pLeft;
			else if (cur->_val < val)
				cur = cur->_pRight;
			else
				return false;
		}

		pNode newNode = new Node(val);
		if (parent->_val > val)
			parent->_pLeft = newNode;
		else
			parent->_pRight = newNode;
		return true;
	}
	void print()
	{
		_InOrder(_root);
		cout << endl;
	}
private:
	void _InOrder(pNode root)
	{
		if (root) {
			_InOrder(root->_pLeft);
			cout << root->_val << " ";
			_InOrder(root->_pRight);
		}
	}
	void Destory(pNode root)
	{
		if (root) {
			Destory(root->_pLeft);
			Destory(root->_pRight);
			root = nullptr;
		}
	}
private:
	pNode _root;
};



#endif // ! __BSTREE_HPP__

