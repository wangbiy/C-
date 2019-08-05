#include <iostream>
using namespace std;
#if 0
class Date
{
public:
	Date* operator&()
	{
		return this;
	}
	const Date* operator&()const//const取地址操作符重载，返回值类型是不能改变的，因此前面加上const
	{
		return this;
	}
private:
	int _year;
	int _month;
	mutable int _day;
};
int main()
{
	Date d1;
	const Date d2;
	cout << &d1 << endl;
	cout << &d2 << endl;
	return 0;
}
#endif
class Date
{
public:
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << "Date(Date&):" << this << endl;
	}
	Date& operator=(const Date& d)
	{
		cout << this << "=" << &d << endl;
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	~Date()
	{
		cout << "~Date():" << this << endl;
	}
public:
	int _year;
	int _month;
	int _day;
};
Date TestDate(Date d)
{
	Date temp(d);
	temp._day++;
	return temp;
}
void TestDate()
{
	Date d1(2019, 8, 5);
	Date d2(d1);
	d1 = TestDate(d2);
}
int main()
{
	TestDate();
	return 0;
}