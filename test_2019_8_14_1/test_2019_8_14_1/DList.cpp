#include "DList.h"
void DList:: DListInit()//初始化
{
	_pHead = new DLNode(0);
	_pHead->_pNext = _pHead;
	_pHead->_pPrev = _pHead;
}
void DList::DListClear()
{
	DLNode* cur = _pHead->_pNext;
	while (cur!=_pHead)
	{
		_pHead->_pNext = cur->_pNext;
		delete cur;
		cur = _pHead->_pNext;
	}
	_pHead->_pNext = _pHead;
	_pHead->_pPrev = _pHead;
}
void DList::PrintDList()//打印
{
	DLNode* cur = _pHead->_pNext;
	while (cur != _pHead)
	{
		cout << cur->_data << " ";
		cur = cur->_pNext;
	}
	cout << endl;
}
void DList::DListPushBack(DLDataType data)
{
	DLNode* pNewNode = new DLNode(data);
	pNewNode->_pPrev = _pHead->_pPrev;
	pNewNode->_pNext = _pHead;
	_pHead->_pPrev = pNewNode;
	pNewNode->_pPrev->_pNext = pNewNode;
}
void DList::DListPopBack()
{
	assert(_pHead);//链表是否存在,PHead代表头结点,只要链表不销毁，这个头结点永远存在
	if (_pHead == _pHead->_pNext)//空链表
		return;
	DLNode* pDelNode = _pHead->_pPrev;
	pDelNode->_pPrev->_pNext = _pHead;
	_pHead->_pPrev = pDelNode->_pPrev;
	delete pDelNode;
}
void DList::DListPushFront(DLDataType data)//头插
{
	DLNode* pNewNode = new DLNode(data);
	assert(_pHead);
	pNewNode->_pNext = _pHead->_pNext;
	pNewNode->_pPrev = _pHead;
	_pHead->_pNext = pNewNode;
	pNewNode->_pNext->_pPrev = pNewNode;
}
void DList::DListPopfront()
{
	assert(_pHead);
	if (_pHead->_pNext == _pHead)//空链表
		return;
	DLNode* pDelNode = _pHead->_pNext;
	_pHead->_pNext = pDelNode->_pNext;
	pDelNode->_pNext->_pPrev = _pHead;
	delete pDelNode;
}
DLNode* DList::Find(DLDataType data)
{
	assert(_pHead);
	DLNode* cur = _pHead->_pNext;
	while (cur != _pHead)
	{
		if (cur->_data == data)
			return cur;
		cur = cur->_pNext;
	}
	return nullptr;
}
void DList::DListInsertFront(DLNode* pos, DLDataType data)
{
	assert(_pHead);
	DLNode* pNewNode = new DLNode(data);
	if (pos == nullptr)
		return;
	pNewNode->_pNext = pos;
	pNewNode->_pPrev = pos->_pPrev;
	pos->_pPrev = pNewNode;
	pNewNode->_pPrev->_pNext = pNewNode;
}
void DList::DListErase(DLNode* pos)
{
	if (pos == nullptr)
		return;
	pos->_pPrev->_pNext = pos->_pNext;
	pos->_pNext->_pPrev = pos->_pPrev;
	delete pos;
}
int DList::DListSize()
{
	int size = 0;
	DLNode* cur = _pHead->_pNext;
	while (cur != _pHead)
	{
		++size;
		cur = cur->_pNext;
	}
	return size;
}
bool DList::Empty() const
{
	return _pHead->_pNext == _pHead;
}
const DLDataType& DList::DListFront() const
{
	assert(!Empty());
	return _pHead->_pNext->_data;
}
const DLDataType& DList::DListBack()const
{
	assert(!Empty());
	return _pHead->_pPrev->_data;
}

