#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <assert.h>
#include <string.h>
#if 0
class Date
{
public:
	void DateInit(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void printDate()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1, d2, d3;
	d1.DateInit(2019, 7, 25);
	d1.printDate();
	d2.DateInit(2019, 7, 26);
	d2.printDate();
	d3.DateInit(2019, 7, 27);
	d3.printDate();
	return 0;
}
#endif
//但是可不可以在定义对象时就初始化值，以方便起见

//定义构造函数
#if 0
class Date
{
public:
	Date()//构造函数
	{
		cout << "Date():" << this << endl;//this指针用来打印当前位置
	}
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void DateInit(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void printDate()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1, d2, d3;
	//Date d4();//不是创建了一个对象，而是函数声明，(没有一个参数,返回日期类型对象函数)
	Date d5(2019, 7, 10);
	d1.DateInit(2019, 7, 25);
	d1.printDate();
	d2.DateInit(2019, 7, 26);
	d2.printDate();
	d3.DateInit(2019, 7, 27);
	d3.printDate();
	return 0;
}
#endif
#if 0
class Date
{
public:
	Date()
	{
		_year = 2019;
		_month = 7;
		_day = 25;
	}
	Date(int year = 2019, int month = 7, int day = 25)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void print()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1;//指定了多个默认构造函数，无法通过编译，
	       //因为无参的构造函数和全缺省构造函数都是默认构造函数
	return 0;
}
#endif
#if 0
class Date
{
public:
	Date()
	{
		_year = 2019;
		_month = 7;
		_day = 25;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1; //可以通过编译，因为只定义了一个默认构造函数
	return 0;
}
#endif
#if 0
class Date
{

};
int main()
{
	Date d1;//用户没有显式定义，编译器自动生成了默认构造函数
	return 0;
}
#endif
#if 0
class SeqList
{
public:
	SeqList(int Capacity = 10)
	{
		_arr = (int*)malloc(sizeof(int)*Capacity);
		assert(_arr);
		_Capacity = Capacity;
		_size = 0;	
	}
	~SeqList()//析构函数
	{
		if (_arr)
		{
			free(_arr);
			_Capacity = 0;
			_size = 0;
		}
	}
private:
	int* _arr;
	int _Capacity;
	int _size;
};
#endif
#if 0
class String
{
public:
	String(const char* str = "")
	{
		cout << "(const char*):" << this << endl;
		if (str == nullptr)
			str = "";
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}
	~String()//析构函数
	{
		cout << "~String():" << this << endl;
		free(_str);
		_str = nullptr;
	}
private:
	char* _str;
};
class Person
{
	//生成默认的构造函数：将对象中_name和_gender的两个string类的对象构造好
	//生成默认的析构函数：将_name和_gender两个string类的对象销毁掉，
	//即编译器生成的默认析构函数，对会自定类型成员调用它的析构函数
private:
	String _name;
	String _gender;
	int age;
};
void Test()
{
	Person p;
}
int main()
{
	Test();
	return 0;
}
#endif
#if 1
class String
{
public:
	String(const char* str = "")
	{
		cout << "(const char*):" << this << endl;
		if (str == nullptr)
			str = "";
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}
	~String()//析构函数
	{
		cout << "~String():" << this << endl;
		free(_str);
		_str = nullptr;
	}
private:
	char* _str;
};
int main()
{
	String s1("aaad");
	String s2(s1);//拷贝构造函数，如果没有显式实现，编译器会自动生成
	return 0;
}
#endif
#if 0
class Time
{
public:
	Time()
	{
		cout << "Time():" << endl;
		_hour = 0;
		_minute = 0;
		_second = 0;
	}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
private:
	//内置类型
	int _year;
	int _month;
	int _day;
	//自定义类型
	Time _t;
};
int main()
{
	Date d;
	return 0;
}
#endif

