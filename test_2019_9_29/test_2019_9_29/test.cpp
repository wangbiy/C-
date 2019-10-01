#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#if 0
//C语言模拟实现封装
typedef struct A
{
	void(*Fm)(A* pa,int _a);
	int _a;
}A;
void initA(A* pa,int a)
{
	pa->_a = a;
}
void Construct(A* pa, int a)
{
	pa->_a = a;
	pa->Fm = initA;
}
int main()
{
	A a;
	Construct(&a, 10);
	a.Fm(&a, 100);
	return 0;
}
#endif
#if 0
//C语言模拟实现继承
typedef struct B
{
	void(*func)(B* pb);
	int _b;
}B;
typedef struct D
{
	void(*func)(B* pb);
	struct B b;
	int _d;
}D;
void f1(B*)
{}
void ConstructB(B* pb, int b)
{
	pb->_b = b;
	pb->func = f1;
}
void ConstructD(D* pd, int b,int d)
{
	ConstructB(&pd->b, b);
	pd->_d = d;
	pd->func = pd->b.func;
}
int main()
{
	return 0;
}
#endif
#if 0
//多态
typedef struct A
{
	void* p;
	void(*_A)(struct A* a);
}A;
int main()
{
	return 0;
}
#endif
#if 0
//组合
class A
{
public:
	void Testfunc()
	{

	}
private:
	int _a;
};
class B
{
public:
	void TestFunc()
	{}
private:
	A _a;
	int _b;
};
#endif

#if 0
//异常
#include <windows.h>
void TestFunc()
{
	FILE* pf = fopen("111.txt", "rb");
	if (nullptr == pf)
	{
		size_t errID = GetLastError();//最近发生的错误
		cout << errID << endl;
		cout << errno << endl;//最近发生的错误
		return;
	}		
	fclose (pf);
}
int main()
{
	TestFunc();
	return 0;
}
#endif
#if 0
void TestFunc()
{
https://www.baidu.com;
	FILE* pf = fopen("111.txt", "rb");
	if (nullptr == pf)
	{
		goto L;
	}
L:cout << "EndFunc" << endl;
}
int main()
{
	return 0;
}
#endif
#if 0
#include <setjmp.h>
jmp_buf buff;//结构体变量
void Func1()
{
	FILE* pf = fopen("111.txt", "rb");
	if (nullptr == pf)
	{
		longjmp(buff, 1);
		//return;//不清楚是正常结束还是异常结束
	}
	//文件操作
	fclose(pf);
}
void Func2()
{
	int *p = (int*)malloc(0x7ffffff);//没有使用new,new如果申请失败就会抛异常
	if (nullptr == p)
	{
		longjmp(buff, 2);
	}
}
int main()
{
	//1.记录跳转点：将当前位置的寄存器信息保存到buff中
	//2.setjmp第一次返回值一定是0
	int state = setjmp(buff);//setjmp第一次返回值一定是0
	if (state == 0)
	{
		//进行正常操作
		Func1();
		Func2();
	}
	else
	{
		switch (state)
		{
		case 1:
			cout << "打开文件失败" << endl;
			break;
		case 2:
			cout << "malloc申请空间失败" << endl;
			break;
		default:
			cout << "未知错误" << endl;
		}
	}
	return 0;
}
#endif
#if 0
void Func1()
{
	FILE* pf = fopen("111.txt", "rb");
	if (nullptr == pf)
	{
		throw 1;
	}
	fclose(pf);
}
void Func2()
{
	int *p = (int*)malloc(10*sizeof(int));
	if (nullptr == p)
	{
		throw '1';
	}
	try
	{
		Func1();
	}
	catch (int err)
	{
		cout << err << endl;
	}
	free(p);	
}
int main()
{
	try
	{
		Func2();
	}
	catch (int err)
	{
		cout << err << endl;
	}
	catch (char err)
	{
		cout << err << endl;
	}
	//执行后面的语句	
	return 0;
}
#endif
#if 0
class A
{
public: 
	A()
	{
		cout << "A::A()" << this << endl;
	}
	A(const A& a)
	{
		cout << "A::A(const A& a)" << this << endl;
	}
	~A()
	{
		cout << "A::~A()" << this<< endl;
	}
};
void TestFunc()
{
	A a;
	cout << &a << endl;
	throw a;//实际抛出的是a的一份拷贝，因为a是函数中的临时对象
}
int main()
{
	try
	{
		TestFunc();
	}
	catch (const A& a)//将临时的拷贝对象引用
	{
		cout << &a << endl;
		cout << "A Exception" << endl;
	}
	return 0;
}
#endif
#if 0
class A
{
public:
	A()
	{
		cout << "A::A()" << this << endl;
	}
	A(const A& a)
	{
		cout << "A::A(const A& a)" << this << endl;
	}
	~A()
	{
		cout << "A::~A()" << this << endl;
	}
};
void TestFunc()
{
	A a;
	throw a;//实际抛出的是a的一份拷贝，因为a是函数中的临时对象
}
int main()
{
	try
	{
		TestFunc();
	}
	catch (...)
	{
		cout << "A Exception" << endl;
	}
	return 0;
}
#endif
#if 0
//异常的重新抛出，即Func2中不得不对Func1中的异常进行捕获，否则就无法释放空间，内存泄漏，但是没有对Func1中的异常进行处理，可以使用catch(...)，重新抛出Func1的异常
void Func1()
{
	FILE* pf = fopen("111.txt", "rb");
	if (nullptr == pf)
	{
		throw 1;
	}
	fclose(pf);
}
void Func2()
{
	int *p = (int*)malloc(10 * sizeof(int));
	if (nullptr == p)
	{
		throw '1';
	}
	try//Func2没有义务为Func1处理异常，但是他对Func1的异常进行了捕获
	{
		Func1();
	}
	catch (...)
	{
		free(p);
		throw;//将Func1中的异常接着往出抛,但是不知道是什么异常，因此是catch（...）
	}
	free(p);
}
int main()
{
	try
	{
		Func2();
	}
	catch (int err)
	{
		cout << err << endl;
	}
	catch (char err)
	{
		cout << err << endl;
	}
	//执行后面的语句	
	return 0;
}
#endif
#if 0
void Testfunc()throw(int)
{
	throw 1.0;
}
#endif
#if 0
void Func()
{
	char* p = nullptr;
	p = new char[0x7fffffff];
}
int main()
{
	try
	{
		Func();
	}
	catch (const std::exception& e)
	{
		e.what();
		return 0;
	}
	return 0;
}
#endif
#if 0
#include <string>
class Exception
{
public:
	Exception(size_t errID, const string& errInfo)
		:_errID(errID)
		, _errInfo(errInfo)
	{}
	virtual void What()const = 0;//具体不知道异常
protected:
	size_t _errID;
	string _errInfo;
};
class DBException:public Exception
{
public:
	DBException(size_t errID, const string& errInfo)
		:Exception(errID, errInfo)
	{}
	virtual void What()const
	{
		cout << _errID << "--->" << _errInfo << endl;
	}
};
void Func1()
{
	DBException e(404,"网络不通");
	throw e;
}
void Func2()
{
	DBException e(504, "数据库未打开");
	throw e;
}
int main()
{
	try
	{
		Func1();
		Func2();
	}
	catch (const Exception& e)//采取基类引用的方式来捕获
	{
		e.What();
	}
	catch (const exception& e)//库里的捕获
	{
		e.what();
	}
	catch (...)
	{
		cout << "未知异常" << endl;
	}
	return 0;
}
#endif