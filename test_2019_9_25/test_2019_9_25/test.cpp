#include <iostream>
using namespace std;
#if 0
class Person
{
public:
	virtual void BuyTicket()
	{
		cout << "ȫ��Ʊ" << endl;
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
		cout << "���Ʊ" << endl;
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
		cout << "��������" << endl;
	}
};
void TestBuyTicket(Person& p)//�û��������������麯��
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
//�����̬������û����ȫʵ�ֵĻ���ȫ�����û�����麯��
class Person
{
public:
	 void BuyTicket()//�����麯��û��virtual
	{
		cout << "ȫ��Ʊ" << endl;
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
		cout << "���Ʊ" << endl;
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
		cout << "��������" << endl;
	}
};
void TestBuyTicket(Person& p)//�û��������������麯��
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
	virtual void TetsFunc1()//�����ĺ�������ͬ
	{
		cout << "Derived::TestFunc1()" << endl;
	}
	virtual void TestFunc2()//����TestFunc2�����麯��
	{
		cout << "Derived::TestFunc2()" << endl;
	}
	virtual void TestFunc3(int)//������麯�������б�ͬ
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
	//virtual void TetsFunc1()override//������������ͬ�����ܹ�����д
	virtual void TestFunc1()override
    {
		cout << "Derived::TestFunc1()" << endl;
	}
	//virtual void TestFunc2()override//����TestFunc2�����麯��
	virtual void TestFunc2()override
	{
		cout << "Derived::TestFunc2()" << endl;
	}
	//virtual void TestFunc3(int)override//������麯�������б�ͬ
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