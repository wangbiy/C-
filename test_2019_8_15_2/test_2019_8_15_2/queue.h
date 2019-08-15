#pragma once
#include <iostream>
using namespace std;
typedef int DataType;
class QNode//���
{
public:
	QNode* _pNext;
	DataType _data;
	QNode(DataType data)//������
		:_data(data)
		, _pNext(nullptr)
	{}

};
class Queue
{
public:
	Queue()//�������
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
	void QueuePush(DataType data);//���,������β��
	void QueuePop();//����
	DataType QueueFront();//��ȡ��ͷԪ��
	DataType QueueBack();//��ȡ��βԪ��
	bool Queuempty();//�п�
	int QueueSize();//��ȡ��ЧԪ�ظ���
	void QueueShow();
private:
	QNode* front;
	QNode* rear;
};