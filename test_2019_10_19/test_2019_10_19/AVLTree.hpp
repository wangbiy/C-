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
	int _bf;//ƽ������
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
		//�Ȱ��ն����������Ĺ������
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
				return false;//˵���Ѿ��������㣬����ʧ��
			}
		}
		//��ʼ����
		pCur = new Node(data);//����һ���½��
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
			//AVL���������˫�׽ڵ�pParent��˫��
			if (pCur == pParent->_pLeft)//��pCur���뵽��˫�׵����
			{
				pParent->_bf--;//ƽ������--
			}
			else//��pCur���뵽��˫�׵��Ҳ�
			{
				pParent->_bf++;//ƽ������++
			}
			if (pParent->_bf == 0)
				break;
			else if (1 == pParent->_bf || -1 == pParent->_bf)
			{
				pCur = pParent;
				pParent = pCur->_pParent;
			}
			else//pParent��ƽ�������Ѿ�Ϊ����2
			{
				if (2 == pParent->_bf)//�������Ƚϸ�
				{
					if (1 == pCur->_bf)//����,��Ϊ��ʱ��������
						RotateL(pParent);
					else
						RotateRL(pParent);				
				}
				else
				{
					if (pCur->_bf == -1)//�ҵ���,��Ϊ��ʱ�������Ƚϸ�
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
	//�ҵ���
	void RotateR(Node* pParent)//����pParentָ80
	{
		Node* pSubL = pParent->_pLeft;//����pSubLָ60
		Node* pSubLR = pSubL->_pRight;

		//��ת
		pParent->_pLeft = pSubLR;//����80������ָ��70
		if (pSubLR)//���ָ���60���Һ��Ӵ���
		{
			pSubLR->_pParent = pParent;//��70˫��ָ��80
		}

		pSubL->_pRight = pParent;//��60���Һ���ָ��80

		//��Ϊ80������һ�������������Ǹ���㣬�����ڸ���˫��ǰӦ�ñ���˫�ף��Ա�����60����˫��
		Node* pPParent = pParent->_pParent;

		//����60��˫��
		pSubL->_pParent = pPParent;

		//����80��˫��
		pParent->_pParent = pSubL;
		//���80����ת֮ǰ�Ǹ����
		if (nullptr == pPParent)
		{
			_pRoot = pSubL;
			pSubL->_pParent = nullptr;
		}
		else//���80���Ǹ���㣬��ʱ�������ֿ��ܣ�80��pPParent�����Һ�������һ�����ֿ���
		{
			if (pPParent->_pLeft = pParent)
			{
				pPParent->_pLeft = pSubL;
			}
			else
				pPParent->_pRight = pSubL;
		}
		pParent->_bf = pSubL->_bf = 0;//����ƽ������

	}
	//����
	void RotateL(Node* pParent)//pParentָ30
	{
		Node* pSubR = pParent->_pRight;//��ʱpsubRָ50
		Node* pSubRL = pSubR->_pLeft;//�˴�pSubRLָ40

		//��ת
		pParent->_pRight = pSubRL;
		if (pSubRL)
		{
			pSubRL->_pParent = pParent;//��40��˫��ָ��30
		}

		pSubR->_pLeft = pParent;//��50������ָ��30

		//�ı�50��30��˫��
		Node* pPParent = pParent->_pParent;//�Ƚ�30��˫�״��������������30��˫�׻����50�Ҳ���30��˫��

		//�ı�50��˫�ף����������
		pSubR->_pParent = pPParent;

		//�ı�30��˫��Ϊ50
		pParent->_pParent = pSubR;
		if (nullptr == pPParent)//˵��30����ת֮ǰ�Ǹ����
		{
			_pRoot = pSubR;
			pSubR->_pParent = nullptr;
		}
		else//30ԭ��˫�ײ��ǿգ������ֿ���
		{
			if (pPParent->_pLeft = pParent)
			{
				pPParent->_pLeft = pSubR;
			}
			else
				pPParent->_pRight = pSubR;
		}
		pParent->_bf = pSubR->_bf = 0;//����ƽ������
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