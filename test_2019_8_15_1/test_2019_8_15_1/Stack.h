#pragma once
#include <iostream>
using namespace std;
typedef int DataType;
class Stack
{
public:
	Stack()//���캯��
		:_arr(nullptr)
		, _top(0)
		, _Capacity(0)
	{
		_arr = new DataType[3];
		_top = 0;
		_Capacity = 3;
	}
	Stack(const Stack& s)//�������캯��
	{
		_Capacity = s._Capacity;
		_top = s._top;
		_arr = new DataType[_Capacity];//���ٿռ�
		for (int i = 0; i < _top; ++i)
		{
			_arr[i] = s._arr[i];
		}
	}
	Stack& operator=(const Stack& s)//��ֵ���������
	{
		if (_Capacity < s._Capacity)
		{
			_Capacity = s._Capacity;
			_arr = new DataType[_Capacity];
		}
		_top = s._top;
		for (int i = 0; i < _top; ++i)
		{
			_arr[i] = s._arr[i];
		}
		return *this;
	}
	~Stack()
	{
		StackDestroy();
	}
	void CheckCapacity();
	void StackPush(const DataType& data);//ѹջ
	void StackPop();//��ջ
	DataType StackTop();//��ȡջ��Ԫ��
	DataType StackSize();//��ȡջ����ЧԪ�ظ���
	bool StackEmpty();
	void StackPrint();
	void StackDestroy();
private:
	DataType* _arr;
	int _top;
	int _Capacity;
};
