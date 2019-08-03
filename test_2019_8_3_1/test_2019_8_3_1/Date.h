#pragma once
#include <iostream>
#include <assert.h>
using namespace std;
class Date
{
public:
	bool IsLeapYear(int year);//�ж�����
	int GetMonthDay(int year, int month);//������֪������ֱ�����µ�����
	bool IsValid(int year, int month, int day);//�ж������Ƿ�Ϸ�
	Date(int year , int month , int day );//���캯��
	Date(const Date& d);//�������캯��
	//��ֵ���������
	Date& operator= (const Date& d);//��ֵ
	Date& operator++();//ǰ��
	Date operator++(int);//����
	Date& operator--();//ǰ��
	Date operator--(int);//����
	bool operator==(const Date& d);//�жϱ������Ƿ���d���
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