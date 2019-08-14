#pragma once
#include <iostream>
using namespace std;
#include <assert.h>
typedef int SDataType;
class Node
{
public:
	SDataType _data;
	Node* _pNext;
	Node(SDataType data)//������
		:_data(data)
		, _pNext(nullptr)
	{}
};
class SList
{
public:
	SList()//��ʼ��
		:_pHead(nullptr)
		, _Tail(nullptr)
	{}
	SList(const SList& l)//�������캯��
		:_pHead(nullptr)
		,_Tail(nullptr)
	{
		Node* cur = l._pHead;
		if (cur == nullptr)
			return;
		while (cur)
		{
			this->SListPushBack(cur->_data);//β�嵱ǰֵ
			cur = cur->_pNext;
		}
	}
	void SListDestroy()
	{
		Node* cur = _pHead;
		while (cur)
		{
			Node* DelNode = cur;
			cur = cur->_pNext;
			delete DelNode;
		}
		_pHead = _Tail = nullptr;
	}
	~SList()//����
	{
		SListDestroy();
	}
	SList& operator=(SList& l)
	{
		if (this != &l)
		{
			swap(_pHead, l._pHead);
			swap(_Tail, l._Tail);
		}
		return *this;
	}
	void SListPushBack(SDataType data);//β��
	void SListPopBack();
	void SListPushFront(SDataType data);//ͷ��
	void SListPopFront();
	void SListInsertAfter(Node* pos, SDataType data);//����λ�ò���
	void SListErase(Node* pos);//����λ��ɾ��
	Node* SListFind(SDataType data);//����
	int SListSize();//������
	Node* SListFront();//��ȡ��һ���ڵ�
	Node* SListBack();//��ȡ���һ���ڵ�
	int SListEmpty();//�п�
	void PrintSList();
	Node* ReverseSList();//���õ�����
private:
	Node* _pHead;
	Node* _Tail;//����β���
};