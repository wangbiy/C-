#pragma once
#include <iostream>
#include <assert.h>
using namespace std;
class Date
{
public:
	bool IsLeapYear(int year);//判断闰年
	int GetMonthDay(int year, int month);//根据已知的年月直到该月的天数
	bool IsValid(int year, int month, int day);//判断日期是否合法
	Date(int year , int month , int day );//构造函数
	Date(const Date& d);//拷贝构造函数
	//赋值运算符重载
	Date& operator= (const Date& d);//赋值
	Date& operator++();//前置
	Date operator++(int);//后置
	Date& operator--();//前置
	Date operator--(int);//后置
	bool operator==(const Date& d);//判断本日期是否与d相等
	bool operator!=(const Date& d);
	bool operator<(const Date& d);
	bool operator>(const Date& d);
	bool operator<=(const Date& d);
	bool operator>=(const Date& d);
	Date operator+(int day);
	Date operator-(int day);
	void show();
private:
	int _year;
	int _month;
	int _day;
};