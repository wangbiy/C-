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
//���ǿɲ������ڶ������ʱ�ͳ�ʼ��ֵ���Է������

//���幹�캯��
#if 0
class Date
{
public:
	Date()//���캯��
	{
		cout << "Date():" << this << endl;//thisָ��������ӡ��ǰλ��
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
	//Date d4();//���Ǵ�����һ�����󣬶��Ǻ���������(û��һ������,�����������Ͷ�����)
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
	Date d1;//ָ���˶��Ĭ�Ϲ��캯�����޷�ͨ�����룬
	       //��Ϊ�޲εĹ��캯����ȫȱʡ���캯������Ĭ�Ϲ��캯��
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
	Date d1; //����ͨ�����룬��Ϊֻ������һ��Ĭ�Ϲ��캯��
	return 0;
}
#endif
#if 0
class Date
{

};
int main()
{
	Date d1;//�û�û����ʽ���壬�������Զ�������Ĭ�Ϲ��캯��
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
	~SeqList()//��������
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
	~String()//��������
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
	//����Ĭ�ϵĹ��캯������������_name��_gender������string��Ķ������
	//����Ĭ�ϵ�������������_name��_gender����string��Ķ������ٵ���
	//�����������ɵ�Ĭ�������������Ի��Զ����ͳ�Ա����������������
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
	~String()//��������
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
	String s2(s1);//�������캯�������û����ʽʵ�֣����������Զ�����
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
	//��������
	int _year;
	int _month;
	int _day;
	//�Զ�������
	Time _t;
};
int main()
{
	Date d;
	return 0;
}
#endif

