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
	//插入
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

		//先找地方插
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

		//插上
		cur = new Node;
		cur->_kv = kv;
		if (parent->_kv.first > kv.first)
			parent->_pLeft = cur;
		else
			parent->_pRight = cur;

		cur->_pParent = parent;


		//调整 插入节点是黑色 双亲为黑色不需要调整
		//cur为红， p为红， /g为黑
		while (cur != _Header->_pParent && cur->_pParent->_color == Red)
		{
			parent = cur->_pParent;
			pNode gparent = parent->_pParent;
	
			if (gparent->_pLeft == parent) 
			{
				pNode uncle = gparent->_pRight;
				if (uncle && uncle->_color == Red)
				{
					//u存在且为红
					uncle->_color = Black;
					parent->_color = Black;
					gparent->_color = Red;
					cur = gparent;
				}
				else
				{
					//u不存在/u为黑
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
					//u存在且为红
					uncle->_color = Black;
					parent->_color = Black;
					gparent->_color = Red;
					cur = gparent;
				}
				else
				{
					//u不存在/u为黑
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
	//打印
	void print(const RBTree<K,V>& tree)
	{
		Inoder(tree._Header->_pParent);
	}
	//红黑树的验证
	bool IsValidRBTree()
	{
		pNode pRoot = _Header->_pParent;

		// 空树也是红黑树
		if (nullptr == pRoot)
			return true;
		// 检测根节点是否满足情况
		if (Black != pRoot->_color)
		{
			cout << "违反红黑树性质二：根节点必须为黑色" << endl;
			return false;
		}
		// 获取任意一条路径中黑色节点的个数
		size_t blackCount = 0;
		pNode pCur = pRoot;
		while (pCur)
		{
			if (Black == pCur->_color)
				blackCount++;
			pCur = pCur->_pLeft;
		}
		// 检测是否满足红黑树的性质，k用来记录路径中黑色节点的个数
		size_t k = 0;
		return _IsValidRBTree(pRoot, k, blackCount);
	}
	bool _IsValidRBTree(pNode pRoot, size_t k, const size_t blackCount)
	{
		//走到null之后，判断k和black是否相等
		if (nullptr == pRoot)
		{
			if (k != blackCount)
			{
				cout << "违反性质四：每条路径中黑色节点的个数必须相同" << endl;
				return false;
			}
			return true;
		}

		// 统计黑色节点的个数
		if (Black == pRoot->_color)
			k++;
		// 检测当前节点与其双亲是否都为红色
		pNode pParent = pRoot->_pParent;
		if (pParent && Red == pParent->_color && Red == pRoot->_color)
		{
			cout << "违反性质三：没有连在一起的红色节点" << endl;
			return false;
		}
		return _IsValidRBTree(pRoot->_pLeft, k, blackCount) &&
			_IsValidRBTree(pRoot->_pRight, k, blackCount);
	}
private:
	//左旋
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
	//右旋
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

	tree.insert(pair<int, string>(3, "香蕉"));
	tree.insert(pair<int, string>(2, "苹果"));
	tree.insert(pair<int, string>(4, "葡萄"));
	tree.insert(pair<int, string>(1, "西瓜"));

	tree.print(tree);
	cout << tree.IsValidRBTree() << endl;
	return 0;
}