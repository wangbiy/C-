#include "Stack.h"
void Stack::CheckCapacity()
{
	if (_top == _Capacity)
	{
		int NewCapacity = _Capacity * 2;
		DataType* temp = new DataType[NewCapacity];
		memcpy(temp, _arr, _top*sizeof(DataType));
		delete _arr;
		_arr = temp;
		_Capacity = NewCapacity;
	}
}
void Stack::StackPrint()
{
	for (int i = _top; i > 0; --i)
	{
		cout << _arr[i - 1] << " ";
	}
	cout << endl;
}
void Stack::StackDestroy()
{
	if (_arr)
	{
		delete _arr;
		_arr = nullptr;
		_Capacity = 0;
		_top = 0;
	}
}
void Stack::StackPush(const DataType& data)
{
	CheckCapacity();
	_arr[_top] = data;
	_top++;
}
void Stack::StackPop()
{
	if (_top == 0)//栈存在但没有元素
		return;
	_top--;
}
DataType Stack::StackTop()
{
	return _arr[_top - 1];
}
DataType Stack::StackSize()
{
	return _top;
}
bool Stack::StackEmpty()
{
	return 0 == _top;
}
