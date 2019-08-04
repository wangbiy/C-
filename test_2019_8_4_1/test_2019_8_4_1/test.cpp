#include <iostream>
using namespace std;
class Date
{
public:
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void testfunc1()
	{
		this->_day++;
	}
	void testfunc2()const
	{
		//this->_day++;//不能修改,this指针类型为Date* const,加上const为const Date* const

	}
	void testwithconst()const
	{
		//testfunc1();//错误，说明const成员函数不能调用非const成员函数
	}
	void test()
	{
		testwithconst();//可以调用
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1(2019, 8, 4);
	const Date d2(2019, 8, 5);//常量：d2中的内容不允许被修改
	//d2.testfunc1();//错误，说明const对象不能调用非const的成员函数
	d1.testfunc2();//可以调用，说明非const对象可以调用const成员函数
	return 0;
}