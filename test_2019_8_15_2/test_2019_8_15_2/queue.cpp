#include "queue.h"
void Queue::QueueShow()
{
	QNode* cur = front;
	while (cur)
	{
		cout << cur->_data << "--->";
		cur = cur->_pNext;
	}
	cout << "nullptr"<<endl;
}
void Queue::QueuePush(DataType data)
{
	QNode* pNewNode = new QNode(data);
	if (nullptr == rear)//©у╤сап
	{
		rear = front = pNewNode;
	}
	else
	{
		rear->_pNext = pNewNode;
		rear = pNewNode;
	}
}
void Queue::QueuePop()
{
	if (nullptr == front)
		return;
	else if (front == rear)
	{
		delete front;
		front = rear = nullptr;
	}
	else
	{
		QNode* pDelNode = front;
		front = pDelNode->_pNext;
		delete pDelNode;
	}
}
DataType Queue::QueueFront()
{
	return front->_data;
}
DataType Queue::QueueBack()
{
	return rear->_data;
}
bool Queue::Queuempty()
{
	return nullptr == front;
}
int Queue::QueueSize()
{
	QNode* cur = front;
	int size = 0;
	while (cur)
	{
		size++;
		cur = cur->_pNext;
	}
	return size;
}