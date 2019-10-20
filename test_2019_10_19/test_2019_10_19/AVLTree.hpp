#pragma once
#include <iostream>
using namespace std;
template<class K,class V>
struct AVLTreeNode
{
	AVLTreeNode(const pair<K, V> &data)
	:_pLeft(nullptr)
	, _pRight(nullptr)
	, _pParent(nullptr)
	, _data(data)
	, _bf(0)
	{}
	AVLTreeNode<K, V>* _pLeft;
	AVLTreeNode<K, V>* _pRight;
	AVLTreeNode<K, V>* _pParent;
	pair<K, V> _data;
	int _bf;//平衡因子
};
template<class K,class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	AVLTree()
		:_pRoot(nullptr)
	{}
	bool Insert(const pair<K, V> &data)
	{
		//先按照二叉搜索树的规则插入
		if (_pRoot == nullptr)
		{
			_pRoot = new Node(data);
			return true;
		}
		Node* pCur = _pRoot;
		Node* pParent = nullptr;
		while (pCur)
		{
			pParent = pCur;
			if (data.first < pCur->_data.first)
			{
				pCur = pCur->_pLeft;
			}
			else if (data.first>pCur->_data.first)
			{
				pCur = pCur->_pRight;
			}
			else
			{
				return false;//说明已经有这个结点，插入失败
			}
		}
		//开始插入
		pCur = new Node(data);//申请一个新结点
		if (data.first < pCur->_data.first)
		{
			pParent->_pLeft = pCur;
		}
		else
		{
			pParent->_pRight = pCur;
		}
		pCur->_pParent = pParent;
		while (pParent)
		{
			//AVL：必须更新双亲节点pParent的双亲
			if (pCur == pParent->_pLeft)//将pCur插入到了双亲的左侧
			{
				pParent->_bf--;//平衡因子--
			}
			else//将pCur插入到了双亲的右侧
			{
				pParent->_bf++;//平衡因子++
			}
			if (pParent->_bf == 0)
				break;
			else if (1 == pParent->_bf || -1 == pParent->_bf)
			{
				pCur = pParent;
				pParent = pCur->_pParent;
			}
			else//pParent的平衡因子已经为正负2
			{
				if (2 == pParent->_bf)//右子树比较高
				{
					if (1 == pCur->_bf)//左单旋,因为此时右子树高
						RotateL(pParent);
					else
						RotateRL(pParent);				
				}
				else
				{
					if (pCur->_bf == -1)//右单旋,因为此时左子树比较高
						RotateR(pParent);
					else
						RotateLR(pParent);
				}
				break;
			}
		}
		return true;
	}
	void Inorder()
	{
		_Inorder(_pRoot);
	}
	bool IsBalanceTree()
	{
		return _IsBalaceTree(_pRoot);
	}
private:
	size_t _Height(Node* pRoot)
	{
		if (nullptr == pRoot)
			return 0;
		size_t LeftHeight = _Height(pRoot->_pLeft);
		size_t RightHeight = _Height(pRoot->_pRight);
		return LeftHeight > RightHeight ? LeftHeight : RightHeight + 1;
	}
	bool _IsBalaceTree(Node* pRoot)
	{
		if (nullptr == pRoot)
			return true;
		size_t LeftHeight = _Height(pRoot->_pLeft);
		size_t RightHeight = _Height(pRoot->_pRight);
		int bf = RightHeight - LeftHeight;
		if (abs(bf) > 1 && bf!=pRoot->_bf)
			return false;
		return _IsBalaceTree(pRoot->_pLeft) && _IsBalaceTree(pRoot->_pRight);
	}
	void _Inorder(Node* pRoot)
	{
		if (pRoot)
		{
			_Inorder(pRoot->_pLeft);
			cout << pRoot->_data.first << " ";
			_Inorder(pRoot->_pRight);
		}
	}
	//右单旋
	void RotateR(Node* pParent)//这里pParent指80
	{
		Node* pSubL = pParent->_pLeft;//这里pSubL指60
		Node* pSubLR = pSubL->_pRight;

		//旋转
		pParent->_pLeft = pSubLR;//即让80的左孩子指向70
		if (pSubLR)//如果指如果60的右孩子存在
		{
			pSubLR->_pParent = pParent;//让70双亲指向80
		}

		pSubL->_pRight = pParent;//让60的右孩子指向80

		//因为80可能是一棵子树，即不是根结点，所以在更新双亲前应该保存双亲，以便后面的60更新双亲
		Node* pPParent = pParent->_pParent;

		//更新60的双亲
		pSubL->_pParent = pPParent;

		//更新80的双亲
		pParent->_pParent = pSubL;
		//如果80在旋转之前是根结点
		if (nullptr == pPParent)
		{
			_pRoot = pSubL;
			pSubL->_pParent = nullptr;
		}
		else//如果80不是根结点，此时考虑两种可能，80是pPParent的左右孩子其中一个两种可能
		{
			if (pPParent->_pLeft = pParent)
			{
				pPParent->_pLeft = pSubL;
			}
			else
				pPParent->_pRight = pSubL;
		}
		pParent->_bf = pSubL->_bf = 0;//更新平衡因子

	}
	//左单旋
	void RotateL(Node* pParent)//pParent指30
	{
		Node* pSubR = pParent->_pRight;//此时psubR指50
		Node* pSubRL = pSubR->_pLeft;//此处pSubRL指40

		//旋转
		pParent->_pRight = pSubRL;
		if (pSubRL)
		{
			pSubRL->_pParent = pParent;//让40的双亲指向30
		}

		pSubR->_pLeft = pParent;//让50的左孩子指向30

		//改变50和30的双亲
		Node* pPParent = pParent->_pParent;//先将30的双亲存下来，后面更新30的双亲会造成50找不到30的双亲

		//改变50的双亲，有两种情况
		pSubR->_pParent = pPParent;

		//改变30的双亲为50
		pParent->_pParent = pSubR;
		if (nullptr == pPParent)//说明30在旋转之前是根结点
		{
			_pRoot = pSubR;
			pSubR->_pParent = nullptr;
		}
		else//30原本双亲不是空，有两种可能
		{
			if (pPParent->_pLeft = pParent)
			{
				pPParent->_pLeft = pSubR;
			}
			else
				pPParent->_pRight = pSubR;
		}
		pParent->_bf = pSubR->_bf = 0;//更新平衡因子
	}
	void RotateRL(Node* pParent)
	{
		Node* pSubR = pParent->_pRight;
		Node* pSubRL = pSubR->_pLeft;
		int bf = pSubRL->_bf;
		RotateR(pSubR);
		RotateL(pParent);
		if (bf == 1)
			pParent->_bf = -1;
		else if (bf == -1)
			pSubR->_bf = 1;
	}
	void RotateLR(Node* pParent)
	{
		Node* pSubL = pParent->_pLeft;
		Node* pSubLR = pSubL->_pRight;
		int bf = pSubLR->_bf;
		RotateL(pSubL);
		RotateR(pParent);
		if (bf == 1)
			pSubL->_bf = -1;
		if (bf == -1)
			pParent->_bf = 1;
	}
private:
	Node* _pRoot;
};