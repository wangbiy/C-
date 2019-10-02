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
		auto_ptr(auto_ptr<T>& ap)//资源转移，将ap中的资源转移到当前对象中去
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
				_ptr = ap._ptr;//资源转移
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
	bite::auto_ptr<int> sp2(sp1);//出现浅拷贝问题
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
		mutable bool _owner;//_owner表示是否还有资源

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
	//unique_ptr<int> up2(up1);//不能拷贝或者赋值
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
		//在访问权限private中只声明不定义
		unique_ptr(const unique_ptr<T>&);
		unique_ptr<T>& operator=(const unique_ptr<T>&);
		//C++11中
		unique_ptr(const unique_ptr<T>&) = delete;
		unique_ptr<T>& operator=(const unique_ptr<T>&) = delete;
	private:
		T* _ptr;
	};
}
int main()
{
	bite::unique_ptr<int> up1(new int);
	//bite::unique_ptr<int> up2(up1);//不能拷贝
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
		//sp1:未管理资源---直接与sp2共享
		//sp1:单独管理资源---在于sp2共享前，必须先释放自己的资源
		//sp1：已经与其他对象共享资源了，sp1将其计数+1，再与sp2共享
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (_ptr!=sp._ptr)
			{
				Release();
				//未管理资源，与sp共享
				_ptr = sp._ptr;
				pcount = sp.pcount;

				//已经与其他对象共享资源
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
	bite::shared_ptr<int> sp4;//没有管理资源
	sp4 = sp1;//sp4未管理资源，共享资源
	sp3 = sp1;//sp3单独管理资源，在使用前释放旧资源，与sp1共享资源
	sp2 = sp1;//sp2与sp1已经共享资源了
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
	template<class T,class DF=DFDel<T>>//增加删除器，使用仿函数的方式来处理
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
		//sp1:未管理资源---直接与sp2共享
		//sp1:单独管理资源---在于sp2共享前，必须先释放自己的资源
		//sp1：已经与其他对象共享资源了，sp1将其计数+1，再与sp2共享
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (_ptr != sp._ptr)
			{
				Release();
				//未管理资源，与sp共享
				_ptr = sp._ptr;
				pcount = sp.pcount;
				_pMutex = sp._pMutex;

				//已经与其他对象共享资源
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
				//别把这里写死
				//delete _ptr;
				
				//DF()(_ptr);//DF是一个类型，DF()创建一个无名对象,
				//相当于DF df;df(_ptr);   
				DF df;
				df(_ptr);
				delete pcount;
				delete _pMutex;
			}
			_pMutex->unlock();
		}
		void AddRefCount()//对计数加锁
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
//	//bite::shared_ptr<int> sp3(new int[10]);//一般不会有这种情况
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
		// 这里智能指针拷贝会++计数，智能指针析构会--计数，这里是线程安全的。
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
	thread t2(SharePtrFunc, p, n);//创建t1、t2两个线程对象
	//两个线程往下跑，主线程也在跑，当遇到t1.join(),主线程等待
	t1.join();
	t2.join();
	//这时t1和t2已经跑完了，主线程开始
	cout << p->_year << endl;
	cout << p->_month << endl;
	cout << p->_day << endl;
	return 0;
}
#endif
#if 0
//shared_ptr循环引用问题
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
	cout << sp1.use_count() << endl;//引用计数
	cout << sp2.use_count() << endl;

	sp1->_pNext = sp2;
	sp2->_pPre = sp1;
	cout << sp1.use_count() << endl;//引用计数
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
	//weak_ptr<int> wp(new int);//报错
	return 0;
}
#endif
//weak_ptr解决shared_ptr的循环引用问题
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
	cout << sp1.use_count() << endl;//引用计数
	cout << sp2.use_count() << endl;

	sp1->_pNext = sp2;
	sp2->_pPre = sp1;
	cout << sp1.use_count() << endl;//引用计数
	cout << sp2.use_count() << endl;
}
int main()
{
	Test();
	return 0;
}
