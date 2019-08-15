#pragma once
#include <iostream>
using namespace std;
typedef int DataType;
class QNode//结点
{
public:
	QNode* _pNext;
	DataType _data;
	QNode(DataType data)//构造结点
		:_data(data)
		, _pNext(nullptr)
	{}

};
class Queue
{
public:
	Queue()//构造队列
		:front(nullptr)
		,rear(nullptr)
	{}
	~Queue()
	{
		QNode* cur = front;
		while (cur)
		{
			front = cur->_pNext;
			delete cur;
			cur = front;
		}
		front = rear = nullptr;
	}
	void QueuePush(DataType data);//入队,类似于尾插
	void QueuePop();//出队
	DataType QueueFront();//获取队头元素
	DataType QueueBack();//获取队尾元素
	bool Queuempty();//判空
	int QueueSize();//获取有效元素个数
	void QueueShow();
private:
	QNode* front;
	QNode* rear;
};