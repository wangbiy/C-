#pragma once
#include <iostream>
using namespace std;
template <class T>
struct BSTNode
{
	BSTNode(const T& data = T())//构造函数
	:_pLeft(nullptr)
	, _pRight(nullptr)
	, _data(data)
	{}
	BSTNode <T>* _pLeft;
	BSTNode <T>* _pRight;
	T _data;
};
template <class T>
class BSTree
{
	typedef BSTNode<T> Node;
public:
	BSTree()
		:_pRoot(nullptr)
	{}
	Node* find(const T& data)
	{
		Node* pCur = _pRoot;
		while (pCur)
		{
			if (data == pCur->_data)
				return pCur;
			else if (data < pCur->_data)
			{
				pCur = pCur->_pLeft;
			}
			else
				pCur = pCur->_pRight;
		}
		return nullptr;
	}
	bool Insert(const T& data)
	{
		if (nullptr == _pRoot)//空树
		{
			_pRoot = new Node(data);
			return true;
		}
		Node* pCur = _pRoot;
		Node* Parent = nullptr;//给一个标记
		while (pCur)
		{
			Parent = pCur;
			if (data < pCur->_data)
			{
				pCur = pCur->_pLeft;
			}
			else if (data>pCur->_data)
				pCur = pCur->_pRight;
			else
				return false;
		}
		pCur = new Node(data);
		if (data < Parent->_data)
			Parent->_pLeft = pCur;
		else 
			Parent->_pRight = pCur;
		return true;		
	}
	bool Delete(const T& data)//删除
	{
		if (nullptr==_pRoot)
		{
			return false;
		}
		//按照二叉搜索树的规则找待删除结点的位置
		Node* pCur = _pRoot;
		Node* Parent = nullptr;
		while (pCur)
		{
			if (data == pCur->_data)//找到了
				break;
			else if (data < pCur->_data)
			{
				Parent = pCur;
				pCur = pCur->_pLeft;
			}
			else
			{
				Parent = pCur;
				pCur = pCur->_pRight;
			}	
		}
		if (pCur == nullptr)//待删除结点不存在
			return false;
		//开始删除
		/*1、待删除结点是叶子结点,也就是没有左右孩子
		//2、只有左孩子
		//3、只有右孩子
		//4、左右孩子都存在
		1可以与2或者3合并在一起
		*/
		if (nullptr == pCur->_pLeft)//1和3合并
		{
			if (pCur == _pRoot)//待删除结点是根结点且只有右孩子
			{
				_pRoot = pCur->_pRight;
			}
			else
			{
				//待删除结点是双亲的左孩子
				if (pCur == Parent->_pLeft)
					Parent->_pLeft = pCur->_pRight;
				else
					Parent->_pRight = pCur->_pRight;
			}
		}
		else if (nullptr == pCur->_pRight)//1和2合并
		{
			if (pCur == _pRoot)//待删除结点是根结点且只有右孩子
			{
				_pRoot = pCur->_pLeft;
			}
			else
			{
				//待删除结点是双亲的左孩子
				if (pCur == Parent->_pLeft)
					Parent->_pLeft = pCur->_pLeft;
				else
					Parent->_pRight = pCur->_pLeft;
			}
		}
		else//左右孩子都存在,找替代结点(在这里我们在它的右子树中找最小的，也就是右子树中最左的）
		{
			Node* Firstofin = pCur->_pRight;//在右子树中找
			Parent = pCur;
			while (Firstofin->_pLeft)//找最左的
			{
				Parent = Firstofin;//这个Parent就是找到的右子树中最小的节点的双亲
				Firstofin = Firstofin->_pLeft;
			}
			pCur->_data = Firstofin->_data;
			if (Firstofin == Parent->_pLeft)
				Parent->_pLeft = Firstofin->_pRight;
			else
				Parent->_pRight = Firstofin->_pRight;
			pCur = Firstofin;
		}
		delete pCur;
		return true;
	}
	Node* LeftMost()//找最左侧的（最小的）
	{
		if (_pRoot == nullptr)
		return nullptr ;
		Node* pCur = _pRoot;
		while (pCur->_pLeft)
			pCur = pCur->_pLeft;
		return pCur;
	}
	Node* RightMost()//找最右侧的（最大的）
	{
		if (_pRoot == nullptr)
			return nullptr;
		Node* pCur = _pRoot;
		while (pCur->_pRight)
			pCur = pCur->_pRight;
		return pCur;
	}
	void Inorder()
	{
		_Inorder(_pRoot);
	}
private:
	void _Inorder(Node* root)
	{
		if (root)
		{
			_Inorder(root->_pLeft);
			cout << root->_data <<" ";
			_Inorder(root->_pRight);
		}
	}
	void Destroy(Node*& root)//销毁会改变指针指向
	{
		if (root)
		{
			Destroy(root->_pLeft);
			Destroy(root->_pRight);
			delete root;//根据后序遍历来销毁
			root = nullptr;
		}
	}
private:
	Node* _pRoot;
};
void testBSTree()
{
	int array[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	BSTree<int> t;
	for (auto e : array)
	{
		t.Insert(e);
	}
	cout << t.LeftMost()->_data << endl;
	cout << t.RightMost()->_data << endl;
	BSTNode<int>* pCur = t.find(2);
	if (pCur)
		cout << "2 is in BSTree" << endl;
	else
		cout << "2 is not in BSTree" << endl;
	t.Inorder();
	cout << endl;
	//只有右孩子---其双亲的右孩子
	t.Delete(8);
	t.Inorder();
	cout << endl;
	//只有右孩子===其双亲的左孩子
	t.Delete(1);
	t.Inorder();
	cout << endl;

	//左右孩子都存在
	t.Delete(5);
	t.Inorder();
	cout << endl;
}
