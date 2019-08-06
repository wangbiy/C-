#include <iostream>
using namespace std;
#if 0
class Time
{
public:
	Time(int hour , int minute, int second)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{
		cout << "Time(int,int,int):" << this << endl;
	}
	void testfunc()
	{

	}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:
	Date(int year=1900, int month=3, int day=3)
		: _year(year)
		//初始化，赋值不是初始化，因为初始化只能进行一次，而赋值可以进行多次
		, _month(month)
		, _day(day)
		, _t(0,0,0)
		//,_t()没有无参的默认构造函数
	{}
private:
	int _year;
	int _month;
	int _day;
	Time _t;
};
#endif
#if 0
class Time
{
public:
	Time(int hour=0, int minute=0, int second=0)
		: _hour(hour)//这里不能使用this指针，因为this是指向对象的，当前初始化列表中对象还没有构造成功，无法使用this指针
		, _minute(minute)
		, _second(second)
	{
		cout << "Time(int,int,int):" << this << endl;//可以使用this指针，因为对象已经构造完整
	}
	void testfunc()
	{

	}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:
	Date(int year = 1900, int month = 3, int day = 3)
		: _year(year)
		//初始化，赋值不是初始化，因为初始化只能进行一次，而赋值可以进行多次
		, _month(month)
		, _day(day)
		, _t()
		//,_t()没有无参的默认构造函数
	{}
private:
	int _year;
	int _month;
	int _day;
	Time _t;
};
int main()
{
	//在编译器编译期间，已经为主函数分配了栈空间，
	//主函数在运行期间所需要的栈的大小用ebp和esp两个寄存器标记
	//这个空间已经包含了函数体的局部对象
	Date d;//在构造函数调用之前，对象是不存在的
	Time t;
	t.testfunc();
	return 0;
}
#endif
#if 0
class Date
{
public:
	explicit Date(int year = 1900, int month = 3, int day = 3)
		: _year(year)
		//初始化，赋值不是初始化，因为初始化只能进行一次，而赋值可以进行多次
		, _month(month)
		, _day(day)
	{}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d(2019);
	d = 2020;//通过单参构造函数，类型转换,但这种代码可读性不高
	//用explicit修饰构造函数，禁止单参构造函数的隐式转换
	return 0;
}
#endif
#if 0
class Time
{
public:
	Time(int hour = 0, int minute = 0, int second = 0)
		:_hour(hour)
		, _minute(minute)
		, _second(second)
	{}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:

private:
	int _year;
	int _month; 
	int _day;
	Time _t;
};
int main()
{
	Date d;
	return 0;
}
#endif
#if 0
int g_count = 0;//设置一个全局变量
class Test
{
	//计数的变量不能包含在每个对象中，而是所有对象共享
public:
	Test()
	{
		g_count++;
	}
	Test(Test& t)
	{
		g_count++;
	}
	~Test()
	{
		g_count--;
	}
private:
	int _b;
};
void test()
{
	Test t1, t2;
	cout << g_count << endl;
}
int main()
{
	Test t1, t2;
	test();
	cout << g_count << endl;//2,因为出了test函数，创建的两个对象销毁
	return 0;
}
#endif
#if 0
class Test
{
public:
	Test()
	{
		_count++;
	}
	Test(Test& t)
	{
		_count++;
	}
	~Test()
	{
		_count--;
	}
public:
	static int _count;
};
int Test::_count = 0;
void test()
{
	Test t1, t2;
	cout << &t1._count << endl;
	cout << &t2._count << endl;
	//这两个地址一样，说明所有对象共享
	cout << Test::_count << endl;//类名+作用域限定符访问
	int a = 10;
	a = t1._count;
	a = Test::_count;
}
int main()
{
	test();
	return 0;
}
#endif
#if 0
class Test
{
public:
	Test()
	{
		_count++;
	}
	Test(Test& t)
	{
		_count++;
	}
	~Test()
	{
		_count--;
	}
	static int GetCount()//static修饰的成员函数
	{
		//cout << _b << endl;//错误，因为对于普通的成员变量，编译器通过this指针访问，而静态成员函数中没有this指针，因此报错。
		//cout << this << endl;//错误
		//Getb();//静态成员函数不能调用普通成员函数
		return _count;
	}
	int Getb()//普通成员函数
	{
		GetCount();//可以调用静态成员函数
		cout << this << endl;
		return _b;
	}
private:
	static int _count;
	int _b;
};
int Test::_count = 0;//static修饰的成员变量在类外初始化
int main()
{
	return 0;
}
#endif
#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	void printDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	//void operator<<(ostream& _cout)//ostream是cout的类型
	//{
	//	_cout << _year << "-" << _month << "-" << _day << endl;
	//}
	friend ostream& operator<<(ostream& _cout, const Date& d);//友元函数的声明
private:
	int _year;
	int _month;
	int _day;
};
ostream& operator<<(ostream& _cout,const Date& d)//友元函数
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}
int  main()
{
	Date d(2019, 8, 6);
	d.printDate();
	//cout << d;//不能这样使用，cout只能用于内置类型，对于自定义类型无法使用
	//d << cout;
	cout << d << endl;//定义了友元函数，可以这样使用,这个函数是有返回值的，返回的是cout
	return 0;
}
#endif
#if 0
class Date
{
	friend istream& operator>>(istream& _cin, Date& d);//声明
	friend ostream& operator<<(ostream& _cout, const Date& d);
public:
	Date(int year = 1900, int month = 1 , int day = 1 )
		:_year(year)
		, _month(month)
		, _day(day)
	{}	
private:
	int _year;
	int _month;
	int _day;
};
istream& operator>>(istream& _cin, Date& d)
{
	_cin >> d._year;
	_cin >> d._month;
	_cin >> d._day;
	return _cin;
}
ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}
int main()
{
	Date d;
	cin >> d;
	cout << d << endl;
	//输入输出运算符都有两个参数，一个是cout或cin，一个是输入或输出的内容,其中输出的内容不能修改，用const修饰，输入的内容可以修改，不用const
	return 0;
}
#endif
#if 0
class Time
{
	friend class Date;//友元类
public:
	Time(int hour , int minute , int second )
		:_hour(hour)
		, _minute(minute)
		, _second(second)
	{
		cout << this->_hour << endl;
	}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
		, _t(0,0,0)
	{}
	void printDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
		cout << _t._hour << ":" << _t._minute << ":" << _t._second << endl;
	}
private:
	int _year;
	int _month;
	int _day;
	Time _t;
};
int main()
{
	return 0;
}
#endif
class A
{
	class B
	{
	public:
		B(int b)
			:_b(b)
		{}
		void testfunc()
		{
			//内部类是外部类的友元类，内部类可以访问外部类的私有成员
			A a(10);
			a._a = 10;
			//外部类的静态成员变量相当于内部类的全局变量
			_c = 10;
		}
	private:
		int _b;
	};
public:
	A(int a)
		:_a(a)
		, _b(0)
	{}
private:
	int _a;
	static int _c;
	B _b;
};
int A::_c = 0;//在类外初始化A类中的静态成员变量
int main()
{
	cout << sizeof(A) << endl;//8，sizeof(外部类)=外部类，和内部类没有任何关系
	return 0;
}
