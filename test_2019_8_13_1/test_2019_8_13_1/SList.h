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
	Node(SDataType data)//构造结点
		:_data(data)
		, _pNext(nullptr)
	{}
};
class SList
{
public:
	SList()//初始化
		:_pHead(nullptr)
		, _Tail(nullptr)
	{}
	SList(const SList& l)//拷贝构造函数
		:_pHead(nullptr)
		,_Tail(nullptr)
	{
		Node* cur = l._pHead;
		if (cur == nullptr)
			return;
		while (cur)
		{
			this->SListPushBack(cur->_data);//尾插当前值
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
	~SList()//销毁
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
	void SListPushBack(SDataType data);//尾插
	void SListPopBack();
	void SListPushFront(SDataType data);//头插
	void SListPopFront();
	void SListInsertAfter(Node* pos, SDataType data);//任意位置插入
	void SListErase(Node* pos);//任意位置删除
	Node* SListFind(SDataType data);//查找
	int SListSize();//结点个数
	Node* SListFront();//获取第一个节点
	Node* SListBack();//获取最后一个节点
	int SListEmpty();//判空
	void PrintSList();
	Node* ReverseSList();//逆置单链表
private:
	Node* _pHead;
	Node* _Tail;//链表尾结点
};