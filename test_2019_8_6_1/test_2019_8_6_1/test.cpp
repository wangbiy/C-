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
