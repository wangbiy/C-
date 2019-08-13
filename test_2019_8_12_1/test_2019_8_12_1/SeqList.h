#pragma once
#include <iostream>
using namespace std;
typedef int DataType;
class SeqList
{
public:
	SeqList()
		:_arr(new DataType[3])
		, _Capacity(3)
		, _size(0)
	{}
	SeqList(DataType* arr,int size)
		:_arr(new DataType[size])
		, _Capacity(size)
		, _size(size)
	{
		for (int i = 0; i < size; ++i)
		{
			_arr[i] = arr[i];//或者
		}
	}
	SeqList(const SeqList& s)//拷贝构造
		:_arr(new DataType[s._size])
		, _Capacity(s._size)
		, _size(s._size)
	{
		for (int i = 0; i < _size; ++i)
		{
			_arr[i] = s._arr[i];
		}
	}
	SeqList& operator=(const SeqList& s)//将s中的值赋给别人
	{
		if (this != &s)//保证不是给本身赋值
		{
			DataType* pTemp = new DataType[s._size];//开辟空间
			for (int i = 0; i < s._size; ++i)
			{
				pTemp[i] = s._arr[i];
			}
			delete[]_arr;
		}
		return *this;
	}
	~SeqList()//析构函数
	{
		if (_arr)
		{
			delete[]_arr;
			_arr = nullptr;
			_Capacity = 0;
			_size = 0;
		}
	}
	void show();//打印
	void CheckCapacity();//扩容
	void PushBack(const DataType data);//尾插
	void PopBack();//尾删
	void PushFront(const DataType data);//头插
	void PopFront();//头删
	int FindSeqList(DataType data);//查找
	void InsertSeqList(int pos, DataType data);//任意位置插入
	void EraseSeqList(int pos);//任意位置删除
	int SeqListCapacity();//获取顺序表容量
	int SeqListSize();//获取有效元素个数
	int SeqlistEmpty();
	DataType SeqListFront();//返回第一个元素
	DataType SeqListBack();//返回最后一个元素
	void SeqListRemove(DataType data);//移除第一个为data的元素
	void RemoveAll(DataType data);//移除所有为data的元素
	void SeqListSort();//排序
private:
	DataType* _arr;
	int _size;//有效元素个数
	int _Capacity;
};