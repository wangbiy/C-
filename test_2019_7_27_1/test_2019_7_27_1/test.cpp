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
	Date(const Date& d)//�������캯��,��Ϊ�ڿ����ڼ����ݲ������仯������const
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
	//������d2�ȵ���������������Ϊ����ջ������ȳ�������
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
	//String s2(s1);//�����
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
	Date(const Date& d)//�������캯��,��Ϊ�ڿ����ڼ����ݲ������仯������const
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
	Date(const Date& d)//�������캯��,��Ϊ�ڿ����ڼ����ݲ������仯������const
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << "Date(Date&)::" << this << endl;
	}
	//���ȷ������ã������������Ƿ����--->������Ϊ�����ķ���ֵ���Ͳ��ܷ���ջ�ϵĿռ�
	/*Date& DateAdd(int day)
	{
		_day += day;
		return *this;
	}*/

	Date operator+(int day)//���⣺��ô����Ƿ�����
		//����Ӧ������������������������������Ѿ����ˣ����Կ�����ֻ��һ��
	{
		Date tmp(*this);
		tmp._day += day;
		return tmp;
	}
	Date& operator=(const Date& d)
	{
		if (*this != d)//�ڱ�֤�����Լ����Լ���ֵ
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	bool operator==(const Date&d)//�ж����
	{
		return _year == d._year&&_month == d._month&&_day == d._day;
	}
	bool operator!=(const Date&d)//�жϲ����
	{
		return !(*this == d);
	}
	//ǰ��++
	//d2 = ++d1;
	Date& operator++()
	{
		_day += 1;
		return *this;
	}
	//����++,d2=d1++
	Date operator++(int)
	{
		Date tmp(*this);
		_day += 1;
		return tmp;
	}
	//int operator+(int left, int right)//���Ǵ���ģ�Ҫ�����������������һ���������͵Ĳ���
	//{
	//	return left + right;
	//}
	//�ڸú����в����޸ĵ�ǰ����ĳ�Ա����
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
	/*d1 = d1 + 3;*///+�������������ͣ������ֲ����������͵ı�������֪���ӵ��������ĸ���ȥ
	d1 = d1 + 3;//��������ع���
	
	Date d3(2018, 7, 23);
	d3 = d1;
	if (d3 == d1)
	{
		;
	}
	d1=d2=d3;//��˼��d3��d2��ֵ��Ȼ����ֵ�Ľ������d1������������������з���ֵ
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
