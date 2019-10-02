#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#if 0
void TestFunc1()
{
	throw 1;
}
bool TestFunc2()
{
	return false;
}
void TestFunc()
{
	int* p = new int[10];
	FILE* pf = fopen("111.txt", "rb");
	if (pf == nullptr)
	{
		delete[]p;
		return;
	}
	try
	{
		TestFunc1();
	}
	catch (...)
	{
		delete[]p;
		fclose(pf);
		return;
	}
	if (!TestFunc2())
	{
		delete[]p;
		fclose(pf);
		return;
	}
	delete[]p;
	fclose(pf);
}
int main()
{
	TestFunc();
	return 0;
}
#endif
#if 0
template <class T>
class Smartptr
{
public:
	Smartptr(T* ptr = nullptr)
		:_ptr(ptr)
	{}
	~Smartptr()
	{
		if (_ptr)
			delete[]_ptr;
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}

protected:
	T* _ptr;
};
struct A
{
	int a;
	int b;
	int c;
};
void TestFunc()
{
	Smartptr<int> sp1(new int);
	*sp1 = 10;
	Smartptr<A> sp2(new A);
	sp2->a = 1;
	sp2->b = 2;
	sp2->c = 3;
}

int main()
{
	TestFunc();
	return 0;
}
#endif
#if 0
namespace bite
{
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr = nullptr)
			:_ptr(ptr)
		{}
		~auto_ptr()
		{
			if (_ptr)
				delete[]_ptr;
		}
		auto_ptr(auto_ptr<T>& ap)//��Դת�ƣ���ap�е���Դת�Ƶ���ǰ������ȥ
		{
			_ptr = ap._ptr;
			ap._ptr = nullptr;
		}
		auto_ptr<T>& operator=( auto_ptr<T>& ap)
		{
			if (this != &ap)
			{
				if (_ptr)
					delete[]_ptr;
				_ptr = ap._ptr;//��Դת��
				ap._ptr = nullptr;
			}
			return *this;
		}
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
	private:
		T* _ptr;
	};
}
void TestFunc()
{
	bite::auto_ptr<int> sp1(new int);
	bite::auto_ptr<int> sp2(sp1);//����ǳ��������
	sp2 = sp1;
}
int main()
{
	TestFunc();
	return 0;
}
#endif
#if 0
namespace bite
{
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _owner(false)
		{
			if (_ptr)
				_owner = true;
		}
		~auto_ptr()
		{
			Release();
		}
		auto_ptr(const auto_ptr<T>& ap)
			:_ptr(ap._ptr)
			, _owner(ap._owner)
		{
				ap._owner = false;
		}
		auto_ptr<T>& operator=(const auto_ptr<T>& ap)

		{
			if (this != &ap)
			{
				Release();
				_ptr = ap._ptr;
				_owner = ap._owner;
				ap._owner = false;
			}
			return *this;
		}
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
	private:
		void Release()
		{
			if (_ptr&&_owner)
				delete[]_ptr;
		}
		T* _ptr;
		mutable bool _owner;//_owner��ʾ�Ƿ�����Դ

	};
}
void TestFunc()
{
	bite::auto_ptr<int> sp1(new int);
	bite::auto_ptr<int> sp2(sp1);
	if (true)
	{
		bite::auto_ptr<int> sp3(sp2);
	}
	*sp1 = 10;
	*sp2 = 20;
}
int main()
{
	TestFunc();
	return 0;
}
#endif
#if 0
#include <memory>
int main()
{
	unique_ptr<int> up1(new int);
	//unique_ptr<int> up2(up1);//���ܿ������߸�ֵ
	return 0;
}
#endif
#if 0
namespace bite
{
	template<class T>
	class unique_ptr
	{
	public:
		unique_ptr(T* ptr=nullptr)
			:_ptr(ptr)
		{}
		~unique_ptr()
		{
			if (_ptr)
				delete[]_ptr;
		}
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
	private:
		//C++98
		//�ڷ���Ȩ��private��ֻ����������
		unique_ptr(const unique_ptr<T>&);
		unique_ptr<T>& operator=(const unique_ptr<T>&);
		//C++11��
		unique_ptr(const unique_ptr<T>&) = delete;
		unique_ptr<T>& operator=(const unique_ptr<T>&) = delete;
	private:
		T* _ptr;
	};
}
int main()
{
	bite::unique_ptr<int> up1(new int);
	//bite::unique_ptr<int> up2(up1);//���ܿ���
	return 0;
}
#endif
#if 0
#include <memory>
int main()
{
	shared_ptr<int> sp1(new int);
	shared_ptr<int> sp2(sp1);
	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;
	return 0;
}
#endif
#if 0
namespace bite
{
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, pcount(nullptr)
		{
			if (ptr)
			{
				pcount = new int(1); 
			}
		}
		~shared_ptr()
		{
			Release();
		}
		shared_ptr(shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, pcount(sp.pcount)
		{
			if (_ptr)
			{
				++(*pcount);
			}
		}
		//sp1=sp2
		//sp1:δ������Դ---ֱ����sp2����
		//sp1:����������Դ---����sp2����ǰ���������ͷ��Լ�����Դ
		//sp1���Ѿ���������������Դ�ˣ�sp1�������+1������sp2����
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (_ptr!=sp._ptr)
			{
				Release();
				//δ������Դ����sp����
				_ptr = sp._ptr;
				pcount = sp.pcount;

				//�Ѿ���������������Դ
				if (_ptr)
					++(*pcount);
			}
			return *this;
		}		
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
		int usecount()
		{
			return *pcount;
		}
	private:
		void Release()
		{
			if (_ptr && 0 == --(*pcount))
			{
				delete _ptr;
				delete pcount;
			}

		}
		T* _ptr;
		int* pcount;
	};
}
int main()
{
	bite::shared_ptr<int> sp1(new int);
	bite::shared_ptr<int> sp2(sp1);
	bite::shared_ptr<int> sp3(new int);
	bite::shared_ptr<int> sp4;//û�й�����Դ
	sp4 = sp1;//sp4δ������Դ��������Դ
	sp3 = sp1;//sp3����������Դ����ʹ��ǰ�ͷž���Դ����sp1������Դ
	sp2 = sp1;//sp2��sp1�Ѿ�������Դ��
	return 0;
}
#endif
#if 0
#include <mutex>
template <class T>
class DFDel
{
public:
	void operator()(T*& p)
	{
		delete p;
		p = nullptr;
	}
};
template <class T>
class Free
{
public:
	void operator()(T*& p)
	{
		if (p)
		{
			free p;
			p = nullptr;
		}
	}
};
template <class T>
class Fclose
{
public:
	void operator()(T*& p)
	{
		if (p)
		{
			fclose(p);
			p = nullptr;
		}
	}
};
namespace bite
{
	template<class T,class DF=DFDel<T>>//����ɾ������ʹ�÷º����ķ�ʽ������
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, pcount(nullptr)
			, _pMutex(new mutex)
		{
			if (ptr)
			{
				pcount = new int(1);
			}
		}
		~shared_ptr()
		{
			Release();
		}
		shared_ptr(shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, pcount(sp.pcount)
			, _pMutex(sp._pMutex)
		{
			AddRefCount();
		}
		//sp1=sp2
		//sp1:δ������Դ---ֱ����sp2����
		//sp1:����������Դ---����sp2����ǰ���������ͷ��Լ�����Դ
		//sp1���Ѿ���������������Դ�ˣ�sp1�������+1������sp2����
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (_ptr != sp._ptr)
			{
				Release();
				//δ������Դ����sp����
				_ptr = sp._ptr;
				pcount = sp.pcount;
				_pMutex = sp._pMutex;

				//�Ѿ���������������Դ
				AddRefCount();
			}
			return *this;
		}
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
		int usecount()
		{
			return *pcount;
		}
	private:
		void Release()
		{
			_pMutex->lock();
			if (_ptr && 0 == --(*pcount))
			{
				//�������д��
				//delete _ptr;
				
				//DF()(_ptr);//DF��һ�����ͣ�DF()����һ����������,
				//�൱��DF df;df(_ptr);   
				DF df;
				df(_ptr);
				delete pcount;
				delete _pMutex;
			}
			_pMutex->unlock();
		}
		void AddRefCount()//�Լ�������
		{
			_pMutex->lock();
			if (_ptr)
				++(*pcount);
			_pMutex->unlock();
		}
		T* _ptr;
		int* pcount;
		mutex* _pMutex;
	};
}
//void Test()
//{
//	//bite::shared_ptr<int,Free<int>> sp1((int*)malloc(sizeof(int)* 10));
//	//bite::shared_ptr<FILE,Fclose> sp2(fopen("111.txt", "rb"));
//	//bite::shared_ptr<int> sp3(new int[10]);//һ�㲻�����������
//	bite::shared_ptr<int> sp4(new int); 
//}
class Date
{
public:
	Date()
	{
		_year = _month = _day = 0;
	}
	int _year;
	int _month;
	int _day;
};
void SharePtrFunc(bite::shared_ptr<Date>& sp, size_t n) 
{
	for (size_t i = 0; i < n; ++i)
	{
		// ��������ָ�뿽����++����������ָ��������--�������������̰߳�ȫ�ġ�
		bite::shared_ptr<Date> copy(sp);
		copy->_year++;
		copy->_month++;
		copy->_day++;
	}
}
#include <thread>
int main()
{
	bite::shared_ptr<Date> p(new Date);
	const size_t n = 10000;
	thread t1(SharePtrFunc, p, n);
	thread t2(SharePtrFunc, p, n);//����t1��t2�����̶߳���
	//�����߳������ܣ����߳�Ҳ���ܣ�������t1.join(),���̵߳ȴ�
	t1.join();
	t2.join();
	//��ʱt1��t2�Ѿ������ˣ����߳̿�ʼ
	cout << p->_year << endl;
	cout << p->_month << endl;
	cout << p->_day << endl;
	return 0;
}
#endif
#if 0
//shared_ptrѭ����������
#include <memory>
struct ListNode
{
	ListNode(int data = int())
	:_pPre(nullptr)
	, _pNext(nullptr)
	,_data(data)
	{
		cout << "ListNode::ListNode(int)" << this << endl;
	}
	~ListNode()
	{
		cout << "ListNode::~ListNode()" << this << endl;
	}
	shared_ptr<ListNode> _pPre;
	shared_ptr<ListNode> _pNext;
	int _data;
};
void Test()
{
	shared_ptr<ListNode> sp1(new ListNode(10));
	shared_ptr<ListNode> sp2(new ListNode(20));
	cout << sp1.use_count() << endl;//���ü���
	cout << sp2.use_count() << endl;

	sp1->_pNext = sp2;
	sp2->_pPre = sp1;
	cout << sp1.use_count() << endl;//���ü���
	cout << sp2.use_count() << endl;
}
int main()
{
	Test();
	return 0;
}
#endif
#if 0
//weak_ptr
#include <memory>
int main()
{
	//weak_ptr<int> wp(new int);//����
	return 0;
}
#endif
//weak_ptr���shared_ptr��ѭ����������
#include <memory>
struct ListNode
{
	ListNode(int data = int())
	:_data(data)
	{
		cout << "ListNode::ListNode(int)" << this << endl;
	}
	~ListNode()
	{
		cout << "ListNode::~ListNode()" << this << endl;
	}
	weak_ptr<ListNode> _pPre;
	weak_ptr<ListNode> _pNext;
	int _data;
};
void Test()
{
	shared_ptr<ListNode> sp1(new ListNode(10));
	shared_ptr<ListNode> sp2(new ListNode(20));
	cout << sp1.use_count() << endl;//���ü���
	cout << sp2.use_count() << endl;

	sp1->_pNext = sp2;
	sp2->_pPre = sp1;
	cout << sp1.use_count() << endl;//���ü���
	cout << sp2.use_count() << endl;
}
int main()
{
	Test();
	return 0;
}
