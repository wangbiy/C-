#pragma once
#include <iostream>
using namespace std;
#include <assert.h>
typedef int DLDataType;
class DLNode
{
public:
	DLNode(const DLDataType& data)//构造结点函数
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
	DList()//构造函数
	{
		DListInit();//初始化
	}
	
	DList(const DList& d)//拷贝构造函数
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
	void DListPushBack(DLDataType data);//尾插
	void DListPopBack();//尾删
	void DListPushFront(DLDataType data);//头插
	void DListPopfront();//头删
	DLNode* Find(DLDataType data);//查找
	void DListInsertFront(DLNode* pos,DLDataType data);//任意位置插入
	void DListErase(DLNode* pos);//任意位置删除
	void PrintDList();//打印
	void DListClear();//将链表中所有的有效结点清理掉
	int DListSize();//获取链表大小
	bool Empty() const;//判空
	const DLDataType& DListFront() const;//取出第一个元素
	const DLDataType& DListBack()const;//取出最后一个元素
private:	
	DLNode* _pHead; 
};