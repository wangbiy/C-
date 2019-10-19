#pragma once
#include <iostream>
using namespace std;
template <class T>
struct BSTNode
{
	BSTNode(const T& data = T())//���캯��
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
		if (nullptr == _pRoot)//����
		{
			_pRoot = new Node(data);
			return true;
		}
		Node* pCur = _pRoot;
		Node* Parent = nullptr;//��һ�����
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
	bool Delete(const T& data)//ɾ��
	{
		if (nullptr==_pRoot)
		{
			return false;
		}
		//���ն����������Ĺ����Ҵ�ɾ������λ��
		Node* pCur = _pRoot;
		Node* Parent = nullptr;
		while (pCur)
		{
			if (data == pCur->_data)//�ҵ���
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
		if (pCur == nullptr)//��ɾ����㲻����
			return false;
		//��ʼɾ��
		/*1����ɾ�������Ҷ�ӽ��,Ҳ����û�����Һ���
		//2��ֻ������
		//3��ֻ���Һ���
		//4�����Һ��Ӷ�����
		1������2����3�ϲ���һ��
		*/
		if (nullptr == pCur->_pLeft)//1��3�ϲ�
		{
			if (pCur == _pRoot)//��ɾ������Ǹ������ֻ���Һ���
			{
				_pRoot = pCur->_pRight;
			}
			else
			{
				//��ɾ�������˫�׵�����
				if (pCur == Parent->_pLeft)
					Parent->_pLeft = pCur->_pRight;
				else
					Parent->_pRight = pCur->_pRight;
			}
		}
		else if (nullptr == pCur->_pRight)//1��2�ϲ�
		{
			if (pCur == _pRoot)//��ɾ������Ǹ������ֻ���Һ���
			{
				_pRoot = pCur->_pLeft;
			}
			else
			{
				//��ɾ�������˫�׵�����
				if (pCur == Parent->_pLeft)
					Parent->_pLeft = pCur->_pLeft;
				else
					Parent->_pRight = pCur->_pLeft;
			}
		}
		else//���Һ��Ӷ�����,��������(����������������������������С�ģ�Ҳ����������������ģ�
		{
			Node* Firstofin = pCur->_pRight;//������������
			Parent = pCur;
			while (Firstofin->_pLeft)//�������
			{
				Parent = Firstofin;//���Parent�����ҵ�������������С�Ľڵ��˫��
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
	Node* LeftMost()//�������ģ���С�ģ�
	{
		if (_pRoot == nullptr)
		return nullptr ;
		Node* pCur = _pRoot;
		while (pCur->_pLeft)
			pCur = pCur->_pLeft;
		return pCur;
	}
	Node* RightMost()//�����Ҳ�ģ����ģ�
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
	void Destroy(Node*& root)//���ٻ�ı�ָ��ָ��
	{
		if (root)
		{
			Destroy(root->_pLeft);
			Destroy(root->_pRight);
			delete root;//���ݺ������������
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
	//ֻ���Һ���---��˫�׵��Һ���
	t.Delete(8);
	t.Inorder();
	cout << endl;
	//ֻ���Һ���===��˫�׵�����
	t.Delete(1);
	t.Inorder();
	cout << endl;

	//���Һ��Ӷ�����
	t.Delete(5);
	t.Inorder();
	cout << endl;
}
