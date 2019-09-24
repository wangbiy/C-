#include <iostream>
using namespace std;
#if 0
#include <string>
class Person//基类
{
public:
	Person(const string& name, int age)
		:_name(name)
		, _age(age)
	{}
	void PrintPerson()
	{
		cout << _name << endl;
		cout << _age << endl;
	}
private:
	string _name;
	int _age;
};
class Student :Person//派生类
{};
int main()
{
	cout << sizeof(Student) << endl;//string类的字节大小是28，
	//大小为32，将基类中的成员变量继承到派生类中
	Student s;
	return 0;
}
#endif
#if 0
class Base
{
public:
	void SetBase(int pub, int pro, int pri)
	{
		_pub = pub;
		_pro = pro;
		_pri = pri;
	}
	void print()
	{
		cout << _pub << endl;
		cout << _pro << endl; 
		cout << _pri << endl;
	}
public:
	int _pub;
protected:
	int _pro;
private:
	int _pri;
};
class Derived :public Base//按照public继承方式继承
{
public:
	void SetDerived(int pub, int pro, int pri)
	{
		//从基类中继承的成员变量的赋值

		_pub = pub;//基类中访问权限是public的pub被继承了，并且可以访问
		_pro = pro;//基类中访问权限是protected的pro被继承了，并且可以访问，但是在类外不能访问
		//_pri = pri;//不可以，基类中的访问权限是private的成员变量被继承了，但是不能访问(不可见的）
		/*
		派生类的继承方式是public时：基类中private的成员在派生类中不能直接被访问
		但该成员已经被继承了
		*/

		//子类自己的成员变量赋值
		_pubD = pub;
		_proD = pro;
		_priD = pri;	
	}
public:
	int _pubD;
protected:
	int _proD;
private:
	int _priD;
};
class D :public Derived
{
public:
	void TestFunc()
	{
		_pro = 10;//可以使用，说明Derive的类中继承的_pro访问权限不是private的，而是protected的，说明没有改变
	}
};
int main()
{
	cout << sizeof(Derived) << endl;
	Derived d;
	d._pub = 10;//可以直接被访问，基类中public的成员变量在子类中也是public的
	//d._pro = 10;//不能直接访问，不能在类外访问,私有的也一样
	return 0;
}
#endif
#if 0
class Base
{
public:
	void SetBase(int pub, int pro, int pri)
	{
		_pub = pub;
		_pro = pro;
		_pri = pri;
	}
	void print()
	{
		cout << _pub << endl;
		cout << _pro << endl;
		cout << _pri << endl;
	}
public:
	int _pub;
protected:
	int _pro;
private:
	int _pri;
};
class Derived :protected Base//按照protected继承方式继承
{
public:
	void SetDerived(int pub, int pro, int pri)
	{
		//从基类中继承的成员变量的赋值

		_pub = pub;//可以访问
		_pro = pro;//可以访问
		//_pri = pri;//已经被继承，不能访问（不可见）

		//子类自己的成员变量赋值
		_pubD = pub;
		_proD = pro;
		_priD = pri;
	}
public:
	int _pubD;
protected:
	int _proD;
private:
	int _priD;
};
class D :public Derived
{
public:
	void TestFunc()
	{
		_pub = 10;//它可以被访问，但是不能在类外访问，因此访问权限是protected
		_pro = 20;//可以被访问，因此访问权限还是protected	
	}
};
int main()
{
	cout << sizeof(Derived) << endl;
	Derived d;
	//d._pub = 10;//不能在类外访问,说明_pub的访问权限public变成了protected或者private
	//d._pro = 20;//不能在类外访问，它的访问权限有可能是protected或者private
	return 0;
}
#endif
#if 0
class Base
{
public:
	void SetBase(int pub, int pro, int pri)
	{
		_pub = pub;
		_pro = pro;
		_pri = pri;
	}
	void print()
	{
		cout << _pub << endl;
		cout << _pro << endl;
		cout << _pri << endl;
	}
public:
	int _pub;
protected:
	int _pro;
private:
	int _pri;
};
class Derived :private Base//按照private继承方式继承
{
public:
	void SetDerived(int pub, int pro, int pri)
	{
		//从基类中继承的成员变量的赋值

		_pub = pub;//可以访问
		_pro = pro;//可以访问
		//_pri = pri;//不能访问

		//子类自己的成员变量赋值
		_pubD = pub;
		_proD = pro;
		_priD = pri;
	}
public:
	int _pubD;
protected:
	int _proD;
private:
	int _priD;
};
class D :public Derived
{
public:
	void TestFunc()
	{
		_pub = 10;
		_pro = 10;
		//这两个在Derived的子类中都不能使用，并且在类外也不能使用，说明
		//访问权限都是【private
	}
};
int main()
{
	cout << sizeof(Derived) << endl;
	Derived d;
	//d._pub = 10;//不能在类外访问，说明它的访问权限是protected或者private
	//d._pro = 20;//不能在类外访问，说明它的访问权限是protected或者private
	return 0;
}
#endif
#if 0
class B
{
public:
	void SetB(int b)
	{
		_b = b;
	}
protected:
	int _b;
};
class D :public B
{
public:
	void SetD(int b, int d)
	{
		_b = b;
		_d = d;
	}
protected:
	int _d;

};
int main()
{
	B b;//基类
	b.SetB(10);
	D d;//派生类
	d.SetD(20, 30);
	b = d;//可以赋值
	//d = b;//报错，基类对象不能对子类对象赋值
	B* pb = &d;
	B& rb = d;
	//派生类对象可以赋值给基类的指针和引用，但是如果

	//D* pd = &b;
	//D& rd = b;
	//错误，基类对象不可以赋值给派生类的指针和引用
	D* pd = (D*)&b;//进行强制类型转换，但是是不安全的
	return 0;
}
#endif
#if 0
class B
{
public:
	void TestFunc(int b)
	{
		_b = b;
	}
protected:
	int _b;
};
class D:public B
{
public:
	void TestFunc()
	{
		_b = 10;
	}
	char _b;
};
int main()
{
	D d;
	d._b = 10;//赋值给子类自己的_b
	d.TestFunc();
	//d.TestFunc(10);//错误，它调用的是子类中与基类同名的成员函数，不是调用的基类的成员函数
	d.B::TestFunc(10);//这样就可以了
	return 0;
}
#endif
#if 0
class Base
{
public:
	Base(int b)
		:_b(b)
	{}
	int _b;
};
class Derived : public Base
{
public:
	/*
	编译器默认生成的构造函数一定是
	Derived()
	  :Base()//只能调用无参的基类构造函数
	{}这样的
	*/
	Derived(int b, int d)//用户显式定义出派生类的构造函数
		:Base(b)
		, _d(d)
	{}
	int _d;
};
int main()
{
	//Derived d;//报错，没有合适的默认构造函数
	Derived d(10, 20);//没有问题
	return 0;
}
#endif
#if 0
class Base
{
public:
	Base(int b=10)
		:_b(b)
	{}
	int _b;
};
class Derived : public Base
{
public:

	int _d;
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
	Base(int b)
		:_b(b)
	{}
	Base(Base& b)//拷贝构造函数
		:_b(b._b)
	{
		cout << "Base(Base&)" << endl;
	}
	int _b;
};
class Derived :public Base
{
public:
	Derived(int b, int d)
		:Base(b)
		, _d(d)
	{}
	Derived(Derived& d)//显式给出拷贝构造函数,在初始化列表出给出基类的拷贝构造函数
		:Base(d._b)
	{}
	Derived& operator=(const Derived& d)
	{
		Base::operator=(d);
		cout << "Derived::operator=(Derived&)" << endl;
		return *this;
	}
	int _d;
};
int main()
{
	Derived d1(10, 20);
	Derived d2(d1);//如果派生类没有显式定义拷贝构造函数，编译器自动生成
	d2 = d1;
	//派生类没有显式定义赋值运算符重载，编译器自动生成，
	//要调用基类的赋值运算符重载
	return 0;
}
#endif
#if 0
class Base
{
public:
	Base(int b)
		:_b(b)
	{
		cout << "Base::Base()" << endl;
	}
	~Base()
	{
		cout << "Base::~Base()" << endl;
	}
	int _b;
};
class Derived :public Base
{
public:
	Derived(int b, int d)
		:Base(b)
		, _d(d)
	{
		cout << "Derived::Derived()" << endl;
	}
	~Derived()
	{
		cout << "Derived::~Derived()" << endl;
	}
	int _d;
};
void Testfunc()
{
	Derived d1(10, 20);
	Derived d2(d1);
}
int main()
{
	Testfunc();
	return 0;
}
#endif
#if 0
//防止类被继承（C++98）,但是这种方法效率不够高，在C++11中可以使用final关键字来防止类被继承
class Base
{
public:
	static Base GetInstance(int b)
		//这个如果是普通的成员函数，则必须通过对象来调用，
		//但是这时无法用构造函数创建对象，因此可以将它变为静态成员函数
	{
		return Base(b);
	}
private:
	Base(int b)//将基类的构造函数给成私有的,但是虽然不能被继承了，但是如果想要在类外创建对象，又无法做到了，因此可以
		:_b(b)
	{}
	int _b;

};
class Derived :public Base
{
public:
	//Derived(int b, int d)
	//	:Base(b)//不能访问，因为基类中的构造函数为private的，不能被继承
	//	, _d(d)
	//{}
	int _d;
};
int main()
{
	Base b = Base::GetInstance(10);
	return 0;
}
#endif
#if 0
class Base final
{
public:
	Base(int b)
		:_b(b)
	{}
	int _b;

};
class Derived :public Base//不能继承
{
public:
	int _d;
};
int main()
{
	return 0;
}
#endif
#if 0
class Base
{
public:
	Base(int b)
		:_b(b)
	{
		++count;
	}
protected:
	int _b;
public:
	static int count;
};
int Base::count = 0;
class Derived :public Base
{
public:
	Derived(int b, int d)
		:Base(b)
		, _d(d)
	{}
protected:
	int _d;
};
int main()
{
	Derived d(10,20);
	cout << &Base::count << endl;
	cout<<&Derived::count<< endl;
	return 0;
}
#endif
#if 0
class Base
{
	friend void TestFunc();
public:
	Base(int b)
		:_b(b)
	{}
	~Base()
	{}
protected:
	int _b;

};
class Derived :public Base
{
public:
	Derived(int b, int d)
		:Base(b)
		, _d(d)
	{}
	~Derived()
	{}
protected:
	int _d;
};
void TestFunc()
{
	Base b(10);
	cout << b._b << endl;//无法直接访问，因为基类中的_b是protected的,可以使用友元
	Derived d(10, 20);
	//cout << d._d << endl;//无法打印，因此友元关系没有继承
}
int main()
{
	TestFunc();
	return 0;
}
#endif
#if 0
//多继承
class B1
{
public:
	int _b1;
};
class B2
{
public:
	int _b2;
};
class D :public B1, public B2
{
public:
	int _d;
};
void TestFunc()
{
	cout << sizeof(D) << endl;//12
}
int main()
{
	TestFunc();
	return 0;
}
#endif
#if 0
//菱形继承
class B
{
public:
	int _b;
};
class C1 :public B
{
public:
	int _c1;
};
class C2 :public B
{
public:
	int _c2;
};
class D :public C1, public C2
{
public:
	int _d;
};
int main()
{
	cout << sizeof(D) << endl;//20
	D d;
	d.C1::_b = 10;
	d.C2::_b = 20;//可以通过此类方法来具体的访问C1或者C2中继承的_b，让访问变得明确
	return 0;
}
#endif
#if 0
class B
{
public:
	int _b;
};
class D :virtual public B
{
public:
	int _d;
};
int main()
{
	cout << sizeof(D) << endl;//12
	return 0;
}
#endif
#if 0
//菱形虚拟继承
class B
{
public:
	void TestFunc()
	{}
	int _b;
};
class C1 :virtual public B
{
public:
	int _c1;
};
class C2 :virtual public B
{
public:
	int _c2;
};
class D :public C1, public C2
{
public:
	int _d;
};
int main()
{
	D d;
	d._b = 1;
	d._c1 = 2;
	d._c2 = 3;
	d._d = 4;
	return 0;
}
#endif
class Base1
{
public:
	int _b1;
};
class Base2 
{
public:
	int _b2;
};
class Derive : public Base1, public Base2 
{
public:
	int _d;
};
int main()
{
	// A. p1 == p2 == p3
	// B. p1 < p2 < p3
	// C. p1 == p3 != p2
	// D. p1 != p2 != p3
	Derive d;
	Base1* p1 = &d;
	Base2* p2 = &d;
	Derive* p3 = &d;
	return 0;
}


