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
		//��ʼ������ֵ���ǳ�ʼ������Ϊ��ʼ��ֻ�ܽ���һ�Σ�����ֵ���Խ��ж��
		, _month(month)
		, _day(day)
		, _t(0,0,0)
		//,_t()û���޲ε�Ĭ�Ϲ��캯��
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
		: _hour(hour)//���ﲻ��ʹ��thisָ�룬��Ϊthis��ָ�����ģ���ǰ��ʼ���б��ж���û�й���ɹ����޷�ʹ��thisָ��
		, _minute(minute)
		, _second(second)
	{
		cout << "Time(int,int,int):" << this << endl;//����ʹ��thisָ�룬��Ϊ�����Ѿ���������
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
		//��ʼ������ֵ���ǳ�ʼ������Ϊ��ʼ��ֻ�ܽ���һ�Σ�����ֵ���Խ��ж��
		, _month(month)
		, _day(day)
		, _t()
		//,_t()û���޲ε�Ĭ�Ϲ��캯��
	{}
private:
	int _year;
	int _month;
	int _day;
	Time _t;
};
int main()
{
	//�ڱ����������ڼ䣬�Ѿ�Ϊ������������ջ�ռ䣬
	//�������������ڼ�����Ҫ��ջ�Ĵ�С��ebp��esp�����Ĵ������
	//����ռ��Ѿ������˺�����ľֲ�����
	Date d;//�ڹ��캯������֮ǰ�������ǲ����ڵ�
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
		//��ʼ������ֵ���ǳ�ʼ������Ϊ��ʼ��ֻ�ܽ���һ�Σ�����ֵ���Խ��ж��
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
	d = 2020;//ͨ�����ι��캯��������ת��,�����ִ���ɶ��Բ���
	//��explicit���ι��캯������ֹ���ι��캯������ʽת��
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
int g_count = 0;//����һ��ȫ�ֱ���
class Test
{
	//�����ı������ܰ�����ÿ�������У��������ж�����
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
	cout << g_count << endl;//2,��Ϊ����test������������������������
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
	//��������ַһ����˵�����ж�����
	cout << Test::_count << endl;//����+�������޶�������
	int a = 10;
	a = t1._count;
	a = Test::_count;
}
int main()
{
	test();
	return 0;
}
