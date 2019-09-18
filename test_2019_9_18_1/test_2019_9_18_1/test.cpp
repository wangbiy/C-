#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#if 0
#include <assert.h>
template <class T,size_t N>
class Array
{
public:
	T& operator[](size_t index)
	{
		//N = 100;//������������
		assert(index < N);
		return _arr[index];
	}
private:
	T _arr[N];
	size_t size;
};
int main()
{
	int N1 = 10;
	int N2 = 20;
	//����N1+N2���ʽ����ڱ����ڼ��޷�ȷ�Ͻ����ֻ�еȵ����������ڼ����ȷ�ϣ��൱���ڱ����ڼ��Arrayʵ����ʧ��
	//Array<int, N1 + N2> a;
	Array<int, 10 + 20> a;//�����ſ���
	a[0] = 10;
	return 0;
}
#endif
#if 0
template<class T>
T& Max(T& left, T& right)
{
	if (left > right)
		return left;
	return right;
}
template<>
char*& Max<char*>(char*& left, char*& right)
{
	if (strcmp(left, right) > 0)
		return left;
	return right;
}//���к���ģ���ػ��󣬵���һ�㲻�ý��к���ģ���ػ�
int main()
{
	int a = 10;
	int b = 20;
	cout << Max(a, b) << endl;
	cout << Max(b, a) << endl;
	//��ȷ
	/*char* p1 = "hello";
	char* p2 = "world";
	cout << Max(p1, p2) << endl;
	cout << Max(p2, p1) << endl;*/
	//�����������ȷ�ģ����������p1��p2�����˳�����
	char* p2 = "world";
	char* p1 = "hello";
	cout << Max(p1, p2) << endl;
	cout << Max(p2, p1) << endl;
	//��Ӧ�ý����world��������������hello�����������ǿ��Խ��к���ģ���ػ�
	return 0;
}
#endif
#if 0
//һ�㲻ʹ�ú���ģ���ػ���ֱ�Ӹ��������Ͷ�Ӧ�ĺ�������Ϊ����
template<class T>
const T&(const T& left, const T& right)
{
	if (left > right)
		return left;
	return right;
}
//�����ػ���Ϊ
template <>
const char*& Max<const char*>(const char*& left, const char*& right)
{
	if (strcmp(left, right) > 0)
		return left;
	return right;
}
int main()
{
	char* p2 = "world";
	char* p1 = "hello";
	p1[0] = 'H';//�����޸ģ���Ϊhello��world���ǳ������������ڴ����
	//�����޸ĳ�
	const char* p2 = "world";
	const char* p1 = "hello";
	//���������ڱ����ڼ�ͱ����ˣ���ʱ���ػ�T������const char*,��������Щ������ֻᱨ�����һ�㲻ʹ�ú���ģ���ػ�
	cout << Max(p1, p2) << endl;
	cout << Max(p2, p1) << endl;
	return 0;
}
#endif
//��ģ���ػ�
#if 0
//ȫ�ػ�����ģ������б������е�����ȫ���ػ�
template < class T1, class T2>
class Data//��ģ��
{
public:
	Data()
	{
		cout << "Data<T1,T2>" << endl;
	}
private:
	T1 _d1;
	T2 _d2;
};
//�����Data��ģ�尴��int��double�ķ�ʽ������ʵ����
template <>
class Data<int, double>
{
public:
	Data()
	{
		cout << "Data<int,double>" << endl;
	}
private:
	int _d1;
	double _d2;
};
int main()
{
	Data<int, int> d1;
	Data<int, double>d2;
	return 0;
}
#endif
#if 0
//ƫ�ػ�
//1.�����ػ�
template <class T1,class T2>
class Data
{
public:
	Data()
	{
		cout << "Data<T1,T2>" << endl;
	}
private:
	T1 _d1;
	T2 _d2;
};
//���Data��ģ����ʵ�����ڼ䣬ֻҪ�ڶ�����������int��ʽ����ʵ�������ͻ�ִ���ػ��İ汾
template <class T1>
class Data<T1, int>
{
public:
	Data()
	{
		cout << "Data<T1,int>" << endl;
	}
private:
	T1 _d1;
	int _d2;
};
int main()
{
	Data<double, int> d1;//�����ػ�
	Data<char, int> d2;//�����ػ�
	Data<int, short> d3;//��ģ��
	return 0;
}
#endif
#if 0
template <class T1,class T2>
class Data
{
public:
	Data()
	{
		cout << "Data<T1,T2>" << endl;
	}
private:
	T1 _d1;
	T2 _d2;
};
//ƫ�ػ�����һ�ַ�ʽ�������Ͳ������Ƹ����ϸ�
template<class T1,class T2>
class Data<T1*, T2*>
{
public:
	Data()
	{
		cout << "Data<T1*,T2*>" << endl;
	}
private:
	T1* _d1;
	T2* _d2;
};
int main()
{
	Data<int*, char*> d1;//��ģ���ػ�
	Data<char*, short*> d2;//��ģ���ػ�
	Data<int, char*> d3;//��ģ��
	return 0;
}
#endif
//дһ��ͨ�õĿ�������
#if 0
template <class T>
void copy(T* dst, const T* src, size_t size)
{
	//�ŵ㣺�������
	//ȱ�㣺Ч�ʵ�
	for (size_t i = 0; i < size; ++i)
	{
		dst[i] = src[i];
	}
	//�ŵ㣺Ч�ʸ�
	//ȱ�㣺�ڴ�������Դ������Զ�������ʱ��������ǳ��������
	//memcpy(dst, src, size*sizeof(T));
}
#endif
#if 0
//����ʹ��������ȡ�������ַ������
struct TrueType//��ʾ��������
{
	static bool Get()
	{
		return true;
	}
};
struct FalseType//��ʾ�Զ�������
{
	static bool Get()
	{
		return false;
	}
};
template<class T>
struct TypeTraits//��ģ��
{
	typedef FalseType PODType;
};
//��ģ���ػ�
//�����е��������Ͷ�����
template<>
struct TypeTraits<char>
{
	typedef TrueType PODType;
};
template<>
struct TypeTraits<short>
{
	typedef TrueType PODType;
};
template<>
struct TypeTraits<int>
{
	typedef TrueType PODType;
};
template<>
struct TypeTraits<long>
{
	typedef TrueType PODType;
};
//.......
template<class T>
void Copy(T* dst, const T* src, size_t size)
{
	if (TypeTraits<T>::PODType::Get())
	{
		memcpy(dst, src, size*sizeof(T));
	}
	else
	{
		for (size_t i = 0; i < size; ++i)
		{
			dst[i] = src[i];
		}
	}
}
void Test1()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int _arr[10];
	Copy(_arr, arr, sizeof(arr) / sizeof(arr[0]));
}
class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
		{
			str = "";
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	~String()
	{
		if (_str)
		{
			delete[]_str;
			_str = nullptr;
		}
	}
	String(const String& s)
		:_str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* pstr = new char[strlen(s._str) + 1];
			strcpy(pstr, s._str);
			delete[]_str;
			_str = pstr;
		}
		return *this;
	}
private:
	char* _str;
};
void Test2()
{
	String s1[3] = { "1111", "2222", "3333" };
	String s2[3];
	Copy(s2, s1, 3);//ʹ�õ����Զ������ͣ������ѭ������
}
int main()
{
	//Test1();
	Test2();
	return 0;
}
#endif 
#include "test.h"
//���ִ���
template<class T> 
T Add(const T& left, const T& right)
{
	return left + right; 
}