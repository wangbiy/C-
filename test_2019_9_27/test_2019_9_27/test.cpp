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
		cout << "DErived::Func3()" << endl;
	}
	virtual void Func4()
	{
		cout << "DErived::Func4()" << endl;
	}
	virtual void Func5()
	{
		cout << "DErived::Func5()" << endl;
	}
	int _d;
};
typedef void(*PVFT)();
void printVFT(Base& b)
{
	PVFT* pVFT = (PVFT*)(*(int*)&b);
	while (*pVFT)
	{
		(*pVFT)();
		++pVFT;
	}
	cout << endl;
}
void TestVirtual(Base& b)
{
	b.Func1();
	b.Func2();
	b.Func3();
}
void Test1()
{
	Base b;
	b._b = 1;
	Derived d;
	d._b = 1;
	d._d = 2;
	TestVirtual(b);
	cout << "***************" << endl;
	TestVirtual(d);
}
void Test2()
{
	Base b;
	b._b = 1;
	Derived d;
	d._b = 1;
	d._d = 2;
	printVFT(b);
	cout << "*****************" << endl;
	printVFT(d);

}
int main()
{
	//Test1();
	Test2();
	return 0;
}
#endif


