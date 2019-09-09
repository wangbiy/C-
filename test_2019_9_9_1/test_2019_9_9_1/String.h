#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
//ģ��ʵ��string��
#include <iostream>
using namespace std;
#include <assert.h>
#include <string.h>
class String
{
public:
	typedef char* iterator;
public:
	friend ostream& operator<<(ostream& _cout, const String& s);
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";
		_capacity = strlen(str);
		_size = _capacity;
		_str = new char[_capacity + 1];
		strcpy(_str, str);
	}
	String(size_t n, char ch)
		:_str(new char[n + 1])
		, _capacity(n)
		, _size(n)
	{
		memset(_str, ch, _size);
		_str[_size] = '\0';
	}
	String(const char* pstr, size_t n)
	{
		size_t length = strlen(pstr);
		_size = length > n ? n : length;
		_capacity = _size;
		_str = new char[_capacity + 1];
		for (size_t i = 0; i < _size; ++i)
		{
			_str[i] = pstr[i];
		}
		_str[_size] = '\0';
	}
	String substr(size_t pos, size_t n)const
	{
		return String(_str + pos, n);
	}
	~String()
	{
		if (_str)
		{
			delete[]_str;
			_str = nullptr;
			_size = 0;
			_capacity = 0;
		}
	}
	String(const String& s)//���
		:_str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
		_size = s._size;
		_capacity = s._capacity;
	}
	String& operator=(const String& s)//��ֵ���������
	{
		if (this != &s)
		{
			char* ptr = new char[strlen(s._str) + 1];
			strcpy(ptr, s._str);
			delete[]_str;
			_str = ptr;//���ַ�ʽ�ȽϺã���Ϊ��һ�ַ���ʵ���ͷſռ䣬����������ռ䣬������һ��������ռ�ʧ�ܣ��ͻ����
			_size = s._size;
			_capacity = s._capacity;
		}
		return *this;
	}


	void Pushback(char ch);
	void Popback();
	void Pushfront(char ch);
	void Pushfront(const char* str);
	void Popfront();
	void insert(size_t pos, char ch);
	void insert(size_t pos, const char* str);
	void erase(size_t pos, size_t n);
	void append(size_t n, char ch);
	void swap(String& s);
	char& operator[](size_t index);
	const char& operator[](size_t index)const;


	size_t find(char ch);
	size_t find(const char* str);
	size_t rfind(char ch, size_t pos);
	iterator begin();
	iterator end();

	String operator+(char ch);
	String operator+(const char* str);
	String& operator+=(char ch);
	String& operator+=(const String& s);

	bool operator>(const String& s);
	bool operator>=(const String& s);
	bool operator<(const String& s);
	bool operator<=(const String& s);
	bool operator==(const String& s);
	bool operator!=(const String& s);


	size_t size()const;
	size_t capacity()const;
	const char* c_str()const;
	void resize(size_t newsize, char ch);
	void reserve(size_t newcapacity);

	bool empty()const;
	void clear();
private:
	char* _str;
	size_t _capacity;
	size_t _size;
};

