#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#if 0
//C����ģ��ʵ�ַ�װ
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
//C����ģ��ʵ�ּ̳�
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
//��̬
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
//���
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
//�쳣
#include <windows.h>
void TestFunc()
{
	FILE* pf = fopen("111.txt", "rb");
	if (nullptr == pf)
	{
		size_t errID = GetLastError();//��������Ĵ���
		cout << errID << endl;
		cout << errno << endl;//��������Ĵ���
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
jmp_buf buff;//�ṹ�����
void Func1()
{
	FILE* pf = fopen("111.txt", "rb");
	if (nullptr == pf)
	{
		longjmp(buff, 1);
		//return;//��������������������쳣����
	}
	//�ļ�����
	fclose(pf);
}
void Func2()
{
	int *p = (int*)malloc(0x7ffffff);//û��ʹ��new,new�������ʧ�ܾͻ����쳣
	if (nullptr == p)
	{
		longjmp(buff, 2);
	}
}
int main()
{
	//1.��¼��ת�㣺����ǰλ�õļĴ�����Ϣ���浽buff��
	//2.setjmp��һ�η���ֵһ����0
	int state = setjmp(buff);//setjmp��һ�η���ֵһ����0
	if (state == 0)
	{
		//������������
		Func1();
		Func2();
	}
	else
	{
		switch (state)
		{
		case 1:
			cout << "���ļ�ʧ��" << endl;
			break;
		case 2:
			cout << "malloc����ռ�ʧ��" << endl;
			break;
		default:
			cout << "δ֪����" << endl;
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
	//ִ�к�������	
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
	throw a;//ʵ���׳�����a��һ�ݿ�������Ϊa�Ǻ����е���ʱ����
}
int main()
{
	try
	{
		TestFunc();
	}
	catch (const A& a)//����ʱ�Ŀ�����������
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
	throw a;//ʵ���׳�����a��һ�ݿ�������Ϊa�Ǻ����е���ʱ����
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
//�쳣�������׳�����Func2�в��ò���Func1�е��쳣���в��񣬷�����޷��ͷſռ䣬�ڴ�й©������û�ж�Func1�е��쳣���д�������ʹ��catch(...)�������׳�Func1���쳣
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
	try//Func2û������ΪFunc1�����쳣����������Func1���쳣�����˲���
	{
		Func1();
	}
	catch (...)
	{
		free(p);
		throw;//��Func1�е��쳣����������,���ǲ�֪����ʲô�쳣�������catch��...��
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
	//ִ�к�������	
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
	virtual void What()const = 0;//���岻֪���쳣
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
	DBException e(404,"���粻ͨ");
	throw e;
}
void Func2()
{
	DBException e(504, "���ݿ�δ��");
	throw e;
}
int main()
{
	try
	{
		Func1();
		Func2();
	}
	catch (const Exception& e)//��ȡ�������õķ�ʽ������
	{
		e.What();
	}
	catch (const exception& e)//����Ĳ���
	{
		e.what();
	}
	catch (...)
	{
		cout << "δ֪�쳣" << endl;
	}
	return 0;
}
#endif