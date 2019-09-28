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
class Person//抽象类
{
public:
	virtual void GoToWc(WashRoom& wc) = 0;//纯虚函数
protected:
	string _name;
	int _age;
};
class Man :public Person//在派生类中必须重写基类的纯虚函数，否则子类也是抽象类
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
	//Person p;//抽象类不能实例化对象
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
typedef void(*PVFT)();//将函数指针变量转为函数指针类型

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
	virtual void Func1()//对B1中的Func1进行重写
	{
		cout << "D::Func1()" << endl;
	}
	virtual void Func4()//对B2中的Func4进行重写
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
	while (*pVFT)//虚表中最后一行是00 00 00 00
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
	while (*pVFT)//虚表中最后一行是00 00 00 00
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
	virtual void Func1()//对B中的Func进行重写
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
	virtual void Func2()//对B中的Func2进行重写
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
	virtual void Func1()//对C1中的Func1进行重写
	{
		cout << "D::Func1()" << endl;
	}
	virtual void Func3()//对C1中的Func3进行重写
	{
		cout << "D::Func2()" << endl;
	}
	virtual void Func4()//对C2中的Func4进行重写
	{
		cout << "D::Func4()" << endl;
	}
	virtual void Func5()//新增加的
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


