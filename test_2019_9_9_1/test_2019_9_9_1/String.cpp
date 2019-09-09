#include "String.h"
ostream& operator<<(ostream& _cout, const String& s)
{
	_cout << s._str;
	return _cout;
}
void String::Pushback(char ch)//β��һ���ַ�
{
	if (_size == _capacity)
	{
		reserve(_capacity * 2);
	}
	_str[_size++] = ch;
	_str[_size] = '\0';
}
void String::PushBack(const char* str)
{
	size_t str_size = strlen(str);
	if (_size + str_size == _capacity)
	{
		_capacity += str_size;
		reserve(_capacity);
	}
	while (*str != '\0')
	{
		_str[_size++] = *str++;
	}
	_str[_size] = '\0';
}
void String::Popback()
{
	if (_size == 0)
	{
		return;
	}
	_size--;
	_str[_size] = '\0';
}
void String::Pushfront(char ch)
{
	if (_size == _capacity)
	{
		reserve(_capacity * 2);
	}

	for (int i = _size; i >= 0; --i)
	{
		_str[i] = _str[i - 1];
	}
	_str[0] = ch;
	_size += 1;
	_str[_size] = '\0';
}
void String::Pushfront(const char* str)
{
	size_t strsize = strlen(str);//Ҫ������ַ����ĳ���
	if (strsize + _size == _capacity)
	{
		_capacity = strsize + _size + 1;
		reserve(_capacity);
	}
	size_t indexPrev = _size;
	size_t indexLast = _size + strsize - 1;
	while (indexPrev)
	{
		_str[indexLast--] = _str[--indexPrev];//����ǰ�ַ��������strsize�����ǰ���ڳ�λ��
	}
	while (*str != '\0')
	{
		_str[indexPrev++] = *str++;
	}
	_size += strsize;
	_str[_size] = '\0';
}
void String::Popfront()
{
	for (size_t i = 0; i < _size - 1; ++i)
	{
		_str[i] = _str[i + 1];
	}
	_size--;
}
void String::insert(size_t pos, char ch)
{
	assert(pos <= _size);
	reserve(_size + 1);
	size_t end = _size;
	while (end >= pos)
	{
		_str[end + 1] = _str[end];
		end--;
	}
	_str[pos] = ch;
	_size++;

}
void String::insert(size_t pos, const char* str)
{
	assert(pos <= _size);
	size_t len = strlen(str);
	size_t end = strlen(_str);
	int i = 0;
	reserve(_size + len);
	while (end >= pos)
	{
		_str[end + len] = _str[end];//pos�����ͳһ�����
		--end;
	}
	while (*str)
	{
		_str[pos++] = *str++;
	}
	_size += len;
}
void String::erase(size_t pos, size_t n)//��pos��ʼɾ������Ϊn���ַ���
{
	assert(pos <= _size-1);
	while (_str[pos+n-1])
	{
		_str[pos-1] = _str[pos+n-1];
		pos++;
	}
	_str[pos - 1] = '\0';
	_size -= n;
}
size_t String::capacity()const
{
	return _capacity;
}
size_t String::size()const
{
	return _size;
}
void String::resize(size_t newsize, char ch)//����ЧԪ�ظ����ı䵽newsize������������ַ���ch���
{
	size_t oldsize = size();
	if (oldsize > newsize)//��С
	{
		_size = newsize;
		_str[_size] = '\0';
	}
	else
	{
		if (newsize > _capacity)//���newsize��������������
		{
			size_t newcapacity = capacity() * 2;
			reserve(newcapacity);
		}
		memset(_str + _size, ch, newsize - oldsize);//���
		_size = newsize;
		_str[_size] = '\0';
	}
}
void String::reserve(size_t newcapacity)
{
	if (newcapacity > capacity())
	{
		char* pStr = new char[newcapacity + 1];
		strcpy(pStr, _str);
		delete[]_str;
		_str = pStr;
		_capacity = newcapacity;
	}
}
char& String:: operator[](size_t index)
{
	assert(index < size());
	return _str[index];
}
const char& String:: operator[](size_t index)const
{
	assert(index < size());
	return _str[index];
}

void String::append(size_t n, char ch)
{
	size_t leftByte = _capacity - _size;
	if (n > leftByte)
	{
		reserve(n + _size);
	}
	memset(_str + _size, ch, n);
	_size += n;
	_str[_size] = '\0';
}
void String::swap(String& s)
{
	std::swap(_str, s._str);//ʹ�ÿ����swap
	std::swap(_size, s._size);
	std::swap(_capacity, s._capacity);
}
const char* String::c_str()const
{
	return _str;
}
size_t String::find(char ch)
{
	for (size_t i = 0; i < _size; ++i)
	{
		if (ch == _str[i])
			return i;
	}
	return -1;
}
size_t String::find(const char* str)
{
	size_t index_str = 0;
	while (_str[index_str] != '\0')
	{
		if (_str[index_str] == *str)
		{//�����������
			size_t find_index = index_str;
			size_t str_index = 0;
			while (1)
			{
				if (str[str_index] == '\0')//��������str
				{
					return index_str;
				}
				if (_str[find_index] != str[str_index])
					break;
				find_index++;
				str_index++;
			}
		}
		index_str++;
	}
	return -1;
}
size_t String::rfind(char ch, size_t pos)//��ĩβ�ң�posĬ��Ϊnpos
{
	pos = _size - 1;
	for (int i = pos; i >= 0; --i)
	{
		if (_str[i] == ch)
			return i;
	}
	return -1;
}
String::iterator String::begin()
{
	return _str;
}
String::iterator String::end()
{
	return _str + _size;
}
String String::operator+(char ch)
{
	String strTemp(_str);
	strTemp.insert(_size, ch);
	return strTemp;
}
String String::operator+(const char* str)
{
	String strTemp(_str);
	strTemp.insert(_size, str);
	return strTemp;
}
String& String:: operator+=(char ch)
{
	insert(_size, ch);
	return *this;
}
String& String:: operator+=(const String& s)
{
	size_t leftByte = _capacity - _size;//ʣ�˶��ٿռ�
	size_t totalByte = s.size();//ƴ�ӵ��ַ�����Ҫ�Ŀռ�
	if (totalByte>leftByte)
	{
		reserve(_size + totalByte);//��������
	}
	strcpy(_str + _size, s._str);//ƴ�ӵ�_str��
	_size += totalByte;
	return *this;
}
bool String::operator>(const String& s)
{
	char* pstr1 = _str;
	char* pstr2 = s._str;
	while (*pstr1 == *pstr2)
	{
		pstr1++;
		pstr2++;
	}
	if (*pstr1 > *pstr2)
		return true;
	else
	{
		return false;
	}
}
bool String::operator>=(const String& s)
{
	if (*this > s || *this == s)
		return true;
	return false;
}
bool String::operator==(const String& s)
{
	char* pstr1 = _str;
	char* pstr2 = s._str;
	while ((*pstr1 == *pstr2) && (*pstr1 != '\0' || *pstr2 != '\0'))
	{
		pstr1++;
		pstr2++;
	}
	if (*pstr1 == *pstr2)
		return true;
	else
		return false;
}
bool String::operator<(const String& s)
{
	if (!(*this >= s))
		return true;
	return false;
}
bool String::operator<=(const String& s)
{
	if (*this < s || *this == s)
		return true;
	return false;
}
bool String::operator!=(const String& s)
{
	if (*this == s)
		return false;
	return true;
}
bool String::empty()const
{
	return 0 == _size;
}
void String::clear()
{
	_size = 0;
	_str[0] = '\0';
}