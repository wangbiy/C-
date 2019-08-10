//求1+2+3+...+100，要求不能使用乘除法、
//for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
#include <iostream>
using namespace std;
#if 0
class Solution
{
	class Sum
	{
	public:
		Sum()
		{
			++count;
			sum += count;
		}
		static int GetSum()
		{
			return sum;
		}
		static void ReSet()
		{
			count = 0;
			sum = 0;
		}
		void testfunc()
		{
			Solution s;
			s._a = 10;//内部类可以访问外部类的私有成员
		}
	private:
		static int count;
		static int sum;
	};
public:
	int Sum_Solution()
	{
		Solution::Sum::ReSet();
		Sum s[200];
		return Solution::Sum::GetSum();
	}
private:
	int _a;
};
int Solution::Sum::count = 0;
int Solution::Sum::sum = 0;
int main()
{
	return 0;
}
#endif
#if 0
int GlobalVar = 1;
static int staticGlobalVar = 1;
void Test()
{
	static int staticVar = 1;
	int localVar = 1;
	int num1[10] = { 1, 2, 3, 4 };
	char char2[] = "abcd";
	char* pchar3 = "abcd";
	int* ptr1 = (int*)malloc(sizeof(int)* 4);
	int* ptr2 = (int*)calloc(4, sizeof(int));
	int* ptr3 = (int*)realloc(ptr2, sizeof(int)* 4);
	free(ptr1);
	free(ptr3);
}
int main()
{
	Test();
	return 0;
}
#endif
#if 0
int main()
{
	int* p1 = new int;//new后面跟类型
	int *p2 = new int(10);//可以对申请的空间初始化
	delete p1;
	delete p2;
	int array[10];//int 是数组中所放元素的类型
	//连续空间
	int* p3 = new int[10];
	int* p4 = new int[10]{1, 2, 3, 4};//还可以初始化,不过编译器必须是2013版本后的，因为它是C++11加的语法
	delete[]p3;//释放连续空间
	delete[]p4;
	return 0;
}
#endif
#if 0
//自定义类型的空间
class Test
{
public:
	Test()
	{
		cout << "Test():" << this << endl;
	}
	~Test()
	{
		cout << "~Test():" << this << endl;
	}
	void TestNewDelete()
	{
		//new申请空间调用构造函数
		Test* t1 = new Test;
		delete t1;//delete销毁空间调用析构函数
		Test* t2 = (Test*)malloc(sizeof(Test));//malloc申请的空间没有调用构造函数，没有创造对象
		if (nullptr == t2)
			;
		free(t2);//没有调用析构函数
		Test* t3 = new Test[10];//调用了10次构造函数
		delete[]t3;//调用了10次析构函数
	}
private:
	int _t;
};
int main()
{
	Test t;
	t.TestNewDelete();
	return 0;
}
#endif
#include <crtdbg.h>
#if 0
//如果没有配合使用，代码会出现什么情况？
//结论：对于内置类型没有匹配没有影响
void testfunc()
{
	int* p1 = (int*)malloc(sizeof(int));
	delete p1;
	int* p2 = (int*)malloc(sizeof(int));
	delete[]p2;
	int* p3 = new int;
	free(p3);
	int* p4 = new int;
	delete[]p4;
	int* p5 = new int[10];
	free(p5);
	int* p6 = new int[10];
	delete p6;
}
int main()
{
	testfunc();
	_CrtDumpMemoryLeaks();//进行内存泄漏检测,但是它不能检测出哪里发生了内存泄漏
	//可以使用第三方库，例如vld内存检测工具
	return 0;
}
#endif
#if 0
class Test
{
public:
	Test()
	{
		ptr = new int;
	}
	~Test()
	{
		delete ptr;
		ptr = nullptr;
	}
private:
	int* ptr;
};
void testfunc()
{
	//代码崩溃,malloc没有构造对象，无法使用delete调用析构函数来释放
	/*Test* p1 = (Test*)malloc(sizeof(Test));
	delete p1;*/
	//代码崩溃,因为malloc没有调用构造函数，而delete要调用析构函数，而这时候没有对象，无法释放
	Test* p2 = (Test*)malloc(sizeof(Test));
	delete[]p2;
	//p3在栈上，Test在堆上，堆里面ptr申请的空间，释放的是ptr申请的空间，因此存在内存泄漏
	Test* p3 = new Test;
	free(p3);//free不会调用析构函数
	//代码崩溃
	Test* p4 = new Test;
	delete[]p4;
	//代码崩溃，内存泄漏
	Test* p5 = new Test[10];
	free(p5);
	//代码崩溃
	Test* p6 = new Test[10];
	delete p6;
}
int main()
{
	testfunc();
	return 0;
}
#endif
#if 0
class Test
{
public:
	Test()
	{
		cout << "Test()" << endl;
	}
	~Test()
	{
		cout << "~Test()" << this <<endl;
	}
private:
	int* data;
};
void testfunc()
{
	//代码没有问题，因为类里面没有管理资源
	Test* p1 = (Test*)malloc(sizeof(Test));
	delete p1;
	//代码崩溃
	Test* p2 = (Test*)malloc(sizeof(Test));
	delete[]p2;
	//没有影响，因为类中没有管理资源	
	Test* p3 = new Test;
	free(p3);
	//代码崩溃
	Test* p4 = new Test;
	delete[]p4;
	//代码崩溃
	Test* p5 = new Test[10];
	free(p5);
	//代码崩溃
	Test* p6 = new Test[10];
	delete p6;
}

int main()
{
	testfunc();
	return 0;
}
#endif
#if 0
class Test
{
public:
	Test()
	{
		cout << "Test()" << endl;
	}
private:
	int* data;
};
void testfunc()
{
	Test* p1 = (Test*)malloc(sizeof(Test));
	delete p1;

	Test* p2 = (Test*)malloc(sizeof(Test));
	delete[]p2;

	Test* p3 = new Test;
	free(p3);

	Test* p4 = new Test;
	delete[]p4;

	Test* p5 = new Test[10];
	free(p5);

	Test* p6 = new Test[10];
	delete p6;
}
int main()
{
	testfunc();
	return 0;
}
#endif
#if 0
class Test
{
public:
	Test()
	{
		cout << "Test()" << endl;
	}
	~Test()
	{
		cout << "~Test()" << this << endl;
	}
private:
	int* data;
};
int main()
{
	Test* ptr = new Test;
	delete ptr;
	return 0;
}
#endif
#if 0
void *__CRTDECL operator new(size_t count) 
{
	// try to allocate size bytes
	void *p;
	while ((p = malloc(count)) == 0)
	if (_callnewh(count) == 0)
	{
		// report no memory
		// 如果申请内存失败了，这里会抛出bad_alloc 类型异常
		static const std::bad_alloc nomem;
		_RAISE(nomem);
	}
	return (p);
}
#endif
#if 0
void operator delete(void *pUserData) {
	_CrtMemBlockHeader * pHead;
	RTCCALLBACK(_RTC_Free_hook, (pUserData, 0));
	if (pUserData == NULL)
		return;
	_mlock(_HEAP_LOCK); /* block other threads */
	__TRY
		/* get a pointer to memory block header */
		pHead = pHdr(pUserData);
	/* verify block type */
	_ASSERTE(_BLOCK_TYPE_IS_VALID(pHead->nBlockUse));
	_free_dbg(pUserData, pHead->nBlockUse);
	__FINALLY
		_munlock(_HEAP_LOCK); /* release other threads */
	__END_TRY_FINALLY
		return;
}
#endif
#if 0
class Test
{
public:
	Test()
	{
		cout << "Test()" <<this << endl;
	}
	~Test()
	{
		cout << "~Test()" << this << endl;
	}
private:
	int* data;
};
int main()
{
	Test* ptr = new Test[];
	delete[] ptr;
	return 0;
}
#endif
#if 0
class Test
{
public:
	Test()
		:_data(0)
	{
		cout << "Test():" << this << endl;
	}
	~Test()
	{
		cout << "~Test():" << this << endl;
	}
private:
	int _data;
};
int main()
{
	Test* pt = (Test*)malloc(sizeof(Test));
	new(pt)Test;//如果Test类的构造函数有参数时，此时应该传参
	return 0;
}
#endif
#if 0
//设计一个类，只能在堆上申请空间
class HeapOnly
{
public:
	static HeapOnly* GetObject()
	{
		return new HeapOnly;
	}
private:
	HeapOnly()
	{}
	//C++98
	//HeapOnly(const HeapOnly&);//拷贝构造函数,必须是私有的，如果不是私有的，在类外用户可能会定义拷贝构造函数，例如HeapOnly* o(*p),是在栈上申请空间因此不能实现只能在堆上申请空间的要求，所以必须是私有的
	//C++11
	HeapOnly(const HeapOnly&) = delete;//告诉编译器，删除拷贝构造函数
};
int main()
{
	HeapOnly* p = HeapOnly::GetObject();
	//HeapOnly* o(*p);//在栈上申请的空间，因此要将拷贝构造函数改成私有的
	return 0;
}
#endif
#if 0
//只能在栈上申请空间
class StackOnly
{
public:
	static StackOnly GetObject()
	{
		return StackOnly();
	}
private:
	StackOnly()//将构造函数设为私有的
	{
		cout << "StackOnly():" << this << endl;
	}
};
int main()
{
	//StackOnly* s = new StackOnly;//不能实现
	//StackOnly::GetObject();
	StackOnly s = StackOnly::GetObject();//相当于StackOnly s(StackOnly::GetObject()),即拷贝构造函数
	//但这种方法不太好，在编译器没有优化的情况下，创建了3个对象
	return 0;
}
#endif
#if 0
class StackOnly
{
public:
	StackOnly()
	{}
private:
	void* operator new(size_t size);
	void operator delete(void* p);
};
int main()
{
	//StackOnly* = new StackOnly;//错误
	//StackOnly* s=(StackOnly*)malloc(sizeof(StackOnly)); 
	//new(s)StackOnly;//错误，因为屏蔽了operator new，实际也将定位new屏蔽掉
	/*StackOnly s;*/
	return 0;
}
#endif
#if 0
//防止被拷贝，只要将拷贝构造函数和赋值运算符重载屏蔽
class Test
{
public:
	Test()
	{}
public:
	//Test(const Test&);
	//Test& operator=(const Test&);
	//C++98
	Test(const Test&)=delete;
	Test& operator=(const Test&)=delete;//C++11
};
int main()
{
	Test t1;
	//Test t2(t1);//错误
	return 0;
}
#endif
#if 0
//饿汉模式,程序启动时，将对象创建好
class Singleton
{
public:
	static Singleton& GetInstrance()
	{
		return m_ins;
	}
private:
	Singleton()
	{}
	static Singleton m_ins;//程序启动时对象创建好
	Singleton(const Singleton&) = delete;
	Singleton& operator=(Singleton const&) = delete;
};
Singleton Singleton::m_ins;//初始化
int main()
{
	Singleton& s = Singleton::GetInstrance();
	return 0;
}
#endif
#if 0
#include <mutex>
#include <thread>
//懒汉模式,第一次使用时创建，延迟加载
//不是线程安全的，不能保证只能创建一个对象,因此实现加锁功能
//容易造成线程阻塞,利用双判断
//volatile作用是禁止编译器对代码发生指令重排
class Singleton
{
public:
	static volatile Singleton* GetInstrance()
	{
		if (nullptr == m_ins)//加一层检测，防止线程阻塞
		{
			m_mutex.lock();//加锁
			if (nullptr == m_ins)//若为空，说明是第一次调用
				m_ins = new Singleton;
			m_mutex.unlock();//解锁
		}
		return m_ins;
	}
	class GC
	{
	public:
		~GC()
		{
			if (m_ins)
			{
				delete m_ins;
				m_ins = nullptr;
			}
		}
	};
	
private:
	Singleton()
	{}

	Singleton(const Singleton&) = delete;
	static volatile Singleton* m_ins;
	static mutex m_mutex;
	static GC m_gc;
	
};
volatile Singleton*  Singleton::m_ins = nullptr;
mutex Singleton::m_mutex;
Singleton::GC m_gc;
void ThreadFunc()
{
	cout<<Singleton::GetInstrance()<<endl;
}
void TestSingleton()
{
	thread t1(ThreadFunc);
	thread t2(ThreadFunc);
	thread t3(ThreadFunc);
	thread t4(ThreadFunc);
	thread t5(ThreadFunc);
	thread t6(ThreadFunc);
	thread t7(ThreadFunc);
	thread t8(ThreadFunc);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	t7.join();
	t8.join();
}
int main()
{
	TestSingleton();
	return 0;
}
#endif
#if 0
void testfunc()
{
	FILE* pf = fopen("111.txt", "rb");
	if (nullptr == pf)
	{
		throw 1;
	}
	fclose(pf);
}
void MemoryLeaks()
{
	// 1.内存申请了忘记释放
	int* p1 = (int*)malloc(sizeof(int));
	int* p2 = new int;
	// 2.异常安全问题
	int* p3 = new int[10];
	testfunc();//这里Func函数抛异常
	delete[] p3;
	delete p2;
	free(p1);
}
int main()
{
	try
	{
		MemoryLeaks();
	}
	catch (int err)
	{
		cout << err << endl;
	}
	return 0;
}
#endif
//如何一次在堆上申请4G的内存？
//在x64的环境下可以运行
int main()
{
	void* p = new char[0xfffffffful];
	cout << "new:" << p << endl;
	return 0;
}
