#include "SeqList.h"
void SeqList::show()
{
	if (_size > 0)//顺序表不为空
	{
		for (int i = 0; i < _size; ++i)
		{
			cout << _arr[i] << " ";
		}
		cout << endl;
	}
	else
		cout << "顺序表是空的!" << endl;
}
void SeqList::CheckCapacity()//扩容
{
	if (_size == _Capacity)
	{
		int _newCapacity = _Capacity * 2;
		DataType* pTemp = new DataType[_newCapacity];
		memcpy(pTemp, _arr, _size*sizeof(DataType));
		delete[]_arr;
		_arr = pTemp;
		_Capacity = _newCapacity;
		cout << "扩容成功!" << endl;
	}
}
void SeqList::PushBack(const DataType data)//尾插
{
	CheckCapacity();
	_arr[_size++] = data;
}
void SeqList::PopBack()//尾删
{
	if (_size > 0)
		_size--;
}
void SeqList::PushFront(const DataType data)//头插
{
	CheckCapacity();
	for (int i = _size; i > 0; --i)//从最后一个开始向后移
	{
		_arr[i] = _arr[i - 1];
	}
	_arr[0] = data;
	_size++;
}
void SeqList::PopFront()//头删
{
	if (_size > 0)
	{
		for (int i = 0; i < _size - 1; ++i)
		{
			_arr[i] = _arr[i + 1];
		}
		--_size;
	}
}
int SeqList::FindSeqList(DataType data)//查找
{
	for (int i = 0; i < _size; ++i)
	{
		if (_arr[i] == data)
			return i;
	}
	return -1;
}
void SeqList::InsertSeqList(int pos, DataType data)//任意位置插入
{
	if (pos<0 || pos>_size)
	{
		cout << "插入位置不合法!" << endl;
		return;
	}
	CheckCapacity();
	for (int i = _size - 1; i >= pos; --i)
	{
		_arr[i + 1] = _arr[i];
	}
	_arr[pos] = data;
	_size++;
}

void SeqList::EraseSeqList(int pos)//任意位置删除
{
	if (pos < 0 || pos >= _size)
	{
		cout << "删除位置不合法!" << endl;
		return;
	}
	for (int i = pos; i < _size; ++i)
	{
		_arr[i] = _arr[i + 1];
	}
	_size--;
}
int SeqList::SeqListCapacity()//获取顺序表容量
{
	return _Capacity;
}
int  SeqList::SeqListSize()//获取有效元素个数
{
	return _size;
}
int SeqList::SeqlistEmpty()
{
	return 0 == _size;
}
DataType SeqList::SeqListFront()
{
	return _arr[0];
}
DataType SeqList::SeqListBack()//返回最后一个元素
{
	return _arr[_size - 1];
}
void SeqList::SeqListRemove(DataType data)//移除第一个为data的元素
{
	EraseSeqList(FindSeqList(data));
}
void SeqList::RemoveAll(DataType data)//移除所有为data的元素
{
	int count = 0;
	for (int i = 0; i < _size; ++i)
	{
		if (_arr[i] == data)
		{
			count++;
		}
		else
		{
			_arr[i - count] = _arr[i];
		}
	}
	_size -= count;
}
void SeqList::SeqListSort()//排序
{
	for (int i = 0; i < _size - 1; ++i)
	{
		int flag = 0;
		for (int j = 0; j < _size - i - 1; ++j)
		{
			if (_arr[j]>_arr[j + 1])
			{
				swap(_arr[j], _arr[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}
