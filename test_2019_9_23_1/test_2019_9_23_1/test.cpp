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
	return 0;
}


