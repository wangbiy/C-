#pragma once
#include <iostream>
using namespace std;
typedef int DataType;
class Stack
{
public:
	Stack()//构造函数
		:_arr(nullptr)
		, _top(0)
		, _Capacity(0)
	{
		_arr = new DataType[3];
		_top = 0;
		_Capacity = 3;
	}
	Stack(const Stack& s)//拷贝构造函数
	{
		_Capacity = s._Capacity;
		_top = s._top;
		_arr = new DataType[_Capacity];//开辟空间
		for (int i = 0; i < _top; ++i)
		{
			_arr[i] = s._arr[i];
		}
	}
	Stack& operator=(const Stack& s)//赋值运算符重载
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
	void StackPush(const DataType& data);//压栈
	void StackPop();//出栈
	DataType StackTop();//获取栈顶元素
	DataType StackSize();//获取栈内有效元素个数
	bool StackEmpty();
	void StackPrint();
	void StackDestroy();
private:
	DataType* _arr;
	int _top;
	int _Capacity;
};
