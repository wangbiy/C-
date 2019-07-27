#define _CRT_SECURE_NO_WARNINGS 1
#include <string>

#include <iostream>
using namespace std;
#if 0
class Date
{
public:
	Date(int year=1900, int month=1, int day=1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int, int, int):" << this << endl;
	}
	~Date()
	{
		cout << "~Date():" <<this<< endl;
	}
	Date(const Date& d)//拷贝构造函数,因为在拷贝期间内容不发生变化，加上const
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << "Date(Date&)::" << this << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1(2019, 7, 27);
	Date d2(d1);
	//拷贝后d2先调用析构函数，因为符合栈区后进先出的特性
	return 0;
}
#endif
#if 0
class String
{
public:
	String(const char* str)
	{
		cout << "String(const char*):" << this << endl;
		if (str == nullptr)
			str = "";
		_str = (char*)malloc(strlen(str + 1));
		strcpy(_str, str);
	}
	~String()
	{
		cout << "~String()" << this << endl;
		free(_str);
		_str = nullptr;
	}
private:
	char* _str;
};
int main()
{
	String s1("adfe");
	//String s2(s1);//错误的
	return 0;
}
#endif
#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int, int, int):" << this << endl;
	}
	~Date()
	{
		cout << "~Date():" << this << endl;
	}
	Date(const Date& d)//拷贝构造函数,因为在拷贝期间内容不发生变化，加上const
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << "Date(Date&)::" << this << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1(2019, 1, 1);
	Date d2(d1);
	Date d3(2018, 3, 5);
	d3 = d1;
	return 0;
}
#endif
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int, int, int):" << this << endl;
	}
	~Date()
	{
		cout << "~Date():" << this << endl;
	}
	Date(const Date& d)//拷贝构造函数,因为在拷贝期间内容不发生变化，加上const
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << "Date(Date&)::" << this << endl;
	}
	//首先返回引用，看返回引用是否可行--->引用作为函数的返回值类型不能返回栈上的空间
	/*Date& DateAdd(int day)
	{
		_day += day;
		return *this;
	}*/

	Date operator+(int day)//问题：怎么解决非法日期
		//本来应该有两个参数，但是左参数编译器已经给了，所以看起来只有一个
	{
		Date tmp(*this);
		tmp._day += day;
		return tmp;
	}
	Date& operator=(const Date& d)
	{
		if (*this != d)//在保证不是自己给自己赋值
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	bool operator==(const Date&d)//判断相等
	{
		return _year == d._year&&_month == d._month&&_day == d._day;
	}
	bool operator!=(const Date&d)//判断不相等
	{
		return !(*this == d);
	}
	//前置++
	//d2 = ++d1;
	Date& operator++()
	{
		_day += 1;
		return *this;
	}
	//后置++,d2=d1++
	Date operator++(int)
	{
		Date tmp(*this);
		_day += 1;
		return tmp;
	}
	//int operator+(int left, int right)//这是错误的，要重载运算符，至少有一个是类类型的参数
	//{
	//	return left + right;
	//}
	//在该函数中不能修改当前对象的成员变量
	/*void TestConst()const
	{
		_day++;
	}*/
private:
	int _year;
	int _month;
	int _day;
};
void test()
{
	Date d1(2019, 7, 23);
	/*d1.DateAdd(3);*/
	Date d2(d1);
	/*d1 = d1 + 3;*///+号用于内置类型，而这种不是内置类型的编译器不知道加到年月日哪个上去
	d1 = d1 + 3;//运算符重载过了
	
	Date d3(2018, 7, 23);
	d3 = d1;
	if (d3 == d1)
	{
		;
	}
	d1=d2=d3;//意思是d3给d2赋值，然后赋完值的结果赋给d1，所以这个函数必须有返回值
	d2 = ++d1;
	d3 = d1++;
	/*const Date d5;
	d5.TestConst();*/
}
int main()
{
	test();
	return 0;
}
