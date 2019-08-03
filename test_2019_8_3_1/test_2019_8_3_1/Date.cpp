#include "Date.h"
bool Date::IsLeapYear(int year)//判断闰年
{
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
		return true;
	else
		return false;
}
int Date::GetMonthDay(int year, int month)//根据已知的年月直到该月的天数
{
	int Month_array[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int day = Month_array[month];
	if (month == 2 && IsLeapYear(year))//这时2月有29天
	{
		day += 1;
	}
	return day;
}
bool Date::IsValid(int year, int month, int day)//判断日期是否合法
{
	if (year >= 0 && month >0 && month<13 && day>0 && day <= GetMonthDay(year, month))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	return true;
}

Date::Date(int year , int month , int day )//构造函数
	{
		_year = year;
		_month = month;
		_day = day;
		if (!IsValid(_year, _month, _day))
		{
			assert(false);
			cout << "非法日期" << endl;
		}
	}
Date::Date(const Date& d)//拷贝构造函数
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
Date& Date:: operator= (const Date& d)//赋值
{
	if (*this != d)//在保证不是自己给自己赋值
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}
Date& Date:: operator++()//前置
{
	_day += 1;
	return *this;
}
Date Date:: operator++(int)//后置
{
	Date tmp(*this);
	_day += 1;
	return tmp;
}
Date& Date:: operator--()//前置
{
	_day -= 1;
	return *this;
}
Date Date:: operator--(int)//后置，后面的参数不需要进行传递
{
	Date tmp(*this);
	_day -= 1;
	return tmp;
}
bool Date:: operator==(const Date& d)//判断本日期是否与d相等
{
	return (_year == d._year) && (_month == d._month) && (_day == d._day);
}
bool Date:: operator!=(const Date& d)
{
	return !(*this == d);
}
bool Date::operator<(const Date& d)
{
	if (_year < d._year)
		return true;
	else if (_year == d._year&&_month < d._month)
		return true;
	else if (_year == d._year&&_month == d._month&&_day < d._day)
		return true;
	else
		return false;
}
bool Date:: operator>(const Date& d)
{
	if (_year > d._year)
		return true;
	else if (_year == d._year&&_month > d._month)
		return true;
	else if (_year == d._year&&_month == d._month&&_day > d._day)
		return true;
	else
		return false;
}
bool Date:: operator<=(const Date& d)
{
	return *this < d || *this == d;
}
bool Date::operator>=(const Date& d)
{
	return *this>d || *this == d;
}
Date Date:: operator+(int day)//不能改变自身的值，因此构造tmp，保存当前值
{
	Date tmp(*this);
	tmp._day += day;
	return tmp;
}
Date Date:: operator-(int day)//不能改变自身的值，因此构造tmp，保存当前值
{
	Date tmp(*this);
	tmp._day -= day;
	return tmp;
}
void Date:: show()
{
	cout << _year << " " << _month << " " << _day << endl;
}
int main()
{
	Date d1(2019, 8, 3);
	d1.show();
	Date d2(2019, 8, 4);
	d2.show();
	cout << (d1 == d2) << endl;
	cout << (d1 != d2) << endl;
	cout << (d1 < d2) << endl;
	cout << (d1 > d2) << endl;
	cout << (d1 >= d2) << endl;
	cout << (d1 <= d2) << endl;
	d1 = d2;
	d1.show();
	d2++;
	d2.show();
	++d2;
	d2.show();
	d1--;
	d1.show();
	--d1;
	d1.show();
	Date d3 = d2 + 10;
	d3.show();
	Date d4 = d2 - 3;
	d4.show();
	return 0;
}
	

