#include<iostream>

using namespace std;

enum Color
{
	Red,
	Black
};

template <class K, class V>
struct RBTreeNode
{
	pair<K, V> _kv;
	Color _color = Red;

	RBTreeNode<K, V>* _pLeft = nullptr;
	RBTreeNode<K, V>* _pRight = nullptr;
	RBTreeNode<K, V>* _pParent = nullptr;
};

template <class K, class V>
class RBTree
{
public:
	typedef RBTreeNode<K, V> Node;
	typedef Node* pNode;
public:
	RBTree()
		:_Header(new Node)
	{}
	//����
	bool insert(const pair<K, V>& kv)
	{
		if (_Header->_pParent == nullptr)
		{
			pNode root = new Node;
			root->_kv = kv;
			_Header->_pParent = root;
			_Header->_color = Red;
			_Header->_pLeft = root;
			_Header->_pRight = root;
			root->_pParent = _Header;
			return true;
		}

		//���ҵط���
		pNode cur = _Header->_pParent;
		pNode parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->_kv.first > kv.first) {
				cur = cur->_pLeft;
			}
			else if (cur->_kv.first < kv.first) {
				cur = cur->_pRight;
			}
			else {
				return false;
			}
		}

		//����
		cur = new Node;
		cur->_kv = kv;
		if (parent->_kv.first > kv.first)
			parent->_pLeft = cur;
		else
			parent->_pRight = cur;

		cur->_pParent = parent;


		//���� ����ڵ��Ǻ�ɫ ˫��Ϊ��ɫ����Ҫ����
		//curΪ�죬 pΪ�죬 /gΪ��
		while (cur != _Header->_pParent && cur->_pParent->_color == Red)
		{
			parent = cur->_pParent;
			pNode gparent = parent->_pParent;
	
			if (gparent->_pLeft == parent) 
			{
				pNode uncle = gparent->_pRight;
				if (uncle && uncle->_color == Red)
				{
					//u������Ϊ��
					uncle->_color = Black;
					parent->_color = Black;
					gparent->_color = Red;
					cur = gparent;
				}
				else
				{
					//u������/uΪ��
					if (parent->_pRight == cur)
					{
						RotateL(parent);
						swap(parent, cur);
					}

					RotateR(gparent);
					gparent->_color = Red;
					parent->_color = Black;
					break;
				}
			}
			else 
			{
				pNode uncle = gparent->_pLeft;
				if (uncle && uncle->_color == Red)
				{
					//u������Ϊ��
					uncle->_color = Black;
					parent->_color = Black;
					gparent->_color = Red;
					cur = gparent;
				}
				else
				{
					//u������/uΪ��
					if (parent->_pLeft == cur)
					{
						RotateR(parent);
						swap(parent, cur);
					}

					RotateL(gparent);
					gparent->_color = Red;
					parent->_color = Black;
					break;
				}
			}
		}
		_Header->_pParent->_color = Black;
		pNode curL = _Header->_pParent;
		while (curL->_pLeft)
		{
			curL = curL->_pLeft;
		}
		_Header->_pLeft = curL;
		
		pNode curR = _Header->_pParent;
		while (curR->_pRight)
		{
			curR = curR->_pRight;
		}
		_Header->_pRight = curR;
		return true;

	}
	//��ӡ
	void print(const RBTree<K,V>& tree)
	{
		Inoder(tree._Header->_pParent);
	}
	//���������֤
	bool IsValidRBTree()
	{
		pNode pRoot = _Header->_pParent;

		// ����Ҳ�Ǻ����
		if (nullptr == pRoot)
			return true;
		// �����ڵ��Ƿ��������
		if (Black != pRoot->_color)
		{
			cout << "Υ����������ʶ������ڵ����Ϊ��ɫ" << endl;
			return false;
		}
		// ��ȡ����һ��·���к�ɫ�ڵ�ĸ���
		size_t blackCount = 0;
		pNode pCur = pRoot;
		while (pCur)
		{
			if (Black == pCur->_color)
				blackCount++;
			pCur = pCur->_pLeft;
		}
		// ����Ƿ��������������ʣ�k������¼·���к�ɫ�ڵ�ĸ���
		size_t k = 0;
		return _IsValidRBTree(pRoot, k, blackCount);
	}
	bool _IsValidRBTree(pNode pRoot, size_t k, const size_t blackCount)
	{
		//�ߵ�null֮���ж�k��black�Ƿ����
		if (nullptr == pRoot)
		{
			if (k != blackCount)
			{
				cout << "Υ�������ģ�ÿ��·���к�ɫ�ڵ�ĸ���������ͬ" << endl;
				return false;
			}
			return true;
		}

		// ͳ�ƺ�ɫ�ڵ�ĸ���
		if (Black == pRoot->_color)
			k++;
		// ��⵱ǰ�ڵ�����˫���Ƿ�Ϊ��ɫ
		pNode pParent = pRoot->_pParent;
		if (pParent && Red == pParent->_color && Red == pRoot->_color)
		{
			cout << "Υ����������û������һ��ĺ�ɫ�ڵ�" << endl;
			return false;
		}
		return _IsValidRBTree(pRoot->_pLeft, k, blackCount) &&
			_IsValidRBTree(pRoot->_pRight, k, blackCount);
	}
private:
	//����
	void RotateL(pNode parent)
	{
		pNode subR = parent->_pRight;
		pNode subRL = subR->_pLeft;

		subR->_pLeft = parent;
		parent->_pRight = subRL;

		if(subRL != nullptr)
			subRL->_pParent = parent;

		if (parent != _Header->_pParent)
		{
			pNode gparent = parent->_pParent;

			if (gparent->_pRight == parent)
				gparent->_pRight = subR;
			else
				gparent->_pLeft = subR;

			subR->_pParent = gparent;

		}
		else
		{
			subR->_pParent = _Header;
			_Header->_pParent = subR;
		}
		parent->_pParent = subR;
	}
	//����
	void RotateR(pNode parent)
	{
		pNode subL = parent->_pLeft;
		pNode subLR = subL->_pRight;

		subL->_pRight = parent;
		parent->_pLeft = subLR;
		if (subLR)
			subLR->_pParent = parent;

		if (_Header->_pParent != parent)
		{
			pNode gparent = parent->_pParent;
			if (gparent->_pLeft == parent)
				gparent->_pLeft = subL;
			else
				gparent->_pRight = subL;
			subL->_pParent = gparent;
		}
		else {
			_Header->_pParent = subL;
			subL->_pParent = _Header;
		}
		parent->_pParent = subL;
	}

	void Inoder(pNode root)
	{
		if (root) {
			Inoder(root->_pLeft);
			cout << root->_kv.first << "-------" << root->_kv.second << endl;
			Inoder(root->_pRight);
		}
	}
private:
	pNode _Header;
};


int main()
{
	RBTree<int, string> tree;

	tree.insert(pair<int, string>(3, "�㽶"));
	tree.insert(pair<int, string>(2, "ƻ��"));
	tree.insert(pair<int, string>(4, "����"));
	tree.insert(pair<int, string>(1, "����"));

	tree.print(tree);
	cout << tree.IsValidRBTree() << endl;
	return 0;
}