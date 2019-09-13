#pragma once
#include <iostream>
using namespace std;
#include <assert.h>
template<class T>//ģ������б�
class Vector
{
public:
	typedef T* iterator;
public:
	Vector()//�����޲κ���
		: _start(nullptr)
		, _finish(nullptr)
		, _endofStorage(nullptr)
	{}
	Vector(size_t n, const T& data = T())//����n��Ϊdata��Ԫ��
		:_start(new T[n])
		, _finish(_start + n)
		, _endofStorage(_finish)
	{
		for (size_t i = 0; i < n; ++i)
		{
			_start[i] = data;
		}
	}
	Vector(T* first, T* last)//��Χ
	{
		size_t size = last - first;
		_start = new T[size];
		for (size_t i = 0; i < size; ++i)
		{
			_start[i] = first[i];
		}
		_finish = _endofStorage = _start + size;
	}
	Vector(const Vector<T>& v)//�������캯��
	{
		size_t size = v.size();
		_start = new T[size];
		for (size_t i = 0; i < size; ++i)
		{
			_start[i] = v[i];
		}
		_finish = _endofStorage = _start + size;
	}
	Vector<T>& operator=(const Vector<T> & v)//��ֵ���������
	{
		Swap(v);
		return *this;
	}
	void Swap(Vector<T> &v)//��������
	{
		std::vector(_start, v._start);
		std::vector(_finish, v._finish);
		std::vector(_endofStorage, v._endofStorage);
	}
	~Vector()//��������
	{
		if (_start)
		{
			delete[]_start;
			_start = nullptr;
			_finish = nullptr;
			_endofStorage = nullptr;
		}
	}

	size_t size()const
	{
		return _finish - _start;
	}
	size_t capacity()const
	{
		return _endofStorage - _start;
	}
	bool empty()const
	{
		return _finish == _start;
	}
	void resize(size_t newsize, const T& data = T())
	{
		size_t oldsize = size();//ԭ���ռ��С
		if (newsize <= oldsize)//��С
		{
			_finish = _start + newsize;
		}
		else
		{
			size_t oldcapacity = capacity();
			if (newsize >= oldcapacity)
			{
				reserve(newsize);//����
			}
			for (size_t i = oldsize; i < newsize; ++i)
			{
				*_finish++ = data;
			}
		}
	}
	void reserve(size_t newcapacity)
	{
		size_t oldcapacity = capacity();
		if (oldcapacity < newcapacity)
		{
			//����
			T* temp = new T[newcapacity];
			if (_start)
			{
				size_t originSize = size();
				for (size_t i = 0; i < originSize; ++i)
				{
					temp[i] = _start[i];//��_start�е�Ԫ�ط���temp
				}
				delete[]_start;
				_start = temp;
				_finish = _start + originSize;//��ʱ����ֱ��+size()����Ϊ��ʱsize()����������ڵ�size
				_endofStorage = _start + newcapacity;
			}
		}
	}
	T& operator[](size_t index)
	{
		assert(index < size());
		return _start[index];
	}
	const T& operator[](size_t index)const
	{
		assert(index < size());
		return _start[index];
	}
	T& front()
	{
		return _start[0];
	}
	const T& front()const
	{
		return _start[0];
	}
	T& back()
	{
		return *(_finish - 1);
	}
	const T& back()const
	{
		return *(_finish - 1);
	}
	iterator begin()
	{
		return _start;
	}
	iterator end()
	{
		return _finish;
	}

//�޸�
	void PushBack(const T data)
	{
		if (_finish == _endofStorage)
		{
			reserve(2 * capacity());
		}
		(*_finish) = data;
		++_finish;
	}
	void PopBack()
	{
		if (_finish == _start)
			return;
		--_finish;
	}
	iterator Insert(iterator pos, const T data)
	{
		assert(pos <= _finish);
		size_t index = pos - _start;
		if (_finish == _endofStorage)
		{
			reserve(2 * capacity());
			pos = _start + index;
		}
		//����Ԫ��
		for (int i = size() - 1; i >= pos - _start; --i)
		{
			_start[i + 1] = _start[i];
		}
		*pos = data;
		++_finish;
		return pos;
	}
	iterator Erase(iterator pos)
	{
		//����Ԫ��
		iterator cur = pos;
		iterator curNext = cur + 1;
		while (curNext != _finish)
		{
			*cur++ = *curNext++;
		}
		--_finish;
		return pos;
	}
	void clear()
	{
		_finish = _strat;
	}
	size_t Find(T& x)
	{
		size_t cur = 0;
		while (cur < size())
		{
			if (_start[cur] == x)
				return cur;
		}
		return -1;
	}
private:
	/*T* _array;
	size_t _capacity;
	size_t _size;*/
	iterator _start;//��ʼλ��
	iterator _finish;//������_size,���һ��Ԫ�ص���һ��λ��
	iterator _endofStorage;
};
void Print(Vector<int>& v)
{
	auto it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
void Test1()
{
	Vector<int> v1;
	Vector<int> v2(10, 5);
	Print(v2);
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	Vector<int> v3(arr, arr + sizeof(arr) / sizeof(arr[0]));
	Print(v3);
	Vector<int> v4(v3);
	Print(v4);
}
void Test2()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	Vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
	Print(v);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(3);
	Print(v);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(6,6);
	Print(v);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(9);
	Print(v);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(20, 6);//��Ҫ����
	Print(v);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
}
void Test3()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	Vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
	Print(v);
	cout << v[6] << endl;
	cout << v.front() << endl;
	cout << v.back() << endl;

	v.Insert(v.begin(), 0);
	Print(v);
	v.Erase(v.begin());
	Print(v);
	v.PushBack(8);
	Print(v);
	v.PopBack();
	Print(v);
}
int main()
{
	//Test1();
	//Test2();
	Test3();
	return 0;
}