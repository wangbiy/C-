#include <iostream>
using namespace std;
#if 0
class WashRoom
{
public:
	void GoToManRoom()
	{
		cout << "WashRoom::GoToManRoom()" << endl;
	}
	void GoToWomanRoom()
	{
		cout << "WashRoom::GoToWomanRoom()" << endl;
	}
};
class Person//������
{
public:
	virtual void GoToWc(WashRoom& wc) = 0;//���麯��
protected:
	string _name;
	int _age;
};
class Man :public Person//���������б�����д����Ĵ��麯������������Ҳ�ǳ�����
{
public:
	virtual void GoToWc(WashRoom& wc)
	{
		wc.GoToManRoom();
	}
};
class Woman :public Person
{
public:
	virtual void GoToWc(WashRoom& wc)
	{
		wc.GoToWomanRoom();
	}
};
#include <windows.h>
void Test(size_t n)
{
	Person* p;
	WashRoom wc;
	for (size_t i = 0; i < n; ++i)
	{
		if (rand() % 2)
		{
			p = new Man;
		}
		else
		{
			p = new Woman;
		}
		p->GoToWc(wc);
		delete p;
		Sleep(1000);
	}
}
int main()
{
	//Person p;//�����಻��ʵ��������
	Test(10);
	return 0;
}
#endif
#if 0
class Base
{
public:
	virtual void Func()
	{
		cout << "Base::Func()" << endl;
	}
	int _b;
};
int main()
{
	cout << sizeof(Base) << endl;//8
	Base b;
	return 0;
}
#endif
#if 0
class Base
{
public:
	virtual void Func3()
	{
		cout << "Base::Func3()" << endl;
	}
	virtual void Func1()
	{
		cout << "Base::Func1()" << endl;
	}
	virtual void Func2()
	{
		cout << "Base::Func2()" << endl;
	}
	int _b;
};
class Derived :public Base
{
public:
};
int main()
{
	Derived d;
	return 0;
}
#endif
#if 0
class Base
{
public:
	virtual void Func3()
	{
		cout << "Base::Func3()" << endl;
	}
	virtual void Func1()
	{
		cout << "Base::Func1()" << endl;
	}
	virtual void Func2()
	{
		cout << "Base::Func2()" << endl;
	}
	int _b;
};
class Derived : public Base
{
public:
	virtual void Func3()
	{
		cout << "Derived::Func3()" << endl;
	}
	virtual void Func2()
	{
		cout << "Derived::Func2()" << endl;
	}
};
int main()
{
	Derived d;
	return 0;
}
#endif
#if 0
class Base
{
public:
	virtual void Func3()
	{
		cout << "Base::Func3()" << endl;
	}
	virtual void Func1()
	{
		cout << "Base::Func1()" << endl;
	}
	virtual void Func2()
	{
		cout << "Base::Func2()" << endl;
	}
	int _b;
};
class Derived : public Base
{
public:
	virtual void Func5()
	{
		cout << "Derived::Func5()" << endl;
	}
	virtual void Func3()
	{
		cout << "Derived::Func3()" << endl;
	}
	virtual void Func2()
	{
		cout << "Derived::Func2()" << endl;
	}
	virtual void Func4()
	{
		cout << "Derived::Func4()" << endl;
	}
	int _d;
};
typedef void(*PVFT)();//������ָ�����תΪ����ָ������

int main()
{
	cout << sizeof(Base) << endl;
	cout << sizeof(Derived) << endl;
	Base b;
	b._b = 1;
	Derived d;
	d._b = 1;
	d._d = 2;
	PVFT* pVFT = (PVFT*)(*(int*)(&d));
	while (*pVFT)
	{
		(*pVFT)();
		++pVFT;
	}
	return 0;
}
#endif
#if 0
#include <string>
class Base
{
public:
	virtual void Func1()
	{
		cout << "Base::Func1()" << endl;
	}
	virtual void Func2()
	{
		cout << "Base::Func2()" << endl;
	}
	virtual void Func3()
	{
		cout << "Base::Func3()" << endl;
	}
	int _b;
};
class Derived :public Base
{
public:
	virtual void Func1()
	{
		cout << "Derived::Func1()" << endl;
	}
	virtual void Func3()
	{
		cout << "Derived::Func3()" << endl;
	}
	virtual void Func4()
	{
		cout << "Derived::Func4()" << endl;
	}
	virtual void Func5()
	{
		cout << "Derived::Func5()" << endl;
	}
	int _d;
};
//typedef void(*PVFT)();
//void printVFT(Base& b,const string& str)
//{
//	cout << str << endl;
//	PVFT* pVFT = (PVFT*)(*(int*)&b);
//	while (*pVFT)
//	{
//		(*pVFT)();
//		++pVFT;
//	}
//	cout << endl;
//}
void TestVirtual(Base& b)
{
	b.Func1();
	b.Func2();
	b.Func3();
}
//void Test()
//{
//	Base b;
//	b._b = 1;
//	Derived d;
//	d._b = 1;
//	d._d = 2;
//	printVFT(b,"Base VFT");
//	printVFT(d, "Base VFT");
//
//}
int main()
{
	Base b;
	b._b = 1;
	Derived d;
	d._b = 1;
	d._d = 2;
	TestVirtual(b);
	TestVirtual(d);
	Base* pb = (Base*)&d;//Derived*
	pb->Func1();
	return 0;
}
#endif
#if 0
class B1
{
public:
	virtual void Func1()
	{
		cout << "B1::Func1()" << endl;
	}
	virtual void Func2()
	{
		cout << "B1::Func2()" << endl;
	}
	int _b1;
};
class B2
{
public:
	virtual void Func3()
	{
		cout << "B2::Func3()" << endl;
	}
	virtual void Func4()
	{
		cout << "B2::Func4()" << endl;
	}
	int _b2;
};
class D :public B1, public B2
{
public:
	virtual void Func1()//��B1�е�Func1������д
	{
		cout << "D::Func1()" << endl;
	}
	virtual void Func4()//��B2�е�Func4������д
	{
		cout << "D::Func4()" << endl;
	}
	virtual void Func5()
	{
		cout << "D::Func5()" << endl;
	}
	int _d;
};
typedef void(*PVFT)();
#include <string>
void PrintVFT1(B1& b, const string& str)
{
	cout << str << endl;
	PVFT* pVFT = (PVFT*)(*(int*)(&b));
	while (*pVFT)//��������һ����00 00 00 00
	{
		(*pVFT)();
		++pVFT;
	}
	cout << endl;
}
void PrintVFT2(B2& b, const string& str)
{
	cout << str << endl;
	PVFT* pVFT = (PVFT*)(*(int*)(&b));
	while (*pVFT)//��������һ����00 00 00 00
	{
		(*pVFT)();
		++pVFT;
	}
	cout << endl;
}

int main()
{
	cout << sizeof(D) << endl;
	D d;
	d._b1 = 1;
	d._b2 = 2;
	d._d = 3;
	PrintVFT1(d, "override B1");
	PrintVFT2(d, "override B2");
	return 0;
}
#endif
class B
{
public:
	virtual void Func1()
	{
		cout << "B::Func1()" << endl;
	}
	virtual void Func2()
	{
		cout << "B::Func2()" << endl;
	}
	int _b;
};
class C1 :virtual public B
{
public:
	virtual void Func1()//��B�е�Func������д
	{
		cout << "C1::Func()" << endl;
	}
	virtual void Func3()
	{
		cout << "C1::Func3()" << endl;
	}
	int _c1;
};
class C2 :virtual public B
{
public:
	virtual void Func2()//��B�е�Func2������д
	{
		cout << "C2::Func2()" << endl;
	}
	virtual void Func4()
	{
		cout << "C2::Func4()" << endl;
	}
	int _c2;
};
class D :public C1, public C2
{
public:
	virtual void Func1()//��C1�е�Func1������д
	{
		cout << "D::Func1()" << endl;
	}
	virtual void Func3()//��C1�е�Func3������д
	{
		cout << "D::Func2()" << endl;
	}
	virtual void Func4()//��C2�е�Func4������д
	{
		cout << "D::Func4()" << endl;
	}
	virtual void Func5()//�����ӵ�
	{
		cout << "D::Func5()" << endl;
	}
	int _d;
};
#include <string>
typedef void(*PVFT)();
void PrintVFT1(C1& b, const string& str)
{
	cout << str << endl;
	PVFT* pVFT = (PVFT*)(*(int*)(&b));
	while (*pVFT)
	{
		(*pVFT)();
		++pVFT;
	}
	cout << endl;
}
void PrintVFT2(C2& b, const string& str)
{
	cout << str << endl;
	PVFT* pVFT = (PVFT*)(*(int*)(&b));
	while (*pVFT)
	{
		(*pVFT)();
		++pVFT;
	}
	cout << endl;
}
void PrintVFT3(B& b, const string& str)
{
	cout << str << endl;
	PVFT* pVFT = (PVFT*)(*(int*)(&b));
	while (*pVFT)
	{
		(*pVFT)();
		++pVFT;
	}
	cout << endl;
}
int main()
{
	cout << sizeof(D) << endl;
	D d;
	d._b = 1;
	d._c1 = 2;
	d._c2 = 3;
	d._d = 4;
	PrintVFT1(d, "override C1");
	PrintVFT2(d, "override C2");
	PrintVFT3(d, "override B");
	return 0;
}


