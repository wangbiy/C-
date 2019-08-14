#include "SList.h"
void SList::SListPushBack(SDataType data)
{
	if (_pHead == nullptr)
		_pHead = _Tail = new Node(data);//ֱ�Ӳ���
	else
	{
		_Tail->_pNext = new Node(data);
		_Tail = _Tail->_pNext;
	}
}
void SList::SListPopBack()
{
	Node* TailPrev = _pHead;
	if (_pHead == nullptr)
		return;
	else if (_pHead->_pNext == nullptr)//ֻ��һ�����
	{
		delete _pHead;
		_pHead = _Tail = nullptr;
	}
	else//�ж���ڵ�
	{
		Node* cur = _pHead;
		while (cur->_pNext != _Tail)
		{
			cur = cur->_pNext;
		}
		delete _Tail;
		_Tail = cur;
		_Tail->_pNext = nullptr;
	}
}
void SList::SListPushFront(SDataType data)
{
	Node* temp = _pHead;
	_pHead = _Tail = new Node(data);
	_pHead->_pNext = temp;
}
void SList::SListPopFront()
{
	if (_pHead == nullptr)
		return;
	else if (_pHead->_pNext == nullptr)
	{
		delete _pHead;
		_pHead = _Tail = nullptr;
	}
	else
	{
		Node* DelNode = _pHead;
		_pHead = DelNode->_pNext;
		delete DelNode;
	}
}
Node* SList::SListFind(SDataType data)
{
	assert(_pHead);
	Node* cur = _pHead;
	while (cur)
	{
		if (cur->_data == data)
			return cur;
		cur = cur->_pNext;
	}
	return cur;
}
void SList::SListInsertAfter(Node* pos, SDataType data)
{
	if (pos == nullptr)
		return;
	Node* pNewNode = new Node(data);
	pNewNode->_pNext = pos->_pNext;
	pos->_pNext = pNewNode;
}
void SList::SListErase(Node* pos)
{
	if (_pHead == nullptr || pos == nullptr)
		return;
	else if (pos == _pHead)
	{
		_pHead = pos->_pNext;
		delete pos;
	}
	else
	{
		Node* PrePos = _pHead;
		while (PrePos->_pNext != pos)
		{
			PrePos = PrePos->_pNext;
		}
		PrePos->_pNext = pos->_pNext;
		delete pos;
	}
}
int SList::SListSize()
{
	Node* cur = _pHead;
	int size = 0;
	while (cur)
	{
		size++;
		cur = cur->_pNext;
	}
	return size;
}
Node* SList::SListFront()
{
	return _pHead;
}
Node* SList::SListBack()
{
	Node* cur = _pHead;
	while (cur->_pNext)
	{
		cur = cur->_pNext;
	}
	return cur;
}
int SList::SListEmpty()
{
	return nullptr == _pHead;
}

void SList::PrintSList()
{
	Node* cur = _pHead;
	while (cur)
	{
		cout << cur->_data << "--->";
		cur = cur->_pNext;
	}
	cout <<"NULL"<< endl;
}
Node* SList::ReverseSList()
{
	if (_pHead == nullptr || _pHead->_pNext == nullptr)
	{
		return nullptr;
	}
	Node* cur = _pHead;
	Node* pre = _pHead;
	Node* Del = _pHead->_pNext; 
	//�ӵڶ����ڵ㿪ʼ��ժ��ÿ���ڵ㣬ͷ�嵽ԭʼ����
	//Ȼ�󽫵�һ���ڵ��Ľ���ͷ�
	while (cur->_pNext)//ͷ��
	{
		SListPushFront(cur->_pNext->_data);
		cur = cur->_pNext;
	}
	while (Del)//�ͷ�
	{
		Node* _pDel = Del;
		Del = Del->_pNext;
		delete _pDel;
	}
	_Tail = pre;
	_Tail->_pNext = nullptr;
}