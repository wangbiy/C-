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
		//this->_day++;//�����޸�,thisָ������ΪDate* const,����constΪconst Date* const

	}
	void testwithconst()const
	{
		//testfunc1();//����˵��const��Ա�������ܵ��÷�const��Ա����
	}
	void test()
	{
		testwithconst();//���Ե���
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1(2019, 8, 4);
	const Date d2(2019, 8, 5);//������d2�е����ݲ������޸�
	//d2.testfunc1();//����˵��const�����ܵ��÷�const�ĳ�Ա����
	d1.testfunc2();//���Ե��ã�˵����const������Ե���const��Ա����
	return 0;
}