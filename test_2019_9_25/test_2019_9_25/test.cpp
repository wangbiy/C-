#include <iostream>
using namespace std;
#if 0
class Person
{
public:
	virtual void BuyTicket()
	{
		cout << "全价票" << endl;
	}
protected:
	string _name;
	string _gender;
	string _job;
	int _age;
};
class Student :public Person
{
public:
	virtual void BuyTicket()
	{
		cout << "半价票" << endl;
	}
protected:
	int _stuID;
	double _score;
};
class soldier :public Person
{
public:
	virtual void BuyTicket()
	{
		cout << "军人优先" << endl;
	}
};
void TestBuyTicket(Person& p)//用基类引用来调用虚函数
{
	p.BuyTicket();
}
int main()
{
	Person p;
	Student s;
	soldier so;
	TestBuyTicket(p);
	TestBuyTicket(s);
	TestBuyTicket(so);
	return 0;
}
#endif
#if 0
//如果多态的条件没有完全实现的话，全部调用基类的虚函数
class Person
{
public:
	 void BuyTicket()//基类虚函数没有virtual
	{
		cout << "全价票" << endl;
	}
protected:
	string _name;
	string _gender;
	string _job;
	int _age;
};
class Student :public Person
{
public:
	virtual void BuyTicket()
	{
		cout << "半价票" << endl;
	}
protected:
	int _stuID;
	double _score;
};
class soldier :public Person
{
public:
	virtual void BuyTicket()
	{
		cout << "军人优先" << endl;
	}
};
void TestBuyTicket(Person& p)//用基类引用来调用虚函数
{
	p.BuyTicket();
}
int main()
{
	Person p;
	Student s;
	soldier so;
	TestBuyTicket(p);
	TestBuyTicket(s);
	TestBuyTicket(so);
	return 0;
}
#endif
#if 0
class Base
{
public:
	virtual Base* TestFunc()
	{
		cout << "Base::TestFunc()" << endl;
		return this;
	}
};
class Derived :public Base
{
public:
	virtual Derived* TestFunc()
	{
		cout << "Derived::TestFunc()" << endl;
		return this;
	}
};
void TestVirtualFunc(Base* pd)
{
	pd->TestFunc();
}
int main()
{
	Base b;
	Derived d;
	TestVirtualFunc(&b);
	TestVirtualFunc(&d);
	return 0;
}
#endif
#if 0
class Base
{
public:
	virtual ~Base()
	{
		cout << "Base::~Base()" << endl;
	}
protected:
	int _b;
};
class Derived :public Base
{
public:
	Derived()
	{
		_p = new int[10];
	}
	~Derived()
	{
		if (_p)
		{
			delete[]_p;
		}
		cout << "Derived::~Derived()" << endl;
	}
protected:
	int* _p;
};
int main()
{
	Base* pb = new Derived;
	delete pb;
	return 0;
}
#endif
#if 0
class Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Base::TestFunc1()" << endl;
	}
	void TestFunc2()
	{
		cout << "Base::TestFunc2()" << endl;
	}
	virtual void TestFunc3()
	{
		cout << "Base::TestFunc3()" << endl;
	}
};
class Derived :public Base
{
public:
	virtual void TetsFunc1()//与基类的函数名不同
	{
		cout << "Derived::TestFunc1()" << endl;
	}
	virtual void TestFunc2()//基类TestFunc2不是虚函数
	{
		cout << "Derived::TestFunc2()" << endl;
	}
	virtual void TestFunc3(int)//与基类虚函数参数列表不同
	{
		cout << "Derived::TestFunc3()" << endl;
	}
};
void TestFunc(Base& b)
{
	b.TestFunc1();
	b.TestFunc2();
	b.TestFunc3();
}
int main()
{
	Base b;
	Derived d;
	TestFunc(b);
	TestFunc(d);
	return 0;
}
#endif
#if 0
class Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Base::TestFunc1()" << endl;
	}
	virtual void TestFunc2()
	{
		cout << "Base::TestFunc2()" << endl;
	}
	virtual void TestFunc3()
	{
		cout << "Base::TestFunc3()" << endl;
	}
};
class Derived :public Base
{
public:
	//virtual void TetsFunc1()override//报错，函数名不同，不能构成重写
	virtual void TestFunc1()override
    {
		cout << "Derived::TestFunc1()" << endl;
	}
	//virtual void TestFunc2()override//基类TestFunc2不是虚函数
	virtual void TestFunc2()override
	{
		cout << "Derived::TestFunc2()" << endl;
	}
	//virtual void TestFunc3(int)override//与基类虚函数参数列表不同
	virtual void TestFunc3()override
	{
		cout << "Derived::TestFunc3()" << endl;
	}
};
void TestFunc(Base& b)
{
	b.TestFunc1();
	b.TestFunc2();
	b.TestFunc3();
}
int main()
{
	Base b;
	Derived d;
	TestFunc(b);
	TestFunc(d);
	return 0;
}
#endif
#if 0
class Base
{
public:
	virtual void TestFunc()final
	{
		cout << "Base::TestFunc()" << endl;
	}
};
class Derived :public Base
{
public:
	virtual void TestFunc()
	{
		cout << "Base::TestFunc()" << endl;
	}
};
int main()
{
	return 0;
}
#endif