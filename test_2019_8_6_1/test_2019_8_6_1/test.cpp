//��1+2+3+...+100��Ҫ����ʹ�ó˳�����
//for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����
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
			s._a = 10;//�ڲ�����Է����ⲿ���˽�г�Ա
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
	int* p1 = new int;//new���������
	int *p2 = new int(10);//���Զ�����Ŀռ��ʼ��
	delete p1;
	delete p2;
	int array[10];//int ������������Ԫ�ص�����
	//�����ռ�
	int* p3 = new int[10];
	int* p4 = new int[10]{1, 2, 3, 4};//�����Գ�ʼ��,����������������2013�汾��ģ���Ϊ����C++11�ӵ��﷨
	delete[]p3;//�ͷ������ռ�
	delete[]p4;
	return 0;
}
#endif
#if 0
//�Զ������͵Ŀռ�
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
		//new����ռ���ù��캯��
		Test* t1 = new Test;
		delete t1;//delete���ٿռ������������
		Test* t2 = (Test*)malloc(sizeof(Test));//malloc����Ŀռ�û�е��ù��캯����û�д������
		if (nullptr == t2)
			;
		free(t2);//û�е�����������
		Test* t3 = new Test[10];//������10�ι��캯��
		delete[]t3;//������10����������
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
//���û�����ʹ�ã���������ʲô�����
//���ۣ�������������û��ƥ��û��Ӱ��
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
	_CrtDumpMemoryLeaks();//�����ڴ�й©���,���������ܼ������﷢�����ڴ�й©
	//����ʹ�õ������⣬����vld�ڴ��⹤��
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
	//�������,mallocû�й�������޷�ʹ��delete���������������ͷ�
	/*Test* p1 = (Test*)malloc(sizeof(Test));
	delete p1;*/
	//�������,��Ϊmallocû�е��ù��캯������deleteҪ������������������ʱ��û�ж����޷��ͷ�
	Test* p2 = (Test*)malloc(sizeof(Test));
	delete[]p2;
	//p3��ջ�ϣ�Test�ڶ��ϣ�������ptr����Ŀռ䣬�ͷŵ���ptr����Ŀռ䣬��˴����ڴ�й©
	Test* p3 = new Test;
	free(p3);//free���������������
	//�������
	Test* p4 = new Test;
	delete[]p4;
	//����������ڴ�й©
	Test* p5 = new Test[10];
	free(p5);
	//�������
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
	//����û�����⣬��Ϊ������û�й�����Դ
	Test* p1 = (Test*)malloc(sizeof(Test));
	delete p1;
	//�������
	Test* p2 = (Test*)malloc(sizeof(Test));
	delete[]p2;
	//û��Ӱ�죬��Ϊ����û�й�����Դ	
	Test* p3 = new Test;
	free(p3);
	//�������
	Test* p4 = new Test;
	delete[]p4;
	//�������
	Test* p5 = new Test[10];
	free(p5);
	//�������
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
		// ��������ڴ�ʧ���ˣ�������׳�bad_alloc �����쳣
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
	new(pt)Test;//���Test��Ĺ��캯���в���ʱ����ʱӦ�ô���
	return 0;
}
#endif
#if 0
//���һ���ֻ࣬���ڶ�������ռ�
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
	//HeapOnly(const HeapOnly&);//�������캯��,������˽�еģ��������˽�еģ��������û����ܻᶨ�忽�����캯��������HeapOnly* o(*p),����ջ������ռ���˲���ʵ��ֻ���ڶ�������ռ��Ҫ�����Ա�����˽�е�
	//C++11
	HeapOnly(const HeapOnly&) = delete;//���߱�������ɾ���������캯��
};
int main()
{
	HeapOnly* p = HeapOnly::GetObject();
	//HeapOnly* o(*p);//��ջ������Ŀռ䣬���Ҫ���������캯���ĳ�˽�е�
	return 0;
}
#endif
#if 0
//ֻ����ջ������ռ�
class StackOnly
{
public:
	static StackOnly GetObject()
	{
		return StackOnly();
	}
private:
	StackOnly()//�����캯����Ϊ˽�е�
	{
		cout << "StackOnly():" << this << endl;
	}
};
int main()
{
	//StackOnly* s = new StackOnly;//����ʵ��
	//StackOnly::GetObject();
	StackOnly s = StackOnly::GetObject();//�൱��StackOnly s(StackOnly::GetObject()),���������캯��
	//�����ַ�����̫�ã��ڱ�����û���Ż�������£�������3������
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
	//StackOnly* = new StackOnly;//����
	//StackOnly* s=(StackOnly*)malloc(sizeof(StackOnly)); 
	//new(s)StackOnly;//������Ϊ������operator new��ʵ��Ҳ����λnew���ε�
	/*StackOnly s;*/
	return 0;
}
#endif
#if 0
//��ֹ��������ֻҪ���������캯���͸�ֵ�������������
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
	//Test t2(t1);//����
	return 0;
}
#endif
#if 0
//����ģʽ,��������ʱ�������󴴽���
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
	static Singleton m_ins;//��������ʱ���󴴽���
	Singleton(const Singleton&) = delete;
	Singleton& operator=(Singleton const&) = delete;
};
Singleton Singleton::m_ins;//��ʼ��
int main()
{
	Singleton& s = Singleton::GetInstrance();
	return 0;
}
#endif
#if 0
#include <mutex>
#include <thread>
//����ģʽ,��һ��ʹ��ʱ�������ӳټ���
//�����̰߳�ȫ�ģ����ܱ�ֻ֤�ܴ���һ������,���ʵ�ּ�������
//��������߳�����,����˫�ж�
//volatile�����ǽ�ֹ�������Դ��뷢��ָ������
class Singleton
{
public:
	static volatile Singleton* GetInstrance()
	{
		if (nullptr == m_ins)//��һ���⣬��ֹ�߳�����
		{
			m_mutex.lock();//����
			if (nullptr == m_ins)//��Ϊ�գ�˵���ǵ�һ�ε���
				m_ins = new Singleton;
			m_mutex.unlock();//����
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
	// 1.�ڴ������������ͷ�
	int* p1 = (int*)malloc(sizeof(int));
	int* p2 = new int;
	// 2.�쳣��ȫ����
	int* p3 = new int[10];
	testfunc();//����Func�������쳣
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
//���һ���ڶ�������4G���ڴ棿
//��x64�Ļ����¿�������
int main()
{
	void* p = new char[0xfffffffful];
	cout << "new:" << p << endl;
	return 0;
}
