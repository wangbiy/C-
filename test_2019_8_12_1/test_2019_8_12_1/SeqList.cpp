#include "SeqList.h"
void SeqList::show()
{
	if (_size > 0)//˳���Ϊ��
	{
		for (int i = 0; i < _size; ++i)
		{
			cout << _arr[i] << " ";
		}
		cout << endl;
	}
	else
		cout << "˳����ǿյ�!" << endl;
}
void SeqList::CheckCapacity()//����
{
	if (_size == _Capacity)
	{
		int _newCapacity = _Capacity * 2;
		DataType* pTemp = new DataType[_newCapacity];
		memcpy(pTemp, _arr, _size*sizeof(DataType));
		delete[]_arr;
		_arr = pTemp;
		_Capacity = _newCapacity;
		cout << "���ݳɹ�!" << endl;
	}
}
void SeqList::PushBack(const DataType data)//β��
{
	CheckCapacity();
	_arr[_size++] = data;
}
void SeqList::PopBack()//βɾ
{
	if (_size > 0)
		_size--;
}
void SeqList::PushFront(const DataType data)//ͷ��
{
	CheckCapacity();
	for (int i = _size; i > 0; --i)//�����һ����ʼ�����
	{
		_arr[i] = _arr[i - 1];
	}
	_arr[0] = data;
	_size++;
}
void SeqList::PopFront()//ͷɾ
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
int SeqList::FindSeqList(DataType data)//����
{
	for (int i = 0; i < _size; ++i)
	{
		if (_arr[i] == data)
			return i;
	}
	return -1;
}
void SeqList::InsertSeqList(int pos, DataType data)//����λ�ò���
{
	if (pos<0 || pos>_size)
	{
		cout << "����λ�ò��Ϸ�!" << endl;
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

void SeqList::EraseSeqList(int pos)//����λ��ɾ��
{
	if (pos < 0 || pos >= _size)
	{
		cout << "ɾ��λ�ò��Ϸ�!" << endl;
		return;
	}
	for (int i = pos; i < _size; ++i)
	{
		_arr[i] = _arr[i + 1];
	}
	_size--;
}
int SeqList::SeqListCapacity()//��ȡ˳�������
{
	return _Capacity;
}
int  SeqList::SeqListSize()//��ȡ��ЧԪ�ظ���
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
DataType SeqList::SeqListBack()//�������һ��Ԫ��
{
	return _arr[_size - 1];
}
void SeqList::SeqListRemove(DataType data)//�Ƴ���һ��Ϊdata��Ԫ��
{
	EraseSeqList(FindSeqList(data));
}
void SeqList::RemoveAll(DataType data)//�Ƴ�����Ϊdata��Ԫ��
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
void SeqList::SeqListSort()//����
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
