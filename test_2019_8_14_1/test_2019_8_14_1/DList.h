#pragma once
#include <iostream>
using namespace std;
#include <assert.h>
typedef int DLDataType;
class DLNode
{
public:
	DLNode(const DLDataType& data)//�����㺯��
		:_pPrev(nullptr)
		, _pNext(nullptr)
		, _data(data)
	{}
	DLNode* _pPrev;
	DLNode* _pNext;
	DLDataType _data;
};
class DList
{
public:
	DList()//���캯��
	{
		DListInit();//��ʼ��
	}
	
	DList(const DList& d)//�������캯��
	{
		_pHead = new DLNode(0);
		_pHead->_pNext = _pHead;
		_pHead->_pPrev = _pHead;
		DLNode* cur = d._pHead->_pNext;
		while (cur != d._pHead)
		{
			this->DListPushBack(cur->_data);
			cur = cur->_pNext;
		}
	}
	DList& operator=(DList& s)
	{
		swap(_pHead, s._pHead);
		return *this;
	}
	~DList()
	{
		DListClear();
		delete _pHead;
		_pHead = nullptr;
	}
	void DListInit();
	void DListPushBack(DLDataType data);//β��
	void DListPopBack();//βɾ
	void DListPushFront(DLDataType data);//ͷ��
	void DListPopfront();//ͷɾ
	DLNode* Find(DLDataType data);//����
	void DListInsertFront(DLNode* pos,DLDataType data);//����λ�ò���
	void DListErase(DLNode* pos);//����λ��ɾ��
	void PrintDList();//��ӡ
	void DListClear();//�����������е���Ч��������
	int DListSize();//��ȡ�����С
	bool Empty() const;//�п�
	const DLDataType& DListFront() const;//ȡ����һ��Ԫ��
	const DLDataType& DListBack()const;//ȡ�����һ��Ԫ��
private:	
	DLNode* _pHead; 
};