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
