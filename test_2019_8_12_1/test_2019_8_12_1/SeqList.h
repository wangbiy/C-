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
			_arr[i] = arr[i];//����
		}
	}
	SeqList(const SeqList& s)//��������
		:_arr(new DataType[s._size])
		, _Capacity(s._size)
		, _size(s._size)
	{
		for (int i = 0; i < _size; ++i)
		{
			_arr[i] = s._arr[i];
		}
	}
	SeqList& operator=(const SeqList& s)//��s�е�ֵ��������
	{
		if (this != &s)//��֤���Ǹ�����ֵ
		{
			DataType* pTemp = new DataType[s._size];//���ٿռ�
			for (int i = 0; i < s._size; ++i)
			{
				pTemp[i] = s._arr[i];
			}
			delete[]_arr;
		}
		return *this;
	}
	~SeqList()//��������
	{
		if (_arr)
		{
			delete[]_arr;
			_arr = nullptr;
			_Capacity = 0;
			_size = 0;
		}
	}
	void show();//��ӡ
	void CheckCapacity();//����
	void PushBack(const DataType data);//β��
	void PopBack();//βɾ
	void PushFront(const DataType data);//ͷ��
	void PopFront();//ͷɾ
	int FindSeqList(DataType data);//����
	void InsertSeqList(int pos, DataType data);//����λ�ò���
	void EraseSeqList(int pos);//����λ��ɾ��
	int SeqListCapacity();//��ȡ˳�������
	int SeqListSize();//��ȡ��ЧԪ�ظ���
	int SeqlistEmpty();
	DataType SeqListFront();//���ص�һ��Ԫ��
	DataType SeqListBack();//�������һ��Ԫ��
	void SeqListRemove(DataType data);//�Ƴ���һ��Ϊdata��Ԫ��
	void RemoveAll(DataType data);//�Ƴ�����Ϊdata��Ԫ��
	void SeqListSort();//����
private:
	DataType* _arr;
	int _size;//��ЧԪ�ظ���
	int _Capacity;
};